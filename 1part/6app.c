#include <stdio.h>
/*проверка, что getchar()!=EOF принимает значения 1 или 0*/

void main()
{
    int c;
    while (c = (getchar()!=EOF) != 1){
        putchar(c);
    }    
}
