#include<stdio.h>

int main(void)
{
    printf("The character \0 is used to terminate a string");
    return 0;
}

/**
 * If you compile the program and run it, you'll get this output:
 * - The character
 * Only the first part of the string has been displayed.
 * Output ends after the first two words because the function stops outputting the string when it reaches the first null character.
 * The second \0 at the end of the string will never be reached.
*/