/*
 * in this we use sigfillset because it blocks the other signals during the execution of the isr but sigempty set allows all other signals except the specific signal
* */
#include"../header.h"
#include<stdlib.h>
void my_isr(int n);
int main(){
    printf("In main pid = %d \n",getpid());
    struct sigaction *v=(struct sigaction *)malloc(sizeof(struct sigaction));
    v->sa_handler=my_isr;
    sigfillset(&v->sa_mask); // block all other signals 
    //sigemptyset(&v->sa_mask); // allow all other signals 
    v->sa_flags=SA_RESETHAND;
    sigaction(2,v,0);
    printf("hai ...\n");
    while(1);
  return 0;
}
void my_isr(int n){
  printf("in isr n=%d pid = %d \n",n,getpid());
  sleep(20);
  printf("after sleep \n");

}
