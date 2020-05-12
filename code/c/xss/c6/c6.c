// c4.c - C in four functions
// char, int, and pointer types
// if, while, return, and expression statements
// just enough features to allow self-compilation and a bit more
// Written by Robert Swierczek
// 修改者: 陳鍾誠 (模組化並加上中文註解)

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
// #include <unistd.h>
// #include <fcntl.h>
#include "c6.h"

// ----------- ccc add ----------------
int *stack,       // 堆疊段
    *rel, *relp,  // 重定位紀錄
    output;       // 輸出目的檔 
char *st, *stp,   // 字串表, 字串表指標
     *ops;        // 運算列表。
char *cFile, *oFile;
char *obj;        // 目的檔
enum { RCode, RData }; // RCode: 程式重定位, RData 資料重定位。
enum { O_READ=0, O_WRITE = 769 }; // O_READ: 讀取模式, O_WRITE: 寫入模式, 769 = O_WRONLY|O_CREAT|O_TRUNC
// ----------- ccc ----------------

// tokens and classes (operators last and in precedence order) (按優先權順序排列)
enum { // token : 0-127 直接用該字母表達， 128 以後用代號。
  Num = 128, Fun, Sys, Glo, Loc, Id,
  Char, Else, Enum, If, Int, Return, Sizeof, While,
  Assign, Cond, Lor, Lan, Or, Xor, And, Eq, Ne, Lt, Gt, Le, Ge, Shl, Shr, Add, Sub, Mul, Div, Mod, Inc, Dec, Brak
};

// types (支援型態，只有 int, char, pointer)
enum { CHAR, INT, PTR };

// 因為沒有 struct，所以使用 offset 代替，例如 id[Tk] 代表 id.Tk (token), id[Hash] 代表 id.Hash, id[Name] 代表 id.Name, .....
// identifier offsets (since we can't create an ident struct)
enum { Tk, Hash, Name, Class, Type, Val, HClass, HType, HVal, Idsz }; // HClass, HType, HVal 是暫存的備份 ???

// opcodes (機器碼的 op)
enum { LEA ,IMM ,JMP ,JSR ,BZ  ,BNZ ,ENT ,ADJ ,LEV ,LI  ,LC  ,SI  ,SC  ,PSH ,
       OR  ,XOR ,AND ,EQ  ,NE  ,LT  ,GT  ,LE  ,GE  ,SHL ,SHR ,ADD ,SUB ,MUL ,DIV ,MOD ,
       OPEN,READ,WRIT,CLOS,PRTF,MALC,FREE,MSET,MCMP,MCPY,EXIT };

char *source, *p, *lp, // current position in source code (p: 目前原始碼指標, lp: 上一行原始碼指標)
     *data, *datap;    // datap/bss pointer (資料段機器碼指標)

int *code, *pc, // code: 程式段, pc: 程式計數器
    *e, *le,  // current position in emitted code (e: 目前機器碼指標, le: 上一行機器碼指標)
    *id,      // currently parsed identifier (id: 目前的 id)
    *sym,     // symbol table (simple list of identifiers) (符號表)
    tk,       // current token (目前 token)
    ival,     // current token value (目前的 token 值)
    ty,       // current expression type (目前的運算式型態)
    loc,      // local variable offset (區域變數的位移)
    line,     // current line number (目前行號)
    src,      // print source and assembly flag (印出原始碼)
    debug,    // print executed instructions (印出執行指令 -- 除錯模式)
    poolsz;   // 分配空間大小

// ------------------ 字串表 ------------------------
char* st_add(char *str, int len) {
  char *s; s = stp;
  memcpy(stp, str, len);
  stp = stp + len;
  *stp++ = 0;
  return s;
}

// ------------------ 符號表 ------------------------
int hash(char *str, int len) {
  int i, h; char *p;
  i=0; h = 0; p = str;
  while (i++ < len)
    h = h * 147 + *p++;  // 計算雜湊值
  h = (h << 6) + (p - str); // 考慮長度的雜湊值！
  return h;
}

int *sym_add(char *name, int len) {
  int h, *id;
  h = hash(name, len);
  id = sym;
  while (id[Tk]) { // 循序搜尋 ?
    if (h == id[Hash] && !memcmp((char *)id[Name], name, len)) { h = id[Tk]; return id; } // 該變數出現過，直接傳回舊的！
    id = id + Idsz; // 碰撞，前進到下一格。
  }
  id[Name] = (int) name; // 變數名稱
  id[Hash] = h; // id.Hash = 雜湊值
  id[Tk] = Id;  // id.Tk = Id
  return id;
}

