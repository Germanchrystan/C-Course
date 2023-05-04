# Character Strings
The `char` data type contains a single character. To assign a single character to a char variable, the character is enclosed within a pair of single quotation marks. 
A string constant or string literal is a sequence of characters or symbols between a pair of double-quote characters. Anything between a pair of double quotes is interpreted by the compiler as a string. Every time we display a message using the printf() function, w define the message as a stirng constant.

## Null Character
A special character with the code value 0 is added to the end of each string to mark where it ends. This character is known as the null character and we write is as `\0`. A string is always terminated by a null character, so the length of a string is always one greater than the number of characters in the string. 
- Don't confuse the null character with NULL: 
    - null character is a string terminator.
    - NULL is a symbol that represents a memory address that doesn't reference anything.

# Defining a string
C has no special variable type for strings. This means there are no special operators in the language for processing string.
The standard library provides an extensive range of functions to handle strings.

Strings in C are stored in an array of type char. Characters in a string are sotred in adjacent memeory cells, one character per cell.

~~~c
char myString [20];
~~~

This variable can accomodate a string that contains up to 19 characters. We must allow one element for the termination character.

We can also initialize a string variable when declaring it.

~~~c
char word[] = {'H', 'e', 'l', 'l', 'o', '!'};
~~~

To initialize a string it is the same as any other array initialization.
- in the absence of a particular array size, the C compiler automatically computes the number of elements in the array, based upen the number of initializers.
- This statement reserves space in memory for exactly seven characters.
- automatically adds the null terminator.

Luckily we can initialize the string without having to write single quotes for each character followed by commas, just by putting double quotes around the string. 

We can also specify the size of the string explicitly, just to make sure we leave enough space for the terminating null character

~~~c
char word[7] = {"Hello!"};
~~~

If the size specified is too small, then the compiler can't fit a terminating null character at the end of the array, and it doesn't put one there. It doesn't complain about it either.

~~~c
char word[6] = {"Hello!"};
~~~

So we better don't specify the size, and let the compiler figure it out.
Or initialize just part of an array of elements of type char with a string.

~~~c

char str[50] = "Hello!";
~~~

The compiler will initialize the first 6 elements, with the characters of the string constant. 
- `str[7]` will contain the null character `\0`.
- space is allocated for all 50 elements of the array.

## Assigning a value to a string after initializing
Since we can not assign arrays in C, we can not assign strings either.
The following is an error
~~~c
char s[100]; // declare
s = "hello"; // initialize - DOESN'T WORK
~~~

We a re performing an assignment operation, and we cannot assign one array of characters to another array of characters like this. We have to use `strncpy()` to assign a value to a char after it has been declared or initialized.

The below is perfectly valid

~~~c
s[0] = 'h';
s[1] = 'e';
// ...
s[5] = '\0';
~~~

When you want to refer to a string stored in an array, you just use the array name by itself.
To display a string as output using the printf function, you do the following:

~~~c
printf("\n the message is: %s", message);
~~~

The %s format specifier is for outputting a null-terminated string. The printf() function assumes when it encounters the %s format characters that the corresponding argument is a character string that is terminated by a null character.
To input a string via the keyboard, use the scanf function
~~~c
char input[10];
printf("Please input your name: ");
scanf("%s", input);
~~~

- the %s format specifier is for inputting string
- no nedd to use the & (address olf operator) on a string.
- scanf is going to read a string up until a space is found.

### Testing if two strings are equal
We cannot directly test two strings to see if they are equal with a statement such as 
~~~c
if(string1 == string2) // WRONG
~~~

the equality operator can only be applied to simple variables types, such as floats, ints, or chars. It does not work on structures or arrays.
To determine if two strings are equal, we must explicitly compare the two chacter strings character by character. We will later use the `strcmp` function.

## Constant String
The preprocessor let us define constants

~~~c
#define OOPS "Now you have done it!"
~~~

C90 added a second way to create symbolic constants. Using the const keyword yo convert a declaration for a variable into a declaration for a constant.

