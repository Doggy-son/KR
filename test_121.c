#include <stdio.h>
#include "121.h"
/*проверка функции entab*/

#define MAX_LINE 1000

int getln(char s[], int limit);

int main() 
{
    int c;    
    char line[MAX_LINE];
    char entabbed[(MAX_LINE*4-3)];
    int len;

    while((len=getln(line, MAX_LINE-1)) > 0){
        printf("%s : ", line);
        entab(line, entabbed);
        printf("%s", entabbed);
    }

    return 0;

    return 0;
}
int getln(char s[], int limit)
{
    int c, i;

    for (i=0;(c=getchar())!=EOF&&c!='\n'&&i<limit-1;++i){
            s[i] = c;
    }

   if (c=='\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}