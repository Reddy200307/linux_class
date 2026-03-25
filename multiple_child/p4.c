#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include <bits/waitflags.h>

int main(){
  if((fork())==0){//y+1
        printf("In c pid = %d \n",getpid());
        while (1);        
  }
  else{
    //y
    int r,s;
    printf("In p pid = %d \n",getpid());
    printf("In pid before wait ..\n");
    waitpid(-1,0,WCONTINUED);
    printf("In parent after wait pid:- %d \n",getpid());
    }

  return 1;
}
