#include <stdio.h>

/* программа с использованием цикла for и именованных констант
печатает таблицу Цельсий - Фаренгейт в обратном порядке */

#define LOWER 0 /*нижняя граница цикла*/
#define UPPER 300 /*верхняя граница цикла*/
#define STEP 30 /*шаг цикла*/

void main()
{
    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr+STEP)
        printf("%3d %6.1f\n", fahr, 5/9.0*(fahr - 32));    
}