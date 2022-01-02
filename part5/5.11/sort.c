#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(void *v[], int a, int b);

/*функция сортирует массив*/
void q_sort (void *v[], int left, int right, int (*comp)(void *a, void *b), char a[5])
{
    int last, i, asc;

    if (left >= right)
        return;

    if (strcmp(a, "desc") == 0)
        asc = -1;
    else
        asc = 1; // по умолчанию сортировка в порядке возрастания

    swap (v, left, (left+right)/2);
    last = left;

    for (i=left+1; i<=right; i++)
        if ((*comp)(v[i], v[left])*asc < 0 )
            swap (v, ++last, i);
    swap (v, left, last);


    q_sort (v, left, last-1, comp, a);
    q_sort (v, last+1, right, comp, a);
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
    char *a[] = {"abc", "def", "a", "zxy"};

    q_sort((void **)a, 0, 3, (int (*)(void*, void*))(strcmp), "desc");

    for (int i=0; i<4; i++)
        printf(" %s ", (char *)a[i]);
}
*/
