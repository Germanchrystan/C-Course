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

