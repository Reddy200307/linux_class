/*
Alarm system call  function
*/
#include<stdio.h>
#include <unistd.h>
#include<signal.h>
void my_isr(int n){
        printf("In isr pid = %d n=%d \n",getpid(),n);
        alarm(10);
}
int main(){
        printf("Hello pid =%d \n",getpid());
        signal(SIGALRM,my_isr);
        printf("alarm return value %d \n",alarm(2));
        // alarm(2);//alarm will now do for 2 seconds because only 1 timer
        printf("hai .. \n");
        while(1);

        return 0;
}