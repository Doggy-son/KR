#include <stdio.h>
/*печать строк, длина которых превышает 80 символов*/

#define LIMIT 10/*выводятся строки, длина которых > LIMIT-2*/

int main()
{
    int c, i;
    char s1[LIMIT];
    char s2[2];

    i=0;
    s1[LIMIT-1] = '\0';
    s2[1] = '\0';

    while ((c=getchar())!=EOF){  
        if (i < LIMIT-1){
            s1[i] = c;
            ++i;
        }
        else if (i == LIMIT-1){
            printf("%s", s1);
            s2[0] = c;
            ++i;
        }
        else {
            printf("%s", s2);
            s2[0] = c;
        }

        if (c=='\n')
            i = 0;
    }

    return 0;
}

