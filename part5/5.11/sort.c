#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

void swap(void *v[], int a, int b);

/*функция сортирует массив*/
void q_sort (void *v[], int left, int right, int (*comp)(void *a, void *b),
             int option, int pos1, int pos2 )
{
    int last, i, n, r, f, d, k;
    char *s1 = (char *)malloc(LINESIZE * sizeof(char));
    char *s2 = (char *)malloc(LINESIZE * sizeof(char));

    if (left >= right)
        return;

    n = option%2;
    k = option/2;
    r = k%2;
    k = k/2;
    f = k%2;
    k = k/2;
    d = k%2;
    last = left;

    for (i=left+1; i<=right; i++){
        if (pos2==0)
            pos2 = LINESIZE;
        strcpy(s1, substr(v[i], pos1, pos2));
        printf("sort: s1 = %s\n", s1);
        strcpy(s2, substr(v[left], pos1, pos2));
        printf("sort: s2 = %s\n", s2);
        if (f){
            to_lower(s1);
            to_lower(s2);
        }
        if (d){
            to_alphanum(s1);
            to_alphanum(s2);
        }
        if ((*comp)(s1, s2)*(r ? -1 : 1) < 0 )//если r=0, сортировка desc
            swap (v, ++last, i);
        }
    swap (v, left, last);

    q_sort (v, left, last-1, comp, option, pos1, pos2);
    q_sort (v, last+1, right, comp, option, pos1, pos2);
}
void swap(void *v[], int a, int b)
{
    void *temp;

    temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

int numcmp(void *a, void *b)
{
    double x, y;

    x = atof(a);
    y = atof(b);

    if (x > y)
        return 1;
    else if (x == y)
        return 0;
    else if (x < y)
        return -1;
}
// test
/*void main ()
{
    char *a[] = {"&abc", "def", "+a", ">  zxy"};

    q_sort((void **)a, 0, 3, (int (*)(void*, void*))(strcmp), 15, 0, 0);

    for (int i=0; i<4; i++)
        printf(" %s ", (char *)a[i]);
}*/
