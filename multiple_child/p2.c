#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
  int r;
  int id[3]={0};
  int delay;
  if((id[0]=fork())==0){//y+1
    srand(getpid());
    delay=rand()%10+1;
    getpid();
    printf("this is child %d of delay %d  \n",getpid(),delay);
    sleep(delay);
    exit(1);
  }
  else{
    //y
    if((id[1]=fork())==0){
      //y+2
      srand(getpid());
      delay=rand()%10+1;
      id[1]=getpid();
      printf("this is child %d of delay %d \n",getpid(),delay);
      sleep(delay);
      exit(1);
    }
    else{
      //y
      if((id[2]=fork())==0){
        //y+3
        srand(getpid());
        delay=rand()%10+1;
        id[2]=getpid();
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
        if(id[0]==r){
                printf("child 1 is terminated \n");
        }
        else if(id[1]==r){
                printf("child 2 is terminated \n");
        }
        else if(id[2]==r){
                printf("child 3 is terminated \n");
        }
  }
  return 1;
}
