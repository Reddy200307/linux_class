#include<stdio.h>
#include <unistd.h>
int main(){
        if(fork()==0){
                printf("IN c pid =%d ppid =%d \n",getpid(),getppid());
                sleep(5);
                // printf("IN c pid =%d ppid =%d \n",getpid(),getppid());
                printf("child completed \n");

        }
        else{
                printf("IN P pid =%d ppid =%d \n",getpid(),getppid());
                while (1)
                {
                        /* code */
                }
                


        }
        return 0;
}