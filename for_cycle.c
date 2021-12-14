#include <stdio.h>

void main ()
{
    int lim, c, i;
    lim = 5;

    for (i=0; (i<lim-1) + ((c=getchar())!='\n') + (c!=EOF) == 3; ++i)
        printf("i=%d, c=%d", i, c);
        
    printf("i=%d, c=%d", i, c);
}