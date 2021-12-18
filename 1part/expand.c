#include <stdio.h>
#include <string.h>
#include <ctype.h>
/*заменяет сокращенную запись наподобие a-z в строке s1
эквивалентной полной записью abc. . . xyz в s2*/
void expand(char s1[], char s2[]);

void main()
{
    char s1[100] = "A-B-C111ddda-z0-9000-a-b";
    char s2[200];

    expand(s1, s2);
    printf("s1=%s -> s2=%s\n", s1, s2);
}
void expand(char s1[], char s2[])
{
    int i, j, k;
    int len = strlen(s1);
    j=0;

    for(i=0; i<len; i++){
        if (s1[i]=='-'
            &&(i!=0)
            &&(i<len-1)
            &&(
                isdigit(s1[i-1])&&isdigit(s1[i+1])
                ||islower(s1[i-1])&&islower(s1[i+1]) 
                ||isupper(s1[i-1])&&isupper(s1[i+1]) 
                )
            &&s1[i+1]>s1[i-1]
        ){
            for (k=s1[i-1] + 1; k<s1[i+1]; ++k)
                s2[j++] = k;
        }
        else {
            s2[j++] = s1[i];
        }
    }
    s2[j] = '\0';
}