# Variables and Data Types

A program needs to store the instructions of its program and the data that it acts upon while your computer is executing that program.
- This information is tored in memory (RAM).
- RAM's contents are lost when the computer is turned off.
- Hard drives store persistent data.

We can think of RAM as an ordered sequence of boxes.
- The box is full when it represents 1 or the box is empty when it represents 0.
- Each box represents one binary digit, either 0 or 1 (true or false)
- Each box is called a bit.

- Bits in memory are grouped into sets of eight(byte)
    - each byte has been labeled with a number (address).
    - The address of a byte uniquely references that byte in your computer's memory. 

- Again, memory consists of a large number of bits that are in groups of eight (bytes) and each byte has a unique address.

- The true power of programs you create is their manipulation of data. So, we need to understand the different data types we can use, as well as how to create and name variables.

- Constants are types of data that do not change and retain their values throughout the life of the program.

- Variables are types of data that may change or be assigned values as the program runs.

- Variables are the names you give to computer memory locations which are used to store values in a computer program.

- Assume you want to store two values 10 and 20 in your program and at a later stage, you want to use these two values.
    - Create variables witrh appropriate names.
    - Store your values in those two variables.
    - Retrieve and use the stored values from the variables.

## Naming variables
The rules for naming variables in C is that all names must begin with a letter or underscore (_) and can be followed by any combination of letters (upper- or lowercase), underscores, or the digits 0-9.
Examples of *valid* variable names:
~~~
Jason
myFlag
i
J5x7
my_data
_anotherVariable
~~~

and here are some *invalid* names:
~~~
temp$value - $ is not a valid character
my flag - embedded spaces arew not permitted
3Jason - variables names cannot start with a number
int - int is a reserved word
~~~

Use meaningful names when selecting variable names. This can dramatically increasde the readability of a program and pay off in the debug and documentation phases.

Some types of data in programs are numbers, letters or words.

## Data Types 

Some types of data in programs are numbers, letters or words. A computer needs a way to identify and use these different kinds. 
A data type represents a type of the data which you can process using your program. Examples include ints, floats, doubles, etc. They also correspond to byte sizes on the platform of your program. Primitive data types are types that are not objects and store all sorts of data.

### Declaring variables
Declaring a variable is when you specify the type of the variable followed by the variable name. This specifies to the compiler how a particular variable will be used by the program. 

~~~c
int age;
~~~

To declare more than one variable, we can declare ewach variable separately, or we can follow the int with a list of names in which each name is separated from the next by a comma;

~~~c
int age, score;
~~~

C requires that all program variables be declared before they are used in a program.

We can assign a variable a value by using the = operator.

~~~c
age = 32;
~~~

### Initializing variables
To initialize a variable means to assign it a starting or initial value.

This can be done as part of the declaration. 

~~~c
int x = 21;
int y = 32; z = 14;
~~~

## Basic data types
Some basic data types in C are:
- int
- float
- double
- char
- _Bool

The difference between the types is the amount of memory they occupy and the range of values they can hold.
- The amount of storage that is allocated to store a particular type of data.
- Depends on the computer you are running (machine independent).
- An integer might take up to 32 bits on your computer, or perhaps it might be stored in 64.


* int: contains integral values only (values that do not contain decimal places). It can be positive, negative, or zero. 
If an integer is preceded by a zero and the letter x, the value is taken as beign expressed in hexadecimal notation

~~~
int rgbColor = 0xFFEF0D;
~~~

* float: stores floating-point numbers.

~~~c
float price = 1.5;
~~~

Floating point constants can also be expressed in scientific notation. 1.7e4 is a floating point value expressed in this notation and represents the value 1.7 x 10 to the power of 4.

* Double
The doublre type is the same as type float, only with roughly twice the precision. Used whenever the range preovided by a float variable is not sufficient. Most computers represent double values using 64 bits.

All floating point constants are taken as double values by the compiler. To explicitly express a float constant, append an f or an F to the end of the number

~~~
12.5f
~~~

* _Bool 
Used for indicating true or false. The values than can be used are 0 or 1.
If you are using a C99 compiler, you can actually use the bool data type. All you have to do is to add the stdbool header.

## Other data types
The int will probably meet most of your integer needs when beginning in C. However, C offers many other integer types that provide more options to a particular use case.

C offers three adjective keywords to modfy the basic integer type: short, long and unsigned.

- The type `short int`, or short may use less storage than int, thus saving space when only small numbers are needed.

- The type `long int`, or `long`, may use more storage than int, thus enabling us to express larger integer values.

- The type `long long int`, or `long long` may use more storage than long. A constan value of type long int is formed by optionally appending the letter L (upper or lowercase) onto the end of an integer constant

~~~c
long int numberOfPoints = 131071100L;
~~~

Type specifiers can also be applied to doubles. A long doub le constant is written as a floating constant with the letter l o L immediately following. 

~~~c
1.234e+7L
~~~

The type `unsigned` int, or unsigned is used for variables that have only nonnegative values (positive).

The keyword `signed` can be used with any of the signed types to make your intent to use negative numbers more explicit.


## Enums
An enum is a data type that allows a programmer to define a variable and specify the valid values that could be stored into that variable.

