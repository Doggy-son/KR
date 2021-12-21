#define MAXLEN 1000 // максимальная длина строки
#define MAXLINESCNT 100 // максимальное количество строк для сортировки

char *strpointers[MAXLINESCNT]; // массив указателей на строки

/*записывает указатели на строки из ввода в сортируемый массив,
возвращает количсетво строк < maxlines*/
int readlines(char *strpointers[], int maxlines);
/*сортировка Шелла для массива строк*/
void sort(char *v[], int left, int right);
/*writelines выводит отсортированный массив в консоль*/
void writelines(char *strpointers[], int nlines);
