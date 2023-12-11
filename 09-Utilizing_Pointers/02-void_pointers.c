#include<stdio.h>
#include<stddef.h>

int main(void)
{
  int i = 10;
  float f = 2.35;
  char ch = 'l';

  void *vPtr;

  vPtr = &i;
  printf("Value of i = %d\n", *(int *)vPtr);
  
  vPtr = &f;
  printf("Value of f = %.2f\n", *(float *)vPtr);

  vPtr = &ch;
  printf("Value of ch = %c\n", *(char *)vPtr);

  return 0;
}