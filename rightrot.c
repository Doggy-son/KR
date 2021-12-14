#include <stdio.h>
/*циклически  сдвигает x вправо  на n разрядов*/
int rightrot(int x, int n);

void main()
{
    int x=0456;
    int n=3; 

    printf("%d - %d\n", x, rightrot(x, n));
}
int rightrot(int x, int n)
{
    int i, res;

    for(i=0;(x>>i)!=0; ++i)
    ;

    res = x>>n | (x&~(~0<<n))<<(i-n);

    return res;
}

