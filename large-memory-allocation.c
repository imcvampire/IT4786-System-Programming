#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define A_MEGABYTE (1024*1024)
#define PHY_MEM_MEGS (1024*200)

int main()
{
  char* mem_pointer;
  size_t size_to_allocate = A_MEGABYTE;
  int megs_allocated = 0;

  while (megs_allocated < PHY_MEM_MEGS) {
    mem_pointer = (char*)malloc(size_to_allocate);

    if (mem_pointer != NULL) {
      megs_allocated++;
      sprintf(mem_pointer, "Hello world %d!", megs_allocated);
      printf("%s - now allocated %d Megs. Newest pointer address: %p \n", mem_pointer, megs_allocated, mem_pointer);
    } else {
      return EXIT_FAILURE;
    }
  }

  return 0;
}
