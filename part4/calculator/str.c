#include "common.h"
#include <stdio.h>
#include <ctype.h>

/*сравнение 2 строк по первым n символам*/
int strcm(char s1[], char s2[], int n);
/*удаление пробелов и табуляций из строк*/
void strtrm(char s[]);
/*проверка записано ли в строку число с плавающей точкой*/
int isnum(char s[]);
/*копирование строки s1 в s2, c позиции from до to*/
void strcp(char s1[], char s2[], int from, int to);
/*превращает строку в число типа double*/
double stonum(char s[]);

int strcm(char s1[], char s2[], int n)
{
  int i;

  for (i=0; s1[i]!='\0' && s2[i]!='\0' && i<n; i++){
    if (s1[i]!=s2[i])
      break;
  }

  if (i<n)
    return 0; //false
  return 1;
}
void strtrm(char s[])
{
  int i, j;

  for (i=0, j=0; s[i]!='\0'; i++){
    if (isspace(s[i]))
      ;
    else
      s[j++] = s[i];
  }
  s[j] = '\0';
}
/*формат числа [+-]9..9[.][9..9]*/
int isnum(char s[])
{
  int i=0, res=0;

  if(s[0]=='+' || s[0]=='-')//число может начинаться со знака
    i++;
  //цикл до первой точки
  while (s[i]!='\0' && ( isdigit(s[i]) || s[i]=='.')){
    if (s[i]=='.'){
      i++;
      break;
    }
    else { //обработка цифры
      res=1;
      i++;
    }
  }
  //цикл после точки
  while (isdigit(s[i]) && s[i]!='\0'){
    res = 1;
    i++;
  }
  if (s[i]=='\0')
    return res;
  return 0;
}
void strcp(char s1[], char s2[], int from, int to)
{
  int i;

  if (to < from)
    printf("strcp: ошибка, to < from \n");

  for (i=0; s1[from]!='\0' && from<=to; from++, i++)
    s2[i] = s1[from];

  s2[i] = '\0';
}
double stonum(char s[])
{
  double val = 0.0, pow = 1.0, sign = 1;
  int i=0;

  if (!isnum(s)){
    printf("stonum: ошибка, неправильный формат %s\n", s);
    return -1;
  }
//обработка знака
  if (s[0]=='-')
    sign = -1;
  if (s[0]=='-' || s[0]=='+')
    i++;

  while (isdigit(s[i])){
    val = val*10.0 + s[i]-'0';
    i++;
  }

  if (s[i] == '.')
    i++;

  while (isdigit(s[i])){
    val = 10.0*val + s[i] - '0';
    pow = 10.0*pow;
    i++;
  }

  return sign*(val/pow);
}
//тест
/*void main(void)
{
  printf("%g\n", stonum("+1.56"));
  printf("%g\n", stonum(".56"));
  printf("%g\n", stonum("-1"));
}*/
