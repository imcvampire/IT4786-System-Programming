#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define A_MEGABYTE (1024 * 1024)

int main() {

  char *mem_pointer;
  int megabyte = A_MEGABYTE;

  mem_pointer = (char *)malloc(megabyte);

  if (mem_pointer != NULL) {
    sprintf(mem_pointer, "Hello world!");
    printf("Var value: %s \n", mem_pointer);
    printf("Var address: %p \n", mem_pointer);

    mem_pointer = realloc(mem_pointer, 10000 * megabyte);
    printf("Var value: %s \n", mem_pointer);
    printf("Var address: %p \n", mem_pointer);

    return 0;
  }

  return EXIT_FAILURE;
}
