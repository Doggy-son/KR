#include <stdio.h>
/*переводит большие буквы в малые*/

void lower(char s[]);

int main()
{
    char s[100] = "ABCdef232io";
    char s2[100];

    printf("%s - ", s);
    lower(s);
    printf("%s\n", s);
}
void lower(char s[])
{
    int i;

    for (i=0; s[i]!='\0'; ++i)
        s[i]>='A'&&s[i]<='Z' ? s[i]+='a'-'A' : 1;
}
