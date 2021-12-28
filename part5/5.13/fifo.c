#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/*fifo стек для указателей на строки*/
#define STACKSIZE 100

static char *stack[STACKSIZE];
static int begin = 0;
static int end = 0;

int push(char *c)
{
    if (end == STACKSIZE){
        printf("push: стек переполнен\n");
        return -1;
    }
    stack[end++] = c;
    return 0;
}
char *pop(void)
{
    if (begin == end){
        printf("pop: стек пуст\n");
        return NULL;
    }
    return stack[begin++];
}
