# The C Programming Language
C is a general purpose, imperative computer programming language that supṕorts structured programming. By imperative, we mean that it organized around statements, that change a program's state.

Currently it is one of the most widely used programming languages of all time.

C is a modern language.
- Has most basic control structures and features of modern languages.
- Designed for top-down planning: .
- Organized around the use of functions (modular design). Structured programming.
- Very reliable and readable program

C is used on everything from minicomputers, Unix/Linux systems to pc's and mainframes.

C is the preferred language for producing word preocessing programs, spreadsheets and compilers.

C has become popular for programming embedded systems, used to program microprocessors found in automobiles, cameras, DVD players, etc.

C has and continues to play a strong role in the development of Linux.

C programs are easy to modigy and easy to adapt to new models or languages.

C is a subset of C++ with object-oriented programming tools added. Any C program is a  valid C++ program. By learning C, you also learn much of C++.

C remains a core skilñl neeeded by corporations and ranks in the top 10 of desired skills.

C provides constructs that map efficiently to typical machine instructions and thus is used by programs that were previously implemented in assembly language. It provides low level access to memory (has many low-level capabilities), and requires minimal run time support.

C is available for most computers, and it is hardware independent.

# A bit of history
C was invented in 1972 by Dennis Ritchie of Bell Laboratories. Ritchie was working on the design of the UNIX operating System, which is a precursor to Linux.
C was created as a tool for working programmers. Its main goal is to be an useful language, with easy readability and writability.

C initially became widely known as the development language of the UNIX operating system. Virtually all new major operating systems are written in C and/or C++.

The language evolved grom a previous programming language named B. C uses many of the important concepts of B while adding data typing and other powerful features. B was a typeless language, every data item occupied one "word" in memory, and the burden of typing variables fell on the shoulders of the programmer.

By the late 1979s, C had evolved into what is now referred to as "traditional C", which is what we are learning here. There are different versions of C. There is C89, C90, and C11. The names basically represent the years 1989, 1990, 1999, and 2011. They are standard versions of C. A program written only in standard C and without any hardware depenmdent assumptions will ruyn correctly on any platform with a standar C compiler. 

- Most of the C code we may see out there today is written in based on C89, it has the basic constructs.

- C99 was a little revision that refines and expands the capabilities of C. It has not been widely aqdopted and not all popular C compilers support it.

- The current standard is commonly referred to as C11. Some elements of the language as defined by C11 are optional. It is also possible that a C11 compiler may not implement all of the language features mandated by the C11 standard. This class will base its examples and concepts off C11.

# Compilers
A compiler is a program that translates the high lvel language source code into the detailed set of machine language instructions the computer requires. The program does the high level thinking and the compiler generates the tedious instructions to the cpu.

Compilers will also check that your program has valid syntax for the programming language that you are compiling. It finds errors, it reports them to you and doesn't produce an executable until you fix them.

# Writing a program
The act of writing a C program can be broken down into multiple steps

1. Define the program objectives.
    - Understand the requirements of the program.
    - Get a clear idea of what you want the program to accomplish.
2. Design the program.
    - Decide how the program will meet the above requirements.
    - What should the user interface be like?
    - How should the program be organized?
3. Write the code.
    - Start implementation, translate the design in the syntax of C
4. Compile.
    - Translate the source code into machine code (executable code).
5. Run the program.
    - The executable file is a program you can run.
6. Test and debug the program.
    - Just because a program is running, does not mean it works as intended.
    - Need to test, to see that your program does what it is supposed to do.
    - Debugging is the process of finding and fixing program errors.
    - Making mistakes is a natural part of learning (and programming, i might add).
7. Mantain and modify the program.
    - Programs are released and used by many people.
    - Have to continue to fix new bugs or add new features.

(Taken from the book "C Primer Plus", by Stephen Prata)


# Estructure of a C program
This is the basic structure for all C programs.

~~~c
#include<stdio.h>

int main(){
    printf("Hi");
    return 0;
}

~~~

The main function is a special function that servers as the entry point for the program. There should be one main function in all C programs. 

The int before main indicates the function is going to return an integer. This usually represents whether or not there was an error in the program. So when the program returns 0, it means that there were no errors in it.

NOTE: In C all statements end in a semicolon!

