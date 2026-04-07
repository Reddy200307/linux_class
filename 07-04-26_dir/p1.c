/*
Custom ls command
*/
#include "../header.h"
#include <dirent.h>

int main(int argc, char **argv) {
  DIR *dp;
  if (argc != 2) {
    printf("Usage :./a.out dirname \n");
    return 0;
  }
  dp = opendir(argv[1]);
  if (dp == 0) {
    perror("opendir");
    return 0;
  }
  struct dirent *p;
  while ((p = readdir(dp))) {
    if (p->d_name[0] != '.')
      printf("%s \n", p->d_name);
  }
  return 0;
}