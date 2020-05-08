#include "xcc.h"

char *types[] = {"char", "int", "ptr", "char*", "int*", "ptr*" };

void xobj_dump(Obj *obj) { // 虛擬機 => pc: 程式計數器, sp: 堆疊暫存器, bp: 框架暫存器
  // printf("codeLen = %d obj->data=%p\n", obj->codeLen, obj->data);
  // int *pc = obj->code;
  int *pc = obj->code; // 第 0 個沒放指令，因為都用 *++e=....。
  while (1) {
    int ci = pc - obj->code;
    int i = *pc++;
    if (ci >= obj->codeLen) break;
    printf("%d: %.4s", ci, &OP[i * 5]);
    if (i == IMM) {
      char *immp = (char*) *pc;
      if (immp >= obj->data && immp < obj->data + poolsz) { // 立即值，資料段中的指標。
        // 改為目的檔中資料段的位置存檔。
      } else if (i >= JMP && i<= BNZ) { // JMP ,JSR ,BZ  ,BNZ
        // 改為目的檔中程式段的位置存檔。
      } 
    }
    if (i <= ADJ) printf(" %d\n", *pc++); else printf("\n");
  }
  // 接著對 symTable 存檔。(包含存字串表)。
  ID *id = sym;
  while (id->tk) { // 檢查該符號是否已經存在 ? (循序搜尋?)
    if (id->class != Loc && id->class != 0) // 單純區域變數 (沒有同名的全域)，不須存放在符號表內了！ (注意，其 type, class 已經被還原了，所以 type 不正確。)
      printf("name=%.10s type=%s htype=%s val=%d\n", id->name, types[id->type], types[id->htype], id->val);
    id++;
  }
}

/*

int saveObj(Obj *obj) { 
  
}

int loadObj(Obj *obj) {

}
*/
