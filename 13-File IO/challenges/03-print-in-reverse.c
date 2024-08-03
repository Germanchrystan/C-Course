#include<stdio.h>
/**
 * Write a program that will print the contents of a file in reverse order
 * 
 * use the fseek function to seek to the end of the file
 * use the ftell function to get the position of the file pointer
 * display as output the file in reverse order
 * 
 */

int main()
{
  FILE *fp = fopen("example.txt", "r");
  if (fp == NULL) return -1;

  fseek(fp, 0, SEEK_END);
  int cnt = ftell(fp);

  int i = 0;
  while (i < cnt)
  {
    i++;
    fseek(fp, -i, SEEK_END);
    printf("%c\n", fgetc(fp));
  }

  fclose(fp);
  return 0;
}