#include "../header.h"
int main() {
  int r = mkfifo("f1", 0664);
  perror("mkfifo");
  printf("r=%d \n", r);

  printf("Before..\n");
  int fd = open("f1", O_RDONLY);
  printf("After..\n");

  char s[20];
  read(fd, s, sizeof(s));
  printf("Data=%s\n", s);
}