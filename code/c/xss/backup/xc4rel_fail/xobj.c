#include "xcc.h"

char *types[] = {"char", "int", "ptr", "char*", "int*", "ptr*" };
char *classes[] = {"Num"/*=128*/, "Fun", "Sys", "Glo", "Loc", "Id", 
  "Char", "Else", "Enum", "If", "Int", "Return", "Sizeof", "While",
  "Assign", "Cond", "Lor", "Lan", "Or", "Xor", "And", "Eq", "Ne", "Lt", "Gt", "Le", "Ge", 
  "Shl", "Shr", "Add", "Sub", "Mul", "Div", "Mod", "Inc", "Dec", "Brak"};
char *sections[] = {"Code", "Data"};
char *rtypes[] = { "RNone", "RData", "RCode" };

void xobj_dump(Obj *obj) {
  printf("code=%p=%d codeLen=%d data=%p=%d\n", obj->code, obj->code, obj->codeLen, obj->data, obj->data);
  int *pc = obj->code;
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
      printf("name=%.10s type=%s class=%s val=%d\n", id->name, types[id->type], classes[id->class-Num], id->val);
    id++;
  }
  Rel *relp = obj->rel;
  while (relp->rtype) {
    printf("offset=%d rtype=%s name=%.10s\n", relp->offset, rtypes[relp->rtype], relp->name);
    relp++;
  }
}

/*

int saveObj(Obj *obj) { 
  
}

int loadObj(Obj *obj) {

}
*/
