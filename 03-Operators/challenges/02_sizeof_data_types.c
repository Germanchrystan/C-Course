#include<stdio.h>

/**
 * In this challenge, you must create a C program that displays 
 * the byte size of basic data types supported in C.
 * - The output varies depending on the system
 * you are using to run the program
 
	Display the byte size of the following types
	- int
	- char
	- long
	- long long 
	- double
	- long double

	You can use the %zd format specifier to format each size

	Use the sizeof operator
 */

int main()
{	
	printf("The byte size of int is %zd\n", sizeof (int));
	printf("The byte size of char is %zd\n", sizeof (char));
	printf("The byte size of long is %zd\n", sizeof (long));
	printf("The byte size of long long is %zd\n", sizeof (long long));
	printf("The byte size of double is %zd\n", sizeof (double));
	printf("The byte size of long double is %zd\n", sizeof (long double));
	
	return 0;
}