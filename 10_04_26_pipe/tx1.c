/*
Write a c program to open the file  f1 using fifo and then print the data of the
struct into the file
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
  int fd = open("f1", O_WRONLY);
  printf("After..\n");
  struct st s;
  printf("Enter the string \n");
  scanf("%s", s.name);
  printf("Enter the character \n");
  scanf(" %c", &s.ch);
  write(fd, &s, sizeof(struct st));
}