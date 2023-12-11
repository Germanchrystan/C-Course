#include<stdio.h>
#include<stdlib.h>
/*
  Write a function that calculates the length of a string.
  The function should take as a parameter a const char pointer.
  the function can only determinethe length of the string using pointer arithmetic
  the function should return an int.
*/

int stringLength(char *str);
int stringLengthAlt(char *str)

int main(void)
{
  char str[] = "Hello world";
  printf("%d\n", stringLength(str));
  
  return 0;
}

int stringLength(char *str)
{
  int length = 0;
  for(int i = 0; str[i] != '\0'; i++)
  {
    length++;
  }
  return length;
}

// Other solution provided
int stringLengthAlt(char *str)
{
  const char *lastAddress = str;

  while(*lastAddress) // Checking if lastAddress is not the null terminator
   ++lastAddress;
  
  return lastAddress - str; // subtraccion between last and first position
}