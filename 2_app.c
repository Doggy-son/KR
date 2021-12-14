#include <stdio.h>

/*печать таблицы температур по Фаренгейту 
и Цельсию для fahr = 0,15,30...*/

void main()
{
    float fahr, celcius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 15;

    printf("%s\n", "Таблица температур по Фаренгейту и Цельсию");
    printf("\n");

    fahr = lower;
    while (fahr <= upper){
        celcius = 5/9.0*(fahr-32);
        printf("%10.0f %6.1f\n", fahr, celcius);
        fahr = fahr + step;
    }
}