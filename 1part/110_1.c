#include <stdio.h>
/*печать самой длинной строки с использованием внешних переменных*/

#define MAXLINE 1000 /*ограничение на длину строк*/

int max; /*максимальная длина строки*/
char line[1000]; /*Текущая строка*/
char longest[1000]; /*самая длинная строка*/

int getln(void);
void copy(void);

int main()
{
    int len;
    extern char line[], longest[];
    extern int max;

    while((len=getln()) > 0){
        if (len > max){
            max = len;
            copy();
        }
    }

    if (max > 0)
        printf("%s", longest);

    return 0;
}
int getln(void)
{
    int c, i;
    extern char line[];

    for (i=0;(c=getchar())!=EOF&&c!='\n'&&i<MAXLINE;++i){
        line[i] = c;
    }

    if (c=='\n'){
        line[i] = '\n';
        ++i;
    }
    line[i] = '\0';
 
   return i;
}
void copy(void)
{
    extern char line[], longest[];
    int i;

    i=0;

    while ((longest[i]=line[i])!='\0')
        ++i;
}
