#include <stdio.h>

int main()
{
  int a = 15;
  void *ptr = (int *)&a;
  printf("%d", *(int *)ptr);
  int b[5] = {1, 2, 3, 4, 5};
  int *p = b;
  printf("%d\t%d\t%d\t%d\t", *p, b[0], b, p);


  return 0;
}





