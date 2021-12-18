#include <stdio.h>
/*подсчет количества табуляций, пробелов 
и перевода строки из ввода циклом for*/

void main()
{
    long ns;
    int c;

    for (ns=0;(c=getchar())!=EOF;)
        if (c=='\t'||c==' '||c=='\n')
            ns++;

    printf("%ld\n", ns);
}