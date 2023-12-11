# Pointers
Pointer are very similar to the concept of indirection.
In programming langauges, indirection is the ability to reference something using a name, reference or containwr, instead of the value itself.
The most commmon form of indirection is the ct o manipulating a value through its memory address.
A pointer provides an indirect means of accesing the value of a particular data item.
- a variable whose value is a memory address
- its value is the address of another location in memory that can contain a value.

Using pointer in tour program is one of the most powerful tools available in the C language.


The compiler must know the type of data stored in the variable to which it points.
- Need to know how much memory is occupied or how to handle the contents of the memory to which it points.
- every pointer will be associated with a specific variable type.
- it can be used only to point to variables of that type.

pointers of type "pointer to int" can point only to variables of type int.
pointers of type "pointer to float" can point only to variables of type float.

## Why use pointers
Accesing data by means of only variables is very limiting. With pointer e cqan access any location, and perform arithmetic with pointers.
- Pointers in C make it easier to use arrays and strings. 
- They allow us to refer to the same space in memory from multiple locations. This means that we can update memory in one location and the cange can be seen from another location in our program. They can also save space by being able to share components in our data structures.
- Pointers allow functions to modify data passed to them as variables. Pass by reference: passing arguments to function in way they can be changed by the function.
- can also be used to optimize a program to run faster or use less memory than it would be otherwise.
- pointers allow us to get multiple values from the functions.
- with pointers dynamic memory can be created according to the program use. We can save memory from static (compile time) declarations.
- they allow us to design and develop complex data structures like a stack, wueue, or linked list.
- they provide direct memory access.

## Declaring pointers

~~~c
int *pnumber;
~~~

The type of the variable with the name pnumber is int*. It can store the address of any variable of type int.

~~~c
int * pi; // pi is a pointer to an integer variable
char * pc; // pc is  pointer to a characger variable
float * pf, * pg; // pf, pg are pointers to float variables
~~~

The space between the * and the pointer name is optional.  Programmers use the space in a declaration and omit it when dereferencing a variable.

The value of a pointer is an address, and it is represented internally ad an unsigned integer on most systems. However, we should not think of a pointer an an integer type. There are thing we can do with integers that we can not do with pointers, and vice versa. For instance, we can multiply one integer by another, but we can not multiply one pointer  by another.

- A pointer really is a new type, not an integer type.

- `%p` represents the formaat specifier for pointers

The previous declarations creates the variable but does not initialize it. It is dangerous to no initialize pointer variables. The pointer variables should always be initialized when declared.

We can initialize a pointer so that it does not point to anything.

~~~c
int *pnumber = NULL;
~~~

`NULL` is a constant that is defined in the standard library. It is the equivalent of zero for a pointer.
It is a value that is guranteed not to point to any location in memory. It means that it implicitly prevents the accidental overwriting of memory by using a pointer that does not point to anything specific.

We need to add and `#include` directive for `stddef.h` in the source file.

## Address of operator
If you want to initialize your variable with the address of a variable you have already declared use the address of operator `&`.

~~~c
int number = 99;
int *pnumber; &number; 
~~~

The intiial value of pnumber is the address of the variable number. The declaration of number must precede the decoaration of the pointer that stores its address.
The compiler must have already allocated space and thus an address for number to use it to initialize pnumber.

## Declaring pointers and variables
There is nothing special about the declaration of a pointer. We can declare regular variables and pointers in the same statement.

~~~c
double value; *pVal, fnum; // Only the second variable is a pointer
int *p, q; // only the first variable is a pointer
~~~

It is a good ideo to use names beginning with p as pointer names.


## Accesing pointer values
We use the indirection operator `*` to access the value of the variable poionter to by a pointer. Alse, referred to as the dereference operator because we use it to "dereference" a pointer.

~~~c
int number = 15;
int *pointer = &number; // The pointer variable contains the address of the variable number
int result = 0;

result = *pointer + 5; // dereferencing pointer to calculate result.
~~~

The indirection operator * is also the symbol for multiplication, and it is used to specify pointer types.
- Depending on where the asterisk appears, the compiler will understand whether it should interpret it as an indirection operator, a a multiplication sign, or as part of a type specification.
- Context determines what it means in any instance.

~~~c
int main(void) {
  int count = 10, x;
  int *int_pointer;

  int_pointer = &count;
  x = *int_pointer;

  printf("counter = %i, x = %i\n", count, x);
  return 0;
}
~~~

## Displaying a pointers value
To output the address of a variable, you use the output format specifier `%p`. It outputs a pointer value as a memory address in hexadecimal form.

~~~c
int number = 0;
int *pnumber = NULL;

number = 10;
pnumber = &number;
printf("pnumber's value: %p\n", pnumber);
~~~

Pointers occupy 8 bytes.
- If a machine has 64-bit operating system and the compiler supports 64-bit addresses, the addresses will have 16 hexadecimal digits.
- Some compilers only support 32-bit addressing, in whihc case addresses will be 32-bit addresses. It that case we could see 8 hexadecimal digits.

~~~c
printf("number's ddress: %p\n", &number); // Output the address
printf("pnumber's address: %p\n", (void*)&pnumber); // Output the address
~~~

- A pointer itself has an address, just like any other variable
- We use `%p` as the conversion specifier to display an address
- We use the `&` operator to reference the address the the pnumber variable occupies.
- The cast to `void*` is to prevent a possible warning from the compiler.
- The %p specification expects the value to be some kind of pointer type, but the type of &pnumber is "pointer to pointer to int".

## Displaying the number of bytes a pointer is using
We use the `sizeof` operator to obtain the number of bytes a pointer occupies. 

~~~c
printf("pnumber's size: %d bytes\n", (int)sizeof(pnumber)); // Output the size
~~~


~~~c
int main(void) {
  int number = 0;
  int *pnumber = NULL;

  number = 10;
  printf("number's address: %p\n" &number);
  printf("number's value: %d\n\n", number);

  pnumber = &number; // Store the address of number in pnumber

  printf("pnumber's address: %p\n", (void*)&pnumber);
  printf("pnumber's size: %zd bytes\n", sizeof(pnumber));
  printf("pnumber's value: %p\n", pnumber);
  printf("value pointed to: %d\n", *pnumber); // Value at the address

  return 0;
}
~~~