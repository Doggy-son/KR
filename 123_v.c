#include <stdio.h>

  #define BUFSIZE 10000 /* максимальный размер буфера ввода + 1 */

  int getbuffer(char line[], int maxline);
  void decomment(char to[], char from[]);

  int main()
  {
      int len; /* размер содержимого буфера */
      char buffer[BUFSIZE]; /* буфер ввода */
      char newbuffer[BUFSIZE]; /* буфер ввода с удаленными комментариями */

      len = 0;
      while ((len = getbuffer(buffer, BUFSIZE)) > 0) {
          decomment(newbuffer, buffer);
          printf("%s", newbuffer);
      }
      return 0;
  }

  /* getbuffer: считывает содержимое ввода в s, возвращает длину */
  int getbuffer(char s[], int lim)
  {
      int c, i;

      for (i = 0; i < lim && (c = getchar()) != EOF; ++i)
          s[i] = c;
      s[i] = '\0';
      return i;
  }

  void decomment(char to[], char from[])
  {
      int i, j, c;
      int cf;

      i = j = 0;
      cf = 0;
      while ((c = from[i]) != '\0') {
          if (c == '/' && from[i+1] == '*' && cf == 0) {
              cf = 1;
              ++i;
          }
          else if (c == '*' && from[i+1] == '/' && cf == 1) {
              cf = 0;
              ++i;
          }
          else if (cf == 0) {
              to[j] = from[i];
              ++j;
          }
          ++i;
      }
  }