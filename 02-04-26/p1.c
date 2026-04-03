#include "../header.h"

void my_isr(int n){
  printf("In Isr %s \n",strsignal(n));
}
int main(){
  FILE *fp;
  struct rlimit v;
  signal(SIGXFSZ  ,my_isr);
  getrlimit(RLIMIT,my_isr);
  printf("File size :soft limit =%u , hard_limit=%u\n",(int)v.rlim_cur,(int)v,rlim_max);
  v.rlim_cur=5;
  setrlimit(RLIMIT_FSIZE,&v);
  getrlimit(RLIMIT_FSIZE,&v);
  printf("File size :soft limit =%u , hard_limit=%u\n",(int)v.rlim_cur,(int)v,rlim_max);
  fp=fopen("DATA","w");
  fwrite("abcdefghdjfhsfh",12,1,fp);
  return 0;
}
