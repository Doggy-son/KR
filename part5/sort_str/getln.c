#include <stdio.h>
#include "4readlines.h"
/*функция читает строку из ввода*/
int getln(char *s, int maxlen)
{
  char *begin = s;

  for ((*s)=getchar(); (*s)!=EOF && (*s)!='\n' && (s-begin)<(maxlen-1); (*++s)=getchar())
    ;

  if ((*s)==EOF)
    return 0;

  *++s = '\0';

  return s-begin;
}
/*функция копирует t в s*/
void strcpn(char *s, char *t)
{
  for (; *t!='\0'; t++)
      *s++ = *t;
  *s = '\0';
}
/*void main()
{
  char *ptr, line[1000];
  ptr = "abcdef";

  strcpn (line, ptr);
  printf("%s - %s", ptr, line);
}*/
