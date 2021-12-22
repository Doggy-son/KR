#include <stdio.h>
/*возвращает позицию самого правого вхождения t в s либо -1*/
int strindex (char *s, char *t)
{
  int res = -1;
  int i, j;

  for (j=0; *(s+j); j++){
    for (i=0; (*(t+i)) && (*(t+i)==*(s+j+i)); i++)
    if (!(*(t+i)) && ((t+i)!=t))
      res = j;
  }

  return res;
}
//test
void main()
{
  char s[] = "ab12cd123";
  char t[] = "12";
  char s2[] = "";
  char t2[] = "";
  printf("s = %s, t = %s, idx = %d\n", s, t, strindex(s,t));
  printf("s = %s, t = %s, idx = %d\n", s, t2, strindex(s,t2));
  printf("s = %s, t = %s, idx = %d\n", s2, t2, strindex(s2,t2));
  printf("s = %s, t = %s, idx = %d\n", s2, t, strindex(s2,t));
}
