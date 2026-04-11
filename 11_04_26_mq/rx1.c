#include "../header.h"
#include <sys/ipc.h>
struct student {
  int rollNo;
  char Name[20];
  int mark;
};
struct msgbuf {
  long int mtype;
  struct student stud;
};
int main(int argc, char **argv) {
  if (argc != 2) {
    printf("usage: ./tx msgtype \n");
    printf("Ex:- ./tx 2  \n");
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
  printf("After Data\n");
  printf("Name:- %s\n", v.stud.Name);
  printf("RollNo:- %d\n", v.stud.rollNo);
  printf("Marks:- %d\n", v.stud.mark);
  return 0;
}