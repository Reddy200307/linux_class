/*
Write a c program to open the file  f1 using fifo and then read the struct in it
and then print the data of the struct into the file
*/
#include "../header.h"
struct st {
  char name[20];
  char ch;
};
int main() {
  int r = mkfifo("f1", 0664);
  perror("mkfifo");
  printf("r=%d \n", r);

  printf("Before..\n");
  int fd = open("f1", O_RDONLY);
  printf("After..\n");

  struct st s;
  read(fd, &s, sizeof(s));
  printf("Name=%s character=%c \n", s.name, s.ch);
}