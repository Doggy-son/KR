#include <stdio.h>
/*выдает позицию самого правого вхождения t в s или -1*/
#define MAX_LINE 1000 //ограничение на длину строки

int getln(char s[], int maxlen);
int strindex(char s[], char t[]);

void main()
{
  int l, idx;
  char s[MAX_LINE];
  char t[MAX_LINE] = "shit";

  while ((l=getln(s, MAX_LINE-1)) != 0){
      idx = strindex(s, t);
      if (idx>-1)
        printf("line %s contains %s on position %d\n", s, t, idx);
  }
}
