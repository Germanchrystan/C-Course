#include<stdio.h>
#include<stdbool.h>
/**
 * In this challenge, we must create a program that finds
 * all the prime numbers from 3 - 100.
 * There will be no input to the program.
 * The output will be each prime number separated by a space on a single line.
 * We will need to create an array that will store each prime number as it is generated
 * We can hardcode the first two prime numbers (2 and 3) in the primes array.
 * We should utilize loops to only find prime numbers up to 100,
 * and a loop to print out the primes array
 *
 * The criteria that can be used to identify a prime number is that a number is 
 * considered prime if it is not evenly divisible by any other previous prime numbers. 
 */

int main(void)
{
    int primesLength = 100;
    int primes[primesLength];
    int primesIndex = 0;

    for(int i = 1; i < primesLength; i++)
    {   
        bool isPrime = true;
        if (i <= 3)
        {
            primes[primesIndex] = i;
            primesIndex++;
            continue;
        }

        if (i % 2 == 0 || i % 3 == 0)
        {
            isPrime = false;
            continue;
        }

        for(int j = 3; j < primesIndex; j++)
        {
            if (i % primes[j] == 0)
            {
                isPrime = false;
                break;
            }
        }
        
        if(isPrime)
        {
            primes[primesIndex] = i;
            primesIndex++;
        }
    }

    printf("Here are the prime numbers: ");
    for(int i = 0; i < primesLength; i++)
    {   
        if(primes[i] == 0)
        {
            break;
        }
        printf("%d ", primes[i]);
    }
    printf("\n");
}