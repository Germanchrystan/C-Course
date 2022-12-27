#include<stdio.h>
#include<stdbool.h>

int main(void)
{
    enum gender {
        male, 
        female
    };

    enum gender myGender = male;
    
    bool isMale = (myGender != female);

    printf("%d\n", isMale);

    return 0;
}