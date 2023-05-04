#include<stdio.h>
#include<string.h>

int main(void)
{
    char str[] = "The quick brown fox";
    char ch = 'q';
    char *pGot_char = NULL;
    pGot_char = strchr(str,ch);
    if (pGot_char == NULL)
    {
        printf("character was not found");
    }
    else
    {
        printf("%s", pGot_char); // quick brown fox
    }

    return 0;
}