#include <stdio.h>
/*преобразует целое число в строку цифр*/
#define LINESIZE 1000

void itoa(int n, char s[])
{
  static int i = 0;

  if (n < 0){
    s[i++] = '-';
    n = -n;
  }

  if (n/10 > 0)
    itoa(n/10, s);

  s[i++] = n%10 + '0';
  s[i] = '\0';
}
void main()
{
  char s[LINESIZE];

  itoa(123456, s);
  printf("%s\n", s);

  itoa(-123456, s);
  printf("%s\n", s);
}
