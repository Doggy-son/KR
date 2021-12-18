#include <stdio.h>
/*функция заменяет несколько пробелов подряд на 
минимальное кол. табуляций и пробелов*/

#define TAB_SIZE 4 /*шаг табуляции*/
#define MAX_LINE 1000
void entab(char in_ln[], char out_ln[]);

int getln(char s[], int limit);

int main() 
{
    int c;    
    char line[MAX_LINE];
    char entabbed[(MAX_LINE*4-3)];
    int len;

   /* while((len=getln(line, MAX_LINE-1)) > 0){
        printf("%s : ", line);
        entab(line, entabbed);
        printf("%s", entabbed);
    }*/

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

void entab(char in_ln[], char out_ln[])
{
    int i, j, k, c;
    i = j = k = 0;

    while((c=in_ln[i]!='\0')){
        while(c==' '){
            ++k;
            ++i;
            c = in_ln[i];
        }
        while ((k-TAB_SIZE)>=0){
            out_ln[j] = '\t';
            ++j;
            k -= TAB_SIZE;
        }
        while (k > 0){
            out_ln[j] = ' ';
            ++j;
            --k;
        }
        if (c!=' '){
            out_ln[j] = c;
            ++j;
        }
        ++i;
        k = 0;
    }

}
