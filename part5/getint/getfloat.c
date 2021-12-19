#include <stdio.h>
#include <ctype.h>
#include "getch.h"
/*аналог getint  для чисел с плавающей точкой*/
int getfloat(float *x)
{
   int c, sign;
   float pow ;

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

  for (*x=0.0; isdigit(c); c=getch())
    *x = (10.0* *x) + (float)(c - '0');

  if (c=='.')
    c = getch();

  for (pow = 1.0; isdigit(c); c=getch()){
      *x = 10.0* *x + (c - '0');
      pow = 10.0 * pow;
}

  *x = sign * *x/pow;

  if (c!=EOF)
    ungetch(c);

  return c;
}
void main()
{
  int r, c;
  float x;

  while ((r=getfloat(&x))!= EOF){
   if (r){
      printf("получено число %f\n", x);
      continue;
    }
    else {
      c = getch();
      continue;
    }
  }
}
