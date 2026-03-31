#include"../header.h"
#include<stdlib.h>
void my_isr(int n);
int main(){
  printf("In main pid = %d \n",getpid());
//  signal(2,my_isr);
  struct sigaction *v=(struct sigaction *)malloc(sizeof(struct sigaction));
  v->sa_handler=my_isr;
  sigemptyset(&v->sa_mask);
  v->sa_flags=0;
  sigaction(2,v,0);
  printf("hai ...\n");
  while(1);

return 0;
}
void my_isr(int n){
  printf("in isr n=%d pid = %d \n",n,getpid());
  sleep(10);
  printf("this is after sleep\n");

}
