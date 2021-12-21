#include <stdio.h>
#include "4readlines.h"
#include "4main.h"

#define DEBUG 1

/*записывает указатели на строки из ввода в сортируемый массив,
возвращает количеcтво строк < maxlines*/
int readlines(char *strpointers[], int maxlines)
{
  int len, nlines = 0;
  char *ptr;
  char *line;

  while ((len=getln(ptr, MAXLEN))>0){
    if ((line=alloc(len + 1))==NULL || nlines >= maxlines)
      return -1;
    else {
      strcpn(line, ptr);
      strpointers[nlines++] = line;
    }
  }

  return nlines;
}
//test
/*
void main()
{
  int n = readlines(strpointers, 100);
  printf("%d\n", n);
}
*/
