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

### The #include statement
The #include statement is a preprocessor directive. Is the most common preprocessor directive, nearly all C files have it.

~~~c
#include<stdio.h>
~~~

In the above example, the compiler is instructed to "include" in your program the contents of the file with the name stdio.h.
- Called a header file because it is usually included at the head of a program source file. 
- .h extension. The include directive is always going to have file names with this extension.

Header files define information about some of the functions that are provided by that file.
- stdio.h is the standard C library header and provides functionality for displaying output, among many other things.
- We need to include this file in a program when using the printf() function from the standard library.
- stdio.h contains the information that the compiler needs to understand what printf() means, as well as other functions that deal with input and output.
- stdio, is short for standard input/output.

Header files specify information that the compiler uses to integrate any predefined functions within the program.

Header file names are case sensitive on some systems, so you should always write them in lowercase.

The are two ways to #include header files in a program
- Using angle brackets(#include <stdio.h>). Tells the preprocessor to look for the file in one or more standard system directories.
- Using double quotes(#include "mylib.h"). Tells the preprocessor to look first in the current directory.

Every C compiler that conforms to the C11 standard will have a set of standard header files supplied with it. 

We should use #ifndef and #define to protect against multiple inclusions of a header file.

Executable code normally goes into a source code file, not a header file.

## Displaying output
printf() is a standard library function.
- It outputs information to the command line( the standard output stream, which is the command line by default)
- The information displayed is based on what appears between the parentheses that immediately follow the function name(printf).
- It is probably the most common function used in C.
- Provides an easy and convenient means to display program results.
- Can be used for debugging.

## Reading input from the terminal
We are going to use the scanf function for input. It is the most generic function for this end, and it provides different formats to enter.
Scanf read the input from the standard input stream stdin and scans that input according to the format provided. Format can be a simple constant string, but you can specify %s, %d, %c, %f, etc., to read a string, an integer, a character or a float.

If the stdin is input from the keyboard then text is read in because the keys generate text characters: letters, digts, and punctuation.
- When you enter the integer 2014, youy type the characters 2 0 1 and 4.
- If you want to store that as a numerical value rather than a string, your program has to convert the string character by character to a numerical value and this is the job of the scanf function.

Like printf(), scanf() uses a control string followed by a list of arguments. Control string indicates the destination data types for the input stream of characters.