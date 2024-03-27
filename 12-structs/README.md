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

## Struct arrays
The concept of an array of strcutrures is a very powerful and important one in C. Declaring an array of structures is like declaring any other kind of array.

~~~c
struct date myDates[10];
~~~

This defines an array called myDates, which consists of 10 elements.
To identify members of an array of structures, we apply the same rule used for individual structures.
Referencing a particular structure element inside the array is quite natural.

~~~c
myDates[1].month = 8;
myDates[1].day = 8;
myDates[1].year = 1943;
~~~

Initialization of array containing structures is simimlar to initialization of multidimensional arrays.
~~~c
struct date myDates[5] = {{12, 10, 1975}, {12, 30, 1980}, {11, 15, 2005}};
~~~

This sts tyhe firsy three dates in the array.
The inner pairs of braces are optional.

~~~c
structy date myDates[5] = { 12, 10, 1975, 12, 30, 1980, 11, 15, 2005 };
~~~
This is just example sets the array just like the previous example, but it is harder to read.

We can also initial one of the elements of the array, without specifying the previous ones.

~~~c
struct date myDates[5] = { [2] = {12, 10, 1975}};
~~~~

~~~c
struct date myDates[5] = {[1].month = 12, [1].day = 30} 
~~~

## Arrays in structs
It is also possible to define structures that contain arays as members. Most common use is to set up an array of characters inside a structure

~~~c
struct month
{
    int numberOfDays;
    char name[3];
}

struct month aMonth;
aMonth.numberOfDays = 31;
aMonth.name[0] = 'J';
aMonth.name[0] = 'A';
aMonth.name[0] = 'N';

struct month Feb = { 31, { 'F', 'E', 'B'}};

struct month months[12];
~~~

## Nested structures
C allows us to define a structure that itself contains other structures ans one ofr more of its members. 
~~~c
struct date 
{
    int day;
    int year;
    int month;
}

struct time
{
    int hours;
    int minutes;
    int seconds;
}

struct dateAndTime
{
    struct date sdate;
    struct time stime;
}

~~~

It is also possible to set up an array of dateAndTime

~~~c
struct dateAndTime events[100];
events[0].stime.hour = 12;
events[0].stime.minutes = 0;
events[0].stime.seconds = 0;
~~~

## Declaring a structure within a structure
We can define the Date structure within the time structure definition.
~~~c
struct Time
{
    struct Date
    {
        int day;
        int month;
        int year;
    } dob;

    int hour;
    int minutes;
    int seconds;
}

~~~

The struct Date is going to be defined in there within the Time struct.
The declaration is enclosed within the scope of the Time structure definition. It does not exist outside of it.
