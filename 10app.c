#include <stdio.h>
/*несколько пробелов подряд заменяет на один*/

void main()
{
    int c;
    for (c=getchar();c!=EOF;c=getchar()){
        if (c==' '){
            putchar(c);
            while((c=getchar())==' '){
                ;
            }
        }
        putchar(c);
    }
}