// ------------------ 詞彙解析 Lexer --------------------
void next() // 取得下一個詞彙
{
  char *pp, *name;

  while ((tk = *p)) {
    ++p;
    if (tk == '\n') { // 換行
      if (src) {
        printf("%d: %.*s", line, p - lp, lp); // 印出該行
        lp = p; // lp = p = 新一行的原始碼開頭
        while (le < e) { // 印出上一行的所有目的碼
          printf("%8.4s", &ops[*++le * 5]);
          if (*le <= ADJ) printf(" %d\n", *++le); else printf("\n"); // LEA ,IMM ,JMP ,JSR ,BZ  ,BNZ ,ENT ,ADJ 有一個參數。
        }
      }
      ++line;
    }
    else if (tk == '#') { // 取得 #include <stdio.h> 這類的一整行
      while (*p != 0 && *p != '\n') ++p;
    }
    else if ((tk >= 'a' && tk <= 'z') || (tk >= 'A' && tk < 'Z') || tk == '_') { // 取得變數名稱
      pp = p-1;
      while ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z') || (*p >= '0' && *p <= '9') || *p == '_') p++;
      name = st_add(pp, p-pp);
      id = sym_add(name, p-pp);
      tk = id[Tk];
      return;
    }
    else if (tk >= '0' && tk <= '9') { // 取得數字串
      if ((ival = tk - '0')) { while (*p >= '0' && *p <= '9') ival = ival * 10 + *p++ - '0'; } // 十進位
      else if (*p == 'x' || *p == 'X') { // 十六進位
        while ((tk = *++p) && ((tk >= '0' && tk <= '9') || (tk >= 'a' && tk <= 'f') || (tk >= 'A' && tk <= 'F'))) // 16 進位
          ival = ival * 16 + (tk & 15) + (tk >= 'A' ? 9 : 0);
      }
      else { while (*p >= '0' && *p <= '7') ival = ival * 8 + *p++ - '0'; } // 八進位
      tk = Num;
      return;
    }
    else if (tk == '/') {
      if (*p == '/') { // 註解
        ++p;
        while (*p != 0 && *p != '\n') ++p; // 略過註解
      }
      else { // 除法
        tk = Div;
        return;
      }
    }
    else if (tk == '\'' || tk == '"') { // 字元或字串
      pp = datap;
      while (*p != 0 && *p != tk) {
        if ((ival = *p++) == '\\') {
          if ((ival = *p++) == 'n') ival = '\n'; // 處理 \n 的特殊情況
        }
        if (tk == '"') *datap++ = ival; // 把字串塞到資料段裏
      }
      ++p;
      if (tk == '"') ival = (int)pp; else tk = Num; // (若是字串) ? (ival = 字串 (在資料段中的) 指標) : (字元值)
      return;
    } // 以下為運算元 =+-!<>|&^%*[?~, ++, --, !=, <=, >=, ||, &&, ~  ;{}()],:
    else if (tk == '=') { if (*p == '=') { ++p; tk = Eq; } else tk = Assign; return; }
    else if (tk == '+') { if (*p == '+') { ++p; tk = Inc; } else tk = Add; return; }
    else if (tk == '-') { if (*p == '-') { ++p; tk = Dec; } else tk = Sub; return; }
    else if (tk == '!') { if (*p == '=') { ++p; tk = Ne; } return; }
    else if (tk == '<') { if (*p == '=') { ++p; tk = Le; } else if (*p == '<') { ++p; tk = Shl; } else tk = Lt; return; }
    else if (tk == '>') { if (*p == '=') { ++p; tk = Ge; } else if (*p == '>') { ++p; tk = Shr; } else tk = Gt; return; }
    else if (tk == '|') { if (*p == '|') { ++p; tk = Lor; } else tk = Or; return; }
    else if (tk == '&') { if (*p == '&') { ++p; tk = Lan; } else tk = And; return; }
    else if (tk == '^') { tk = Xor; return; }
    else if (tk == '%') { tk = Mod; return; }
    else if (tk == '*') { tk = Mul; return; }
    else if (tk == '[') { tk = Brak; return; }
    else if (tk == '?') { tk = Cond; return; }
    else if (tk == '~' || tk == ';' || tk == '{' || tk == '}' || tk == '(' || tk == ')' || tk == ']' || tk == ',' || tk == ':') return;
  }
}

