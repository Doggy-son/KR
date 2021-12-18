#include <stdio.h>
#include <ctype.h>
#include <string.h>
/*записывает число в строку*/
void itoa(int x, char s[]);

void main()
{
    int n = -512;
    char s[10];

    itoa(n, s);
    printf("%s\n", s);

    n=-32589987;
    itoa(n, s);
    printf("%s\n", s);
}

void itoa(int x, char s[])
{
    int i=0, sign;

    if (x<0){
        sign = -1;
        x = -x;
    }  

    do {
        s[i++] = x%10 + '0';
    }
    while ((x/=10)!=0);

    if (sign == -1)
        s[i++] = '-';

    s[i] = '\0';    
   // strrev(s);
}