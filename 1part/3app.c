#include <stdio.h>

/*печать таблицы температур по Цельсию и Фаренгейту*/

void main()
{
    float celsius, fahr;
    int lower, upper, step;

    lower = -60;
    upper = 100;
    step = 9;

    while (celsius <= upper){
        fahr = 9.0/5*celsius + 32;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}