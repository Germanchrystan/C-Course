# File Input and Output
All serious business applications require more data than would fit into main memory. They also depend on the ability to process data that is persistent and stored on a external device such as a disk drive.

C provides many functions in the header file `stdio.h` for writing to and reading from external devices.

C views a file as a continuous sequence of bytes. Each byte can be read individually.

There are two ways of writing data to a stream that represents a file.
- text
- binary.

Text data is written as a sequence of characters organized as lines (each line ends with a newline).
Binary data is written as series of bytes exactly as they appear in memory (image data, music encoding - not readable).

We can write any data we like to a file. Once a file has been written, it just consists of a series of bytes.

We ha e to understand the format of the file in order to read it. A sequence of 12 bytes in a binary file could be 12 characters, 12 8-bit signed integers, 12 8-bit unsigned integers, etc.
In binary mode, each and every byte of the file is accessible.

C programs automatically open three files on your behalf
- standard input - the normal input device for your system, usually the keyboard.
- standard output - usually the display screen.
- standard error - usually the display screen.

Standard input is the file that is read by getchar() and scanf().
Standard output is used by `putchar()`, `puts()`, and `printf()`.

Redirection causes other files to be recognized as the standard input or standard output.

The purpose of the standard error output file is to provide a logically distinct place to send error messages.

**A stream is an abstract representation of any external source or destination for data.**
- the keybard, the command lline on your display, and files on a disk are all examples of things we can work with as streams.
- The C library provides functions for reading and writing to or from data streams. We use the same input/output functions for reading and writing any external device that is mapped to a stream.

## Accesing files
Files on disk have a name and the rules for naming files are determined by the operating system. We may have to adjust the names depending on what OS the program is running.

A program references a file through a file pointer (or stream pointer, since it works on more than a file).
- We associate a file pointer with a file programmatically when the program runs.
- pointers can be reused to point to different files on different occasions.

A file pointer points to a struct oftype FILE that represents a stream. It contains information about the file.
- Whether we want to read or write or update the file.
- The address of the buffer in memory to be used for data.
- a pointer to the current position in the file for the next operation.
The above is all set via input/output file operations.


If we want to use several files simultaneously in a program, we have to create a separate file pointer for each file. We can only reuse the file pointer if we are reading and writing at different times. There is a limit to the number of open files we can have at one open time. We can look at the limit in the standard I/O library, which has a constant defined as `FOPEN_MAX`. It all depends on what operating system we are running on.
Usually we don't want to create and open a ton of files at once. Writing and reading the files is an expensive operation, because we are writing on the hard drive It is not as fast as writing to the memory, so it can cause the program to be less responsive.

## Opening a file
We associate a specific external file name with an internal pointer variable through a process referred to as opening a file, via the `fopen()` function. This returns the file pointer for a specific external file.

~~~c
FILE *fopen(const char * restrict name, const char * restrict mode);
~~~

The first argument to the function is a pointer to a string that is the name of the external file we want to process.
- We can specify the name explicitly or use a char poionter that contains the address of the character string that defines the file name.
- We can obtain the file name through the command line, as input from the user, or defined as a constant in our program.

The second argument to the fopen() function is a character string that represents the file mode. It specifies what we want to do with the file. A file mode specification is a character string between double quotes.

Assuming the call to `fopen()` is successful, te function returns a pointer of type `FILE*` that we can use to reference the file in further input/output operations using other functions in the ibrary.
If the file cannot be opened for some reason, `fopen()` returns `NULL`.

| Mode | Description                                                                                                                                        |
| ---- | -------------------------------------------------------------------------------------------------------------------------------------------------- |
| "w"  | Open a text file for write operations. If the file exists, its current contents are discarded.                                                     |
| "a"  | Open a text file for append operations. All writes are to the end of the file.                                                                     |
| "r"  | Open a text file for read operations.                                                                                                              |
| "w+" | Open a text file for update (reading and writing), first truncating the file to zero length if it exists or creating the file if it doesn't exist. |
| "a+" | Open a text file for update (reading and writing) appending to the end of the existing file, or creating the file if it does not yet exist.        |
| "r+" | Open a text file for update (for both reading and writing).                                                                                        |


