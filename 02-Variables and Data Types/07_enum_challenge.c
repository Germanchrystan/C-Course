#include<stdio.h>

/**
 * In this challenge, you are to create a C program that defines an enum type and
 * use that type to display the values of some variables
 * 
 *  The program should create and enum type called Company
 * - Valid values for this type are GOOGLE, FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT.
 * 
 * The program should create three varaibles of the above enum type that are assigned values:
 *  XEROX, GOOGLE and EBAY
 * 
 * The program should display as output, the value of the three variables 
 * with each variable separated by a newline.
 * 
 * Correct output would be if XEROX, GOOGLE and EBAY variables are printed in that order:
 * 2
 * 0
 * 4
 */
int main()
{
    enum Company {
        GOOGLE, 
        FACEBOOK, 
        XEROX, 
        YAHOO, 
        EBAY, 
        MICROSOFT
    };

    enum Company xerox, google, ebay;
    xerox = XEROX;
    google = GOOGLE;
    ebay = EBAY;

    printf("%i\n%i\n%i\n", xerox, google, ebay);
    return 0;    
}