# Standard C Library

## stddef
`<stddef.h>` contains some standard definitions 

- **NULL**: A null pointer constant.
- **offsetof (structure member)**: The offset in bytes of the member `member` from the start of the structure `structure`; the type of the result is `size_t`.
- **ptrdiff_t**: The type of integer produced by subtracting two pointers.
- **size_t**: The type of integer produced by the `sizeof` operator.
- **wchar_t**: The type of the integer required to hold a wide character.

## limits

`<limits.h>` contains various implementation-defined limits for character and integer data types.
- **CHAR_BIT**: Number of bits in a char(8).
- **CHAR_MAX**: Maximum value for object of type char(-127 if sign extension is done on char, 255 otherwise).
- **CHAR_MIN**: Minimum value for object of type char.
- **SCHAR_MAX**: Maximum value for object of type signed char(127).
- **SCHAR_MIN**: Minimum value for object of type signed char (-127).
- **UCHAR_MAX**: Maximum value for object of type unsigned char (255).
- **SHRT_MAX**: Maximum value for object of type short int (32767).
- **SHRT_MIN**: Minimum value for object of type short int (-32767).
- **USHRT_MAX**: Maximum value for object of type unsigned short int (65535).
- **INT_MAX**: Maximum value for object of type int (32767).
- **INT_MIN**: Minimum value for object of type int (-32767).
- **UINT_MAX**: Maximum value for object of type unsigned int (65535).
- **LONG_MAX**: Maximum value for object of type long int (2147483647).
- **LONG_MIN**: Minimum value for object of type long int (-2147483647).
- **ULONG_MAX**: Maximum value for object of type unsigned long int (4294967295).
- **LLONG_MAX**: Maximum value for object of type long long int.
- **ULLONG_MAX**: Maximum value for object of type unsigned long long int.

## Stdbool

`<stdbool.h>` file contains definitions for working with boolean variables (type _Bool)
- **bool**: Substitue name for the basic `_Bool` data type.
- **true**: defined as 1.
- **false**: defined as 0.

## Various functions

### String functions
To use any of these functions, we need to include the hader file `<string.h>`.
- `char *strcat(s1,s2)`: Concatenates the character string s2 to the end of s1, placing a null characer at the end of the final string. The function returns s1.
- `char *strchr(s2)`: searches the string s for the first occurrence of the character c. If it is found, a pointer to the character is returned. Otherwise, a null pointer is returned.
- `int strcmp(s1, s2)`: Compares strings s1 and s2 and returns a value less than zero if s1 is less than s2, equal to zero if s1 is equal to s2, and greater then zero if s1 is greater than s2.
- `char *strcpy(s1, s2)`: Copies the string s2 to s1, returning s1.
- `size_t strlen(s)`: Returns the number of characters in s, excluding the null character.
- `char *strncat(s1, s2, n)`: Copies s2 to the end of s1 until either the null characrer is reached or n characters have been copied, whichever occurs first. Returns s1.
- `int strncmp(s1, s2, n)`: Performs the same function as strcmp, except that at ost n characters from the strings are compared.
- `char *strrchr(s,c)`: Searches the string s for the last occurence of the character c. If found, a pointer to the character in s is returned; otherwise, the null pointer is returned.
- `char *strstr(s1, s2)`: Searches the string s1 for the first occurrence of the string s2. If found, a pointer to the start of where s2 is located inside s1 is returned; otherwise, if s2 is not located inside s1, the null pointer is returned.
- `char * strtok(s1, s2)`: Breaks the string s2 into tokens based on delimiter characters in s2.

## Characer functions
To use these character functions, we must include the file `<ctype.h>`.

-isalnum, isalpha, isblank, iscntrl, is digit, isgraph, islower, isspace, ispunct, isupper, isxdigit.

-`int tolower(c)`: returns the lowercase equivalent of c. If c is not an uppercase letter, c itself is returned.
-`int toupper(c)`: returns the uppercase equivalent of c. If c is not a lowercase letter, c itself is returned.

