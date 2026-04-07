#include "../header.h"
#include <string.h>
int main() {
  time_t t1;
  char str[50] = {0};
  t1 = time(0);
  strcpy(str, ctime(&t1));
  int len = strlen(str);
  int i = 0, space = 0;
  printf("len =%d str=%s\n", len, str);
  while (i < len) {
    while (str[i] != 32 && str[i] != '\0') {
      printf("%c", str[i]);
      i++;
    }
    space++;
    switch (space) {
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    }
    i++;
    printf("\n");
  }
  printf("%s \n", str);
  return 0;
}