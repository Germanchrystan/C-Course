# Structs
Structures in C provide another tool for grouping elements together.
A structure declaration describes how a structure is put ogether.
The `struct` keyword enables us to define a collection of variables of various types that we can treat as a single unit.

~~~c
struct date {
    int month;
    int day;
    int year;
}
~~~

The above statement defines what a date structure looks like to the C compiler.
There is no memory allocation for this declaration.

the variable names within the date strucutre are called members or fields.

Variables can now be declared to be of type struct date.

~~~c
struct date today;
~~~

The above statement declares a variable to be of type structy date. Memory is now allocated for the variables above, as well as for the three integer values for each variable.

## Accessing members in a struct
A structure variable name is not a pointer. You need a special syntax to acces the members.

We refer to a member of a structure by writing the variable name followed by a period, followed by the member variable name. The period between the structure vriable name and the member name is called the ***member selection operator***.

~~~c
today.day = 25;
today.year = 2024;

if(today.month == 12)
    nextMonth = 1;

~~~

## Defining the structure and variable at the sametime
Tou do have some flexibility in defining a structure. It is valid to declare a variable to be of a particular structure type at the same time that the structure is defined. 
- Include the variable name (or names) before the terminating semicolon of the structure definition.
- We can also assign initial values to the variables in the normal fashion.

~~~c
struct date {
    int month;
    int day;
    int year;
} today;
~~~

In the above example, an instance of the structure, called today, is declared at the same time that the structure is defined. Today is a variable of type date.

## Un-named structures
We could also not give a sturcture a tag name. If all of the variables of a particular structure type are defined when the structure is defined, the structure name can be omitted.

~~~c
struct { // struct declaration and ...
    int day;
    int year;
    int month
} today; // struct variable declaration combined

~~~

A disadvantage of the above is that you can no longer define further instances of ythe structure in another statement. All the variables of this structure type that we want in out program must be defined in the one statement.

## Initializing Structures
Initializing structures is similar to initializing arrays. The elements are listed inside a pair of braces, with each element separated by a comma.
The initial values listed inside the curly braces must be constant expressions.

~~~c
struct date today = { 7, 2, 2015};
~~~

Just like an array initialization, fewer values might be listed than are contained in the structure.

~~~c
struct date1 = { 12, 10};
~~~

sets `date1.month` to 12 and `date1.day` to 10, but gives no initial value to `date.year`.


We can also specify the member names in the initialization list.

~~~c
struct date date1 = {.month = 12, .day=10};
~~~

set just the year member of the date structure variable today to 2015.
~~~c
struct date today = { .year = 2015}
~~~


## Assignment with compound literals
We can assign one or more values to a structure in a single statement using what is known as compound literals.

~~~c
today = (struct date) {9, 25, 2015};

~~~

This statement can appear anywhere in the program.
- It is not a declaration statement.
- the type cast operator is used to tell the compiler the type of the expression
- the list of values follows the cast and are to be assigned to the members of the structure, in order.
- listed in the same way as if we were initializing a structure variable.

We can also specify values using the .member notation.

~~~c
today = (struct date){.month = 9, .day=25, .year = 2015};
~~~

The advantage of using this approach is that the arguments can appear in any order.