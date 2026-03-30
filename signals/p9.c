#include "../header.h"
int main() {
  signal(1, SIG_IGN);
  while (1)
    ;
  return 0;
}