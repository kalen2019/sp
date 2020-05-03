#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdint.h>

int imTop = 0;
int16_t im[32768];
char *jTable[]    = {"","JGT","JEQ","JGE","JLT", "JNE", "JLE", "JMP"};
char *jX86[]      = {"","jg", "je", "jge","jl",  "jne", "jle", "jmp"};
char *jX86Neg[]   = {"","jle","jne","jl", "jge", "je",  "jg",  "jmp"};
char *dTable[]    = {"", "M", "D",  "MD", "A",   "AM",  "AD",  "AMD"};

int disasm(uint16_t *im, int16_t imTop, char *fileHead) {
  char sFileName[100], cFileName[100];
  sprintf(sFileName, "%s.s", fileHead);
  FILE *sFile = fopen(sFileName, "w");
  int16_t D = 0, A = 0, PC = 0;
  uint16_t I = 0;
  uint16_t a, c, d, j;
  char hCode[100], sCode[1000], cCode[1000];
  int skipCount = 0;
	fprintf(sFile, "	.text\n	.globl	_hcode\n	.def	_hcode;	.scl	2;	.type	32;	.endef\n_hcode:\n");
  for (int PC = 0; PC<imTop; PC++) {
    I = im[PC];
    if ((I & 0x8000) == 0) { // A 指令
      sprintf(hCode, "@%d", I);
      printf("%s\n", hCode);
      fprintf(sFile, "L%d: # %s\n	movl $%d, %%eax\n", PC, hCode, I);
    } else { // C 指令
      a = (I & 0x1000) >> 12;
      c = (I & 0x0FC0) >>  6;
      d = (I & 0x0038) >>  3;
      j = (I & 0x0007) >>  0;
      char op[10] = "", xop[100];
      char AM = (a == 0) ? 'A' : 'M';
      switch (c) { // 處理 c1..6, 計算 aluOut
        case 0x2A: sprintf(op, "0"); // "0",   "101010"
          sprintf(xop, "	movl $0, %%ebx"); break;
        case 0x3F: sprintf(op, "1"); // "1",   "111111"
          sprintf(xop, "	movl $1, %%ebx"); break;
        case 0x3A: sprintf(op, "-1"); // "-1",  "111010"
          sprintf(xop, "	movl $-1, %%ebx"); break;
        case 0x0C: sprintf(op, "D"); // "D",   "001100"
          sprintf(xop, "	movl %%edx, %%ebx"); break;
        case 0x30: sprintf(op, "%c", AM); // "AM",  "110000"
          if (a == 0)
            sprintf(xop, "	movl %%eax, %%ebx");
          else
            sprintf(xop, "	movl _m(%%eax,%%eax), %%ebx"); break;
        case 0x0D: sprintf(op, "!D"); // "!D",  "001101"
          sprintf(xop, "	testw	%%dx, %%dx\n	sete %%bl"); break;
        case 0x31: sprintf(op, "!%c", AM); // "!AM", "110001"
          if (a == 0)
            sprintf(xop, "	testw	%%ax, %%ax\n	sete %%bl");
          else
            sprintf(xop, "	movw _m(%%eax,%%eax), %%bx\n	%%testw	%%bx, %%bx\n	sete %%bl");
          break;
        case 0x0F: sprintf(op, "-D");
            sprintf(xop, "	movl %%edx, %%ebx\n	negl %%ebx"); break; // "-D",  "001111"
        case 0x33: sprintf(op, "-%c", AM); // "-AM", "110011"
          if (a == 0)
            sprintf(xop, "	movl %%eax, %%ebx\n	negl %%ebx");
          else
            sprintf(xop, "	movl _m(%%eax,%%eax), %%ebx\n	negl %%ebx");
          break;
        case 0x1F: sprintf(op, "D+1"); // "D+1", "011111"
          sprintf(xop, "	movl %%edx, %%ebx\n	addl $1, %%ebx");
          break;
        case 0x37: sprintf(op, "%c+1", AM); // "AM+1","110111"
          if (a == 0)
            sprintf(xop, "	movl %%eax, %%ebx\n	addl $1, %%ebx");
          else
            sprintf(xop, "	movl _m(%%eax,%%eax), %%ebx\n	addl $1, %%ebx");
          break;
        case 0x0E: sprintf(op, "D-1"); // "D-1", "001110"
          sprintf(xop, "	movl %%edx, %%ebx\n	subl $1, %%ebx");
          break;
        case 0x32: sprintf(op, "%c-1", AM); // "AM-1","110010"
          if (a == 0)
            sprintf(xop, "	movl %%eax, %%ebx\n	subl $1, %%ebx");
          else
            sprintf(xop, "	movl _m(%%eax,%%eax), %%ebx\n	subl $1, %%ebx");
          break;
        case 0x02: sprintf(op, "D+%c", AM); // "D+AM","000010"
          if (a == 0)
            sprintf(xop, "	movl %%edx, %%ebx\n	addl %%eax, %%ebx");
          else
            sprintf(xop, "	movl _m(%%eax,%%eax), %%ebx\n	addl %%edx, %%ebx");
          break;
        case 0x13: sprintf(op, "D-%c", AM); // "D-AM","010011"
          if (a == 0)
            sprintf(xop, "	movl %%edx, %%ebx\n	subl %%eax, %%ebx");
          else
            sprintf(xop, "	movl %%edx, %%ebx\n	movl _m(%%eax,%%eax), %%ecx\n	subl %%ecx, %%ebx");
          break;
        case 0x07: sprintf(op, "%c-D", AM); // "AM-D","000111"
          if (a == 0)
            sprintf(xop, "	movl %%eax, %%ebx\n	subl %%edx, %%ebx");
          else
            sprintf(xop, "	movl _m(%%eax,%%eax), %%ebx\n	subl %%edx, %%ebx");
          break;
        case 0x00: sprintf(op, "D&%c", AM); // "D&AM","000000"
          if (a == 0)
            sprintf(xop, "	movl %%edx, %%ebx\n	andl %%eax, %%ebx");
          else
            sprintf(xop, "	movl %%edx, %%ebx\n	movl _m(%%eax,%%eax), %%ecx\n	andl %%ecx, %%ebx");
          break;
        case 0x15: sprintf(op, "D|%c", AM); // "D|AM","010101"
          if (a == 0)
            sprintf(xop, "	movl %%edx, %%ebx\n	orl %%eax, %%ebx");
          else
            sprintf(xop, "	movl %%edx, %%ebx\n	movl _m(%%eax,%%eax), %%ecx\n	orl %%ecx, %%ebx");
          break;
        default: assert(0);
      }
      char head[100]="";
      if (d != 0) sprintf(head, "%s=", dTable[d]);
      if (op[0] != '\0') strcat(head, op);
      if (j != 0) 
        sprintf(hCode, "%s;%s", head, jTable[j]);
      else
        sprintf(hCode, "%s", head);

      printf("%s\n", hCode);
      fprintf(sFile, "L%d: # %s\n", PC, hCode);

      char dAsmCode[100] = "";
      if ((d & 0x01)!=0) strcat(dAsmCode, "\n	movl %ebx, _m(%eax,%eax)");
      if ((d & 0x02)!=0) strcat(dAsmCode, "\n	movl %ebx, %edx");
      if ((d & 0x04)!=0) strcat(dAsmCode, "\n	movl %ebx, %eax");

      char jAsmCode[200] = "";
      if (j != 0) {
        if (j == 7)
          sprintf(jAsmCode, "\n	movl %%eax, %%ecx\n	sall $2, %%ecx\n	addl $JumpTable, %%ecx\n	movl (%%ecx), %%ecx\n	jmp *%%ecx");
        else {
          sprintf(jAsmCode, "\n	cmpl $0, %%ebx\n	movl %%eax, %%ecx\n	sall $2, %%ecx\n	addl $JumpTable, %%ecx\n	movl (%%ecx), %%ecx\n	%s SKIP%d\n	jmp *%%ecx\nSKIP%d:", jX86[j], skipCount, skipCount);
          skipCount ++;
        }
        // printf("jAsmCode=%s\n", jAsmCode);
      }
      fprintf(sFile, "%s%s%s\n", xop, dAsmCode, jAsmCode);
    }
  }
  fprintf(sFile, "	movw	%%ax, _A\n	movw	%%dx, _D\n	ret\n.section .rdata,\"dr\"\n	.align 4\nJumpTable:\n");
  for (int PC = 0; PC<imTop; PC++) {
    fprintf(sFile, "	.long L%d\n", PC);
  }
  fprintf(sFile, "	.text\n");
  fclose(sFile);
}

// run: ./disasm <file.bin>
int main(int argc, char *argv[]) {
  char binFileName[100];
  sprintf(binFileName, "%s.bin", argv[1]);
  FILE *binFile = fopen(binFileName, "rb");
  imTop = fread(im, sizeof(uint16_t), 32768, binFile);
  fclose(binFile);
  disasm(im, imTop, argv[1]);
}
