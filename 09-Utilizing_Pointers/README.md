# Utilizing Pointers

## When receiving input
When we have used `scanf()` to input values, we have used the `&` operator to obtain the address of a variable. On the variable that is to store the input (second argument).
When we have a pointer that already contains an address, we can use the pointer name as an argument for `scanf()`.

~~~c
int value = 0;
int *pValue = &value;

printf("Input an integer: ");
scanf("%d", pValue); // read into value via the pointer

printf("You entered %d.\n", value); // Output the value entered
~~~

## Testing for NULL
The is one rule you should burn into your memory: Do not dereference an uninitialized pointer.

~~~c
int *pt; // an uninitialized pointer
*pt = 5; // a terrible error
~~~

Second line means store the value 5 in the location to which pt points. The variable `pt` has a random value, there is no knowing where the 5 will be placed.

It might go somewhere harmless, it might overwrite data or code, or it might cause the program to crash.

Creating a pointer only allocates memory to store the pointer itself. It does not allocate memory to store data.
Before you use a pointer, it should be assigned a memory location that has already been allocated.
- assign the address of an existing variable to the pointer.
- or you can use the `malloc()` function to allocate memory first.

We already know that when declaring a pointer that does not point to anything, we should initialize it to `NULL`. We can alos set the point to null using 0

~~~c
int *pValue = 0;
~~~

Because NULL is the equivalent of zero, if you want to test whether pValue is NULL, you can do this:

~~~c
if(pValue == NULL) {}
~~~
Or this:
~~~c
if(!pValue){}
~~~

We should check for `NULL` before we dereferece a pointer. This can happen often when pointers are passed to functions.

## Pointers and const
When we use the `const` modfiier on a variable or an array it tells the compiler that the contents of the variable/array will not be changed by the program.

With pointer we have to consider two thing when using the const modifier.
- Whether the pointer will be changed.
- Whether the value that the pointer points to will be changed.

### const
You can use the const keyword when you declare a pointer to indicate that the value pointed to must not be changed.

~~~c
long value = 9999L;
const long *pValue = &value; // Defines a pointer to a constant
~~~

You have declared the value pointed to by pValue to be const.
The compiler will check for any statements that attempt to modify the value pointed to by pValue and flag such statements as an error.

~~~c
*pValue = 888Ñ; // Error - attempt to change const location
~~~

We can still modify value, as we have only applied const to the pointer.

~~~c
value = 7777L;
~~~

The value pointed to has changed, but we did not use the pointer to make the change. The pointer itself is not constant, so we can still change what it points to:

~~~c
long number = 8888L;
pValue = &number; // OK
~~~

Will change the address stored in pVaue to point to number
- Still cannot use the pointer to change the value that is sotred.
- We can change the address stored in the pointer as much as we like.
- Using the pointer to change the value pointed to is not allowd, even after we have changed the address stored in the pointer.

### *const
We might also want to ensure that the address stored in a pointer cannot be changed. We can do this by using the const keyword in the declaration of the pointer.

~~~c
int count = 43;
int *const pCount = &count; // Defines a constant pointer
~~~

The above ensures that a pointer always points to the same thing. It indicates tht the address stored must not be changed.
The compiler will check that we do not inadvertently attempt to change what the pointer points to elsewhere in the code.

~~~c
int item = 34;
pCount = &item; // Error - attempt to change a constant pointer
~~~

We can still change the value that pcount points to using dereferencing.

~~~c
*pCount = 345; // OK - changes the value of count
~~~
References the value stored in count through the pointer and changes its value to 345.

It is all about where we place the const keyword, either before the type or after the type.
~~~c
const int * .... // Value can not be changed
int *const .... // pointer address cannot change
~~~

### const *const
We can create a constant pointer that points to a value that is also constant:
~~~c
int item = 35;
const int *const pItem = &item;
~~~

The pItem is a constant pointer to a constant so everything is fixed.
- We cannot change the address sotred in pItem.
- We cannot use pItem to modify what it points to.

