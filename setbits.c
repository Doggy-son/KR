#include <stdio.h>
/*возвращает значение x, в котором n битов, начиная с p-й позиции, заменены на n правых разрядов из y*/
int setbits(unsigned int x, unsigned int n, unsigned int p, unsigned int y);

void main()
{
    unsigned int x=0165, n=3, p=2, y=07;

    printf("%d - %d\n", x, setbits(x, n, p, y));
}
int setbits(unsigned int x, unsigned int n, unsigned int p, unsigned int y)
{
    unsigned int x_res;

    x_res = x&(~0<<p+n+1) | x&~(~0<<p+1) | (y<<p+1)&~(~0<<n+p+1);

    return x_res;
} 