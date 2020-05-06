#include "xcc.h"

int xobj_dump(Obj *obj) { // 虛擬機 => pc: 程式計數器, sp: 堆疊暫存器, bp: 框架暫存器
  printf("codeLen = %d obj->data=%p\n", obj->codeLen, obj->data);
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
}

int saveObj(Obj *obj) { 
  
}

int loadObj(Obj *obj) {

}
