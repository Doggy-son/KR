#include <stdio.h>
/*подсчитывает число единичных битов в аргументе целочисленного типа*/
int bitcount(int x);

void main()
{
    int i;

    for (i=0; i<100; i=i+3)
        printf("%d - %d\n", i, bitcount(i));
}
/*int bitcount(int x)
{
    int b;

    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;

    return b;
}*/
int bitcount(int x)
{
    int b;

    for (b=0; x!=0; x&=(x-1))
        b++;

    return b;
}