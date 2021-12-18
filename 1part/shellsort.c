#include <stdio.h>
/*сортировка методом Шелла*/

void shellsort(int v[], int n);

void main()
{
    int i, n=100;
    int v[n];

    for (i=0; i<n; ++i)
        v[i] = -(i-6)*(i-17)*(i-25)*(i-39)*(i-67)*(i-98);
    for (i=0; i<n; ++i){
        printf("%10d ", v[i]);
        if (i%10==9)
            printf("\n");    
    }

    shellsort(v, n);

    printf("\n\nSorted array: \n\n");

    for (i=0; i<n; ++i){
        printf("%10d ", v[i]);
        if (i%10==9)
            printf("\n");    
    }
}
void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap=n/2; gap>0; gap/=2){
        for (i=gap; i<n; i++){
            for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap){
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
        }
    }
}