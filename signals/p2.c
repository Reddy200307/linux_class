/*
Ctrl + c = 3 times next go to default
ctril + \ = 4 times next go to default
*/
#include<stdio.h>
#include <unistd.h>
#include<signal.h>
void my_isr(int n){
        static int countC=1,count_Slash=1;
        printf("In isr pid =%d n=%d countC= %d  count_Slash=  %d\n",getpid(),n,countC,count_Slash);
        if(countC==3 && n==2)
                signal(n,SIG_DFL);
        if(count_Slash==4 && n==3)
                signal(n,SIG_DFL);
        if(n==2)
                countC+=1;
        if(n==3)
                count_Slash+=1;
}
int main(){
        printf("Hello pid =%d \n",getpid());
        signal(2,my_isr);
        signal(3,my_isr);// we can use multiple signals
        printf("hai .. \n");
        while(1);

        return 0;
}