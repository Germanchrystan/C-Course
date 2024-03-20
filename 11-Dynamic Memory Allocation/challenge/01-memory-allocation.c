#include<stdlib.h>
#include<string.h>
#include<stdio.h>
  /**
  In this challenge, we should write a program that allows a user to input a text string.
  The program will print the text that was inputted. The program will utilize dynamic memory allocation.

  The user can enter the limit of the string they are entering. You can use this limit when involing malloc.

  The progrma should create a char pointer only, no character arrays.

  Be sure yo release the memory that was allocated
  */
int main()
{
  char *str;
  int length;

  printf("Input the length of the string: ");
  scanf("%i", &length);

  str = (char *)malloc(sizeof(char) * length);
  if (str != NULL) 
  {
    printf("Input the string: ");
    /*
    We could use this
    // scanf("%s", str);

    but using scanf/gets
    allows scanf to read in the next character, and then fgets reads
    from the standard input stream, which by default is the keyboard.

    fgets is going to take a pointer.
    This function also allows to read a string with spaces

    NOTE: Don't use gets, it is deprecated.
    */
    scanf(" ");
    fgets(str, sizeof(str) * length, stdin);
    printf("You inputted %s\n", str);
  }

  free(str);
  str = NULL;
  return 0;
}