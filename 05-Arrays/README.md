# Arrays
Arrays are commmon in most programming languages. It is very common in a program to store many data values of a specified type. Arrays allows us to group values together under a single name. This way we don't need separate variables for each item of data. 

An array is a fixed number of data items that are all of the same type. The data items in an array are referred to as elements.

Declaring to use an array in a program is similar to a normal variable that contains a single value. Difference is that we need a number between the square brackets following the name. 

~~~c
long numbers[10];
~~~
The number between square brackets defines how many elements the array contains. This value is known as the size of the array or the array dimension.

Each of the data items stored in an array is accessed by the same name. We select a particular element by using an index (subscript) value between square brackets following the array name. Index values are sequential integers that start from zero. We can also specify an index for an array element by an expression in the square bracktes following the array name. The expression must result in an integer value.

It is very common to use a loop to access each element in an array
~~~c
for (i = 0; i < 10; ++i) {
    printf("Number is %d", numbers[i]);
}

~~~

If you use an expression or a variable for an index value that is outside the range of the array, your program may crash or the array can contain garbage data. This is referred to as an out of bounds error. The compiler cannot check for out of bounds errors so your program will still compile. It is very important to ensure that your array indexes are always within bounds.

A value can be stored in an element of an array simply by specifying the array element on the left side of an equal sign

~~~c
grades[100] = 95;
~~~

## Initializing an array
We want to assign initial values for the elements of our array most of the time. Defining intiial values for array elements makes it easier to detect when things go wrong.
Just as we can assign initial values to variables when they are declared, we can also assign initial values to an array's elements. 
To initialize an array's values, simply provide the values in a list. Values in the list are separated by commas and the entire list is enclosed in a pair of braces. 

~~~c
int counter[5] = {0, 0, 0, 0, 0};
~~~

This declares an array called counters to contain five integers values, and initializes each of those elements to zero.

~~~c
int integers[5] = {0, 1, 2, 3, 4, 5};
~~~

Declares an array named integers and sets the values of integers[0] to 0, integers[1] to 1, and so on.

It is not necessary to completely initialize an entire array. If fewer initial values are specified, only an equal number of elements are intialized. The remaining values in the array are set to zero.

~~~c
float sample_data[500] = {100.0, 300.0, 500.9};
~~~

This initializes the first three values of the array, and sets the remaining 497 elements to zero.

C99 added a feature called designated initializers, that allows us to pick and choose which elements are initialized. By enclosing an element number in a pair of brackets, specific array elements can be initialized in any order.

~~~c
float sample_data[500] = { [2] = 500.0, [1] = 300.0, [0] = 100.0 };
~~~

## Repeating an intial value
C does not provide any shortcut mechanismsfor initializing array elements. There is no way to specify a repeat count. If it were desired to initially set all 500 values of sample_data to 1, all 500 would have to be explicitly assigned. To solve this problem, we would initialize the array inside the program using a loop.

## Multidimensional arrays
The C language allows arrays of any dimension to be defined. Two dimensional arrays are the most common. We can visualize a two dimensional array as a rectangular arrangement like rows and columns in a spreadsheet. One of the most natural applications for a two dimentional array arises in the case of a matrix. 

~~~c
int matrix[4][5];
~~~
This declares the array matrix to be a two dimensional array consisting of 4 rows and 5 columns, for a total of 20 elements. Note how each dimension is between its own pair of square brackets.

~~~c
int numbers[3][4] = {
    {10, 20, 30, 40}, // First row
    {15. 25, 35, 45}. // Second row
    {47, 37, 40, 123} // Third row
}
~~~

Commas are required after each brace that closes off a row, except in the case of the final row. The use of the inner pairs of braces is actually optional, but should be used for readability.

As with one dimensional arrays, it is not required for the entire array to be initialized.
~~~c
int matrix[3][4] = {
    {10, 4, -4},
    {9, 0, 0},
    {32, 20, 1},
    {0, 0, 8}
};
~~~

Subscripts can also be used in the initialization list, in a like manner to single-dimensional arrays.

~~~c
int matrix[4][3] = {[0][0] = 1, [1][1] = 5, [2][2]= 9}; 
~~~

Here is an example of a three dimensional array.

~~~c
int numbers[2][3][4] = {
    { // First block of three rows
        {2, 3, 4, 5},
        [3, 4, 5, 6],
        {4, 5, 6, 7}
    },
    {
        {10, 20, 30, 40},
        {20, 30, 40, 50},
        {40, 60, 80, 100}
    }
}
~~~

We should use nested loops to process all the elements in a multidimentional array.
The level of nesting will be the number of array dimensions, as each loop iterates over one array dimension.

~~~c
int sum = 0;
for(int i = 0; i < 2, i++)
{
    for(int j = 0; j < 3; j++)
    {
        sum += numbers[i][j];
    }
}
~~~

## Variable length arrays
So far, all the sizes of an array have been specified using a number, and size is fixed. The term variable in variable-length array does not mean that we can modify the length of the array after it is created. A VLA keeps the same size after creation, but it allows us to specify the size of an array with a variable when creating an array.

C99 intoduced variable length arrays primarily to allow C to become a better language for numerical computing. VLAs make it easier to convert existing libraries of FORTRAN numerical calculation routines to C. VLAs can not be initialized in their declaration.

~~~c
int n = 5;
int m = 8;
float a1[5]; // yes
float a2[5*2 +1]; // yes
float a3[sizeof(int)+1]; // yes
float a4[-4]; // NO, size must be > 0
float a5[0]; // NO, size must be > 0
float a6[2.5]; // NO, size must be an integer
float a7[(int)2.5]; // yes, typecast float to int constant
float a8[n]; // not allowed before C99, VLA
float a9[m]; // not allowed before C99, VLA
~~~

