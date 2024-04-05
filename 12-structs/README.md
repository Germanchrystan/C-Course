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

## Declaring a struct as a pointer
We can define a variable to be a pointer to a struct

~~~c
struct date *datePtr;
~~~

The variable datePtr can be assigned just like other pointes. We can set it to point to `todaysDate` with the assignment statement.

~~~c
datePtr = &todaysDate;
~~~

We can then indirectly access any of the members of the date structure pointed to by datePtr.

~~~c
(*datePtr).day=21;
~~~

The above has the effect of setting the day of the date structure pointed to by datePtr to 21.
Parentheses are required because the structure member operator `.` has higher precedence than the indirection operator `*`.

Pointers to structures are so often used in C that a special operator exists.
The structure pointer operator `->`, which is the dash followed by the greater sign, allows to access a member without having to dereference a pointer to a struct.

`(*x).y` can be cleary expressed as `x->y`.

## Structures containing pointers
A pointer can also be a member of a structure.

~~~c
struct intPtrs
{
    int *p1;
    int *p2;
}

~~~

## Character arrays or character pointers?

~~~c
struct names
{
    char first[20];
    char last[20];
}
~~~

~~~c
struct pnames
{
    char * first;
    char * last;
}
~~~

We can do both, however, we need to understand what is happening here.

~~~c
struct names veep = { "Talia", "Summers"};
struct pnames treas = {"Brad", "Fallingjaw"};
printf("%s and %s\n", veep.first, treas.first);
~~~


In the first struct `names`, the strings are stored inside the structure. The struct has allocated a total of 40 bytes to hold the two names. We are allocating 40 bytes to hold those two names (20 and 20).

In the second struct `pnames`, the strings are stored wherever the compiler stores string constants. The structure does not allocate memory for the strings, it only holds two pointers, which in most systems take 8 bytes each. It can be used only with strings that have had space allocated for them elsewhere. 
Whenever we have pointers inside of a structure, we have to use `malloc` or `calloc`.
Otherwise, they could be stored wherever string constants are stored.

The pointers in a pnames structure should be used only to manage strings that were created and allocated elsewhere in the program.

One instance in which it does make sense to use a pointer in a structure to handle a string is if you are dynamically allocating that emmory. It has the advantage that we can ask malloc() to allocate just the amount of space that is needed for a string.

~~~c
struct namect 
{
    char * fname;
    char * lname;
    int letters;
}

~~~

The two strings are not stored in the structure, they are stored in the chunk of memory managed by malloc().
Addresses are what string handling functions typically work with.

## Structures as arguments to functions
After declaring a structure named Family, how do we pass this structure as an argument to a function?
~~~c
struct Family
{
    char name[20];
    int age;
    char father[20];
    char mother[20];
}
bool siblings(structy Family member1, struct Family member2)
{
    return strcmp(member1.mother, member2.mother) == 0;
}
~~~

## Pointers to Structures as function arguments
We should use a pointer to a structure as an argument. It can take quite a bit of time to copy laege structures as arguments, as well as requiring whatever amount of memory to store the copy of the structure.
Pointers to structures avoid the memory consumption and the copying time. Only a copy of the pointer argument is made.

~~~c
bool siblings(struct Family *pmember1, struct Family *pmember2)
{
    return strcmp(member1->mother, member2->mother) == 0;
}
~~~~

We can also use the const modifier to not allow any modification of the members of the struct

~~~c
bool siblings(struct Family const *pmember1, struct Family const *pmember2 )
{
    return strcmp(member1->mother, member2->mother) == 0;
}
~~~

We can also use the const modifier to not allow any modification of the pointers address.
Any attempt to change those structures will cause an error message during compilation.

~~~c
bool siblings(struct Family *const pmember1, struct Family *const pmember2)
{
    return strcmp(member1->mother, member2->mother) == 0;
}
~~~

The indirection operator in each parameter definition is now in front of the const keyword, not in front of the parameter name. We cannot modigy the addresses stored in the pointers. The pointers are protected here, not the structures to which they point.

## Returning a structure from a function.
The function prototype has to indicate this return value in the normal way.

~~~c
struct Date my_fun(void);
~~~

This is a prototype for a function taking no arguments that returns a structure of type Date.
It is often more convenient to return a pointer to a structure. When returning a pointer to a structure, it should be created on the heap.


### Reminder
We should always use pointers when passing structures to a function. It works on older as well as newer C implementations. Some old C implementations don't allow to pass structs as arguments, but they do allow to pass pointers to structs.

However, we have less protection for the data. Some operations in the called function could inadvertently affect data in the original structure. For that we use **const** qualifiers.

We can also pass structures as arguments. The functions works with copies of the original data, which is safer, and the programming style tends to be clearer.
The disadvantages of thay is that it wastes time and memory, specially when dealing with large structures to a function that uses only one or two members.
The other disadvantage, as mention early is that not all C versions allow this.
