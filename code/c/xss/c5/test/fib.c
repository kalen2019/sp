#include <stdio.h>

int f(n) {
  if (n<=0) return 0;
  if (n==1) return 1;
  return f(n-1) + f(n-2);
}

int main() {
  printf("f(7)=%d\n", f(7));
  return 0;
}