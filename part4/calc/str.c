#include "common.h"
#include <stdio.h>

/*функция сравнивает первые n символов в строках*/
int compare(char s1[], char s2[], int n)
{
  int i;

  for (i=0; s1[i]!='\0' && s2[i]!='\0' && i<n; i++){
    if (s1[i]!=s2[i])
      break;
  }

  if (i<n)
    return 0; //false
  return 1;
}
/*void main()
{
  char s1[MAX_LENGTH] = "abc123";
  char s2[MAX_LENGTH] = "abcdef";

  if(compare(s1, s2, 3))
    printf("первые %d символов совпадают\n", 3);

  if(!compare(s1, s2, 5))
    printf("первые %d символов не совпадают\n", 5);

}
*/
