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