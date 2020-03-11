#include <stdio.h>
void F();

void E() {
  printf("E started\n");
  // E();
  F();
  printf("E finished\n");
}

void F() {
  printf("F started\n");
  printf("F finished\n");
}

int main() {
  E();
}
