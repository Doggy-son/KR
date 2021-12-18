#include <stdio.h>
/*управление стеком*/
#define SIZE 100

double stek[SIZE];
int id = 0; /*следующая свободная позиция*/

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
/*печатает верхний элемент*/
void show(void)
{
  if (id > 0)
    printf("верхний элемент в стеке : %g\n", stek[id-1]);
  else
    printf("show: стек пуст\n");
}
/*дублирует 1-й элемент*/
void duplicate(void)
{
  double temp;

  if (id > 0){
    temp = stek[id-1];
    stek[id++] = temp;
  }
  else
    printf("duplicate: стек пуст\n");
}
/*меняет местами 2 верхних элемента*/
void swap(void)
{
  double temp;

  if (id > 1){
    temp = stek[id-2];
    stek[id-2] = stek[id-1];
    stek[id-1] = temp;
  }
  else
    printf("SWAP: стек пуст\n");
}
/*очистка стека*/
void clear()
{
  while (id > 0)
    id--;
  printf("стек очищен, id = %d\n", id);
}

void main()
{
  double k = 1.2;
  push(k);
  push(k*0.8);
  swap();
  clear();
}
