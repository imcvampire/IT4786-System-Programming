#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  char *mem_pointer;
  mem_pointer = (char *)malloc(1);
  if (mem_pointer != NULL) {
    printf("Pointer address: %p \n", mem_pointer);
    free(mem_pointer);
    printf("Memory is allocated and freed");
    return 0;
  }
  return EXIT_FAILURE;
}
