#include <stdio.h>
/*заменяет табуляции на пробелы*/
#define TAB_SIZE 4
#define MAX_LINE 1000

void detab(char in_line[], char out[]);
int getln(char s[], int limit);

int main() 
{
    int c;    
    char line[MAX_LINE];
    char detabbed[(MAX_LINE*4-3)];
    int len;

    while((len=getln(line, MAX_LINE-1)) > 0){
        printf("%s : ", line);
        detab(line, detabbed);
        printf("%s", detabbed);
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
/*заменяет табуляции на пробелы*/
void detab(char in[], char out[])
{
    int i, j, k, c;
    i = j = 0;

    while ((c = in[i])!='\0'){
        if (c=='\t'){
            for (k=0;k<TAB_SIZE;++k){
                out[j] = '-';
                ++j;
            }
        }
        else{
            out[j] = in[i];
            ++j;
        }
        ++i;
    }

}