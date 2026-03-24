#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
  int r;
  int delay;
  if((fork())==0){//y+1
    srand(getpid());
    delay=rand()%10+1;
    getpid();
    printf("this is child %d of delay %d  \n",getpid(),delay);
    sleep(delay);
    exit(1);
  }
  else{
    //y
    r=wait(0);
    printf("%d is terminated \n",r);
    if((fork())==0){
      //y+2
      srand(getpid());
      delay=rand()%10+1;
      printf("this is child %d of delay %d \n",getpid(),delay);
      sleep(delay);
      exit(1);
    }
    else{
      r=wait(0);
      printf("%d is terminated \n",r);
      //y
      if((fork())==0){
        //y+3
        srand(getpid());
        delay=rand()%10+1;
        printf("this is child %d of delay %d \n",getpid(),delay);
        sleep(delay);
        exit(1);
      }
      else{
        //y
        r=wait(0);
        printf("%d is terminated \n",r);

      }
    }
  }

  return 1;
}
