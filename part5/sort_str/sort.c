#include <string.h>
#include "4main.h"

/*меняет местами x и y позиции в массиве*/
void swap(char *v[], int x, int y)
{
  char *temp;

  temp = v[x];
  v[x] = v[y];
  v[y] = temp;
}
/*сортировка методом Шелла*/
void sort(char *v[], int left, int right)
{
  int i, last;

  if (right <= left)
    return;

  last = (left+right)/2;
  swap (v, last, left);
  last = left;

  for (i=left+1; i<=right; i++){
    if ( strcmp(v[i], v[last]) < 0 ){
      swap(v, last, i);
      last = i;
    }
  }

  sort(v, left, last-1);
  sort(v, last+1, right);
}
