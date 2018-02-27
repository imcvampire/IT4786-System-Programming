#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const char *test_file = "/tmp/test_segment_lock";

#define SIZE_TO_TRY 5

void show_lock_info(struct flock *to_show)
{
  printf("\tl_type %d, ", to_show->l_type);
  printf("l_whence %d, ", to_show->l_whence);
  printf("l_start %d, ", (int)to_show->l_start);
  printf("l_len %d, ", (int)to_show->l_len);
  printf("l_pid %d\n", to_show->l_pid);
}

int main()
{
  int file_desc;
  int res;
  int start_byte;
  struct flock locking_region;

  file_desc = open(test_file, O_RDWR | O_CREAT, 0666);

  if (!file_desc) {
    fprintf(stderr, "Unable to open %s for read/write\n", test_file);
    exit(EXIT_FAILURE);
  }

  for (start_byte = 0; start_byte < 99; start_byte += SIZE_TO_TRY) {
    locking_region.l_type = F_WRLCK;
    locking_region.l_whence = SEEK_SET;
    locking_region.l_start = start_byte;
    locking_region.l_len = SIZE_TO_TRY;
    locking_region.l_pid = -1;

    printf("Testing F_WRLCK on region from %d to %d\n", start_byte,
           start_byte + SIZE_TO_TRY);

    res = fcntl(file_desc, F_GETLK, &locking_region);
    if (res == -1) {
      fprintf(stderr, "F_GETLK failed\n");
      exit(EXIT_FAILURE);
    }

    if (locking_region.l_pid != -1) {
      printf("Lock would fail. F_GETLK returned:\n");
      show_lock_info(&locking_region);
    } else {
      printf("F_WRLCK - Lock would succeed\n");
    }

    locking_region.l_type = F_RDLCK;
    locking_region.l_whence = SEEK_SET;
    locking_region.l_start = start_byte;
    locking_region.l_len = SIZE_TO_TRY;
    locking_region.l_pid = -1;
    printf("Testing F_RDLCK on region from %d to %d\n", start_byte,
           start_byte + SIZE_TO_TRY);

    res = fcntl(file_desc, F_GETLK, &locking_region);

    if (res == -1) {
      fprintf(stderr, "F_GETLK failed\n");
      exit(EXIT_FAILURE);
    }

    if (locking_region.l_pid != -1) {
      printf("Lock would fail. F_GETLK returned:\n");
      show_lock_info(&locking_region);
    } else {
      printf("F_RDLCK - Lock would succeed\n");
    }
  }

  close(file_desc);
  return 0;
}
