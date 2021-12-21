#include <stdio.h>
#include "4main.h"
/*writelines выводит отсортированный массив в консоль*/

void writelines(char *strpointers[], int nlines)
{
  int i;

  for (i=0; i<nlines; i++){
    printf("%s\n", strpointers[i]);
  }
}
