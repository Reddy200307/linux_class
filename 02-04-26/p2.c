/*
 *
 * write a c program to set a limit to the program so that 
 * the maximim cpy  time is 5 sec for a program 
 *
* */
#include"../header.h"
void my_isr(int n){
  printf("In Isr %d %s \n",n,strsignal(n));
}
int main(){
  struct sigaction s;
  s.sa_handler=my_isr;
  sigemptyset(&s.sa_mask);
  s.sa_flags=SA_RESETHAND;
  sigaction(SIGXCPU,&s,0);
  struct rlimit v;
  getrlimit(RLIMIT_CPU,&v);
  v.rlim_cur=5;
  setrlimit(RLIMIT_CPU,&v);
  while(1);
  return 0;
}
