#include <stdio.h>
#include "common.h"
/*управление стеком*/
#define SIZE 100

static double stek[SIZE];
static int id = 0; /*следующая свободная позиция*/

double pop(void)
{
  if (id > 0)
    return stek[--id];
  else {
    printf("pop: стек пуст\n");
    return -1;
  }
}
void push(double x)
{
  if (id < SIZE)
    stek[id++] = x;
  else{
    printf("push: стек переполнен, невозможно записать %g\n", x);
  }
}
