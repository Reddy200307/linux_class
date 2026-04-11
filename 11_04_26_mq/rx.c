#include "../header.h"
#include <string.h>
#include <sys/ipc.h>
struct msgbuf {
  long int mtype;
  char s[20];
};
int main(int argc, char **argv) {
  if (argc != 2) {
    printf("usage: ./rx msgtype \n");
    printf("Ex:- ./rx 2  \n");
    return 0;
  }
  int id = msgget(2, IPC_CREAT | 0664);
  if (id < 0) {
    perror("msgget");
    return 0;
  }
  printf("id= %d\n", id);

  struct msgbuf v;
  msgrcv(id, &v, sizeof(v), atoi(argv[1]), 0);
  perror("msgrcv");
  printf("After Data=%s \n", v.s);
  return 0;
}