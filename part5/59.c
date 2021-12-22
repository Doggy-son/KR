#include <stdio.h>

static int non_leap[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static int leap[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static int *daytab[2] = {non_leap, leap};

/*определяет номер дня в году*/
int day_of_year(int year, int month, int day)
{
  int leap, i;

  leap = year%4 == 0 && year%100 !=0 || year%400 == 0;

  if (month<1 || month>12 || day<1 || day> *(daytab[leap] + month)){
    printf("day_of_year: некорректные данные\n");
    return -1;
  }

  for (--month; month>0; month--)
    day += *(daytab[leap] + month);

  return day;
}
/*определяет число и месяц по году и номеру дня в году*/
int month_day(int year, int yearday, int *pmonth, int *pday)
{
  int i = 0, leap;

  leap = year%4 == 0 && year%100 !=0 || year%400 == 0;

  if (yearday < 1 || yearday > (leap+365)){
    printf("month_day : некорректные данные\n");
    return -1;
  }

  for (i=1; i<= 12 && yearday > *(daytab[leap] + i); i++){
    yearday = yearday - *(daytab[leap] + i);
  }

  *pmonth = i;
  *pday = yearday;

  return 0;
}
void main()
{
  int m;
  int d;
  int res;

  int a = day_of_year(2020, 5, 30);
  printf("%d\n", a);

  res = month_day(2021, 350, &m, &d);
  printf("%d, %d\n", m, d);
}
