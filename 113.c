#include <stdio.h>
/*выводит гистограммы для вводимых слов*/

#define OUT 0 /*внутри слова*/
#define IN 1 /*вне слова*/

void main()
{
    int c, i, nlen, status;
    status = OUT;
    nlen = 0;

    while((c=getchar())!=EOF){
        if ((c==' '||c=='\t'||c=='\n')){
            if (status==IN){
                status = OUT;
                printf(" - ");
                for (i=0;i<nlen;++i)
                    printf("*");
                putchar('\n');
                nlen =0;
                }
            }
        else {
            putchar(c);
            ++nlen;
            status = IN;
            }

        }
}