## I/O functions
To use the most common I/O functions from the C library we should include the header file `<stdio.h>`.
Included in this file are declarations for the U/O functions and definitions for the names EOF, NULL, stdin, stdout, stderr (all constant values), and FILE.
- `int fclose(filePtr)`: Closes the file identified by filePtr and returns zero if the close is successful, or returns EOF if an error occurs.
- `int feof(filePtr)`: Returns nonzero if the identified file has reached the end of the file and returns zero otherwise.
- `int fflush(filePtr)`: Flushes (writes) any data from internal buffers to the indicated file, returning zero on success and the value EOF if an error occurs.
- `int fgetc(filePtr)`: Returns the next character from the file identified by file Ptr, or the value EOF if an end-of-file condition occurs. Remember that this function returns an int.
- `int fgetpos(filePtr, fpos)`: Gets the current file position for the file associated with filePtr, storing it into the fpos_t(defined in `<stdio.h>`) variable pointed to by fpos. fgetpos returns zero on success, and returns nonzero on failure.
- `char *fgets(buffer, i , filePtr)`: reads characters from the indicated file, until either i - 1 characters are read or a newline character is read, whichever occurs first.
- `FILE *fopen(fileName, accessMode)`: Opens the specified file with the indicated access mode.
- `int fprintf(filePrt, format, arg1, arg2, ..., argn)`: Writes the specified arguments to the file identified by filePtr, according to the format specified by the character string format.
- `int fputc(c, filePtr)`: Writes the value of c to the file identified by filePtr, returning c if the write is successful, and the value EOF otherwise.
- `int fputs(buffer, filePtr)`: Writes the characters in the array pointed to by buffer to the indicated file until the terminating null character in buffer is reached.
- `int fscanf(filePtr, format ,arg1, arg2, ..., argn)`: reads data items from the file identified by filePtr, according to the format specified by the character string format.
- `int fseek(filePtr, offset, mode)`: Positions the indicated file to a point that is offset (a long int) bytes from the beginning of the file, from the current position in the file or from the end of the file, depending upon the value of mode (an integer).
- `int fsetpos (filePtr, fpos)`: Sets the current fule position for the file associated with filePtr to the value pointed to by fpos, which is of type fpos_t(defined in `<stdio.h>`). Returns zero on success, and nonzero on failure.
-`long ftell(filePtr)`: Returns the relative offset in bytes of the current position in the file identified by filePtr, or -1L on error.
- `int printf(format, arg1, arg2, ...m argn)`: Writes the specified arguments to stdout, according to the format specified by the character string. Returns the number of characters written.
- `int remove(fileName)`: Removes the specified file. A nonzero value is returned on failer. The file cannot be opened.
- `int rename(fileName1, fileName2)`: Renames the file fileName1 to fileName2, returning a nonzero result on failure.
- `int scanf(format, arg1, arg2, ..., argn)`: Reads items from stdin according to the format specified by the string format.

## Conversion functions
To use these functions that convert character strings to number we must include the header file `<stdlib.h>`.

- `double atof(s)`: converts the string pointed to by s into a floating-point number, returning the result.
- `int atoi(s)`: Converts the string pointed to by s into a int, returning the result.
- `int atol(s)`: Converts the string pointed to by s into a long int, returning the result.
- `int atoll(s)`: Converts the string pointed to by s into a long long int, returning the result.

## Dynamic Memory functions
To use these function that allocate and free memory dynamically you must include the `<stdlib>`.h header file.

- `void *calloc(n, size)`: Allocates contiguous space for n items of data, where each item is size bytes in lenght. The allocated space is initially set to all zeores. On success, a pointer to the allocated space is returned; on failure, the null pointer is returned.
- `void free(pointer)`: Returns a block of memory pointed to by pointer that was previously allocated by a calloc(), malloc(), or realloc() call.
- `void *malloc(size)`: Allocates contiguous space of size bytes, returning a pointer to the beginning of the allocated block if successful, and null pointer otherwise.
- `void *realloc(pointer, size)`: Changes the size of a previously allocated block to the size bytes, returning a pointer to the new block(which might have moved), or a null pointer if an error occurs.