// ------------------ 編譯器開始 compiler --------------------
void expr(int lev) // 運算式 expression, 其中 lev 代表優先等級
{
  int t, *d;

  if (!tk) { printf("%d: unexpected eof in expression\n", line); exit(-1); } // EOF
  else if (tk == Num) { *++e = IMM; *++e = ival; next(); ty = INT; } // 數值
  else if (tk == '"') { // 字串
    *++e = IMM; *++e = ival; 
    // printf("ccc:expr:string ival=%d data=%d\n", ival, data);
    *relp++ = (e-code); *relp++ = RData; // add by ccc, 字串立即值的修改紀錄。
    next();
    while (tk == '"') next();
    datap = (char *)(((int)datap + sizeof(int)) & -sizeof(int)); ty = PTR; // 用 int 為大小對齊 ??
  }
  else if (tk == Sizeof) { // 處理 sizeof(type) ，其中 type 可能為 char, int 或 ptr
    next(); if (tk == '(') next(); else { printf("%d: open paren expected in sizeof\n", line); exit(-1); }
    ty = INT; if (tk == Int) next(); else if (tk == Char) { next(); ty = CHAR; }
    while (tk == Mul) { next(); ty = ty + PTR; }
    if (tk == ')') next(); else { printf("%d: close paren expected in sizeof\n", line); exit(-1); }
    *++e = IMM; *++e = (ty == CHAR) ? sizeof(char) : sizeof(int);
    ty = INT;
  }
  else if (tk == Id) { // 處理 id ...
    d = id; next();
    if (tk == '(') { // id (args) ，這是 call
      next();
      t = 0;
      while (tk != ')') { expr(Assign); *++e = PSH; ++t; if (tk == ',') next(); } // 推入 arg
      next();
      // d[Class] 可能為 Num = 128, Fun, Sys, Glo, Loc, ...
      if (d[Class] == Sys) *++e = d[Val]; // token 是系統呼叫 ???
      else if (d[Class] == Fun) { // token 是自訂函數，用 JSR : jump to subroutine 指令呼叫
        *++e = JSR; *++e = d[Val];
        *relp++ = e-code; *relp++ = RCode; // add by ccc: 加入重定位紀錄。
        // printf("ccc:expr:Fun:e=%d code=%d\n", e, code);
      }
      else { printf("%d: bad function call\n", line); exit(-1); }
      if (t) { *++e = ADJ; *++e = t; } // 有參數，要調整堆疊  (ADJ : stack adjust)
      ty = d[Type];
    }
    else if (d[Class] == Num) { *++e = IMM; *++e = d[Val]; ty = INT; } // 該 id 是數值
    else {
      if (d[Class] == Loc) { *++e = LEA; *++e = loc - d[Val]; } // 該 id 是區域變數，載入區域變數 (LEA : load local address)
      else if (d[Class] == Glo) { // 該 id 是全域變數，載入該全域變數 (IMM : load global address or immediate 載入全域變數或立即值)
        *++e = IMM; *++e = d[Val];
        // *relp++ = d[Val]; *relp++ = RData;
      }
      else { printf("%d: undefined variable\n", line); exit(-1); }
      *++e = ((ty = d[Type]) == CHAR) ? LC : LI; // LI  : load int, LC  : load char
    }
  }
  else if (tk == '(') { // (E) : 有括號的運算式 ...
    next();
    if (tk == Int || tk == Char) {
      t = (tk == Int) ? INT : CHAR; next();
      while (tk == Mul) { next(); t = t + PTR; }
      if (tk == ')') next(); else { printf("%d: bad cast\n", line); exit(-1); }
      expr(Inc); // 處理 ++, -- 的情況
      ty = t;
    }
    else {
      expr(Assign); // 處理 (E) 中的 E      (E 運算式必須能處理 (t=x) op y 的情況，所以用 expr(Assign))
      if (tk == ')') next(); else { printf("%d: close paren expected\n", line); exit(-1); }
    }
  }
  else if (tk == Mul) { // * 乘法
    next(); expr(Inc);
    if (ty > INT) ty = ty - PTR; else { printf("%d: bad dereference\n", line); exit(-1); }
    *++e = (ty == CHAR) ? LC : LI;
  }
  else if (tk == And) { // & AND
    next(); expr(Inc);
    if (*e == LC || *e == LI) --e; else { printf("%d: bad address-of\n", line); exit(-1); }
    ty = ty + PTR;
  }
  else if (tk == '!') { next(); expr(Inc); *++e = PSH; *++e = IMM; *++e = 0; *++e = EQ; ty = INT; } // NOT
  else if (tk == '~') { next(); expr(Inc); *++e = PSH; *++e = IMM; *++e = -1; *++e = XOR; ty = INT; } // Logical NOT
  else if (tk == Add) { next(); expr(Inc); ty = INT; }
  else if (tk == Sub) {
    next(); *++e = IMM;
    if (tk == Num) { *++e = -ival; next(); } else { *++e = -1; *++e = PSH; expr(Inc); *++e = MUL; } // -Num or -E
    ty = INT;
  }
  else if (tk == Inc || tk == Dec) { // ++ or --
    t = tk; next(); expr(Inc);
    if (*e == LC) { *e = PSH; *++e = LC; }
    else if (*e == LI) { *e = PSH; *++e = LI; }
    else { printf("%d: bad lvalue in pre-increment\n", line); exit(-1); }
    *++e = PSH;
    *++e = IMM; *++e = (ty > PTR) ? sizeof(int) : sizeof(char);
    *++e = (t == Inc) ? ADD : SUB;
    *++e = (ty == CHAR) ? SC : SI;
  }
  else { printf("%d: bad expression\n", line); exit(-1); }
  // 參考: https://en.wikipedia.org/wiki/Operator-precedence_parser, https://www.cnblogs.com/rubylouvre/archive/2012/09/08/2657682.html https://web.archive.org/web/20151223215421/http://hall.org.ua/halls/wizzard/pdf/Vaughan.Pratt.TDOP.pdf
  while (tk >= lev) { // "precedence climbing" or "Top Down Operator Precedence" method
    t = ty;
    if (tk == Assign) {
      next();
      if (*e == LC || *e == LI) *e = PSH; else { printf("%d: bad lvalue in assignment\n", line); exit(-1); }
      expr(Assign); *++e = ((ty = t) == CHAR) ? SC : SI;
    }
    else if (tk == Cond) {
      next();
      *++e = BZ; d = ++e;
      expr(Assign);
      if (tk == ':') next(); else { printf("%d: conditional missing colon\n", line); exit(-1); }
      *d = (int)(e + 3 - d); *++e = JMP; d = ++e;
      expr(Cond);
      *d = (int)(e + 1 - d);
    }
    else if (tk == Lor) { next(); *++e = BNZ; d = ++e; expr(Lan); *d = (int)(e + 1 - d); ty = INT; }
    else if (tk == Lan) { next(); *++e = BZ;  d = ++e; expr(Or);  *d = (int)(e + 1 - d); ty = INT; }
    else if (tk == Or)  { next(); *++e = PSH; expr(Xor); *++e = OR;  ty = INT; }
    else if (tk == Xor) { next(); *++e = PSH; expr(And); *++e = XOR; ty = INT; }
    else if (tk == And) { next(); *++e = PSH; expr(Eq);  *++e = AND; ty = INT; }
    else if (tk == Eq)  { next(); *++e = PSH; expr(Lt);  *++e = EQ;  ty = INT; }
    else if (tk == Ne)  { next(); *++e = PSH; expr(Lt);  *++e = NE;  ty = INT; }
    else if (tk == Lt)  { next(); *++e = PSH; expr(Shl); *++e = LT;  ty = INT; }
    else if (tk == Gt)  { next(); *++e = PSH; expr(Shl); *++e = GT;  ty = INT; }
    else if (tk == Le)  { next(); *++e = PSH; expr(Shl); *++e = LE;  ty = INT; }
    else if (tk == Ge)  { next(); *++e = PSH; expr(Shl); *++e = GE;  ty = INT; }
    else if (tk == Shl) { next(); *++e = PSH; expr(Add); *++e = SHL; ty = INT; }
    else if (tk == Shr) { next(); *++e = PSH; expr(Add); *++e = SHR; ty = INT; }
    else if (tk == Add) {
      next(); *++e = PSH; expr(Mul);
      if ((ty = t) > PTR) { *++e = PSH; *++e = IMM; *++e = sizeof(int); *++e = MUL;  }
      *++e = ADD;
    }
    else if (tk == Sub) {
      next(); *++e = PSH; expr(Mul);
      if (t > PTR && t == ty) { *++e = SUB; *++e = PSH; *++e = IMM; *++e = sizeof(int); *++e = DIV; ty = INT; }
      else if ((ty = t) > PTR) { *++e = PSH; *++e = IMM; *++e = sizeof(int); *++e = MUL; *++e = SUB; }
      else *++e = SUB;
    }
    else if (tk == Mul) { next(); *++e = PSH; expr(Inc); *++e = MUL; ty = INT; }
    else if (tk == Div) { next(); *++e = PSH; expr(Inc); *++e = DIV; ty = INT; }
    else if (tk == Mod) { next(); *++e = PSH; expr(Inc); *++e = MOD; ty = INT; }
    else if (tk == Inc || tk == Dec) {
      if (*e == LC) { *e = PSH; *++e = LC; }
      else if (*e == LI) { *e = PSH; *++e = LI; }
      else { printf("%d: bad lvalue in post-increment\n", line); exit(-1); }
      *++e = PSH; *++e = IMM; *++e = (ty > PTR) ? sizeof(int) : sizeof(char);
      *++e = (tk == Inc) ? ADD : SUB;
      *++e = (ty == CHAR) ? SC : SI;
      *++e = PSH; *++e = IMM; *++e = (ty > PTR) ? sizeof(int) : sizeof(char);
      *++e = (tk == Inc) ? SUB : ADD;
      next();
    }
    else if (tk == Brak) {
      next(); *++e = PSH; expr(Assign);
      if (tk == ']') next(); else { printf("%d: close bracket expected\n", line); exit(-1); }
      if (t > PTR) { *++e = PSH; *++e = IMM; *++e = sizeof(int); *++e = MUL;  }
      else if (t < PTR) { printf("%d: pointer type expected\n", line); exit(-1); }
      *++e = ADD;
      *++e = ((ty = t - PTR) == CHAR) ? LC : LI;
    }
    else { printf("%d: compiler error tk=%d\n", line, tk); exit(-1); }
  }
}

