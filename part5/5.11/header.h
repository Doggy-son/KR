#define LINESIZE 1000 // максимальная длина строки
#define LINESCNT 100 // максимальное количество строк для сортировки

char *strpointers[LINESCNT]; // массив указателей на строки
char *alloc(long n);
int readlines(char *strpointers[], int maxlines);
void writelines(char *strpointers[], int nlines);
void q_sort(void *v[], int left, int right,
            int (*comp)(void *a, void *b), int option, int pos1, int pos2);
int numcmp(void *a, void *b);
void to_lower(char *s);
void to_alphanum(char *s);
char *substr(char *s, int pos1, int pos2);
