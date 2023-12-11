#include<stdio.h>
#include<stddef.h>

/**
 * Write a program that creates an integer variable with a hard coded value. 
 * Assign that variables address to a pointer variables.
 * 
 * Display as output:
 * - the address of the pointer,
 * - the value of the pointer,
 * - and the value of what the pointer is pointing to.
*/

int main(void)
{
  int myNum = 4;
  int *pMyNum = NULL;

  pMyNum = &myNum;

  printf("Address of the pointer: %p\n", &pMyNum);
  printf("Value of the poiner: %p\n",pMyNum);
  printf("Address of myNum: %p\n", &myNum);
  printf("Value of what the pointer is pointing to: %i\n", *pMyNum); 
}