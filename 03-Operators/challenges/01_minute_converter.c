#include<stdio.h>
/*
	In this challenge, you must create a C program that converts the number of minutes to days and years

	the program should ask the user to enter the number of minutes via the terminal

	The program should display as output the minutes and then its equivalent in years and days

	The program should create variables to store
	(all should be of type double)
	
	- minutes (int)
	- minutes in years
	- Years
	- Days
*/

int main()
{

	unsigned int minutes;
	const double minutesInYears = 525600;
	double years, days;

	printf("Please enter amount of minutes\n"); 
	scanf("%d", &minutes);

	days = (minutes / 60.0) / 24.0;
	years = days / 365;
	printf("\nThere are %.0f minutes in a year\n", minutesInYears);
	printf("You entered %u \n", minutes);
	printf("That is equivalent to %.2f days\n", days);
	printf("That equals to %.2f years\n", years);
	return 0;
}