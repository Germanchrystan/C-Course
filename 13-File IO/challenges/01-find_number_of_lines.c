#include<stdlib.h>
#include<stdio.h>

/*
Write a program to find the total number of lines in a text file.

  - Create a file that contains some of text.
  - Open test file
  - Use the fgatc function to parse character in a file until tou get to the EOF
  - If EOF increment counter
  - Display as ouput the total number of line in the file.
*/

int main()
{
  int lineNum = 0;
  FILE *f = fopen("example.txt", "r");

  if (f == NULL)
  {
    printf("Failed to open file");
    return 1;
  }
  
  int fchar = fgetc(f);
  while(fchar != EOF)
  {
    if(fchar == '\n')
    {
      lineNum++;
    }

    fchar = fgetc(f);
  }
  lineNum++;

  printf("Number of lines %d\n", lineNum);

  close(f);
  return 0;
}