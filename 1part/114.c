#include <stdio.h>
/*печать гистограмм для символов из ввода
(0-999 символы юникода)*/

void main()
{
    int c, i, j;
    int nsymbol[1000];

    for (i=0;i<1000;i++)
        nsymbol[i]=0;

    while ((c=getchar())!=EOF){
        ++nsymbol[c];
    }

    for (i=0;i<1000;++i)
        if (nsymbol[i]!=0){
            putchar(i);
            for (j=0;j<nsymbol[i];++j)
                putchar('*');
        }
}