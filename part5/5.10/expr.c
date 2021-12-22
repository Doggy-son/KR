#include <stdio.h>
#include <ctype.h>
/*интерпретирует обратную польскую запись выражения из  командной  строки,
где операторы  и  операнды  представлены  отдельным аргументом*/
#define STACKSIZE 100
static int stack[STACKSIZE];
static int next = 0; // индекс последней свободной позиции в стеке
/*управление стеком операндов*/
void push(int x);
int pop(void);
/*переводит строку в число*/
int atoi(char *a, int *i);

int main(int argc, char *argv[])
{
  int c, r, x;

  while (--argc>0){

    c = *(++argv)[0]; // первый символ аргумента

    switch (c){
      case '+':
        push (pop() + pop());
        break;
      case '-':
        x = pop();
        push(pop() - x);
        break;
      case '*':
        push(pop()*pop());
        break;
      case '/':
        x = pop();
        if (x==0){
          printf("main: деление на 0\n");
          return -1;
        }
        push(pop()/x);
        break;
      default:
        r = atoi(argv[0], &x);
        if (r==-1){
          printf("main: неправильный аргумент\n");
          return -1;
        }
        else
          push(x);
        }
    }
  x = pop();
  printf("main: result = %d\n", x);
  return 0;
  }

int atoi(char *a, int *i)
{
  *i = 0;

  while (isdigit(*a)){
    *i = 10* *i + *a - '0';
    a++;
  }

  if (*a)
    return -1; //ошибка
  else
    return 0;
}

int pop(void)
{
  if (next > 0)
    return stack[--next];
  else {
    printf("pop: стек пуст\n");
    return -1;
  }
}

void push(int x)
{
  if (next < STACKSIZE)
    stack[next++] = x;
  else{
    printf("push: стек переполнен, невозможно записать %d\n", x);
  }
}