void stmt() // 陳述 statement
{
  int *a, *b;

  if (tk == If) { // if 語句
    next();
    if (tk == '(') next(); else { printf("%d: open paren expected\n", line); exit(-1); }
    expr(Assign);
    if (tk == ')') next(); else { printf("%d: close paren expected\n", line); exit(-1); }
    *++e = BZ; b = ++e;
    stmt();
    if (tk == Else) { // else 語句
      *b = (int)(e + 3 - b); *++e = JMP; b = ++e;
      next();
      stmt();
    }
    *b = (int)(e + 1 - b);
  }
  else if (tk == While) { // while 語句
    next();
    a = e + 1;
    if (tk == '(') next(); else { printf("%d: open paren expected\n", line); exit(-1); }
    expr(Assign);
    if (tk == ')') next(); else { printf("%d: close paren expected\n", line); exit(-1); }
    *++e = BZ; b = ++e;
    stmt();
    *++e = JMP; ++e; *e = (int) (a-e);
    *b = (int)(e + 1 - b);
  }
  else if (tk == Return) { // return 語句
    next();
    if (tk != ';') expr(Assign);
    *++e = LEV;
    if (tk == ';') next(); else { printf("%d: semicolon expected\n", line); exit(-1); }
  }
  else if (tk == '{') { // 區塊 {...}
    next();
    while (tk != '}') stmt();
    next();
  }
  else if (tk == ';') { // ; 空陳述
    next();
  }
  else { // 指定 assign
    expr(Assign);
    if (tk == ';') next(); else { printf("%d: semicolon expected\n", line); exit(-1); }
  }
}

