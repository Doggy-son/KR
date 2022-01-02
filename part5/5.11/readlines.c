#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

/*записывает указатели на строки из ввода в сортируемый массив,
возвращает количеcтво строк < maxlines*/
int readlines(char *strpointers[], int maxlines)
{
  int nlines = 0;
  char *ptr;
  char *line;
  size_t ssize = LINESIZE;
  ptr = (char *)malloc(LINESIZE * sizeof(char));
  line = (char *)malloc(LINESIZE * sizeof(char));
  long len_s;

  while((len_s = getline(&ptr, &ssize, stdin)) > -1){
    if ((line=alloc(len_s + 1))==NULL || nlines >= maxlines)
      return -1;
    else {
      strcpy(line, ptr);
      strpointers[nlines++] = line;
    }
  }

  return nlines;
}
/*writelines выводит отсортированный массив в консоль*/
void writelines(char *strpointers[], int nlines)
{
  int i;

  for (i=0; i<nlines; i++){
    printf("%s\n", strpointers[i]);
  }
}
