#include <stdio.h>
/*получает строки из ввода*/

int getln(char s[], int lim)
{
  int c, i;
  i = 0;

  while ((c=getchar())!=EOF && c!='\n' && i < lim)
    s[i++] = c;

  if (c=='\n')
    s[i++] = '\n';

  s[i] = '\0';

  return i;
}
