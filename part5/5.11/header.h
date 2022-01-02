#define LINESIZE 1000 // максимальная длина строки
#define LINESCNT 100 // максимальное количество строк для сортировки

char *strpointers[LINESCNT]; // массив указателей на строки
char *alloc(long n);
int readlines(char *strpointers[], int maxlines);
void writelines(char *strpointers[], int nlines);
void q_sort(void *v[], int left, int right, int (*comp)(void *a, void *b), char a[5]);
int numcmp(void *a, void *b);
