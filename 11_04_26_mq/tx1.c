/*
Write a c program to receive the student details such as rollNo , Name and marks
and pack it in a struct to send it in a message que and receive in a rx1 program
*/
#include "../header.h"
#include <string.h>
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
  if (argc != 5) {
    printf("usage: ./tx msgtype rollNo name marks\n");
    printf("Ex:- ./tx 2 123 Hello 23 \n");
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
  strcpy(v.stud.Name, argv[3]);
  v.stud.rollNo = atoi(argv[2]);
  v.stud.mark = atoi(argv[4]);
  msgsnd(id, &v, sizeof(v), 0);
  perror("msgsnd");
  return 0;
}