~~~c
const int MONTHS = 12; // MONTHS is a symbolic constant for 12
~~~

`const` is a newer approach and is more flexible than using `#define`.
- it lets you declare a type.
- it allows better control over which parts of a program can use the constant.

Initializing a char array and declaring it as constant is a good way of handling standard messages.

~~~c
const char message[] = "The end is nigh";
~~~

# Common String Functions
C provides many functions specifically designed to work with strings.
- strlen: returns length of a string, as a size_t.
This functions does change the stirng. The function header does not use const in declaring the formal parameter string.

- strcpy() and strncpy(): copying one character string into another.
Since you can not assign arrays in C, you can not assign strings either. We can use the strcpy() function to copy a stirntg to an existing string.
This is the string equivalent of the assignment operator.
~~~c
char s[100]; // declare
s = "Hello"; // initialize- DOES NOT WORK
~~~
The strcpy function does not check to see whether the source string actually fits in the target string. The safer way to copy strings is to use strncpy().
strncpy takes a third argument, the maximum number of characters to copy.
~~~c
char src[40];
char dest[12];

// Setting the size of the data inside destination to null terminators.
// That way when you add something it will automatically be there.
memset(dest, '\0', sizeof(dest)); 

strcpy(src, "Hello how are you doing");
strncpy(dest, src, 10);
~~~


- strcat() and strncat(): combining two character strings together (concatenation). This alters the second string. 
    The function strcat() does not check to see whether the second string will fit in the first array. If you fail to allocate enough space for the first array, you will run into problems as excess characters overflow into adjacent memeory locations.
    We should use strncat() instead. This function takes a third argument indicating the maximum number of characters to add.
    For example, strncat(bugs, addon, 13) will add the contents of the addon string to bugs stopping when it reaches 13 additional characters or the null character, whichever comes first.
- `strcmp()` and `strncmp()`: determining if two character strings are equal. We cannot use `==`, as this will only check to see if the string has the same memory address.
    - `strcmp()` does not compare arrays, so it can be used to compare strings stored in arrays of different sizes. 
    - It does not compare characters: We can use arguments such as "A" and "apples", but we cannot use character arguments, such as 'A'.
    - This functions does for strings what relational operators do for numbers.
        - It returns 0 if its two string arguments are the same and nonzeor otherwise.
        - It returns value < 0 when indicating str1 is less than str2.
        - It returns value > 0 when indicating str2 is less than str1.
    - the `strcmp()` function compares strings until it finds corresponding characters that differ. It could take the search to the end of one of the strings.

    - `strncmp()` compares the string until they differ or until it has compared a number of characters specified by a third argument.
    ~~~c
    if(strncmp("astronomy", "astro", 5) == 0)
    {
        printf("Found: astronomy");
    }
    ~~~

The C library supplies these string handling function prototypes in the string.h header file.

### Searching a string
The string.h header declares several string-searching functions for finding a single character or substring: 

#### strchr()
This function searches a given string for a specified character. First argument to the function is the string ot be searched (which will be the address of a char array). Second argument is the character that you are looking for. The functions expects this second argument to be of type int, so the compiler will convert the value of ch to this type.
The function will search the string starting at the beginning and return a pointer to the first position in the string where the character is found (`char*`). If the character is not found, the function returns a special value `NULL`, which is the equivalent of 0 for a pointer, and represents a pointer that does not point ot anything.


#### strstr()
This is probably the most useful of all the searching functions. It searches one string for the first occurrence of a substring, and returns the pointer to the position in the first string where the substring was found. If the substring is not found, the function returns `NULL`.

### Tokenizing a string
A token is a sequence of characters within a string that is bounded by a delimiter (space, comman, period, etc.). A delimiter can be anything, but, should be unique to the string. Breaking a sentence into words is called tokenizing. 
#### strtok()
This function is used for tokenizing a string. It requires two arguments: a string to be tokenized, and a string containing all the possible delimiter characters.


Analizying strings
- lslower(), isupper(), isalpha(), isdigit(), etc.

