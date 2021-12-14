#include <stdio.h>
/*заменяет стоящие подряд таб. и пробелы на один пробел
удаляет пустые строки и пропуски с начала строки*/

#define SKIP 1
#define PRINT 0

void main()
{
    int c, skip_flg;
    skip_flg = PRINT; /*последний прочитанный символ был из множества {'\t', ' ', '\n'}*/

    while ((c=getchar())!=EOF){
        if (c==' '||c=='\t'||c=='\n'){
            if (skip_flg == PRINT)
                putchar(c);
            skip_flg = SKIP;
        }
        else {
            putchar(c);
            skip_flg = PRINT;
        }
    }
}
