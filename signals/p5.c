/*
Take a text file and then for every one second interval it must print the
alpahbets a to z and it must terminate after z
Note:- no for loop and sleep
function
*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
char ch = 'a';
void my_isr(int);
FILE *fp;
int main() {
  fp = fopen("data.txt", "w+");
  signal(SIGALRM, my_isr);
  printf("Writing to file data.txt\n");
  alarm(1);
  while (1)
    ;

  return 0;
}
void my_isr(int n) {
  printf("called isr and writing %c \n", ch);
  fprintf(fp, " %c", ch);
  if (ch <= 'z')
    ch += 1;
  if (ch > 'z') {
    fprintf(fp, " \n");
    printf("Written to file successfully \n");
    fclose(fp);
    raise(9);
  }
  alarm(1);
}