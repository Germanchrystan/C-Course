#include <stdio.h>
/**
 * Write a program that declares a structure and 
 * prints out it's content
 * 
 * create an employee structure with 3 members
 * - id(int)
 * - name (character array)
 * - salary (float)
 * 
 * declare and initialize an instance of an employee type
 * 
 * read in a second employee from the console and store it
 * in a structure of type employee
 * 
 * print out the contents of each employee
*/
struct employee
{
  int id;
  char name[10];
  float salary;
};

int main()
{
  struct employee employee1 = { .name = "Juan", .id = 10, .salary = 1500};
  struct employee employee2;
  printf("Enter id: ");
  scanf("%i", &employee2.id);
  printf("Enter name of new employee: ");
  scanf("%s", employee2.name);
  printf("Enter salary: ");
  scanf("%f", &employee2.salary);

  printf("Employee 1\nId: %i. name: %s. Salary: %.2f\n", employee1.id, employee1.name, employee1.salary);
  printf("Employee 2\nId: %i. name: %s. Salary: %.2f\n", employee2.id, employee2.name, employee2.salary);
}
