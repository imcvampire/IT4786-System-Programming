#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

const char* lock_file = "/tmp/demo-lock-file";

int main() {
  int file_desc;

  while (1) {
    file_desc = open(lock_file, O_RDWR | O_CREAT | O_EXCL, 0444);

    if (file_desc == -1) {
      printf("%d - Lock already present\n", getpid());
      sleep(1);
    } else {
      printf("%d - I have exclusive access\n", getpid());
      sleep(2);

      (void)close(file_desc);
      (void)unlink(lock_file);
      printf("%d - I have removed the lock file\n", getpid());
      sleep(2);
    }
  }
}
