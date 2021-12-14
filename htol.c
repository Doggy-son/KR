#include <stdio.h>
/*функция преобразует 16-ричную запись в десятичное число*/

unsigned long htol(char s[]);

void main()
{
    char s1[100] = "0x12";
    char s2[100] = "0X8374824FBC7887";

    printf("s1 = %ld\n", htol(s1));
    printf("s2 = %ld\n", htol(s2));
    
}
unsigned long htol(char s[])
{
    unsigned long k, n = 0;
    int i;

    if (s[0]!='0' || s[1]!='x'&&s[1]!='X'){
        printf("incorrect number - %s, failed on symbol %d\n", s, s[i]);
        return -1;
    }

    for(i=2;s[i]!='\0';++i){
        if( s[i]>='A' && s[i]<='F'){
            k = s[i] - 'A' + 10;
        }
        else if ( s[i]>='0' && s[i]<='9' ){
            k = s[i] - '0';
        }
        else {
            printf("incorrect number - %s, failed on symbol %d\n", s, s[i]);
            return -1;
        }
        n = 16*n + k;
        printf("part %ld\n", n); 
    }
    return n;
}
