#include<stdio.h>
#include<sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
        if(fork()==0){
                printf("In c pid = %d ppid =%d \n",getpid(),getppid());
                sleep(20);
                printf("In c after sleep pid =%d ppid=%d \n",getpid(),getppid());
                exit(1);
        }
        else{
                int r,s;
                printf("In p pid = %d \n",getpid());
                printf("In P before wait .. \n");
                r= wait(&s);
                if(WIFEXITED(s)){
                        printf("Child is terminated normally %d \n",WEXITSTATUS(s));
                }
                else if(WIFSIGNALED(s)){
                        printf("Child is terminated abnormally %d \n",WTERMSIG(s));

                }
                printf("In P after wait r=%d s=%d \n",r,s);
                while(1);
        }
        return 0;
}