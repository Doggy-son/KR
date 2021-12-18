#include <stdio.h>
/*программа выводит размер самой длинной строки,
и первые 5 символов */

#define MAXLINE 7/*ограничение длины для хранения строк*/

int getln(char s[], int limit);/*возвращает длиу строки и записывает первую часть*/
void copy(char s[], char d[]); /*копирует строку source -> destination*/

int main()
{
    char sline[MAXLINE];
    char stmp[MAXLINE];
    int imax, itmp;

    imax = 0;

    while((itmp=getln(stmp, MAXLINE-2))>0){
        if (itmp > imax){
            copy(stmp, sline);
            imax = itmp;
        }
    }

    if (imax > 0)
        printf("%s - %d символов", sline, imax);
    return 0;
}

int getln(char s[], int limit)
{
    int c, i, len;

    for (i=0;(c=getchar())!=EOF&&c!='\n';++i){
        if (i < limit ){
            s[i] = c;
            len = i;
        }
    }

   if (c=='\n'){
        s[len] = c;
        ++len;
    }
    s[len] = '\0';
    return i;
}

void copy(char s[], char d[])
{
    int i;
    i = 0;

    while((d[i]=s[i]) != '\0')
        ++i;
}