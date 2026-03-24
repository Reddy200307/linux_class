#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
  int r;
  int id[3]={0};
  int delay;
  if(fork()==0){//y+1
    srand(getpid());
    delay=rand()%10+1;
    printf("this is child %d of delay %d \n",getpid(),delay);
    sleep(delay);
    exit(1);
  }
  else{
    //y
    if(fork()==0){
      //y+2
      srand(getpid());
      delay=rand()%10+1;
      printf("this is child %d of delay %d \n",getpid(),delay);
      sleep(delay);
      exit(1);
    }
    else{
      //y
      if(fork()==0){
        //y+3
        srand(getpid());
        delay=rand()%10+1;
        printf("this is child %d of delay %d \n",getpid(),delay);
        sleep(delay);
        exit(1);
      }
      else{
        //y
      }
    }
  }
  while((r=wait(0))!=-1){
    printf("%d is terminated \n",r);
  }
  return 1;
}
