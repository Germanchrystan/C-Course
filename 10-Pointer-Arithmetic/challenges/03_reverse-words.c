#include<stdio.h>
#include<stdlib.h>
/*
Complete the function that accepts a string parameter,
and reverses each word in the string. All spaces in the string should be retained.
"This is an example!" ==> "sihT si na !elpmaxe"
*/
char* reverseWords(const char* text) 
{
  int textLen = 0;
  while(text[textLen] != '\0') textLen++;
  char *txet = malloc(sizeof(char) * textLen);

  for(int i = 0; i < textLen; i++)
  {
    int wordLen = i;
    while(text[wordLen] != ' ' && text[wordLen] != '\0') wordLen++;
    printf("%d\n", wordLen);
    for(int j = i; j < wordLen; j++)
    {
      txet[j] = text[i + wordLen - 1 - j];
    }
    if (wordLen >= textLen) {
      txet[textLen] = '\0';
      break;
    }
    else
    {
      txet[wordLen] = text[wordLen];
      i = wordLen;
    }
  }
  return txet;
}

int main(void)
{
  printf("%s\n", reverseWords("Hello world"));
  printf("%s\n", reverseWords("-`d=HF51 !\bh+ X.:'X !2h"));
}
