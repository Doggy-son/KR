#include <stdio.h>
#include "getch.h"

#define BUFFERSIZE 10

int bufer[BUFFERSIZE] = {0}; // буфер для хранения символов
int id = 0; // id следующего свободного места в буфере

int getch(void)
{
  return (id > 0) ? bufer[id--] : getchar();
}
void ungetch(int c)
{
  if (id<BUFFERSIZE-1)
    bufer[id++] = c;
  else
    printf("ungetch: ошибка, буфер переполнен\n");
}
//test
/*void main()
{
  ;
}*/
