#include<stdio.h>
#include <unistd.h>
int main(){
        printf("one \n");
        fork();
        printf("two \n");
        fork();
        printf("three \n");
        fork();
        printf("four \n");
        while(1);
        return 0;
}