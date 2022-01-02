#include <stdio.h>
#include "header.h"
/*выделяет место в памяти для строки длины n*/

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
