#include <stdio.h>
/*переворачивание строки с использованием указателей*/
void reverse (char *s)
{
  char temp;
  char *begin = s;

  while (*s)
      s++; //при выходе из цикла s указывает на null

  for (s--; s>begin; begin++, s--){
    temp = *s;
    *s = *begin;
    *begin = temp;
  }
}
//test
void main()
{
  char s[] = "abcd123";
  char s2[] = "";
  char s3[] = "abc123";
  reverse(s);
  printf("%s\n", s);
  reverse(s2);
  printf("%s\n", s2);
  reverse(s3);
  printf("%s\n", s3);
}
