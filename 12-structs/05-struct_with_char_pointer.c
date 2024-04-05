#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define SLEN 20
struct namect 
{
    char * fname;
    char * lname;
    int letters;
};

void getinfo(struct namect * pst)
{
    char temp[SLEN];
    printf("Please enter your first name.\n");
    fgets(temp, SLEN, stdin);

    // allocate memory to hold name
    pst->fname = (char *)malloc(strlen(temp) + 1);

    // copy name to allocated memory
    strcpy(pst->fname, temp);
    printf("Please enter your last name.\n");
    fgets(temp, SLEN, stdin);
    pst->lname = (char *)malloc(strlen(temp)+1);
    strcpy(pst->lname,temp);
}

int main()
{
    struct namect * newName;
    getinfo(newName);

    return 0;
}