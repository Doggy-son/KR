#include <stdio.h>
/*функция возведения в степень*/

int power(int m, int n);
/*тест функции power*/
int main()
{
    int i;

    for (i=0;i<10;++i)
        printf("%d: 2 - %d, 3 - %d\n", i, power(i, 2), power(i, 3));

    return 0;
}
/*возводит base в n-ю степень*/
int power(int base, int n)
{
    int res;

    for (res=1;n>0;--n)
        res = res*base;

    return res;
}