#include<stdio.h>

int main()
{
  FILE *filePointer;

  filePointer = fopen("file.txt", "w+");

  fputs("This is Germán Chrystan.", filePointer);
  fputs("I am happy to be here", filePointer);

  fclose(filePointer);

  return 0;
}