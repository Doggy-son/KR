#include <stdio.h>

void main()
{
    unsigned char a = 0x111;
    unsigned long n;

    n = a&017;
    printf("%ld", n);
}