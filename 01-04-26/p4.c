/*
 * in this program the signal will go to the isr only onece and then if its in isr another time then it break because
 * the SA_RESETHAND flag says that only once execute the isr then next time do default task of the signal 2
 *
* */
#include"../header.h"
#include<stdlib.h>
void my_isr(int n);
int main(){
    printf("In main pid = %d \n",getpid());
    struct sigaction *v=(struct sigaction *)malloc(sizeof(struct sigaction));
    v->sa_handler=my_isr;
    sigemptyset(&v->sa_mask);
    v->sa_flags=SA_RESETHAND;
    sigaction(2,v,0);
    printf("hai ...\n");
    while(1);
  return 0;
}
void my_isr(int n){
  printf("in isr n=%d pid = %d \n",n,getpid());


}
