#include "../header.h"
int main() {
  time_t t1;
  t1 = time(0);
  printf(" empty time %lu \n", t1);
  printf("The returned string is %s\n", ctime(&t1));
  return 0;
}