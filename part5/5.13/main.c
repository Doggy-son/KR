#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define LINESIZE 1000

/*печатает n последних строк. параметр n задается в формате "-n"*/
int main (int argc, char *argv[])
{
    int n, i = 0;
    char *s; // для строк из ввода
    char *l;
    size_t ssize = LINESIZE;
    s = (char *)malloc(LINESIZE * sizeof(char));
    l = (char *)malloc(LINESIZE * sizeof(char));
    long len_s;

    if (argc>2 || (*++argv)[0]!='-' || (n = atoi(++*argv))<=0){
        printf("main: некорректный ввод\n");
        return -1;
    }

    while((len_s = getline(&s, &ssize, stdin)) != -1){
        printf("main: get line s = %s", s, len_s);
        if (i >= n)
            pop();
        else
            i++;

        l = alloc(len_s + 1);
        strcpy(l, s);
        push(l);
    }

    while (i-- > 0)
        printf("main out: %s", pop());

    return 0;
}
