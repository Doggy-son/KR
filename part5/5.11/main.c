#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

int main(int argc, char *argv[])
{
    int nlines, c, option;
    int numeric = 0; // флаг, что нужно сравнивать числа
    int reverse = 0; //обратная сортировка
    int fold = 0; // case insensitive
    int dir_order = 0; // directory order
    int pos1 = 0, pos2 = 0;

    while (--argc>0 && (c=*(++argv)[0]=='-')){
        while ((c = *++argv[0])){
            switch (c){
                case 'n':
                    numeric = 1;
                    break;
                case 'r':
                    reverse = 2;
                    break;
                case 'f':
                    fold = 4;
                    break;
                case 'd':
                    dir_order = 8;
                    break;
                default:
                    printf("main : некорректный аргумент\n");
                    break;
            }
        }
    }

    option = numeric + reverse + fold + dir_order;

    if (argc-->0)
        pos1 = atoi(*(argv));
    if (argc>0)
        pos2 = atoi(*(++argv));

    if ( (nlines = readlines(strpointers, LINESCNT)) != -1){

        q_sort((void **)strpointers, 0, nlines-1,
                numeric ? (int (*)(void*, void*))numcmp : (int (*)(void*, void*))strcmp,
                option, pos1, pos2);

        writelines(strpointers, nlines);
    }
    else {
        printf("main: ошибка\n");
        return -1;
    }

return 0;

}
