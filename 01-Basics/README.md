# C Basics
## Comments
Comments are used in a program to document a program and to enhance its readability. They are there to remind you, or someone else reading your code, what the program does or what a particular line of code is doing. Comments are ignored by the compiler.

There are two ways to add comments into a C program. 
- Multiline comment: /**/

~~~c
/*
This is a multiline
comment
*/
~~~

- Single line comment: //

~~~c
// This is a single line comment
~~~


Example:

~~~c
/*
This pŕogram adds two integer values
and displays the results
*/
#include<stdio.h>

int main(void)
{
    // Declare variables
    int value1, value2, sum;

    // Assign values and calculate their sum
    value1 = 50;
    value2 = 25;
    sum = value1 + value2;

    // Display the result
    printf("The sum of %i and %i is %i\n", value1, value2, sum);
    return 0;
}

~~~

## The preprocessor
Another unique feature of the C language that is not found in many other higher-level programming languages is the preprocessor. It allows for programs to be easier to develop, to read, to modify and to port to different computer systems.

It is a part of the C compilation process that recognizes special statements:
- Analyzes special statements before analysis of the C program itself takes place.
- We can use it to optimize the program and make things easier from the start.
- Statements can be anywhere in the code.

Preprocessor statements are identified by the presence of a pound sign, #, which must be the first non-space character on the line.
One of these statements recognized by the preprocessor is the include directive.

We will utilize the preprocessor to:
- Create our own constants and macros with the #define statement.
- Build our own library files with the #include statement.
- Make more powerful programs with the conditional #ifdef, #endif, #else, and #ifndef statements.