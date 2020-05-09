#include <stdio.h>

int main() {
  int *start, *end;
  int array[10] = {0,1,2,3,4,5,6,7,8,9};
  start = array; end = start + 5;
  printf("end-start=%d\n", end-start);
  printf("start-end=%d\n", start-end);
  printf("*start=%d *end=%d", *start, *end);
}
