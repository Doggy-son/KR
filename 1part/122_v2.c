#include <stdio.h>
/*программа переносит строку. если ее длина > n,
когда возможно, перенос проходит по символу-разделителю*/

#define LENGTH 10 /*ширина, к которой нужно привести строки*/
#define MAXLINE 1000 /*ограничения на длину строк*/

int getln(char line[], int lim);    
int println(char inln[], int n);
void mergeln(char left[], char right[]);
int break_idx(char line[]);
int length(char line[]);
void offset(char line[], int n);
void copyln(char inln[], char outln[]);

int main()
{
    int len, len2, br;
    char line[MAXLINE], line2[MAXLINE];
    line2[0] = 0;

    while (len=getln(line, LENGTH-1)!=0)
    {

      mergeln(line2, line);
      copyln(line2, line);
      br = break_idx(line);
      if (br = -1 || br >= LENGTH)
        br = LENGTH - 1;
      println(line, br);
      offset(line, br);
      copyln(line, line2);        
    }    
    if (length(line2)>0)
        printf("%s\n", line2);
        
    return 0;   
}
/*функция читает строку длины LENGTH*/
int getln(char line[], int lim)
{
    int c, i;

    for (i=0;i<lim && (c=getchar())!=EOF && c!='\n';++i){
        line[i] = c;
    }
    
    if (c=='\n'){
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    if (i == 0)
        return 0;

    return i;
}
/*функция печатает первые n символов строки*/
int println(char line[], int n)
{
    line[n] = '\0';
    printf("%s \n", line);
}
/*функция соединяет 2 строки, записывает в left*/
void mergeln(char left[], char right[])
{
    int i, j;
    i = 0;

    while (left[i]!='\0')
        ++i;

    for (j=0;right[j]!='\0';++j, ++i)
        left[i] = right[j];

    left[i] = '\0';
}
/*функция возвращает индекс последнего разделителя в строке, либо -1*/
int break_idx(char line[])
{
    int idx, i;
    idx = -1;

    for (i=0;line[i]!='\0';++i){
        if(line[i]==' '||line[i]=='\t')
            idx = i;
    }

    return idx;
}
/*функция возвращает длину строки*/
int length(char line[])
{
    int i;

    for (i=0;line[i]!='\0';++i)
    ;

    return i;
}
/*функция смещает строку на n символов к началу*/
void offset(char line[], int n)
{
    int i;

    for (i=0; line[n+i]!='\0'; ++i){
        line[i] = line[n+i];
    }

    line[i] = 0;
}
/*функция копирует строку*/
void copyln(char inln[], char outln[])
{
    int i;

    for (i=0; inln[i]!='\0'; ++i){
        outln[i] = inln[i];
    }

    outln[i] = 0;
}