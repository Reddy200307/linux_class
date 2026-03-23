#include<stdio.h>
#include <unistd.h>
int main(){
        if(fork()==0){
                printf("IN c pid =%d ppid =%d \n",getpid(),getppid());
                sleep(10);
                printf("IN c pid =%d ppid =%d \n",getpid(),getppid());

        }
        else{
                printf("IN P pid =%d ppid =%d \n",getpid(),getppid());
                sleep(5);
                printf("done ..");


        }
        return 0;
}