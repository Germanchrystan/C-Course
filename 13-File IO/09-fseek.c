#include<stdio.h>

int main()
{
  FILE *fp;

  fp = fopen("file.txt", "w+");
  fputs("This is German", fp);

  fseek(fp, 7, SEEK_SET);
  fputs(" Hello how are you", fp);
  fclose(fp);

  return 0;
}