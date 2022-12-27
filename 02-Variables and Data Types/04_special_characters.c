#include<stdio.h>
#include<stdbool.h>

int main(void)
{
    int integerVar = 100;
    float floatingVar = 331.65;
    double doubleVar = 8.44e+11;
    char charVar = 'W';

    _Bool boolVar = 0;
    bool stdBoolVar = true;

    printf("integerVar = %i\n", integerVar);
    printf("floatingVar = %f\n", floatingVar);
    printf("doubleVar = %e\n", doubleVar);
    printf("doubleVar = %g\n", doubleVar);
    printf("charVar = %c\n", charVar);

    printf("boolVar = %i\n", boolVar);
    printf("stdBoolVar = %i\n", stdBoolVar);

    float x = 3.9999999923;

    printf("Rounding a long float number: %.2f", x);

    return 0;
}