#include <stdio.h>
#include "common.h"

#define BUFFERSIZE 2

int pos = 0;/*свободная позиция в стеке*/
char buffer[BUFFERSIZE];

int getch(void)
{
    return (pos > 0) ? buffer[--pos] : getchar();
}
void ungetch(int c)
{
  if (pos >= BUFFERSIZE)
    printf("ungetch: буффер переполнен\n");
  else
    buffer[pos++] = c;
}
