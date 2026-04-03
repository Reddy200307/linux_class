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
  printf("file size = %ld \n", v.st_size);
  printf("Inode number = %ld \n", v.st_ino);
  return 0;
}