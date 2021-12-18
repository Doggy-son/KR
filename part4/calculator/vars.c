#include "common.h"
#include <stdio.h>

#define VARSCNT 26 //количество переменных
static double vars[VARSCNT];

/*инициализирует переменные*/
void varinit(void)
{
  int i;

  for (i=0; i<VARSCNT; i++)
  {
    vars[i] = 0.0;
  }
}
/*возвращает значение переменной*/
double getvar(char c)
{
  int i;

  i = c - 'a';//индекс переменной в массиве
  return vars[i];
}
/*меняет значение переменной*/
void setvar(char c, double x)
{
  int i;

  i = c - 'a';
  vars[i] = x;
}
/*тест
void main(void)
{
  int i;

  varinit();
  setvar('b', 20.9);
  printf("%d = %g\n", 'b', getvar('b'));
  printf("%d = %g\n", 'f', getvar('f'));
  for (i='a'; i<'a'+VARSCNT; i++)
      printf("%d = %g\n", i, getvar(i));
}
*/
