#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STRLEN 15
/**
 * Write a C program that creates a structure pointer and passes it to a funtion
 * Create a structure named item with the following members
 * - itemName - pointer
 * - quantity - int
 * - price - float
 * - amount -float (stores quantity * price)
 * 
 * Create a function named readItem that takes a structure pointer of type item as a parameter.
 *  - This function should read in (from the user) a product name, price and quantity.
 *  - The contents read in should be stroed in the passed in structure to the function
 * 
 * Create a function name print item that takes as a parameter a structure pointer of type item
 * - function prints the contents of the parameter
 * 
 * the main function should declare an item and a pointer to the item.
 * - you will need to allocate memory for the itemName pointer
 * - the item pointer should be passed into both the read and print item functions.
*/

struct item
{
  char * itemName;
  int quantity;
  float price;
  float amount;
};

void readItem(struct item * i);
void printItem(struct item * i);

int main()
{
  struct item newItem;
  struct item * itemPtr;
  itemPtr = &newItem;

  readItem(itemPtr);
  printItem(itemPtr);
  return 0;
}

void readItem(struct item * i)
{
  char temp[STRLEN];
  printf("Ingrese nombre del producto: ");
  fgets(temp, STRLEN, stdin);

  i->itemName = (char *)malloc(strlen(temp) + 1);
  strcpy(i->itemName, temp);
  
  printf("Ingrese costo del producto: ");
  scanf("%f", &i->price);

  printf("Ingrese cantidad del item: ");
  scanf("%i", &i->quantity);
  i->amount = i->quantity * i->price;
}

void printItem(struct item * i)
{
  printf("item name: %s\nquantity: %i\nprice: %.2f\namount: %.2f\n", i->itemName, i->quantity, i->price, i->amount);
}