int prog() { // 編譯整個程式 Program
  int bt, i;
  line = 1;
  next();
  while (tk) {
    bt = INT; // basetype
    if (tk == Int) next();
    else if (tk == Char) { next(); bt = CHAR; }
    else if (tk == Enum) { // enum Id? {... 列舉
      next();
      if (tk != '{') next(); // 略過 Id
      if (tk == '{') {
        next();
        i = 0; // 紀錄 enum 的目前值
        while (tk != '}') {
          if (tk != Id) { printf("%d: bad enum identifier %d\n", line, tk); return -1; }
          next();
          if (tk == Assign) { // 有 Id=Num 的情況
            next();
            if (tk != Num) { printf("%d: bad enum initializer\n", line); return -1; }
            i = ival;
            next();
          }
          id[Class] = Num; id[Type] = INT; id[Val] = i++;
          if (tk == ',') next();
        }
        next();
      }
    }
    while (tk != ';' && tk != '}') { // 掃描直到區塊結束
      ty = bt;
      while (tk == Mul) { next(); ty = ty + PTR; }
      if (tk != Id) { printf("%d: bad global declaration\n", line); return -1; }
      if (id[Class]) { printf("%d: duplicate global definition\n", line); return -1; } // id.Class 已經存在，重複宣告了！
      next();
      id[Type] = ty;
      if (tk == '(') { // function 函數定義 ex: int f( ...
        id[Class] = Fun;
        id[Val] = (int)(e + 1);
        next(); i = 0;
        while (tk != ')') { // 掃描參數直到 ...)
          ty = INT;
          if (tk == Int) next();
          else if (tk == Char) { next(); ty = CHAR; }
          while (tk == Mul) { next(); ty = ty + PTR; }
          if (tk != Id) { printf("%d: bad parameter declaration\n", line); return -1; }
          if (id[Class] == Loc) { printf("%d: duplicate parameter definition\n", line); return -1; } // 這裡的 id 會指向 hash 搜尋過的 symTable 裏的那個 (在 next 裏處理的)，所以若是該 id 已經是 Local，那麼就重複了！
          // 把 id.Class, id.Type, id.Val 暫存到 id.HClass, id.HType, id.Hval ，因為 Local 優先於 Global
          id[HClass] = id[Class]; id[Class] = Loc;
          id[HType]  = id[Type];  id[Type] = ty;
          id[HVal]   = id[Val];   id[Val] = i++;
          next();
          if (tk == ',') next();
        }
        next();
        if (tk != '{') { printf("%d: bad function definition\n", line); return -1; } // BODY 開始 {...
        loc = ++i;
        next();
        while (tk == Int || tk == Char) { // 宣告
          bt = (tk == Int) ? INT : CHAR;
          next();
          while (tk != ';') {
            ty = bt;
            while (tk == Mul) { next(); ty = ty + PTR; }
            if (tk != Id) { printf("%d: bad local declaration\n", line); return -1; }
            if (id[Class] == Loc) { printf("%d: duplicate local definition\n", line); return -1; }
            // 把 id.Class, id.Type, id.Val 暫存到 id.HClass, id.HType, id.Hval ，因為 Local 優先於 Global
            id[HClass] = id[Class]; id[Class] = Loc;
            id[HType]  = id[Type];  id[Type] = ty;
            id[HVal]   = id[Val];   id[Val] = ++i;
            next();
            if (tk == ',') next();
          }
          next();
        }
        *++e = ENT; *++e = i - loc;
        while (tk != '}') stmt();
        *++e = LEV;
        id = sym; // unwind symbol table locals (把被區域變數隱藏掉的那些 Local id 還原，恢復全域變數的符號定義)
        while (id[Tk]) {
          if (id[Class] == Loc) {
            id[Class] = id[HClass];
            id[Type] = id[HType];
            id[Val] = id[HVal];
          }
          id = id + Idsz;
        }
      }
      else {
        id[Class] = Glo;
        id[Val] = (int)datap;
        datap = datap + sizeof(int);
      }
      if (tk == ',') next();
    }
    next();
  }
  return 0;
}

