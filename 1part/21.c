#include <limits.h>
#include <stdio.h>
#include <float.h>

float pow_(float a, int b);
void float_check();

void main()
{
    char ch_min, ch_max;
    unsigned char uch_max;
    short sh_min, sh_max;
    int i_min, i_max;
    long l1, l2;
    float min, max, zero;

    /*printf("диапазон char : %d - %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("диапазон short : %d - %d\n", SHRT_MIN, SHRT_MAX);
    printf("диапазон int : %d - %d\n", INT_MIN, INT_MAX);
    printf("диапазон long : %ld - %ld\n", LONG_MIN, LONG_MAX);

    ch_max = (1<<7);
    ch_min = ch_min + 1;
    printf("диапазон char : %d - %d\n", ch_min + 1, ch_max);
    uch_max = ~0;
    printf("диапазон uchar : %d - %d\n", 0, uch_max);*/

    zero = 0;
    max = (pow_(FLT_RADIX, FLT_MANT_DIG) - 1)*pow_(FLT_RADIX, FLT_DIG);

   printf("%f, %f, %f", FLT_MIN, FLT_MAX, max);
  /*  printf("%d, %d, %d", FLT_RADIX, FLT_DIG, FLT_MANT_DIG);
    */

   float_check();

}
float pow_(float a, int b)
{
    int i;
    float res;
    res = 1.0;

    for (i=0; i<b; ++i)
        res *= a;

    return res;

}
void float_check()
{
    float x;

    for (x = 1; x > x/2; x *= 2 ) {
          printf("%e\n", x);
      }
}