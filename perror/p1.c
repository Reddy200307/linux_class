#include <asm-generic/errno-base.h>
#include <errno.h>
#include<stdio.h>
int main(){
        FILE * fp=fopen("data","r");
        errno=E2BIG;
        if(fp==NULL){
                perror("FILE");
                return 0;
        }
        printf("File is present \n");
        printf("%d %d %d",EACCES,ENOENT,E2BIG);
        return 0;
}