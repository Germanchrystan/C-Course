# Dynamic memory allocation
Whenever you define a variable in C, the compiler automaticallu allocates the correct amount of storage for you based on the data type.
It is frequently desirable yo be able to dynamically allocate storage while a program is running.

If you have a program that is designed to read in a set of data from a file into an array in memory, you have three choices
- define the array to contain the maximum number of possible elements at compile time.
- use a variable length array to dimension the size of the array at runtime.
- allocate the array dynamically using one of C's memory allocation routines.

This last approach enables you to allocate memory as the program is executing.
The majority of production programs will use dynamic memory allocation.

## Heap vs. Stack
Dynamic memory allocation reserves space in a memory area called the heap.

The stack is another place where memory is allocated.
- function arguments and local variables in a function are stored there.
- when the execution of a function ends, the space allocated to store arguments and local variables is freed.

The memory in the heap is different in that it is controlled by us.
- when we allocate memory on the heap, it is up to us to keep track of when this memory is no longer required.
- we must free the space we have allocated to allow it to be reused.


## Malloc
The simples standard library function that allocates memory at runtime is called `malloc()`.
- To use it we need to include the stdlib.h header file
- we must specify the number of bytes of memory that wse want allocated as the argument.
- returns the address of the first byte of memory that is allocated.
- because we get and address returned, a pointer is the only place to put it.

~~~c
int *pNumber = (int*)malloc(100);
~~~

int the above, we have requested 100 bytes of memory and assigned the address of his memory block to pNumber.
- pNumber will point to the first int location at the beginning of the 100 bytes that were allocated.
- can hold 25 int values on my computer, because they require 4 bytes each.
- assumes that type int requires 4 bytes (that can change depending on the OS).

It would be better to remove the assumption that ints are 4 bytes.

~~~c
int *pNumber = (int*)malloc(25*sizeof(int));
~~~

This will make the code portable.
Notice the cast (int*) which converts the address returned by the function to the type pointer to int.
**malloc returns a pointer of type pointer to void, so we have to cast.**

If the memory that we requested can not be allocated for any reason.
- malloc() returns a pointer with the value NULL.
- It is always a good ide to check any dynamic memory request immediately using an if statement to make sure the memory is actually there before we try to use it.

~~~c
int *pNumber = (int*)malloc(25*sizeof(int));
if(!pNumber)
{
    // code to deal with memory allocation failure
}
~~~

### Releasing memory 
We always should release the memory allocated when it is no longer required.
Memory allocated on the heap will be automatically released when the program ends. It is better to explicitly release the memory when we are done with it, even it is just before we exit from the program.

A memory leak occurs when we allocate some memory dynamically and we do not retain the reference to it, so we are unable to release the memory.
- often occurs within a loop.
- because we do not release the memory when it is no longer required, the program consumes more and more of the available memory on each loop iteration and eventually may occupy it all.

To free memory that we have allocated dynamically, we must still have access to the address that references the block of memory. To release the memory for a block of dynamically allocated memory whose address we have stored in a pointer we use the `free` function

~~~c
free(pNumber)
pNumber = NULL;
~~~

The free function has a formal parameter of type void*. We can pass a pointer of any type as the argument. As long as pNumber contains the address that was returned when the memory was allocated, the entire block of memory will be freed for further use.

We should always set the pointer to NULL after the memory that it points to has been freed. This is to signify that that pointer is no longer pointing to anything.

## calloc
The `calloc` function offers a couple of advantaes over `malloc`.
- it allocates memory as a number of elements of a given size.
- it initializes the memory that is allocated so that all bytes are zero.

The calloc function requires two argument values.
- number of data items for which space is required.
- size of each data item.

Is declared in the stdlib.h header.

~~~c
int *pNumber = (int*)calloc(75, sizeof(int));
~~~

The return value will be NULL if it was not possible to allocate the memory requested. 
Very similar to using malloc, but the big plus is that we know the memory area will be initialized to 0.

## realloc
The `realloc()` function enables us to reuse or extend memory that we previously allocated using `malloc()` or `calloc()`.
Expects two argument values.
- a pointer containing an address that was previously returned by a call to malloc or calloc.
- the size in bytes of the new memory that we want allocated.

allocates the amount of memory we specify by the second argument.
- transfers the contents of the previously allocated memory referenced by the pointer that we supply as the first argument to the newly allocated memory.
-  returns a void* pointer to the new memory or NULL if the operation fails for some reason.

The most important feture of this operation is that realloc() preserves the contents of the original memory area.

## Guidelines
Avoid allocating lots of small amounts of memory
- allocating memory on the heap carries some overhead with it.
- allocating many small block of memory will carry much more overhead than allocating fewer larger blocks.

Only hand on to the memory as long as you need it. As soon as you are done with a block of memory on the heap, release the memory.

Always ensure that you provide for releasing memory that you have located. Decide where in your code you will release the memory when you write the coe that allocates it.

Make sure you do not inadvertently overwrite the address of memory you have allocated on the heap before you have released it.
- Will cause a memory leak.
- be specially careful when allocating memory within a loop.