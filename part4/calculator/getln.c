#include "common.h"
#include <stdio.h>

int getln(char s[])
{
  int c, i=0;

  while ((c=getchar())!=EOF && i<LINESIZE-1 && c!='\n'){
    s[i++] = c;
  }

  if (c==EOF)
    return EOF;
    
  s[i] = '\0';
  return i; // длина полученной строки
}
/*тест
void main()
{
  char s[LINESIZE];
  int l;

  while ((l=getln(s))!=0)
    printf("%s\n", s);
}*/
