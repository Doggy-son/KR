#include <stdio.h>
#include <ctype.h>
#include "getch.h"

#define DEBUG 1
/*читает целые числа из ввода, возвращает статус
0 - символы не представляют число, c - записано число либо EOF*/

int getint(int *ip)
{
  int c, sign;
  *ip = 0;

  while (isspace(c=getch()))
    ;

/*  if(!isdigit(c) && c!=EOF && c!='+' && c!='-'){
    ungetch(c);
    return 0;
  }*/

  sign = (c=='-') ? -1 : 1;

  if (c=='-' || c=='+')
    c = getch();

  if (!isdigit(c) && c!=EOF){
    ungetch(c);
    return 0;
  }

  for (*ip=0; isdigit(c); c=getch())
    *ip = 10* *ip + (c - '0');

  *ip *= sign;

  if (c!=EOF)
    ungetch(c);

  return c;
}
/*void main()
{
  int x, r, c;

  while ((r=getint(&x))!= EOF){
   if (r){
      printf("получено число %d\n", x);
      continue;
    }
    else {
      c = getch();
      continue;
    }
  }
}*/
