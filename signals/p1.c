#include<stdio.h>
#include <unistd.h>
#include<signal.h>
void my_isr(int n){
        static int count=0;
        printf("In isr pid =%d n=%d count= %d \n",getpid(),n,count);
        if(count==3)
                signal(n,SIG_DFL);
        count++;
}
int main(){
        printf("Hello pid =%d \n",getpid());
        signal(2,my_isr);
        signal(3,my_isr);// we can use multiple signals
        printf("hai .. \n");
        while(1);

        return 0;
}