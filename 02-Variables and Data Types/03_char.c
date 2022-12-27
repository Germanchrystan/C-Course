#include<stdio.h>

int main(void)
{
    char myChar;
    myChar = 'g';
    // char can also contain scape characters
    char newLine = '\n';

    printf("%c%c%c",newLine, myChar, newLine);

    return 0;
}