#include <stdio.h>
/*печатает n как целое десятичное число*/

void printd(int n)
{
  if (n<0){
    putchar('-');
    n = -n;
  }

  if (n/10>0)
    printd(n/10);

  putchar(n%10 + '0');
}
// test
void main()
{
  printd(-18273);
}
