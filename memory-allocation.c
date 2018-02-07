#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define A_MEGABYTE (1024*1024)

int main() {
  char* mem_pointer;
  int megabyte = A_MEGABYTE;

  mem_pointer = (char*) malloc(megabyte);

  if (mem_pointer != NULL) {
    sprintf(mem_pointer, "Hello world!");
    printf("%s \n", mem_pointer);
    printf("%p \n", mem_pointer);

    return 0;
  }

  return EXIT_FAILURE;
}
