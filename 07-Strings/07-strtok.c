#include<stdio.h>
#include<string.h>

int main()
{
    char str[80] = "Hello how are you - my name is -Jason";
    const char s[2] = "-";

    // Get the first token
    token = strtok(str, s);

    // Walk through other tokens
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL,s); // Passing NULL to get the next token, as str is already tokenized.
    }
    return 0;
}