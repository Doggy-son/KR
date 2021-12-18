#define LINESIZE 1000 //максимальный размер строки

#define NUMBER 1 // сигнал что получено число
#define MATHSIN 's' // функция синуса
#define MATHPOW 'p' // возведение в степень
#define MATHEXP 'e' // экспонента
#define VARIABLE 'v' // значение переменной
#define SETVAR '=' // установить значение переменной
#define OPPLUS '+' // сложение
#define OPMINUS '-' // минус
#define OPMULT '*' // умножение
#define OPDIV '/' // деление
#define OPMOD '%' // остаток от деления
#define ERROR -1 // неправильный формат ввода
#define RESULT 'r' // показать ответ


/*сравнение 2 строк по первым n символам*/
int strcm(char s1[], char s2[], int n);
/*удаление пробелов и табуляций из строк*/
void strtrm(char s[]);
/*проверка записано ли в строку число с плавающей точкой*/
int isnum(char s[]);
/*копирование строки s1 в s2, c позиции from до to*/
void strcp(char s1[], char s2[], int from, int to);
/*превращает строку в число типа double*/
double stonum(char s[]);

/*функции управления стеком значений*/
void push(double);
double pop(void);
void clear(void);

/*инициализирует переменные*/
void varinit(void);
/*возвращает значение переменной*/
double getvar(char c);
/*меняет значение переменной*/
void setvar(char c, double x);

/*получение строки из воода*/
int getln(char s[]);

/*запись оператора / операнда в строку*/
int getop(char s[]);
