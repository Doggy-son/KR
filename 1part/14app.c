#include <stdio.h>
/*подсчитывает кол. цифр в массив, кол. разделителей 
и прочих символов в переменные */

void main()
    {
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for (i=0;i<10;i++)
        ndigit[i] = 0;

    while ((c=getchar())!=EOF){
        if (c<='9'&c>='0')
            ++ndigit[c-'0'];
        else if (c==' '||c=='\t'||c=='\n')
            ++nwhite;
        else 
            ++nother;
    }

    printf("цифры: \n");
    for (i=0;i<10;i++)
        printf("\t%d : %d\n", i, ndigit[i]);
    printf("символы-разделители: %d, прочие: %d\n", nwhite, nother);
    }

