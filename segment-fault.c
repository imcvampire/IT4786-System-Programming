#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define A_KILOBYTE (1024)

int main() {
  char *mem_pointer;
  char *scan_pointer;
  int kilobyte = A_KILOBYTE;

  mem_pointer = (char *)malloc(kilobyte);
  if (mem_pointer == NULL) return EXIT_FAILURE;

  scan_pointer = mem_pointer;
  while (1) {
    printf("Address: %p\n", scan_pointer);
    *scan_pointer = 'a';
    scan_pointer += 1;
  }

  return 0;
}
