#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define A_MEGABYTE (1024 * 1024)
#define A_KILOBYTE (1024)
#define PHY_MEM_MEGS (1024 * 200)

int main() {
  char *mem_pointer;
  int size_to_allocate = A_KILOBYTE;
  int megs_allocated = 0;

  while (1) {
    for (int i = 0; i < A_MEGABYTE / A_KILOBYTE; i++) {
      mem_pointer = (char *)malloc(size_to_allocate);

      if (mem_pointer == NULL)
        return EXIT_FAILURE;

      sprintf(mem_pointer, "Hello world!");
    }

    megs_allocated++;
    printf("Allocated %d", megs_allocated);
  }

  return 0;
}
