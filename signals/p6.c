#include "../header.h"
int main(int argc,char ** argv){
  if(argc <2){
    printf("usage ./a.out [string] \n");
    return 0;
  }
  printf("%s\n argc = %d \n",argv[1],argc);
  return 0;
}
