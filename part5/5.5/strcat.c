#include <stdio.h>
/*копирует строку t в конец s
возвращает указатель на строку s*/
char *strcat(char *s, char *t)
{
  char *r = s; // сохраняем указатель на начало строки s

  while (*s)
    s++;
  while ((*s++ = *t++))
    ;
  return r;
}
//test
void main()
{
  char s[] = "abc";
  char t[] = "";
  char *k = strcat(s, t);

  printf("%s\n", k);
}
