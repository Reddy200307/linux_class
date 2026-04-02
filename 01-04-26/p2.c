/*
 *write a c program to display a isr only when the child is terminated otherwise the 17 sigchild will send signal to parent when the child is terminated or suspneded or resumed
 *
* */
#include"../header.h"
#include<stdlib.h>
void my_isr(int n);
int main(){
  /*if(fork()==0){
    printf("In child pid = %d \n",getpid());
    while(1);
  }*/
  //else{
    printf("In main pid = %d \n",getpid());
    struct sigaction *v=(struct sigaction *)malloc(sizeof(struct sigaction));
    v->sa_handler=my_isr;
    sigemptyset(&v->sa_mask);
    v->sa_flags=SA_NOCLDSTOP | SA_NOCLDWAIT;
    sigaction(2,v,0);
    printf("hai ...\n");
    while(1);
  //}

  return 0;
}
void my_isr(int n){
  printf("in isr n=%d pid = %d \n",n,getpid());
  sleep(10);
  printf("after sleep \n");


}
