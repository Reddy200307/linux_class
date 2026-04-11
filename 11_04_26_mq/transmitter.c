#include "../header.h"
#include <string.h>
#include <sys/ipc.h>
struct msgbuf {
  long int mtype;
  char s[20];
};
int main(int argc, char **argv) {
  if (argc != 3) {
    printf("usage: ./tx msgtype msg\n");
    printf("Ex:- ./tx 2 hello \n");
    return 0;
  }
  int id = msgget(2, IPC_CREAT | 0664);
  if (id < 0) {
    perror("msgget");
    return 0;
  }
  printf("id= %d\n", id);

  struct msgbuf v;
  v.mtype = atoi(argv[1]);
  strcpy(v.s, argv[2]);
  msgsnd(id, &v, strlen(v.s) + 1, 0);
  perror("msgsnd");
  return 0;
}