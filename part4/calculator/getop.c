#include "common.h"
#include <ctype.h>
#include <stdio.h>

int getop(char s[])
{
  int l, i;
  char stmp[LINESIZE];

  l = getln(s);
  strtrm(s);

  if (l==EOF){
    s[0] = '\0';
    return EOF;
  }

/*простые операторы и переменные*/
  if (l==1){
    if (s[0] == '+')
      return OPPLUS;
    if (s[0] == '-')
      return OPMINUS;
    if (s[0] == '*')
      return OPMULT;
    if (s[0] == '/')
      return OPDIV;
    if (s[0] == '%')
      return OPMOD;
    if (islower(s[0]))
      return VARIABLE;
    if (s[0] == '=')
      return RESULT;
  }
/*библиотечные функции*/
  if (l==3){
    if (strcm(s, "sin", l))
      return MATHSIN;
    if (strcm(s, "pow", l))
      return MATHPOW;
    if (strcm(s, "exp", l))
      return MATHEXP;
  }
/*изменение значения переменной*/
  if (islower(s[0]) && s[1]=='='){
    strcp(s, stmp, 2, LINESIZE);
    if (isnum(stmp))
      return SETVAR;
    else {
      printf("getop: ошибка - неправильный формат\n");
      return ERROR;
    }
  }
/*в остальных случаях считается, что должно быть введено число*/
  if (isnum(s))
    return NUMBER;

  printf("getop: ошибка - неправильный формат\n");
  return ERROR;
}
//test
/*void main()
{
  char s[LINESIZE];

  printf("%d - %s\n", getop(s), s);
  printf("%d - %s\n", getop(s), s);
  printf("%d - %s\n", getop(s), s);
  printf("%d - %s\n", getop(s), s);
  printf("%d - %s\n", getop(s), s);
}*/
