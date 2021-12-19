#include <stdio.h>
/*переставляет элементы строки в ту же строку в обратном порядке*/

void reverse(char s[])
{
  static int i = 0;
  static int j = 0;
  int temp;

  if (s[i] == '\0'){
    i--;
    return;
  }

  i++;
  reverse(s);

  if (i>j){ //условие нужно, чтобы не менять элементы во второй раз
    temp = s[i];
    s[i--] = s[j];
    s[j++] = temp;
  }
}
void main(void)
{
  char s[] = "abcdef";
  reverse(s);
  printf("reversed s = %s\n", s);
}
