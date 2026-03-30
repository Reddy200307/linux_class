/*
Take a text file and then for every one second interval it must print the
alpahbets a to z and it must terminate after z
Note:- no for loop and sleep
function
*/
#include "../header.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
char ch = 'a';
void my_isr(int);
void child_isr(int n);

FILE *fp;
int r = 0;
int main() {
  if ((r = fork())) {
    fp = fopen("data.txt", "w+");
    printf("Writing to file data.txt\n");
    while (1) {
      printf("called isr and writing %c \n", ch);
      fprintf(fp, " %c", ch);
      if (ch <= 'z')
        ch += 1;
      if (ch > 'z') {
        fprintf(fp, " \n");
        printf("Written to file successfully \n");
        fclose(fp);
        kill(r, 10);
        break;
      }
      sleep(1);
    }
    wait(&r);
    raise(9);
  } else {
    signal(10, child_isr);
    //       signal(SIGALRM, child_isr);
    pause();
    ch = 'A';
    fp = fopen("data.txt", "a+");
    printf("Writing to file data.txt\n");
    while (1) {
      printf("called isr and writing %c \n", ch);
      fprintf(fp, " %c", ch);
      if (ch <= 'Z')
        ch += 1;
      if (ch > 'Z') {
        fprintf(fp, " \n");
        printf("Written to file successfully \n");
        fclose(fp);
        kill(r, 9);
        break;
      }
      sleep(1);
    }
    printf("called child isr and writing %c \n", ch);
  }

  return 0;
}
void child_isr(int n) { printf("Writing to file data.txt from child\n"); }