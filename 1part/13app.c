#include <stdio.h>
/*вывод каждого слова на отдельной строке*/

#define IN 1 /*внутри слова*/
#define OUT 0 /*вне слова*/

void main()
{
    int c, state;
    state = OUT;

    for (c=getchar();c!=EOF;c=getchar()){
        if (c==' '||c=='\t'||c=='\n'){
            if (state == IN)
                putchar('\n');
            state = OUT;
        }
        else {
            putchar(c);
            if (state == OUT)
                state = IN;
        } 
    }
}