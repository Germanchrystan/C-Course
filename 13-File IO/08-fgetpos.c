#include<stdio.h>
#include<stdlib.h>

int main()
{
  FILE *fp;
  fpos_t position;
  fp = fopen("file.txt", "w+");
  fgetpos(fp, &position);
  fputs("Hello, World!", fp);

  fclose(fp);

  return 0;
}