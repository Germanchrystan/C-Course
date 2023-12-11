#include<stdio.h>
/**
 * In this challenge, you are going to write a program that tests your understanding 
 * of pass by reference
 * 
 * Write a function that squares a number by itself. 
 * The function should define as a parameter an int pointer. 
*/

void squareInt(int * num)
{
  *num = *num * *num;
}

int main(void)
{
  int num = 2;
  printf("num's value is %d\n", num);
  squareInt(&num);
  printf("num's value is %d\n", num);
}