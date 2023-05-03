#include<stdio.h>
#include<string.h>

int main()
{
    char myString[] = "my string";
    char src[50], dest[50];
    
    // strlen
    printf("The length of this string is: %d", strlen(myString));
    // strcpy
    strcpy(src, "this is source", sizeof(src) - 1);
    strcpy(dest, "this is destination", sizeof(dest) - 1);
    // strcat
    char input[80];
    printf("Enter a string to be concatenated: ");
    scanf("%s", input);
    printf("\nThe string %s concatenated with %s is %s\n", myString, input, strcat(input, myString));
    // strncat
    strncat(dest, src, 15);
    printf("Final destination stirng : [%s]", dest);
    
    return 0;
}