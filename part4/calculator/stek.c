#include "common.h"
#include <stdio.h>

#define STEKSIZE 100 //максимальный размер стека

static double stek[STEKSIZE];
static int next = 0; //индекс следущего элемента

void push(double x)
{
  if (next < STEKSIZE)
    stek[next++] = x;
  else{
    printf("push: стек переполнен, невозможно записать %g\n", x);
  }
}
double pop(void)
{
  if (next > 0)
    return stek[--next];
  else {
    printf("pop: стек пуст\n");
    return -1;
  }
}
/*очистка стека*/
void clear(void)
{
  next = 0;
}
