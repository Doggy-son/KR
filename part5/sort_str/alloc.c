
#include "4readlines.h"
#include <stdio.h>
/*функция alloc выделяет место для строк длины n
и возвращает указатель на адрес в памяти*/
#define BUFFSIZE 1000000

char bufferArray[BUFFSIZE]; // массив, из которого будут нарезаться кусочки
char *next = bufferArray; //  указатель на следующую свободную позицию в буфере
/*выделяет n ячеек в памяти */
char *alloc(int n)
{
  if (next+n <= bufferArray+BUFFSIZE){ // поместятся ли n символов в буфер
    next += n;
    return next-n;
  }
  else {
    printf("alloc: в буфере не хватает места для выделения памяти\n");
    return 0;
  }
}
/*освобождает буфер до позиции p*/
void afree(char *p)
{
  if (p<=next && p>=bufferArray && p<bufferArray+BUFFSIZE)
    next = p;
  else
    printf("afree: либо p не входит в буфер, либо буфер свободен до p\n");
}
//test
/*void main()
{
  char *s1;
  char *s2;
  char *s3;

  s1 = alloc(10000);
  if (s1!=NULL) // определен в stdio = 0 для указателей
    printf("место выделено\n");
  s2 = alloc(100000);
  if (s2!=NULL) // определен в stdio = 0 для указателей
    printf("место выделено\n");
  s3 = alloc(1000000);
  if (s3!=NULL) // определен в stdio = 0 для указателей
    printf("место выделено\n");
  else
    printf("не удалось получить память\n");
  afree(s1);
  s3 = alloc(1000000);
  if (s3!=NULL) // определен в stdio = 0 для указателей
    printf("место выделено\n");
  else
    printf("не удалось получить память\n");
}*/
