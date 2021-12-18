#include <stdio.h>
/*копирование ввода в вывод*/

void main()
{
    int c;

    while ((c= getchar())!=EOF){
        putchar(c);
    }
    printf("end of input");
}