#include<stdio.h>
#include<stdbool.h>

/*
    Write a function to count the number of character in a string (length)
    cannot use the strlen library function
    function should take a character array as a parameter
    should return an int.
*/
int getStringLength(char *str);
/*
    Write a function to concatenate two character strings
    - cannot use the strcat library function
    - function should take 3 parameters
        - char result[]
        - const char str1[]
        - const char str2[]
        - can return void
*/
void concatenateString(char str1[], char str2[], char concatenated[]);
/*
    Write a function that determines if two strings are equal
    - cannot use strcmp library function
    - function should take two const char arrays as parameters and return a Boolean of true if they are equal and false otherwise
*/
bool areStringsEqual(char str1[], char str2[]);

int main(void)
{
    char str1[] = "string";
    char str2[] = "Concatenated";
    char str3[getStringLength(str1) + getStringLength(str2)];

    concatenateString(str1, str2, str3);
    
    printf("%i\n", getStringLength("length"));
    printf("%s\n", str3);
    printf("%i", areStringsEqual("equal", "equal"));
    return 0;
}

int getStringLength(char *str)
{
    int length = 0;
    while(str[length] != '\0') length++;

    return length;
}

void concatenateString(char str1[], char str2[], char concatenated[])
{
    int str1Length = getStringLength(str1);
    int str2Length = getStringLength(str2);
    int concatenatedStringLength = str1Length + str2Length;

    for(int i = 0; i < concatenatedStringLength; i++)
    {
        concatenated[i] = i < str1Length ? str1[i] : str2[i - str1Length];
    }
    concatenated[concatenatedStringLength] = '\0';
}

bool areStringsEqual(char str1[], char str2[])
{
    int str1Length = getStringLength(str1);
    int str2Length = getStringLength(str2);
    if (str1Length != str2Length) return false;
    
    bool areEqual = true;
    for(int i = 0; i < str1Length; i++)
    {
        if(str1[i] != str2[i])
        {
            areEqual = false;
            break;
        }
        continue;
    }
    return areEqual;
}