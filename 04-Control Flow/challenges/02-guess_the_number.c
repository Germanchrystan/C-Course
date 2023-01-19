#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/**
 * In this challenge, you are going to create a "Guess the number" C program
 * 
 * Your program is going to generate a random number from 0 to 20
 * 
 * You will then ask the user to guess it
 *      - User should only be able to enter numbers from 0 - 20 
 *      - If user enters a number above or below this range, 
 *      you should display an error message.
 * 
 *      - The proghram will indicate to the user if each guess is too high
 *      or too low.
 *      - The player wins the game if they can guess the number within five tries  
 */
int main()
{
    time_t t;
    srand((unsigned) time(&t));
    int randomNumber = rand() % 21;

    int tries = 5;
    int guess;
    printf("This is a guessing game.\nI have chosen a number between 0 and 20 which you must guess.\n");
    do {
        printf("You have %d tries left\n", tries);
        printf("Take a guess: ");
        scanf("%d", &guess);
        
        if(guess > randomNumber)
        {
            printf("\nYou need to go lower\n");
            tries--;
        }
        else if (guess < randomNumber)
        {
            printf("\nYou need to go higher\n");
            tries--;
        }

    } while(randomNumber != guess && tries > 0);

    printf("\n==========================================================\n");
    if (tries == 0)
    {
        printf("\nYou lost!\n");
    } 
    else if (randomNumber == guess)
    {
        printf("\nYou won!\n");
    }
    printf("\n==========================================================\n");
    return 0;
}