#include <stdio.h>
#include <string.h>
/*переводит целое n в  строку s,
 представляющую число по основанию b*/

 int itob(int n, int b, char s[]);
 void reverse(char s[]);

 void main()
 {
    int n = 1383;
    char s[100];
    
    itob(n, 16, s);
    printf("%s\n", s);
 }
 int itob(int n, int b, char s[])
 {
    char digits[38] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i=0, k, sign;

    if (b>36){
       printf("Base is too big");
       return -1;
    }

    if (n < 0){
      sign = -1;
      n = -n;
   }

    do {
      k = n%b;
      s[i++] = digits[k];
    }
    while ((n/=b) != 0);

   if (sign==-1)
      s[i++] = '-';
   
   s[i] = '\0';
   reverse(s);

   return 0;
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