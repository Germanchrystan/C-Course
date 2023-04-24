# Functions
A function is a self-contained unit of program code designed to accomplish a particular task. Syntax rules define the structure of a function and how it can be used. A function in C is the same as subroutines or procedures in other programming languages.

Some functions cause an action to take place

~~~c
printf() // causes data to be printed on your screen
~~~

Some fuinctions find a value for a program to use
~~~c
strlen() // tells a program how long a certain string is
~~~

## Advantages
- allows for the divide and conquer strategy: It is very difficult to write an entire program as a single large main function.

- With divide and conquer, tasks can be divided into several independent subtasks.
    - reduces the overall complexity.
    - separate functions are writeen for each subtask.
    - We can further divide each subtask into smaller subtasks, further reducing the complexity.

- reduce duplication of code.
    - Saves time when writing, testing, and debugging code.
    - reduces the size of the source code.

- If you have to do a certain task several times in a program, you only need to write an appropiate function once.
    - Program can then use that function wherever needed.
    - You can also use the same function in different programs.

- Helps with readability
    - Program is better organized.
    - Easier to read and easier to change or fix.

- The divide and conquer approach also allows the parts of a program to be developed, tested and debugged independently
    - reduces the overall development time.

- The functions developed for one program can be used in another program

- Many programmers like to think of a function as a "black box".
    - Information that goes in (its output).
    - The value or action it produces (its output).

- Using the "black box" thinking helps you concentrate ojn the program's overall design rather than  the details.
    - What thje function should do and how it relates to the program as a whole before worrying about writing the code.


### Examples
- We have already uised built-in functions such as printf() and scanf(). You should have noticed how to invoke thse functions and pass data to them (arguments between parentheses following the function name).

- You should also have noticed how you can receive information back from a function in two ways:
    - Through one of the function arguments(scanf): The input is stored in an address that you supply as an argument.
    - As a return value.


~~~c
#define SIZE 50
int main(void)
{
    float list[SIZE];

    readlist(list, SIZE);
    sort(list, SIZE);
    average(list, SIZE);
    return 0;
}
~~~

In this previous example, we only have 3 lines of code, and we immediately know what each one does. If we have any bugs in the program, we will know how to find or isolate that bug to one of the functions.

## Implementing functions
Just calling functions does not work unless we implement the function itself. 
    - User defined functions.
    - We would have to write the code for the three functions in the previous example.

Always use descriptive function names to make it clear what it does and how it is organized. If you make the functions general enough, you can reuse them in other programs.

## The main() function
The main() is a specially recognized name in the C system. It indicates where the program is to begin execution, so all C programs must have one.
We can pass data to this function, as command line arguments. This functions could also have a returning data value, in order to test for errors.

## Defining functions in C
When you create a function, you specify the function header as the first line of the function definition.
    - Followed byu a starting curly brace.
    - The executable code in between the starting and ending braces.
    - The ending curly brace.
    - The block of code between braces following the function header is called the function body.

The function header defines the name of the function
    - parameters (which specify the number and types of values that are passed to the function when it's called).
    - The type of the value that the function returns.

The function body contains the statements that are executed when the function is called.
    - have access to any values that are passed as arguments to the function.

~~~c
Return_type Function_name(Parameters /*separated by commas*/) {
    // Statements
}

~~~

A more concrete example

~~~c
void printMessage(void)
{
    printf("Programming is fun.\n");
}
~~~

- The statements in the function body can be absent, but the braces must be present.
- If there are no statements in the body of a function, the return type must be boid , and the function will not do anything.
    - Defining a function with an empty body is often useful during the testing phase of a complicated program.
    - allows you to run the program with only selected functions actually doing something.
    - you can then add the detail for the function bodies step by step, testing at each stage, until the whole thing is implemented and fully tested.

## Naming functions
- The name of a function can be any legal name.
    - not a reserved word(such as int, double, sizeof, and so on).
    - Is not the same name as another function in your program.
    - Is not the same name as any of the standard library functions

- A legal name has the same form as that of a variable
    - a sequence of letters and digits.
    - first character must be a letter.
    - underline character counts as a letter.

- The name that you choose should be meaningful and relevant to what the function does.


## Function prototypes
We can write a prototype for a function exactly the same as the function header
    - only difference is that you add a semicolon at the end.

~~~c
void printMessage(void);
~~~

A function prototype enables the compiler to generate the appropriate instructions at each point where you call the function. It also checks that you are using the function correctly in each invocation.

- When you include a standard header file in a program, the header file adds the function prototypes for the library to your program. The header file `stdio.h` contains function prototypes for printf(), among others.

- Generally appear at the beginning of a source file prior to the implementations of any functions or in a header file.

- Allows any of thge functions in the file to call any function regardless of where ytou have places the implementation of the functions.

- Parameter names do not have to be the same as those used in the function definition. Not required to include the naems of parameters in a function prototype.

- It is good practice to always include declarations for all of the functiuuons in a program source file, regardless of where they are called.
    - It will help keep your programs more consisten in design.
    - It will prevent any errors from occurring if, at any stage, you choose to call a function from another part of your program.

~~~c
// Function prototypes
double Average(double data_values[], size_t count);
double Sum(double *x, size_t n);
size_t GetData(double*, size_t);

int main(void)
{
    // Code in main()...
}

// Definitions/implementations for Average(), Sum(), and GetData()...
~~~

## Arguments and Parameters
A parameter is a variable in a function declaration and function definition/implementation.

When a function is called, the arguments are the data you pass into the functions parameters.
    - The actual value of a variable that gets passed to the function.

Function parameters are defined within the function header.
    - Are placeholders for the arguments that need to be specified when the function is called.

The parameters for a function arte a list of parameter names with their types
    - Each parameter is separated by a comma.
    - Entire list of parameters is enclosed between the parentheses that follow the function name.

A function can have no parameters, in which case you should put void between the parentheses.

- Parameters provide the means to pass data to a function.
    - Data passed from the calling function to the function that is called.

- The names of the parameters are local to the function.
    - They will assume the values of the arguments that are passed when the function is called.

The body of the function should use these parameters in its implementation.

A function body may have additional locally defined variables that are needed by the function's implementation.

- When passing an array as an argument to a function.
    - You must also pass an additional argument specifying the size of the array.
    - The function has no means of knowing how many elements there are in the array.

## Returning data


## Local and Global variables
Variables defined inside a function are known as automatic local variables. They are automatically "created" each time the function is called, and their values are local to the function.

The value of a local variable can only be accessed by the function in which the variable is defines, it cannot be accessed by any other function.

If an initial value is given to a variable inside a function, that initial value is assigned to the variable each time the function is called.

Local variables are also applicable to any code where the variable is created in a block (loops, if statements).

### Global variable
- The opposito of a loval variable
- Global variables value can be accessed by any function in the program.
- A global variable has the lifetime of the program.
- Global variables are declared outside of any function. They don't belong to any particular function.


~~~c
int myGlobal = 0; // global variable

int main()
{
    int myLocalMain = 0; // local variable
    // can access myGlobal and myLocalMain
    return 0;
}

void myFunction()
{
    int x; // local variable
    // can access myGlobal, cannot access myLocalMain
}

~~~

In general, global variavles are a bad thing and should be avoided
- promotes coupling between functions (dependencies).
- hard to find the location of a bug in a program
- hard to fix a bug once it is found.