To create an enum, we have to define the enum type and give it a name.
- initiated by the keyword `enum`.
- then the name of the enumerated data type.
- then the list of identifiers (enclosed in a set of curly braces) that define the permissible values that can be assigned to the type.

~~~c
enum primaryColor {
    red, 
    yellow, 
    blue
};
~~~

Variables that are declared to be of this data type can be assigned the values red, yellow, and blue inside the program and no other values.

To declare a vartiable to be of type enum primaryColor: 
- use the keyword enum
- followed by the enumerated type name
- followed by the variable list.

~~~c
enum primaryColor myColor, otherColor;

myColor = red;
~~~

Another example:

~~~c
enum month {
    January,
    February,
    March,
    April,
    May,
    June, 
    July,
    August,
    September,
    October,
    November,
    December
};
~~~

Now, under the hood as far as how enums are implemented in C, the compiler actually treats enumeration identifiers as integer constants. First name in list is 0.

~~~c
enum month thisMonth;

thisMonth = February // the value 1 is assigned to thisMonth
~~~

We can then compare an enum value against ints aswell as comparing against actual enum values like February.

If you wan to have a specific integer value associated with an enumeration identifier, the integer can be assigned tyo the identifier when the data type is defined

~~~c
enum direction {up, down, left = 10, right};
~~~
- up = 0 because it appears first in the list.
- 1 to down because it appears next.
- 10 to left because it explicitly assigned this value.
- 11 to right because it appears immediately after left in the list.

## Char
Chars represent a single character such as the letter 'a', the digit character '6', or a semicolon.
Character literals use single quotes, such as 'A' or 'Z'.

~~~c
char broiled;
broiled = 'T'; // Ok
broiled = T; // NO! thinks T is a variable
broiled = "T"; // NO! thinks "T" is a string
~~~

You can also use the numerical code to assign values

~~~c
char grade = 65; // Ok for ASCII, but not clear
~~~

## Escape Characters

C contains special characters that represent actions
- backspacing
- going to next line
- making the terminal bell ring (or speaker beep)

We can represent these actions by using special symbol sequences, called escape sequences.


| Sequence | Meaning      |
|----------|:------------:|
| \a       | Alert(ANSI C)| 
| \b       | Backspace |
| \f       | Form feed |
| \n       | Newline |
| \r       | Carriage return |
| \t       | Horizontal tab |
| \v       | Vertical tab |
| \\       | Backslash (\) |   
| \'       | Single quote (') |
| \"       | Double quote (") |
| \?       | Question mark (?) |
| \0oo       | Octal value (o represent an octal digit) |
| \xhh       | Hexadecimal value (h represents a hexadecimal digit) |

## Format specifiers
Format specifiers are used when displaying variables as output. They specify the data of the variable to be displayed

~~~c
int sum = 89;
printf("The sum is %d\n",sum); // The sum is 89
~~~

The percent character inside the first argument is a special character recognized by the printf() function. The character that immediately follows the percent sigjn specifies what type of value is to be displayed.

 Type | printf chars      |
|----------|:------------:|
| char       | %c |
| _Bool       | %i, %u |
| short int       | %hi, %hx, %ho |
| unsigned short int       | %hu, %hx, %ho |
| int       | %i, %x, %o |
| unsigned int       | %u, %x, %o | 
| long int       | %li, %lx. %lo |
| unsigned long int       | %lu, %lx. %lo |
| long long int       | %lli, %llx. %llo |
| unsigned long long int       | %llu, %llx. %llo |
| float       | %f, %e. %g, %a |
| double       | %f, %e. %g, %a |
| long double       | %Lf, %Le. %Lg |


## Command Line Arguments
There are times when a program is develop that requires the user to enter a small amount of information at the terminal. The information might consist of a number indicating the triangular number that you want to have calculated or a word that you want to have looked up in a dictionary. There are two ways of handling this:
- Requesting the data from the user
- Supply the information to the program at the time the program is executed (command-line arguments).

We already know the main() function is a special function in C. When main() is called by the runtime system, two arguments are actually passed to the function.
- The first argument (argc for argument count) is an integer value that specifies the number of arguments typed on the command line.
- The second argument (argv for argument vector) is an array of character pointers (strings).

The first entry in the array is a pointer to the name of the program that is executing.

~~~c
int main(int argc, char *argv[])
{
    
}
~~~

### Passing arguments to the command line
To pass arguments to a C program when using the GCC compiler, you can use the following syntax:
~~~
gcc program.c -o program
./program arg1 arg2 arg3
~~~
In this example, arg1, arg2, and arg3 are the arguments being passed to the program.

Inside the C program, you can access the arguments passed on the command line using the argc (argument count) and argv (argument vector) variables. The argc variable is an integer that tells you how many arguments were passed to the program, and argv is an array of strings that contains the actual arguments.

Here is an example of how you can access the arguments in a C program:

~~~c
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Number of arguments: %d\n", argc);
    printf("Argument 1: %s\n", argv[0]);
    printf("Argument 2: %s\n", argv[1]);
    printf("Argument 3: %s\n", argv[2]);
    return 0;
}
~~~

When you run this program with the command ./program arg1 arg2 arg3, it will print the following output:

~~~
Number of arguments: 4
Argument 1: ./program
Argument 2: arg1
Argument 3: arg2
~~~
Note that argv[0] always contains the name of the program itself, so the first argument passed on the command line is actually argv[1].







