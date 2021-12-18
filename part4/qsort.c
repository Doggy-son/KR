#include <stdio.h>
/*быстрая сортировка с использованием рекурсии
сортирует v[left]..v[right] по возрастанию*/
#define DEBUG 1

void qsort(int v[], int left, int right)
{
  int i, last;
  void swap(int v[], int i, int j); // объявление функции

  if (left >= right)
    return;

  swap(v, left, (left + right)/2); // элемент из середины переносится в начало
  last = left;
  for (i=left+1; i<=right; i++){
    if (v[i] < v[last])
      swap(v, last, i);
      last = i;
    }
    
  qsort(v, left, last-1);
  qsort(v, last+1, right);
}
/*поменять местами v[i] и v[j]*/
void swap(int v[], int i, int j) //определение функции
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
void main(void)
{
  int i;
  int v[10] = {-1, 4, 9, -23, 15, 2, -10, -11, 9, 0};

  qsort(v, 0, 9);
  for (i=0; i<10; i++)
    printf("%d = %d\n", i, v[i]);
}
