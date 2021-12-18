#include "common.h"
#include <stdio.h>
#include <math.h>

/*управление*/
int main(void)
{
  char s[LINESIZE], stmp[LINESIZE];
  int command, c;
  double x, temp;

  varinit();

  while ((command = getop(s)) !=EOF){
    switch (command){
      case NUMBER:
        push(stonum(s));
        printf("get operand %s\n", s);
        break;
      case OPPLUS:
        push(pop()+pop());
        printf("get operator + \n");
        break;
      case OPMULT:
        push(pop()*pop());
        printf("get operator * \n");
        break;
      case OPMINUS:
        temp = pop();
        push(pop()-temp);
        printf("get operator - \n");
        break;
      case OPDIV:
        temp = pop();
        if (temp == 0.0){
          printf("main: ошибка деление на 0\n");
          return -1;
        }
        push(pop()/temp);
        printf("get operator / \n");
        break;
      case OPMOD:
        temp = pop();
        if (temp == 0.0){
          printf("main: ошибка деление на 0\n");
          return -1;
        }
        push((int)pop()%(int)temp);
        printf("get operator mod \n");
        break;
      case MATHPOW:
        temp = pop();
        push (pow(pop(), temp));
        printf("main: возведение в степень\n");
        break;
      case MATHEXP:
        push(exp(pop()));
        printf("main: экспонента\n");
        break;
      case MATHSIN:
        temp = sin( pop() );
        push(temp);
        printf("main:синус\n");
        break;
      case VARIABLE:
        c = s[0];
        push(getvar(c));
        printf("main: обращение к переменной\n");
        break;
      case SETVAR:
        c = s[0];
        strcp(s, stmp, 2, LINESIZE);
        x = stonum(stmp);
        setvar(c, x);
        printf("main: запись в переменную %d = %g\n", c, x);
        break;
      case ERROR:
        printf("main: ошибка \n");
        break;
      case RESULT:
        printf("main: result = %g", pop());
        clear();
        return 0;
  }
}
  printf("main: result = %g", pop());
  clear();
  return 0;
}
