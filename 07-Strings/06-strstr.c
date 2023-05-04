#include<stdio.h>
#include<string.h>

int main(void)
{
    char text[] = "Every dog has his day";
    char word[] = "dog";
    char *pFound = NULL;
    pFound = strstr(text, word);
    if (pFound == NULL)
    {
        printf("character was not found");
    }
    else
    {
        printf("%s", pFound); // dog has his day
    }

    return 0;
}