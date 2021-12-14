#include <stdio.h>
/*заменяет \t, пробелы и забой на \\*/

void main()
{
    int c;

    while ((c=getchar())!=EOF){
        if (c=='\t'||c=='\b'||c==' ')
            c='\\';
        putchar(c);
    }
}