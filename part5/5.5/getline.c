#include <stdio.h>
/*функция читает строку из ввода*/

int getln(char *s)
{
  char *begin = s;

  for ((*s)=getchar(); (*s)!=EOF && (*s)!='\n'; (*++s)=getchar())
    ;

  if ((*s)==EOF)
    s--;
  *++s = '\0';

   return s-begin;
}
void main()
{int k;
  char s[20];

while ((k=getln(s))!=0){
  printf("%d - %s", k, s);
}
}
