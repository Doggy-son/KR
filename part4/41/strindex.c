#include <stdio.h>
/*функция ищет последнее вхождение t в s*/

int strindex(char s[], char t[])
{
  int i, j, idx;
  idx = -1;

  for (i=0; s[i]!='\0'; i++){
    for (j=0; t[j]!='\0'; j++){
      if (s[i+j]!=t[j])
        break;
    }
    if (t[j]=='\0')
      idx = i;
  }
  return idx;
}
