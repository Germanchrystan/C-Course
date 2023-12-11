#include <stdlib.h>
#include<stdio.h>

char* reverseString(const char* text) 
{
  int textLen = 0;
  while(text[textLen] != '\0') textLen++;
  char *txet = malloc(sizeof(char) * textLen);

  for(int i = 0; i < textLen; i++)
  {
    txet[i] = text[textLen - i - 1];
  }
  return txet;
}

int main(void)
{
  printf("%s\n", reverseString("Hello!"));
}