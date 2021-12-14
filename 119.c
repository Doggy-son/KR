#include <stdio.h>
/*функция reverse*/
#define LIMIT 1000 /*ограничение длины строки*/

void reverse(char line[], int length); /*передается */
int getln(char line[], int limit);

/*проверка функции reverse*/
int main()
{
    char line[LIMIT];
    int len;

    while((len=getln(line, LIMIT-1)) > 0){
        printf("%s - ", line);
        reverse(line, len);
        printf("%s", line);
    }

    return 0;
}
/*считывает строки, возвращает длину*/
int getln(char line[], int limit)
{
    int c, i;

    for (i=0;(c=getchar())!=EOF&&c!='\n'&&i<limit;++i){
        line[i] = c;
    }

    if (c=='\n'){
        line[i] = '\n';
        ++i;
    }
    line[i] = '\0';
 
   return i;
}
void reverse(char in_line[], int length)
{
    char reversed[length];
    int i;

    for (i=0;i<length;++i )
        reversed[length-1-i] = in_line[i];

    for (i=0;i<length;++i)
        in_line[i] = reversed[i];
}