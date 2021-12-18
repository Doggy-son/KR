#define NUMBER 1
#define MATH_POW 'p'
#define MATH_EXP 'e'
#define MATH_SIN 's'
#define VARIABLE 'v'
#define MAX_LENGTH 1000 /*максимальная длина строки*/

int getch(void);
void ungetch(int c);
double pop(void);
void push(double x);
int getop(char s[]);
int compare(char s1[], char s2[], int n);
