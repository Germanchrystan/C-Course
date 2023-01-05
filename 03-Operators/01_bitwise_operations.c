#include<stdio.h>

int main()
{
    unsigned int a = 60; // 0011 1100
    unsigned int b = 13; // 0000 1101
    int result = 0;

    // & operator
    result = a & b; // should be 0000 1100 => 12
    printf("result for & is %d\n", result);

    // | operator
    result = a | b; // 0011 1101 => 61
    printf("result for | is %d\n", result);

    // ^ operator
    result = a ^ b; // 0011 0001 => 49
    printf("result for ^ is %d\n", result);

    int reverseA = ~a;
    printf("result for ~a is %d\n", reverseA);

    result = a << 2; // 1111 0000
    /**
     * Actually, a is 32 bits, and we are showing the last 8
     * 0000 0000 0000 0000 0000 0000 0011 1100
     * By shifting to the left we will have
     * 0000 0000 0000 0000 0000 0000 1111 0000 => 240
     */
    printf("result is %d\n", result);

    result = a >> 4;
    /**
     * In this case, some of the bits will drop off and we will lose them
     * 0000 0011 => 3
     */
    printf("result is %d\n", result);
    
    return 0;
}