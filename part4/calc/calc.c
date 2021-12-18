#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "common.h"
/*калькулятор в польской нотации*/

int main(void)
{
  char s[MAX_LENGTH];
  int k;
  double temp;

  while ((k=getop(s)) != EOF ){
    switch (k){
      case NUMBER:
        push( atof(s) );
        printf("get operand %s\n", s);
        break;
      case '+':
        push( pop() + pop());
        printf("get operator + \n");
        break;
      case '*':
        push( pop() * pop());
        printf("get operator * \n");
        break;
      case '-':
        temp = pop();
        push( pop() - temp);
        printf("get operator - \n");
        break;
      case '/':
        temp = pop();
        if (temp == 0.0){
          printf("main: деление на 0\n");
          return -1;
        }
        push( pop()/temp);
        printf("get operator / \n");
        break;
      case '%':
        temp = pop();
        if (temp == 0.0){
          printf("main: деление на 0\n");
          return -1;
        }
        push( (int)pop()%(int)temp);
        printf("get operator mod \n");
        break;
      case MATH_POW:
        temp = pop();
        push (pow(pop(), temp));
        printf("main: возведение в степень\n");
        break;
      case MATH_EXP:
        push(exp(pop()));
        printf("main: экспонента\n");
        break;
      case MATH_SIN:
        temp = sin( pop() );
        push(temp);
        printf("main:синус\n");
        break;
      }
  }
  printf( "result = %g\n", pop());
  return 0;
}
