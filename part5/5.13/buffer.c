#include <stdio.h>
#include "header.h"

#define BUFSIZE 1000000

/*выделяет память для строк*/
char buffer[BUFSIZE]; //буфер, из которого выделяется память
char *next = buffer;//первое справа свободное место в буфере

/*функция выделяет массив размера n*/
char *alloc(long n)
{
    if (next + n > buffer + BUFSIZE){
        printf("alloc: не хватает места в  буфере\n");
        return NULL;
        }
    else {
        next += n;
        return next - n;
    }
}

//test
/*
void main(void)
{
    char *s; // для хранения строк из ввода
    char *a;
    size_t ssize = LINESIZE;
    s = (char *)malloc(LINESIZE * sizeof(char));
    long len_s;

    while((len_s = getline(&s, &ssize, stdin)) != -1){
        printf("main: get line s = %s, len_s = %ld\n", s, len_s);
        a = alloc(len_s);
    }
}*/
