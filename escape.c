#include <stdio.h>
/*преобразует символы новая строка и табуляция в \n и \t*/

void escape(char s[], char t[]);

void main()
{
    char s[1000] = "Abcdef 123\n\tQwerty 456\n\t He\the\n!";
    char t[1000];

    escape(s, t);

    printf("%s -> %s", s, t);
}
void escape(char s[], char t[])
{
    int i, j;
    j=0;

    for (i=0; s[i]!='\0'; ++i){
        switch (s[i]){
            case '\t': 
                t[j++] = '\\';
                t[j++] = 't';
                break;
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            default:
                t[j++] = s[i];
                break;
        }
    }
    t[j]='\0';
}
