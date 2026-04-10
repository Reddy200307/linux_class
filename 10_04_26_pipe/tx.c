#include "../header.h"
int main() {
  int r = mkfifo("f1", 0664);
  perror("mkfifo");
  printf("r=%d \n", r);
  printf("Before..\n");
  int fd = open("f1", O_WRONLY);
  printf("After..\n");
  char s[20];
  printf("Enter the string \n");
  scanf("%s", s);
  write(fd, s, strlen(s) + 1);
}