# Math functions
To use common math function we must include the `<math.h>` header file and link to the math library.

- `double acosh(x)`: Returns the hyperbolic arccosine of x, x >= 1.
- `double asin(x)`: Returns the arcsine of x as an angle expressed in radians in the range [-π/2, π/2]. X is in the range [-1, 1].
- `double atan(x)`: Returns the arctangent of x as an angle expressed in radians in the range [-π/2, π/2].
- `double ceil(x)`: Returns the smallest integer value greater than or equal to x. Note that the value is returned as a double.
- `double cos(x)`: Returns the cosine of r.
- `double floor(x)`: Returns the largest integer value less than or equal to x. Note that the value is returned as a double.
- `double log(x)`: Returns the natural logarithm of x, x >= 0.
- `double nan(s)`: Returns a Nan, if possible, according to the content specified by the string pointed to by s.
- `double pow(x, y)`: Returns x to the power of y. If x is less than zero, y must be an integer. If x is equal to zero, y must be greater than zero.
- `double remainder(x, y)`: Returns the remainder of x divided by y.
- `double round(x)`: Returns the value of x rounded to the nearest integer in floating point format. Halfway values are always rounded away from zero (so 0.5 always rounds to 1.0).
- `double sin(r)`: Returns the sine of r.
- `double sqrt(x)`: Returns the square root of x, x >= 0.
- `double tan(r)`: Returns the tangent of r.
And so many more...


## Utility Functions
To use these routines, include the header file `<stdlib.h>`
- `int abs(n)`: Returns the absolte value of its int argument n.
- `void exit(n)`: Terminates program execution. closing any open files and returning the exit status specified by its int argument n.
`EXIT_SUCCESS` and `EXIT_FAILURE` defined in `<stdlib.h>`. Other related routines in the library that we might want to refer to are abort and atexit.
- `char *getenv(s)`: Returns a pointer to the value of the environment variable pointed to by s, or a null pointer if the variable does not exist. Used to get environment variables.
- `void qsort(arr, n, size, comp_fn)`: Sorts the data array pointed to by the void pointer arr.
There are n elements in the array, each size bytes in length. n and size are of type `size_t`. The fourth argument is of type "pointer to the function that returns int and that takes two void pointers as arguments".
- qsort calls this function whenever it needs to compare two elements in the array, passing it pointers to the elements to compare.
- `int rand(void)`: Returns a random nuumber in the range [0, `RAND_MAX`], where `RAND_MAX` is defined in `<stdlib.h>` and has a minimum value of 32767.
- `void srand(seed)`: Seeds the random number generator to the unsigned int value seed.
- `int system(s)`: Gives the command contained in the character array pointed to by s to the system for execution, returning a system defined value. 
For example: `system("mkdir /user/tmp/data)`.

## Assert Library
The assert library, supported by the `<assert.h>` header file, is a small one designed to help with debugging programs.

It consists of a macro named `assert()`.
It takes as its argument an integer expression. If the expression evaluates as false(nonzero), the assert() macro writes an error message to the standard error stream(stderr) and calls the abort() function, which terminates the program.

~~~c
z = x * x - y * y; // It should be +
assert(z >= 0); // Asserts that z is greater than or equal to 0
~~~

## Other useful header files
- `<time.h>`: Defines macros and functions supporting operations with dates and times.
- `<errno.h>`: Defines macros for the reporting of errors.
- `<locale.h>`: Defines functions and macros to assist with formatting data such as monetary units for different countries.
- `<signal.h>`: Defines facilities for dealing with conditions that arise during program execution, including error conditions.
- `stdarg.h`: Defines facilities that enable a variable number of arguments to be passed to a function.
