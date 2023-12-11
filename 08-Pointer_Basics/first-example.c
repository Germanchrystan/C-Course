#include<stdio.h>
#include<stddef.h>

int main(void) {
  int number = 0;
  int *pnumber = NULL;

  number = 10;
  printf("number's address: %p\n", &number);
  printf("number's value: %d\n\n", number);

  pnumber = &number; // Store the address of number in pnumber

  printf("pnumber's address: %p\n", (void*)&pnumber); // Output the address of pointer variable
  printf("pnumber's size: %zd bytes\n", sizeof(pnumber)); // Output the size
  printf("pnumber's value: %p\n", pnumber);
  printf("value pointed to: %d\n", *pnumber); // Value at the address

  return 0;
}