#ifndef __XCC_H__
#define __XCC_H__

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <unistd.h>
#include <fcntl.h>

// opcodes (機器碼的 op)
enum { LEA ,IMM ,JMP ,JSR ,BZ  ,BNZ ,ENT ,ADJ ,LEV ,LI  ,LC  ,SI  ,SC  ,PSH ,
       OR  ,XOR ,AND ,EQ  ,NE  ,LT  ,GT  ,LE  ,GE  ,SHL ,SHR ,ADD ,SUB ,MUL ,DIV ,MOD ,
       OPEN,READ,CLOS,PRTF,MALC,FREE,MSET,MCMP,EXIT };

#define OP "LEA ,IMM ,JMP ,JSR ,BZ  ,BNZ ,ENT ,ADJ ,LEV ,LI  ,LC  ,SI  ,SC  ,PSH ,"\
           "OR  ,XOR ,AND ,EQ  ,NE  ,LT  ,GT  ,LE  ,GE  ,SHL ,SHR ,ADD ,SUB ,MUL ,DIV ,MOD ,"\
           "OPEN,READ,CLOS,PRTF,MALC,FREE,MSET,MCMP,EXIT,"

int xvm_main(int *pc, int argc, char *argv[]);
extern int debug;
extern char *data;   // data/bss pointer (資料段機器碼指標)
extern int *code;    // ccc: add *code (程式段)
extern int *sym;     // symbol table (simple list of identifiers) (符號表)
#define poolsz 256*1024

#endif