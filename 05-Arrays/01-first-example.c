#include<stdio.h>

int main(void)
{
    int grades[10]; // Array storing 10 values
    int count = 10; // number of values to be read
    long sum = 0; // Sum of the numbers
    float average = 0.0f; // Average of the numbers

    printf("\nEnter 10 grades:\n");

    // Read the ten numbers to be averaged
    for (int i = 0; i < count; i++)
    {
        printf("%2u>", i + 1);
        scanf("%d", &grades[i]);
        sum += grades[i];
    }
    average = (float)sum/count;
    printf("\nAverage of the ten grades entered is: %.2f\n", average);

    return 0;
}