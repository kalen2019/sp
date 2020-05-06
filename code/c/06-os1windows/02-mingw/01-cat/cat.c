#include <stdio.h>
#include <fcntl.h>

#define TEXT_SIZE 1000000

char text[TEXT_SIZE];

int main(int argc, char *argv[]) {
  char *fileName = argv[1];
  int fd = open(fileName, O_RDONLY);
  int len = read(fd, text, TEXT_SIZE-1);
  text[len] = 0;
  printf("%s\n", text);
}
