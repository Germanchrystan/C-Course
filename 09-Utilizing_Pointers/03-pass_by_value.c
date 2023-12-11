#include<stdio.h>

void swap(int x, int y)
{
  int temp;

  temp = x; // save the value of x
  x = y; // put y into x
  y = temp; // put temp into y

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
  swap(a,b);

  printf("After swap, value of a: %d\n", a); // 100
  printf("After swap, value of b: %d\n", b); // 200

  return 0;
}