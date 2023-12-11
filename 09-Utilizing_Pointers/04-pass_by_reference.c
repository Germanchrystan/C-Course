#include<stdio.h>

void swap(int *x, int *y)
{
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
  return;
}


int main()
{
  /* local variable definition */
  int a = 100;
  int b = 200;

  printf("Before swap, value of a: %d\n", a); // 100
  printf("Before swap, value of b: %d\n", b); // 200

  // calling a function to swap values
  swap(&a,&b);

  printf("After swap, value of a: %d\n", a); // 200
  printf("After swap, value of b: %d\n", b); // 100

  return 0;
}