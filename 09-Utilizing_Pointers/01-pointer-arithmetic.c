#include<stdio.h>
#include<stddef.h>

int main(void)
{
  long num1 = 0L;
  long num2 = 0L;
  long *pNum = NULL;

  pNum = &num1;
  *pNum = 2L; // Set num1 to 2
  ++num2; // Increment num2
  num2 += *pNum; // add num1 to num2

  pNum = &num2; // Get address of num2
  ++*pNum; // Incfrement num2 indirectly

  printf("num1 = %ld num2 = %ld *pNum = %ld *pnum + num2 = %ld\n", num1, num2, *pNum, *pNum + num2);

  return 0;
}