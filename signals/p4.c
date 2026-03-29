/*
Take a number from command line and set a alarm of that number and that number
must be go on decrementing and if its 0 then it must get terminate with raise(9)
*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
static int Valarm = 0;
void my_isr(int n) {
  printf("In isr pid = %d n=%d  seconds=%d \n", getpid(), n, Valarm);
  alarm(Valarm);
  if (Valarm == 0)
    raise(9);
  else
    Valarm -= 1;
}
int main(int argc, char **argv) {
  if (argc != 2) {
    printf("usage ./a.out [seconds]");
    return 0;
  }
  printf("Hello pid =%d \n", getpid());
  signal(SIGALRM, my_isr);
  Valarm = atoi(argv[1]);
  printf("alarm return value %d \n", alarm(Valarm));
  printf("hai .. \n");
  while (1)
    ;

  return 0;
}