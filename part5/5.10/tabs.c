/*НЕРАБОЧАЯ ВЕРСИЯ*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*функции detab и entab, через аргументы
можно задать список "стопов" табуляции*/

#define LINESIZE 100

/*заменяет пробелы на табуляции если они пересекают стоп*/
void entab(char *s, int *stops);
/*заменяет табуляции на пробелы до ближайшего стопа*/
void detab( char *s, int *stops);
/*читает строки*/
int getln(char *s, int maxlen);
/*переводит строку в число*/
int atoi(char *s, int *x);
/*заполняет массив с позициями стопов*/
void setstops(int argc, char *argv[], int *stops);

int main (int argc, char *argv[])
{
  char *s;
  size_t ssize = LINESIZE;
  s = (char *)malloc(LINESIZE * sizeof(char));
  int stops[LINESIZE];

  setstops( argc, argv, stops );

    while (getline(&s, &ssize, stdin) != -1){
    printf ("main: get line = %s, len = %d\n", s);
    detab(s, stops);
    printf ("main: detabbed line = %s ", s);
  }
/*
  while ((len = getln(s, LINESIZE-1)) > 0){
    printf ("main: get line = %s, len = %d\n", s, len);
    entab(s, stops);
    printf ("main: entabbed line = %s ", s);
    s[0] = '\0';
  }
*/
  return 0;
}
/*void entab(char *s, int *stops){

  int sp = 0;

  while (*(s++)){
    printf ("while: %d\n", *s);
    stops++;
    while (*(s + sp) == ' '){
      sp ++;
      printf("entab: sp = %d\n", sp);
      if (*(stops++) == 1){
        *s = '\t';
        sp = 0;
        printf("entab: табуляция\n");
        break;
      }
    }
    while (sp-- > 0){
      *(s++) = ' ';
      printf("entab: пробел\n");
    }
  }
}*/
void detab (char *s, int *stops)
{
  while (*(s)){
    if (*(s) == '\t'){
      while (*(stops) != 1){
        *(s++) = ' ';
        stops++;
      }
    }
    s++;
    stops++;
}
}
void setstops(int argc, char *argv[], int *stops)
{
  int r, p, i;

  for (i=0; i<LINESIZE; i++)
    *(stops + i) = 0;

  while (--argc > 0 ){
    r = atoi(*(++argv), &p);
    if (r==-1)
      printf("setstops: неправильный аргумент\n");
    *(stops + p) = 1;
  }
}
/*int getln(char *s, int maxlen)
{
  char *begin = s;

  for ((*s)=getchar(); (*s)!=EOF && (*s)!='\n' && (s-begin)<(maxlen-1); (*++s)=getchar())
    ;

  if ((*s)==EOF)
    return 0;

  *++s = '\0';

  return s-begin;
}*/
int atoi(char *a, int *i)
{
  *i = 0;

  while (isdigit(*a)){
    *i = 10* *i + *a - '0';
    a++;
  }

  if (*a)
    return -1; //ошибка
  else
    return 0;
}
