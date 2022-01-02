#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "header.h"

void to_lower(char *s)
{
    int c, i = 0, j = 0;

    while ((c = *(s+i))){
        i++;
        *(s+j++) = tolower(c);
    }
    s[j] = '\0';
}
/*оставляет в строке только цифры, символы и пробелы*/
void to_alphanum(char *s)
{
    int c, i = 0, j = 0;

    while ((c = *(s+i)) != '\0'){
        i++;
        if (isdigit(c) || isalpha(c) || isspace(c))
            *(s+j++) = c;
        }
    s[j] = '\0';
}
char *substr(char *s, int pos1, int pos2)
{
    char *t = (char *)malloc(LINESIZE * sizeof(char));
    int c, i = pos1, j = pos2, k = 0;

    while ((c = *(s+i))!=0 && i<pos2 ){
        *(t + k++) = c;
        i++;
    }
    *(t+k) = '\0';
    
    return t;
}
//test
/*
void main ()
{
    char s[] = "abCD10e-&**f";
    char *t;

    //to_lower(s);
//    printf("t = %s\n", s);

    //to_alphanum(s);
    printf("t = %s\n", substr(s, 1, 4));
}*/
