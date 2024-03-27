#include<stdlib>

struct date 
{
    int day;
    int year;
    int month;
}

struct time
{
    int hours;
    int minutes;
    int seconds;
}

struct dateAndTime
{
    struct date sdate;
    struct time stime;
}

int main()
{
    struct dateAndTime birthDate = { { 3, 9, 1990}; { 22, 35, 0} };

    return 0;
}

