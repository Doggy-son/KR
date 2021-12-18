#include <stdio.h>
/*подсчет количества табуляций, пробелов 
и перевода строки из ввода*/

void main()
{
    long ns;
    int c;

    ns = 0;
    while ((c = getchar())!=EOF){
        if (c=='\t' || c==' ' || c=='\n')
            ++ns;
    }
    printf("%ld\n", ns);
}