int cc_main(char *file) {
  int fd, *idmain, i;
  if ((fd = open(file, O_READ, 0)) < 0) { printf("could not open(%s)\n", file); return -1; }

  ops = "LEA ,IMM ,JMP ,JSR ,BZ  ,BNZ ,ENT ,ADJ ,LEV ,LI  ,LC  ,SI  ,SC  ,PSH ,"\
        "OR  ,XOR ,AND ,EQ  ,NE  ,LT  ,GT  ,LE  ,GE  ,SHL ,SHR ,ADD ,SUB ,MUL ,DIV ,MOD ,"\
        "OPEN,READ,WRIT,CLOS,PRTF,MALC,FREE,MSET,MCMP,MCPY,EXIT,";

  p = "char else enum if int return sizeof while "
      "open read write close printf malloc free memset memcmp memcpy exit void main";
  i = Char; while (i <= While) { next(); id[Tk] = i++; } // add keywords to symbol table
  i = OPEN; while (i <= EXIT) { next(); id[Class] = Sys; id[Type] = INT; id[Val] = i++; } // add library to symbol table
  next(); id[Tk] = Char; // handle void type
  next(); idmain = id; // keep track of main

  lp = p = source;
  if ((i = read(fd, p, poolsz-1)) <= 0) { printf("read() returned %d\n", i); return -1; }
  p[i++] = '\n'; p[i++] = '\0'; // 設定程式 p 字串結束符號 \0
  close(fd);

  if (prog() == -1) return -1;

  if (!(pc = (int *)idmain[Val])) { printf("main() not defined\n"); return -1; }
  if (src) return 0;
  return 0;
}

// ------------------------ VM : 虛擬機 ------------------------
int vm_run(int *pc, int *bp, int *sp) { // 虛擬機 => pc: 程式計數器, sp: 堆疊暫存器, bp: 框架暫存器
  int a, cycle; // a: 累積器, cycle: 執行指令數
  int i, *t;    // temps

  cycle = 0;
  while (1) {
    i = *pc++; ++cycle;
    if (debug) {
      // printf("pc=%d code=%d\n", pc, code);
      printf("%d> %04d:%.4s", cycle, (pc-code-1), &ops[i * 5]); // 印出該行執行訊息; &OP[i * 5] 為運算符號 OP="LEA ,IMM ,JMP..."
      if (i <= ADJ) printf(" %d\n", *pc); else printf("\n");
    }
    if      (i == LEA) a = (int)(bp + *pc++);                             // load local address 載入區域變數
    else if (i == IMM) a = *pc++;                                         // load global address or immediate 載入全域變數或立即值
    else if (i == JMP) pc = (int *) (pc+*pc);                             // jump               相對 PC 跳躍指令
    else if (i == JSR) { *--sp = (int)(pc + 1); pc = (int *)*pc; }        // jump to subroutine 絕對定址跳到副程式
    else if (i == BZ)  pc = a ? pc + 1 : (int *) (pc+*pc);                // branch if zero     if (a==0) 相對 PC 跳躍
    else if (i == BNZ) pc = a ? (int *)(pc+*pc) : pc + 1;                 // branch if not zero if (a!=0) 相對 PC 跳躍
    else if (i == ENT) { *--sp = (int)bp; bp = sp; sp = sp - *pc++; }     // enter subroutine   進入副程式
    else if (i == ADJ) sp = sp + *pc++;                                   // stack adjust       調整堆疊
    else if (i == LEV) { sp = bp; bp = (int *)*sp++; pc = (int *)*sp++; } // leave subroutine   離開副程式
    else if (i == LI)  a = *(int *)a;                                     // load int           載入整數
    else if (i == LC)  a = *(char *)a;                                    // load char          載入字元
    else if (i == SI)  *(int *)*sp++ = a;                                 // store int          儲存整數
    else if (i == SC)  a = *(char *)*sp++ = a;                            // store char         儲存字元
    else if (i == PSH) *--sp = a;                                         // push               推入堆疊

    else if (i == OR)  a = *sp++ |  a; // a = a OR *sp
    else if (i == XOR) a = *sp++ ^  a; // a = a XOR *sp
    else if (i == AND) a = *sp++ &  a; // ...
    else if (i == EQ)  a = *sp++ == a;
    else if (i == NE)  a = *sp++ != a;
    else if (i == LT)  a = *sp++ <  a;
    else if (i == GT)  a = *sp++ >  a;
    else if (i == LE)  a = *sp++ <= a;
    else if (i == GE)  a = *sp++ >= a;
    else if (i == SHL) a = *sp++ << a;
    else if (i == SHR) a = *sp++ >> a;
    else if (i == ADD) a = *sp++ +  a;
    else if (i == SUB) a = *sp++ -  a;
    else if (i == MUL) a = *sp++ *  a;
    else if (i == DIV) a = *sp++ /  a;
    else if (i == MOD) a = *sp++ %  a;

    else if (i == OPEN) a = open((char *)sp[2], sp[1], *sp); // 開檔
    else if (i == READ) a = read(sp[2], (char *)sp[1], *sp); // 讀檔
    else if (i == WRIT) a = write(sp[2], (char *)sp[1], *sp); // 寫檔
    else if (i == CLOS) a = close(*sp); // 關檔
    else if (i == PRTF) { t = sp + pc[1]; a = printf((char *)t[-1], t[-2], t[-3], t[-4], t[-5], t[-6]); } // printf("....", a, b, c, d, e)
    else if (i == MALC) a = (int)malloc(*sp); // 分配記憶體
    else if (i == FREE) free((void *)*sp); // 釋放記憶體
    else if (i == MSET) a = (int)memset((char *)sp[2], sp[1], *sp); // 設定記憶體
    else if (i == MCMP) a = memcmp((char *)sp[2], (char *)sp[1], *sp); // 比較記憶體
    else if (i == MCPY) a = (int)memcpy((char *)sp[2], (char *)sp[1], *sp); // 複製記憶體
    else if (i == EXIT) { printf("exit(%d) cycle = %d\n", *sp, cycle); return *sp; } // EXIT 離開
    else { printf("unknown instruction = %d! cycle = %d\n", i, cycle); return -1; } // 錯誤處理
  }
}

