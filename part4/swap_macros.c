#include <stdio.h>

#define swap(t,x,y) {t temp; temp = x; x = y; y = temp;}
#define dprint(a) printf(#a" = %d\n", a);

void main(void)
{
  int x = 2, y = 3;

  swap (int, x, y);

  dprint(x);
  dprint(y);
}
