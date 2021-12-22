#include <stdio.h>
#include "4main.h"
#include <time.h>

int main(void)
{

  int n = readlines(strpointers, 100);
  sort(strpointers, 0, n - 1);
  writelines(strpointers, n);

  return 0;
}
