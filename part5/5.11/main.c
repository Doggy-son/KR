#include <stdio.h>
#include <string.h>
#include "header.h"

int main(int argc, char *argv[])
{
    int nlines, c;
    int numeric = 0; // флаг, что нужно сравнивать числа
    int reverse = 0; //обратная сортировка

    while (--argc>0 && (c=*(++argv)[0]=='-')){
        while ((c = *++argv[0])){
            switch (c){
                case 'n':
                    numeric = 1;
                    break;
                case 'r':
                    reverse = 1;
                    break;
                default:
                    printf("main : некорректный аргумент\n");
                    break;
            }
        }
    }

    if ( (nlines = readlines(strpointers, LINESCNT)) != -1){

        if (reverse)
            q_sort((void **)strpointers, 0, nlines-1,
                numeric ? (int (*)(void*, void*))numcmp : (int (*)(void*, void*))strcmp, "desc");
        else
            q_sort((void **)strpointers, 0, nlines-1,
                    numeric ? (int (*)(void*, void*))(numcmp) : (int (*)(void*, void*))(strcmp), "asc");

        writelines(strpointers, nlines);
    }
    else {
        printf("main: ошибка\n");
        return -1;
    }

return 0;

}
