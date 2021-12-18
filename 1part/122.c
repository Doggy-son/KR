#include <stdio.h>
/*функция переносит строку. если ее длина > n,
когда возможно, перенос проходит по символу-разделителю*/

#define LENGTH 10 /*ширина, к которой нужно привести строки*/
#define MAXLINE 1000 /*ограничения на длину строк*/

int split_line(char source[], char dest[], int idx);/*в dest записывается отрезок строки source до idx,*/
                                                    /*оставшаяся в source часть сдвигается, возвращает конечную длину source*/
int main()
{
    int c;    
    char tmp_line[MAXLINE];
    char ready_line[MAXLINE];
    int idx, i;

    idx = i = 0;

    while((c=getchar())!=EOF)
    {
        tmp_line[i] = c;

        if (c==' '||c=='\t')
            idx = i;

        if (c=='\n'){
            tmp_line[i+1] = '\0';
            printf("%s", tmp_line);
            i = idx = 0;
        }
        else {
            ++i;
        }

        if (i>=LENGTH-2){
            tmp_line[i+1] = '\0';
            i = split_line(tmp_line, ready_line, idx);
            printf("%s", ready_line);
            idx = 0;
        }
    }
    return 0;
}
int split_line(char left[], char right[], int length)
{
    int i;
    i=0;

    if (length==0){
        while ((right[i]=left[i])!='\0')
            ++i;
    }
    else{
        for(i=0;i<length;++i)
            right[i] = left[i];
        right[length] = '\n';
        right[length+1] = '\0';

        i = 0;
        while((left[i]=left[i+length+1])!='\0')
            ++i;        
    }
    return --i;    
}