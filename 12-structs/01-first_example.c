#include <stdio.h>

struct date
{
  int month;
  int day;
  int year;
};

int main()
{

  struct date today;
  today.month = 3;
  today.day = 20;
  today.year = 2024;

  printf("Today's date is %i/%i/%i\n", today.month, today.day, today.year % 100);
}
