/*выделяет n ячеек в памяти */
char *alloc(int n);
/*освобождает буфер до позиции p*/
void afree(char *p);
/*функция читает строку из ввода*/
int getln(char *s, int maxlen);
/*функция копирует t в s*/
void strcpn(char *s, char *t);
