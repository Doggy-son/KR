#include <stdio.h>

void putint(int x)
{
  int l = 0, i;
  static int a[10];

  if(l<9)
    a[l++] = x;

  for (i=0; i<l; i++)
    printf("%d = %d\n", i, a[i] );
}
void main()
{
  putint(1);
  putint(12);
  putint(-8);
}
