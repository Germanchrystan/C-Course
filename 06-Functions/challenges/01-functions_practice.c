#include<stdio.h>

/*
    For this challenge, you muest write three functions in a single program
    - write a function which finds the greatest common divisor of two non negative integer values and return the result
    - write a function to calculate the absolute value of a number. It should take as a parameter a float and return a float.
    - write a function to compute the square root of a number. If a negative argument is passed then a message is display, and -1.0 should be returned.
*/

unsigned int greatCommonDivisor(unsigned int x, unsigned int y);
float absoluteValue(float value);
float squareRoot(float value);

int main(void)
{
    return 0;
}

unsigned int greatCommonDivisor(unsigned int x, unsigned int y)
{
    while(x != y){
      	if(x > y) {
          	x -= y;
      	}
      	else {
          	y -= x;
      	}
  	}
  	return x;
}

float absoluteValue(float value)
{
    if(value < 0){
        return value * -1;
    }
    return value;
}

float squareRoot(float value)
{
    const float epsilon = .00001;
    float guess = 1.0;
    float returnValue = 0.0;
    
    if (x < 0)
    {
        printf("Negative argument to square root.\n");
        returnValue = -1.0;
    }
    else
    {
        while( absoluteValue(guess * guess - x) >= epsilon)
        {
            guess = (x / guess + guess) / 2.0;
        }
        returnValue = guess;
    }

    return returnValue;
}