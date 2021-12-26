#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//функция использует библиотечные функции atoi, getline

#define LINESIZE 100
#define TABSIZE 4

/*detab - заменяет tab на пробелы. до ближайшего стопа*/
void detab (char *s, int *stops, int size_stops, long size_s);
/*entab - заменяет пробелы на tab, если они пересекают стоп*/
void entab (char *s, int *stops, int size_stops, long size_s);
/*инициализирует массив стопов*/
void setstops (int argc, char *argv[], int *stops);

void main(int argc, char *argv[])
{
    char *s; // для хранения строк из ввода
    int stops[argc-1]; //для хранения стопов
    size_t ssize = LINESIZE;
    s = (char *)malloc(LINESIZE * sizeof(char));
    long len_s;
    int i = 0;

    setstops (argc, argv, stops);
    while (i < (argc-1)){
        printf("main : stops = %d \n", *(stops+i));
        i++;
    }

    while((len_s = getline(&s, &ssize, stdin)) != -1){
        printf("main: get line s = %s, len_s = %ld\n", s, len_s);
        detab(s, stops, argc-1, len_s);
        entab(s, stops, argc-1, len_s);
    }
}
/*ищет соседа справа для x в отсортированном массиве*/
int search_next (int x, int v[], int size);

void entab(char *s, int *stops, int size_stops, long size_s)
{
    int i, point, j = 0, st, nsps = 0;
    char t[LINESIZE];

    for(i=0; i<size_s; i++){
        point = i; // место, с которого начинаются пробелы
        while (s[i]=='\t' || s[i]==' '){ // в цикле считаем кол. табуляций*4 + кол. пробелов подряд
            nsps = nsps + (s[i]=='\t')*TABSIZE + (s[i]==' ');
            i++;
        }
        while (nsps<TABSIZE && nsps-->0){ //просто записываем пробелы, если их < 4
            t[j++] = ' ';
        }
        if (nsps > 0){
            st = stops[search_next(point+nsps, stops, size_stops)] - point + 1;//расстояние до ближайшего стопа
            while (st>=TABSIZE){
                t[j++] = '\t';
                st-=TABSIZE;
            }
            while (st>0){
                t[j++] = ' ';
                st--;
            }
        }
        t[j++] = s[i];
        nsps = 0;
    }
    t[j] = '\0';

    printf("entab: entabbed s = %s\n", t);
}
void detab (char *s, int *stops, int size_stops, long size_s)
{
    int i, j = 0, st;
    char t[LINESIZE];

    for(i=0; i<size_s; i++){
        if (s[i] == '\t'){
            st = stops[search_next(i, stops, size_stops)];
            printf("detab: meet tab on pos %d, next stop on %d\n", i, st);
            for (st = st-i; st>=0; st--)
                t[j++] = ' ';
            continue;
        }
        t[j++] = s[i];
    }
    t[j] = '\0';

    printf("detab: detabbed s = %s\n", t);
}
int search_next (int x, int v[], int size)
{
    int i = 0;

    while (i < size){
        if (v[i] >= x)
            return i;
        i++;
    }
    return -1;
}

/*сортировка массива */
void insertion_sort(int *v, int size);
void swap(int i, int j, int *v);

void setstops(int argc, char *argv[], int *stops)
{
    int size = argc - 1;
    int *begin = stops;

    while (--argc > 0)
    {
        *(stops++) = atoi(*(++argv));
    }
    /*сортировка массива*/
    insertion_sort(begin, size);
}
void insertion_sort(int *v, int size)
{
    int i, j, temp;

    for (i=1; i<size; i++){
        for (j=0; j<i; j++)
            if (*(v+i) < *(v+j)){
                while (j<=i)
                    swap(i, j++, v);
                break;
            }
        }
}
void swap(int i, int j, int *v)
{
    int temp;

    temp = *(v+i);
    *(v+i) = *(v+j);
    *(v+j) = temp;
}