int vm_main(int *pc, int argc, char **argv) {
  int *bp, *sp, *t;
  // setup stack
  bp = sp = (int *)((int)stack + poolsz);
  *--sp = EXIT; // call exit if main returns
  *--sp = PSH;
  t = sp;
  *--sp = argc;
  *--sp = (int)argv;
  *--sp = (int)t;
  vm_run(pc, bp, sp);
  return 0;
}

// ------------------------ obj : 目的檔 ------------------------
enum { H, C, D, T, S, R, Sections }; // H:Header, C:Code, D:Data, R: Rel, T:St, S:Sym, HSects: Sections
enum { P, L, O, F }; // P:Pointer, L:Length, O:Offset, F: Fields
enum { Entry=0 };
enum { SName, SClass, SSize };
enum { ROffset, RType };
enum { W=4 }; // Word: W = sizeof(int)

int sym_to_obj(char *o) {
  int *id; int *objp; objp = (int*) o;
  id = sym;
  while (id[Tk]) {
    if (id[Class]==Glo || id[Class]==Fun) {
      // printf("sym:name=%s\n", (char*) id[Name]);
      objp[SName] = id[Name] - (int) st;
      objp[SClass] = id[Class];
      objp = objp + SSize;
    }
    id = id + Idsz; // 碰撞，前進到下一格。
  }
  return (char*)objp-o;
}

int obj_save() {
  int fd, codeLen, dataLen, relLen, stLen, symLen, headLen, objLen, *h, *hh, *hc, *hd, *hr, *ht, *hs; char *o;

  // printf("obj_save(): entry=%d\n", pc-code);
  h=(int*)obj; hh=h+H*F; hc=h+C*F; hd=h+D*F; hr=h+R*F; ht=h+T*F; hs=h+S*F; headLen = Sections*F*W; o=obj+headLen;
  codeLen = (int)(e-code)*W; dataLen = (int)(datap-data); relLen = (int)(relp-rel)*W; stLen = (int)(stp-st);
  // printf("obj_save(): codeLen=%d dataLen=%d relLen=%d stLen=%d symLen=%d objLen=%d\n", codeLen, dataLen, relLen, stLen, symLen, objLen);

  hh[Entry] = pc-code;
  hc[P]=(int)code; hc[L] = codeLen; hc[O] = o-obj; memcpy(o, code, codeLen); o = o + codeLen;
  hd[P]=(int)data; hd[L] = dataLen; hd[O] = o-obj; memcpy(o, data, dataLen); o = o + dataLen;
  hr[P]=(int)rel;  hr[L] = relLen;  hr[O] = o-obj; memcpy(o, rel,  relLen);  o = o + relLen;
  ht[P]=(int)st;   ht[L] = stLen;   ht[O] = o-obj; memcpy(o, st,   stLen  ); o = o + stLen;

  symLen = sym_to_obj(o);
  hs[P] =(int)o;  hs[L] = symLen;  hs[O] = o-obj; o = o + symLen;
  objLen = o-obj;
  // printf("obj_save(): codeLen=%d dataLen=%d relLen=%d stLen=%d symLen=%d objLen=%d\n", codeLen, dataLen, relLen, stLen, symLen, objLen);
  if ((fd = open(oFile, O_WRITE, 0644)) < 0) { printf("could not open(%s)\n", oFile); return -1; }
  write(fd, obj, objLen);
  close(fd);
  return 0;
}

int obj_read() {
  int fd, objLen;
  if ((fd = open(oFile, O_READ, 0644)) < 0) { printf("could not open(%s)\n", oFile); return -1; }
  objLen = read(fd, obj, poolsz); // 這裡如果用 Mingw32 的 read() 會有讀到《結束字元》就停止的問題，因此改用 c6.h 裡的 fread(..."rb") 定義。
  close(fd);
  printf("obj_read(): oFile=%s objLen=%d\n", oFile, objLen);
  return objLen;
}

