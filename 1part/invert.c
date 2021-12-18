#include <stdio.h>
/*возвращает значение x с инвертированными n битами, начиная с позиции p*/
int invert(int x, int n, int p);

void main()
{
    int x=0777, n=3, p=2;
    printf("%d - %d\n", x, invert(x, n, p));
}
int invert(int x, int n, int p)
{
    int res_x, k;

    k = (~0<<p+1) & ~(~0<<n+p+1);
    res_x = k & ~x + ~k & x;

    return res_x;
}
