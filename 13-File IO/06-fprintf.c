#include<stdio.h>
#include<stdlib.h>

int main()
{
  FILE *fp;

  fp = fopen("file.txt", "w+");
  if(!fp)
  {
    return -1;
  }
  fprintf(fp, "%s %s %s %s %d", "hello", "my", "number", "is", 555);

  fclose(fp);
  return 0;
}