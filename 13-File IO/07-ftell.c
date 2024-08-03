#include<stdio.h>
#include<stdlib.h>

int main()
{
  FILE *fp;
  int len;
  fp = fopen("file.txt", "r");
  if(fp == NULL)
  {
    perror("ERROR opening file");
    return -1;
  }
  fseek(fp, 0, SEEK_END);
  len = ftell(fp);
  fclose(fp);

  printf("Total size fo file.txt = %d bytes\n", len);
  return 0;
}