We can still change the value of item directly. If we wanted to make everything not change, we could specify item as const as well.

## Void pointers
The type name `void` means absence of any type. A pointer of type `void*` can contain the address of a data item of any type. `void*` is often used as a parameter type or return value type with functions that deal with data in a type-independent way.

Any kind of pointer can be passed around as a value of type void*.
 - the void pointer does not know that type of object it is pointing to, so, it cannot be dereference directly.
 - The void pointer must first be explicitly cast to another pointer type before it is dereferenced.

When you wan to access the integer value at the address stored in the `void*` pointer, we must first cast the pointer to type `int*`.

## Pointers and arrays
Arrays and pointers seem quite different, but they are vwery closely related and can sometimes be used interchangeably. One of the most common uses of pointers in C is as pointers to arrays. The main reasons for using pointers to arrays are ones of notational convenience and of program efficency.
Pointers to arrays generally reslt in code that used less memory and executes faster.

~~~c
int values[100];
int *valuesPtr;

valuesPtr = values; // valuesPtr set to point to the first element in the values array.
~~~

The array is actually a pointer under the hood.

The C compiler treats the appearance of an array name as a pointer to the array. Specifying values without a subscript(`[0]`) has the effect of producing a pointer to the first element of values.

An equivalent way of producing a pointer to the start of values is to apply the address operator to the first element of the array.

~~~c
valuesPtr = &values[0];
~~~
Is equivalent to this
~~~c
valuesPtr = values;
~~~

The two epressions `ar[i]` and `*(ar+1)` are equivalent in meaning. Both work if `ar` is the name of an array, and both work if ar is a pointer variable. Using an expression such as `ar++` only works if ars is a pointer variable.

## Passing pointers to a function
There are a few different ways we can pass data to a functionç
- **Pass by value**: When a function copies the actual value of an argument into the formal parameter of the function. Changes made to the parameter inside the function have no effect on the argument.
C programming uses call by value to pass arguments. This means that the code within a function cannot alter the arguments used to call the function. There are no changes in the values, though they had been changed inside the function.
~~~c
/* function definition to swap the values */
void swap(int x, int y)
{
  int temp;

  temp = x; // save the value of x
  x = y; // put y into x
  y = temp; // put temp into y

  return;
}
~~~
When passing the x and y variables, they are going to be local to the function, and they will not be changed outside its scope.

~~~c
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
~~~

- **Pass by reference** Pointers and functions get along quite well. We can pass a pointer as an argument ot  function and we can also have a function return a pointer as its result.
Pass by referen ce copies the address of an argument into the forml parameter. The address is used to access the actual argument used in the call. This means the changes made to the parmeter affect the passed argument.
To pass a alue by reference, argument pointers are passed to the functions just like any other value:
- we need to declare the function parameters as ointer types.
- changes inside the function are reflected outside the function as well.

~~~c
void swap(int *x, int *y)
{
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
  return;
}
~~~


### Const pointer parameters
We can qualify a function parameter using the const keyword. It indicates tha the function will treat the argument that is passed for this parameter as a constant. This is only useful when the parameter is a pointer.

We can apply the `const` keyword to a parameter that is a pointer to specify that a function will not change the value to which the argument points.

~~~c
bool sendMessage(const char * pmessage)
{
  // Code to sent the message
  return true;
}
~~~

The type of the parameter, pmessage, is a pointer to a const char. It is the char value that is const, not its address. We could specify the pointer itself as const too, but this makes little sense, because the address is passed by value. We cannot change the original pointer in the calling function.

The compiler knows that an argument that is a pointer to constant data will be safe.

### Returning pointer from a function
Returning a pointer is a particularly powerful capability. It provides a way for you to return not just a single value, but a whole set of values. We would have to declare a function returning a pointer

~~~c
int * myFunction()
{
  //...
}
~~~

Be careful though, there are specific hazards related to returning a pointer, Use local variables to avoid interfering with the variable that the arguments points to.