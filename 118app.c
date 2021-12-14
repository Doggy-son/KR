#include <stdio.h>
/*заменяет стоящие подряд пробелы и табуляции на 1 пробел
не выводит пустые строки*/
#define SKIP 1 /*признак того, что нужно пропускать пробелы, таб., и пер. строки*/
#define PRINT 0

void main()
{
    int c;
    int skip_flg ;
    
    skip_flg = SKIP;

    while ((c=getchar())!=EOF){
        if (c=='\n'||c=='\t'||c==' '){
            if (skip_flg==PRINT){
                skip_flg = SKIP;
            } }
        putchar(c);
    
    }

}