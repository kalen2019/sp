#include <stdio.h>

extern void hcode();

unsigned short m[65536], A, D;

int main() {
  hcode();
  printf("A=%d D=%d\n", A, D);
}