int headLen, objLen, codeLen, dataLen, relLen, stLen, symLen, *h, *hh, *hc, *hd, *hr, *ht, *hs, *code0;
char *data0;

void obj_head() {
  h=(int*)obj; hh=h+H*F; hc=h+C*F; hd=h+D*F; hr=h+R*F; ht=h+T*F; hs=h+S*F; headLen = Sections*F*W;
  code0 = (int*)hc[P]; data0 = (char*)hd[P];
  codeLen = hc[L]; code = (int*)(obj+hc[O]);
  dataLen = hd[L]; data = (char*)(obj+hd[O]);
  relLen  = hr[L]; rel = (int*)(obj+hr[O]);
  stLen   = ht[L]; st   = (char*)(obj+ht[O]);
  symLen  = hs[L]; sym  = (int*)(obj+hs[O]);
  printf("obj_head(): codeLen=%d dataLen=%d relLen=%d stLen=%d symLen=%d objLen=%d\n", codeLen, dataLen, relLen, stLen, symLen, objLen);
  printf("obj_head(): hc[O]=%d hd[O]=%d hr[O]=%d ht[O]==%d hs[O]=%d\n", hc[O], hd[O], hr[O], ht[O], hs[O]);
  pc = code + hh[Entry];
  printf("obj_head:pc=%d code=%d entry=%d data=%d\n", (int)pc, (int)code, hh[Entry], (int)data);
  printf("obj_head:code0=%d data0=%d\n", (int)code0, (int)data0);
}

void obj_load() {
  int len, *cp;
  objLen = obj_read(); 
  obj_head();

  // relocate -- 重定位。
  len = relLen/W;
  relp = rel;
  // printf("obj_load():code=%d data=%d code0=%d data0=%d\n", (int)code, (int)data, (int)code0, (int)data0);
  while (relp - rel < len) {
    // printf("rel:offset=%d\n", *relp);
    cp = code + *relp++; // offset
    // printf("=>rel:old:*cp=%d\n", *cp);
    // printf("rel:type=%d\n", *relp);
    if (*relp++ == RCode) { // type
      *cp = (int) (((int*)(*cp)-code0) + code);
      // printf("RCode\n");
    } else {
      *cp = (int) (((char*)(*cp)-data0) + data);
      // printf("RData\n");
    }
    // printf("=>rel:new:*cp=%d\n", *cp);
  }
}

void obj_dump() {
  int len, *id; char *name;
  len = symLen/W;
  id = sym;
  while (id - sym < len) {
    name = (char*) (st+id[SName]);
    printf("%s %d\n", name, id[SClass]);
    id = id + SSize;
  }
}

int main(int argc, char **argv) { // 主程式
  poolsz = 256*1024;
  if (!(obj = malloc(poolsz))) { printf("could not malloc(%d) symbol area\n", poolsz); return -1; } // 目的檔。
  memset(obj,  0, poolsz);
  if (!(stack = malloc(poolsz))) { printf("could not malloc(%d) stack area\n", poolsz); return -1; }  // 堆疊段
  memset(stack,0, poolsz);

#ifdef __CC__
  --argc; ++argv;
  if (argc > 0 && **argv == '-' && (*argv)[1] == 's') { src = 1; --argc; ++argv; }
  if (argc > 0 && **argv == '-' && (*argv)[1] == 'd') { debug = 1; --argc; ++argv; }
  if (argc > 0 && **argv == '-' && (*argv)[1] == 'o') { output = 1; --argc; ++argv; oFile = *argv++; --argc; }
  if (argc < 1) { printf("usage: c6 [-s] [-d] file ...\n"); return -1; }
  cFile = *argv;

  if (!(source = malloc(poolsz))) { printf("could not malloc(%d) source area\n", poolsz); return -1; } // C 程式碼
  if (!(sym = malloc(poolsz))) { printf("could not malloc(%d) symbol area\n", poolsz); return -1; } // 符號段
  if (!(code = le = e = malloc(poolsz))) { printf("could not malloc(%d) text area\n", poolsz); return -1; } // 程式段
  if (!(data = datap = malloc(poolsz))) { printf("could not malloc(%d) data area\n", poolsz); return -1; } // 資料段
  if (!(st = stp = malloc(poolsz))) { printf("could not malloc(%d) st area\n", poolsz); return -1; } // 字串表
  if (!(rel = relp = malloc(poolsz))) { printf("could not malloc(%d) rel area\n", poolsz); return -1; } // 重定位表

  memset(code, 0, poolsz);
  memset(data, 0, poolsz);
  memset(rel,  0, poolsz);
  memset(st,   0, poolsz);
  memset(sym,  0, poolsz);

  cc_main(cFile);
  if (output) {
    obj_save();
    obj_load();
    vm_main(pc, argc, argv);
  } else {
    vm_main(pc, argc, argv);
  }
#endif

#include "vm.c"
#include "objdump.c"
}