## Write mode
If you want to write to an existing text file with the name `myfile.txt`

~~~c
FILE *pfile = NULL;
char *filename = "myfile.text";
pfile = fopen(filename, "w"); // Open myfile.txt to write it

if(pfile != NULL)
{
    printf("Failed to open %s.\n", filename);
}

~~~

This opens the file and associates the file with the name `myfile.txt` to the file pointer `pfile`. The mode as `"w"` means we can only write to the file, we cannot read it. If a file with the name `myfile.txt` does not exist, the call to `fopen()` will create a new file with this name.

If we only provide the file name without any path specification, the file is assumed to be in the current directory. We can also specify a string that is the full path and name for the file.

On opening a file for writing, the file length is truncated to zero and the position will be at the beginning of any existing data for the first operation. Any data that was previously written to the file will be lost and overwritten by any write operations.

## Append mode
If we want to add to an existing text file rather than overwrite it, we can use the append mode.

~~~c
pFile = fopen("myfile.txt", "a"); // open myfile.txt to add to it
~~~

**Don't forget that we should always test the return value for null each time**

When we open a file in append mode all write operations will be at the end of the data in the file on each write operation. All write operations append date to the file and we cannot update the existing contents in this mode.

## Read mode
If we want to read a file.

~~~c
pFile = fopen("myfile.txt", "r");
~~~

This positions the file to the beginning of the data. The file must already exist, if it doesn't it will return NULL.


## Renaming a file
Renaming a file is very easy. Just use the `rename()` function.

~~~c
int rename(const char *oldname, const char *newname);
~~~

The integer that is returned will be 0 if the name change was successful and nonzero otherwise.

The file must not be open when we call `rename()`. Otherwise the operation will fail.

~~~c
if(rename("C:\\temp\\myfile.txt","C:\\temp\\myfile_copy.txt"))
    printf("Failed to rename file");
else
    printf("File renamed successfully");
~~~


## Closing a file
When we have finished with a file, we need to tell the operating system so that it can free up the file. We can do this by calling the `fclose()` function.

`fclose()` accepts a file pointer as an argument. Returns `EOF` (int) if an error occurs. This is a special character called the *end of file* character. Defined in stdio.h as a negative integer that is usually equivalent to the value -1.
If the operation is successful the function will return 0.

~~~c
fclose(pfile);
pfile = NULL;
~~~

The result of calling `fclose()` is that the connection between the pointer, `pfile`, and the physical file is broken. `pfile` can no longer be used to access the file.

If the file was being written, the current contents of the output buffer are written to the file to ensure that data is not lost.

It is a good programming practice to close a file as soon as we have finished with it. This prevents output data loss.

We must also close a file before attempting to rename it or remove it.

## Deleting a file
We can delete a file by invoking the `remove()` function, declared in stdio.h.

~~~c
remove("myfile.txt");
~~~

This will delete the file that has the name myfile.txt from the current directory. The file cannot be open when we try to delete it.

We should always double check with operations that delete files. We could wreck our system if we do not.

## Reading characters from a text file
the `fgetc()` functions reads a character from a text file that has been opened for reading.
This takes a file pointers as its only argument and returns the character read as type int.

~~~c
int mchar = fgetc(pfile); // Reads a character into mchar with pfile 
~~~

The return type is int because `EOF` will be returned if the end of the file has been reached.

The function `getc()` which is wequivalent to `fgetc()`, is also available. It requires an argument of type `FILE*` and returns the characer read as type int.
It is virtually identical to `fgetc()`, except `getc()` may be implemented as a *macro*, whereas `fgetc()` is a function.

We can read the contents of a file again when necessary. The `rewind()` function positions the file that is specified by the file pointer argument at the beginning.
