#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define A_MEGABYTE (1024 * 1024)

int main() {
  char *mem_pointer;
  int megabyte = A_MEGABYTE;

  mem_pointer = (char *)malloc(megabyte);

  if (mem_pointer != NULL) {
    sprintf(mem_pointer, "Hello world!");
    printf("Var value: %s \n", mem_pointer);
    printf("Var address: %p \n", mem_pointer);

    char *new_mem_pointer;
    new_mem_pointer = (char *)malloc(100 * megabyte);

    if (new_mem_pointer == NULL) return EXIT_FAILURE;

    memcpy(new_mem_pointer, mem_pointer, strlen(mem_pointer) + 1);
    free(mem_pointer);

    printf("New value: %s \n", new_mem_pointer);
    printf("New address: %p \n", new_mem_pointer);

    return 0;
  }

  return EXIT_FAILURE;
}
