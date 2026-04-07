#include "../header.h"
int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: link_type file1 file2 \n");
    return 1;
  }
  struct stat v, v1;
  if (stat(argv[1], &v) < 0) {
    perror("First file ");
    return 1;
  }
  if (stat(argv[2], &v1) < 0) {
    perror("Second File");
    return -1;
  }
  if (v.st_ino == v1.st_ino) {
    lstat(argv[1], &v);
    lstat(argv[2], &v1);
    if (v.st_ino == v1.st_ino)
      printf("Hard Link...\n");
    else
      printf("Soft Link...\n");
  } else {
    printf("No Link...\n");
  }

  return 0;
}