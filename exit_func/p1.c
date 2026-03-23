#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>
void abc(void){
        printf("In abc function ..\n");
}
int main(){
        printf("Hello pid =%d \n",getpid());
        atexit(abc);
        printf("hai .. \n");
        sleep(10);
        printf("Bye ... \n");

        return 1;
}