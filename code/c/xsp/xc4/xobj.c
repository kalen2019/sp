#include "xcc.h"

int xobj_dump(Obj *obj) { // 虛擬機 => pc: 程式計數器, sp: 堆疊暫存器, bp: 框架暫存器
  printf("codeLen = %d\n", obj->codeLen);
  // int *pc = obj->code;
  int ci = 1, *pc = obj->code+1; // 第 0 個沒放指令，因為都用 *++e=....。
  while (ci < obj->codeLen) {
    int i = *pc++;
    printf("%d: %.4s", ci++, &OP[i * 5]);
    if (i <= ADJ) { printf(" %d\n", *pc++); ci++; } else printf("\n");
  }
}

int saveObj(Obj *obj) { 
  
}

int loadObj(Obj *obj) {

}
