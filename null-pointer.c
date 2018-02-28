#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  char *mem_pointer = (char *)0;

  printf("A read from null %s", mem_pointer);
  sprintf(mem_pointer, "A write to NULL pointer");

  return 0;
}
