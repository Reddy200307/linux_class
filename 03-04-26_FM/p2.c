#include "../header.h"
int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: ./a.out fname \n ");
    return 0;
  }
  struct stat v;
  if (stat(argv[1], &v) < 0) {
    perror("stat");
    return 0;
  }
  printf("file mode = %o \n", v.st_mode);
  printf("file mode = %o \n", (v.st_mode & 0x777));
  if (S_ISREG(v.st_mode))
    printf("regular file \n");
  else if (S_ISDIR(v.st_mode))
    printf("Dir File ..\n");
  return 0;
}