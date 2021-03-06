#include <stdio.h>

static char daytab[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                             {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

/*определяет номер дня в году*/
int day_of_year(int year, int month, int day)
{
  int leap, i;

  leap = year%4 == 0 && year%100 !=0 || year%400 == 0;

  if (month<1 || month>12 || day<1 || day>daytab[leap][month])
    return -1;

  for (--month;month>0; month--)
    day += daytab[leap][month];

  return day;
}
/*определяет число и месяц по году и номеру дня в году*/
int month_day(int year, int yearday, int *pmonth, int *pday)
{
  int i = 0, leap;

  leap = year%4 == 0 && year%100 !=0 || year%400 == 0;

  if (yearday < 1 || yearday > (leap+365))
    return -1;

  for (i=1; i<= 12 && yearday > daytab[leap][i]; i++){
    yearday = yearday - daytab[leap][i];
  }

  *pmonth = i;
  *pday = yearday;

  return 0;
}
char *get_month_name(int n)
{
  static char *month_name[] = {
                                 "NoName", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                 "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
                            };

  return (n<1 || n>12) ? month_name[0] : month_name[n];
}
void main()
{
  printf("%s, %s\n", get_month_name(-9), get_month_name(5));
}
