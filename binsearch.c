#include <stdio.h>
/*бинарный поиск в отсортированном массиве*/

int binsearch(int x, int v[], int n);

void main()
{
    int v[10];
    int i, k;

    for (i=0;i<10;++i)
        v[i] = i*i + 5*i +6;
    
    for (i=0;i<10;++i)
        printf("%d ", v[i]);
    
    k = binsearch(42, v, 10);
    printf("%d - %d\n", k, v[k]);

    k = binsearch(13, v, 10);
    printf("%d - %d\n", k, v[k]);

}
/*int binsearch(int x, int v[], int n)
{
    int i, lower, upper;
    lower=0;
    upper=n-1;
    i=(n-1)/2;

    while (lower <= upper){
        if (v[i]==x)
            return i;
        else if (v[i]>x){
            upper=i-1;
            i=(upper+lower)/2;        
        }
        else if (v[i]<x){
            lower = i+1;
            i=(upper+lower)/2;
        }
    }
    return -1;
}*/
int binsearch(int x, int v[], int n)
{
    int i, lower, upper;
    lower = 0;
    upper = n-1;
    i = (lower+upper)/2;

    while(lower<=upper && x!=v[i]){
        if (v[i]>x)
            upper = i-1;
        else
            lower = i+1;
        i = (upper+lower)/2;
    }

    if (x==v[i])
        return i;
    
    return -1;
}