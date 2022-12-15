#include<stdio.h>

int main() {
    char str[100];
    int i;

    printf("Enter two values:");
    scanf("%s %d", str, &i); // In the case of str, & is not used

    printf("\nYou entered:%s and %d", str, i);
    
    //=====================================//
    //=========== Reading a double =======//
    double x;

    scanf("%lf", &x);
    printf("The value entered was: %lf", x);

    return 0;
}