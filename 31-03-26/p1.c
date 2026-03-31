/*
 *create a struct and then declare a integer pointer and
 then create a function pointer to printf
 then allocate the memory and then print the integer
 and then call the printf from the structure containing printf
 pointer
 *
* */
#include"../header.h"
#include<stdlib.h>
struct dummy{
  int *p;
  int (*print)(const char *,...);
  int (*scan)(const char *,...);
};
int main(){
  struct dummy * str=(struct dummy *)malloc(sizeof(struct dummy));
  str->p=(int *)malloc(sizeof(int));
  printf("enter the integer \n");
  str->scan=scanf;
  (*str->scan)("%d",str->p);
  str->print=printf;
  (*str->print)("hello\n");
  (*str->print)("The integer is %d \n",*(str->p));
  free(str->p);
  str->p=0;
  return 0;
}
