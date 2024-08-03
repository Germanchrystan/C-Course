#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
/*
Write a program that converts all characters of a file to uppercase and write the results out to a temporary file.
Then rename the temporary file to the original filename, and remove the temporary filename.

- use fgetc and fputc
- use the rename and remove functions

- use the islower function
- can convert a character to upper case by subtracting 32 from it.
*/

int main()
{
  FILE *f = fopen("example.txt", "r");
  FILE *temp = fopen("temp.txt", "w+");
  
  if (f == NULL)
  {
    printf("Failed to open file");
    return -1;
  }

  int fchar;
  while((fchar = fgetc(f)) != EOF)
  {
    if (islower(fchar))
    {
      fchar -= 32;
    }
    fputc(fchar, temp);
  }
  fclose(f);
  fclose(temp);

  remove("example.txt");
  rename("temp.txt", "example.txt");
  
  return 0;
}

