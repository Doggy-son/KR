#include <stdio.h>
/*возвращает индекс первого символа из s1, встречающегося в s2, либо -1*/

int any(char s1[], char s2[]);

void main()
{
    char s1[100] = "aabcefferg8kjdksaf";
    char s2[100] = "8";
    char s3[100] = "ab";

    printf("%d\n", any(s1, s2));
    printf("%d\n", any(s1, s3));
    printf("%d\n", any(s2, s3));
}
int any(char s1[], char s2[])
{
    int i, k;

    for(i=0;s1[i]!='\0';i++){
        for(k=0;s2[k]!='\0';k++){
            if(s1[i]==s2[k])
                return i;
        }
    }

    return -1;
}