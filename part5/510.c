#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINESIZE 100

/*печать аргументов из консоли*/
/*void echo(int argc, char *argv[])
{
  int i=0;

  while (--argc > 0)
    printf("%d - %s\n", i, argv[++i]);
}*/
void echo(int argc, char *argv[])
{
  while (--argc > 0)
    printf("%s%s", *(++argv), (argc > 1) ? "+" : "");
}

/* find: печать строк с образцом, заданным 1-м аргументом */
int find(int argc, char *argv[])
{
  char *s;
  size_t ssize = LINESIZE;
  s = (char *)malloc(LINESIZE * sizeof(char));
  int found = 0, except = 0, number = 0, c;
  long lineno = 0;//номер строки

  while (--argc && *(++argv)[0] == '-')
    while (c = *++argv[0])
      switch (c) {
        case 'n':
          number = 1;
          break;
        case 'x':
          except = 1;
          break;
        default:
          printf("find: неверный параметр %d\n", c);
          argc = 0;
          found = -1;
          break;
      }
      if (argc != 1){
        printf("find: используйте шаблон find -x -n образец\n");
        return -1;
      }
      while(getline(&s, &ssize, stdin) != -1){
        lineno++;
        if ((strstr(s, *argv) != NULL) != except){
          printf("%ld : %s\n", (number ? lineno : '-'), s);
          found++;
        }
    }
  return found;
}
/*int find(int argc, char *argv[])
{
  char *s;
  size_t ssize = LINESIZE;
  s = (char *)malloc(LINESIZE * sizeof(char));
  int found = 0;

  while(getline(&s, &ssize, stdin) != -1){
    if (strstr(s, argv[1]) != NULL){
      found ++;
      printf("%s\n", s);
    }
  }
  return found;
}*/
//test
void main(int argc, char *argv[])
{
  find (argc, argv);
}
