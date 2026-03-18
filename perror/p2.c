#include <asm-generic/errno-base.h>
#include <errno.h>
#include<stdio.h>
int main(){
        errno=E2BIG;
        perror("\n");
        errno=EACCES;
        perror("\n");
        errno=EAGAIN;
        perror("\n");
        errno=EADDRINUSE;
        perror("\n");
        return 0;
}