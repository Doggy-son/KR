#include <stdio.h>

#define MAXL 4 /*маскимальный размер строки*/

int getline_2(char line[], int number);
void copy(char to[], char from[]);

/*печатает самую длинную строку из ввода*/
int main()
{
    int len; /*длина текущей строки*/
    int max; /*самая большая длина строки*/
    char line[MAXL]; /*текущая строка*/
    int tmp; /*сюда записывается длина отбрасываемой строки*/
    char longest[MAXL]; /*самая длинная строка*/

    max = 0;

    while ((tmp = getline_2(line, MAXL)) != 0){
        len += tmp - 1;
        if (tmp != MAXL-1){
            if (len > max) {
                max = len;
                copy(longest, line);
                len = 0;
            }
        }
    }
          
    if (max > 0)/*проверка, что была хотя бы одна строка*/
        printf("%s %d - max length\n", longest, max);

    return 0;
}

/*читает строку, возвращает ее длину*/
int getline_2(char s[], int limit)
{
    int c, i;

    for (i=0;i < limit-1 && (c=getchar())!=EOF && c!='\n';++i)
        s[i] = c;
    
    if (c=='\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}

/*копирует из строки from в to*/
void copy(char to[], char from[])
{
    int i;
    i = 0;

    while((to[i]=from[i]) != '\0')
        ++i;
}
