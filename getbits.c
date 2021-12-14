#include <stdio.h>
/*вырезает из целого x n битов, начиная с позиции p*/
int getbits(int x, int n, int p);

void main ()
{
    int n1=0177, n2=0654;
    printf("%d - %d\n %d - %d\n", n1, getbits(n1, 2, 3), n2, getbits(n2, 5, 2));
}
int getbits(int x, int n, int p)
{
    int x2;
    
    x2 = x >> (p + 1) & ~(~0 << n);

    return x2;
}