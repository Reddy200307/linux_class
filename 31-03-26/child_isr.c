#include"../header.h"
void my_isr(int n);
int main(){
  printf("In main pid = %d \n",getpid());
  signal(2,my_isr);
  printf("hai ...\n");
  while(1);

return 0;
}
void my_isr(int n){
  printf("in isr n=%d pid = %d \n",n,getpid());
  sleep(20);
  printf("In isr after sleep \n");

}
