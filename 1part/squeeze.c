#include <stdio.h>
/*удаляет из строки s1 все символы, встречающиеся в s2*/

void squeeze(char s1[], char s2[]);

void main()
{
    char s1[100] = "aabbccddeeff";
    char s2[100] = "aae";

    squeeze(s1, s2);
    printf("s1 -> %s\n", s1);
}
void squeeze(char s1[], char s2[])
{
    int i, j, k, flg;
    flg = j = 0;

    for(i=0;s1[i]!='\0';++i){

        for(k=0;s2[k]!='\0';++k){
            if (s1[i]==s2[k])
                flg = 1;
        }

        if (flg == 0 )
            s1[j++] = s1[i];
        
        flg = 0;
    }

    s1[j] = '\0';
}

