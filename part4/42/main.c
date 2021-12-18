#include <stdio.h>
/*простой калькулятор - складывает введенные строки*/
#include "calculator.h"

void main(void)
{
  char s[MAX_LINE];
  int len;
  double result = 0.0;

  printf("please input numbers:\n");

  while ((len=getln(s, MAX_LINE-1))!=0){
    #ifdef DEBUG
    printf("get line = %s\n", s);
    #endif
    result += atof(s);
  }
    printf("sum = %g\n", result);
}
