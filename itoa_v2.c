#include <stdio.h>
#include <string.h>
/*версия itoa с дополнительным аргументом, 
задающим минимальную ширину поля*/

void itoa(int x, char s[], int w);
void reverse(char s[]);

void main()
{
    int n = 5129867;
    char s[13];

    itoa(n, s, 10);
    printf("%s\n", s);

    n=-32589987;
    itoa(n, s, 12);
    printf("%s\n", s);
}

void itoa(int x, char s[], int w)
{
    int i=0, sign;

    if (x<0){
        sign = -1;
        x = -x;
    }  

    do {
        s[i++] = x%10 + '0';
    }
    while ((x/=10)!=0);

    if (sign == -1)
        s[i++] = '-';

    while (i<w)
        s[i++] = ' ';

    s[i] = '\0';    
    reverse(s);
}
void reverse(char s[])
 {
    int i, temp, len;
    len = strlen(s);    

    for(i=0; i<len/2; i++){
      temp = s[i];
      s[i] = s[len-i-1];
      s[len-1-i] = temp;
    }
 }