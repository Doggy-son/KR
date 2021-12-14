#include <stdio.h>
#define BUFFERSIZE 10

void uncomment(char from[], char to[]);
int getBuffer(char line[], int size);

int main()
{
    char inln[BUFFERSIZE];//буфер ввода
    char outln[BUFFERSIZE];//буфер с удаленными комментариями
    int len; //размер содержимого буфера
    len=0;

    while ( (len = getBuffer(inln, BUFFERSIZE-1)) != 0){
        printf ("%s", inln);
        uncomment(inln, outln);
        printf("%s", outln);
   }

    return 0;
}
  int getBuffer(char s[], int lim)
  {
      int c, i;

      for (i = 0; i < lim && (c = getchar()) != EOF; ++i)
          s[i] = c;
      s[i] = '\0';
      return i;
  }

void uncomment(char from[], char to[])
{
    int i, j, c, cf;
    cf = j = i = 0;

    while((c = from[i]) != '\0'){
        if (c=='\\'&&from[i+1]=='*'&&cf==0){
            cf = 0;
            ++i;
        }
        else if (from[i+1]=='\\'&&c=='*'&&cf==1){
            cf = 1;
            ++i;
        }
        else if(cf=0) {
            to[j] = from[i];
            ++j;
            ++i;
        }
    }
}
