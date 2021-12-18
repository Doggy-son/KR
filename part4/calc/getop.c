#include <ctype.h>
#include <stdio.h>
#include "common.h"
/*записывает число с плавающей точкой и операнды в строку*/

static int getop(char s[])
{
  int c;
  int i = 0;

  c = getch();

  if (c == EOF)
    return c;

  if (c=='+'|| c=='*' || c=='/' || c=='%'){
    s[i++] = c;
    s[i] = '\0';
    return c;
  }
/*обработка числа*/
  if (c=='-'){
    s[i++] = c;
    c = getch();
  }
  while (isdigit(c)){
    s[i++] = c;
    c = getch();
  }
  if (c == '.'){
    s[i++] = '.';
    c = getch();
  }
  while (isdigit(c)){
    s[i++] = c;
    c = getch();
  }
  if (i > 0){
    s[i] = '\0';

    if (s[i-1] == '-')
      return '-';
    return NUMBER;
  }
  /*обработка библиотечных функций sin, exp, pow*/
  while (isalpha(c) && i<3)
  {
    s[i++] = c;
    c = getch();
  }
  if (i > 0 && compare(s, "pow", 3)){
    s[i] = '\0';
    return MATH_POW;
  }
  if (i>0 &&  compare(s, "sin", 3)){
    s[i] = '\0';
    return MATH_SIN;
  }
  if (i>0 && compare(s, "exp", 3)){
    s[i] = '\0';
    return MATH_EXP;
  }
}
