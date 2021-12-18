#include <ctype.h>
#include <stdio.h>
#include "calculator.h"
/*преобразует строку формата "-99.99e-9"
в число типа double*/

double atof(char s[])
{
  int i, sign, exp_sign, exp_pow;
  double val, power;
  i = 0;

  while(isspace(s[i]))
    i++;

  sign = s[i]=='-' ? -1:1;
  if (s[i]=='-'||s[i]=='+')
    i++;
  #ifdef DEBUG
  printf("sign = %d\n", sign);
  #endif

  for (val=0.0; isdigit(s[i]); i++){
    val = 10.0*val + (double)(s[i] - '0');
  }
  #ifdef DEBUG
  printf("val = %g\n", val);
  #endif

  if (s[i]=='.')
    i++;

  for (power=1.0; isdigit(s[i]); i++){
    power = 10.0*power;
    val = 10.0*val + (s[i] - '0');
  }
  #ifdef DEBUG
  printf("power = %g\n", power);
  #endif

  if (s[i]=='e' || s[i]=='E')
    i++;

  exp_sign = s[i]=='-' ? -1:1;
  if (s[i]=='-'||s[i]=='+')
    i++;
  #ifdef DEBUG
  printf("exp_sign = %d\n", exp_sign);
  #endif

  for (exp_pow=0.0; isdigit(s[i]); i++){
    exp_pow = 10*exp_pow + (s[i]-'0');
  }
  #ifdef DEBUG
  printf("exp_pow = %d\n", exp_pow);
  #endif

  #ifdef DEBUG
  printf("sign*(val/power) = %g\n", sign*(val/power));
  printf("get_pow(EULER, exp_sign*exp_pow) = %g\n", get_pow(EULER, exp_sign*exp_pow));
  #endif

  return sign*(val/power)*get_pow(EULER, exp_sign*exp_pow);

}
