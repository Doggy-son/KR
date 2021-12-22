#include <stdio.h>
#include <string.h>
/*выдает 1 если строка t расположена в конце s иначе 0*/

int strln(char *s);

int strend(char *s, char *t)
{
  int ls = strln(s);
  int lt = strln(t);

  if (ls<lt || ls==0)
    return 0;

  while (*(s+ls-lt)==*t && *t){
    s++;
    t++;
  }

  if (*t=='\0')
    return 1;
    
  return 0;
}
int strln(char *s)
{
  char *e = s; //запоминаем начало
  while (*e)
    e++;
  return e-s;
}
// test
void main()
{
  int l;

  printf(" = %d\n", (l=strend("abc", "bc")));
  printf(" = %d\n", (l=strend("abcdef", "de")));
  printf(" = %d\n", (l=strend("", "")));

}
