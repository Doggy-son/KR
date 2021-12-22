#include <stdio.h>
/*функция копирует не более n символов из t в s*/
void strcpn(char *s, char *t, int n)
{
  char *e = t+n;
    for (; *t!='\0' && t<e; t++)
      *s++ = *t;
    *s = '\0';
}
/*функция приписывает не более n символов из t к s*/
void strcatn(char *s, char *t, int n)
{
  char *e = t+n+1;

  printf ("%s\n", e);
  while (*s)
    s++;
  while ((*s++ = *t++) && t<e){
    ;
  }
}
/*сравнивает первые n символов в s и t*/
int strcmpn(char *s, char *t, int n)
{
   //= s+n;

  for (;(*s) && (*t) && (*s==*t) && n>0; s++, t++, n-- )
    ;
  if (n==0 || ((*s)=='\0' && (*t)=='\0'))
    return 1;
  return 0;
}
//test
void main()
{
  int r;
  char s[100] = "abcdef";

  strcpn(s, "abc", 4);
  printf("%s\n", s);
}
