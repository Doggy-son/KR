#include <stdio.h>

#define IN 1 /*внутри слова*/
#define OUT 0 /*вне слова*/

/*подсчет символов, строк, и слов
(последовательность символов без пробелов, таб. и переноса стр.)*/

void main()
{
    int c, ns, nl, nw, state;
    state = OUT;
    ns = nl = nw = 0;

    while((c=getchar())!=EOF){
        ++ns;
        if (c=='\n')
            ++nl;
        if (c=='\n'||c=='\t'||c==' ')
            state = OUT;
        else if (state == OUT){
            state = IN;
            ++nw;
        }
    }

    printf("количество символов %d\n", ns);
    printf("количество строк %d\n", nl);
    printf("количество слов %d\n", nw);
}
