#include<stdio.h>

/* 
    Challenge nº 2: Weather program
    In this challenge, we must create a C program that uses a two dimensional array.
    This program will find the total rainfall for each year, the average yearly rainfall, and the average rainfall for each month.

    Input will be a 2D array with hard coded values for rainfall amounts for the past 5 years
    - the array should have 5 rows and 12 columns
    - Rainfall amounts should be floating point numbers

    The output for the program should look like this

    YEAR        RAINFALL (inches)
    2010        40.9
    2011        23.2
    2012        30.4
    2013        44.0
    2014        32.9

    The yearly average is 29.4 inches

    MONTHLY AVERAGES

    Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec
    3.4 3.4 2.0 2.1 2.5 5.4 3.3 5.4 2.4 3.2 1.2 9.3 
*/

int main() {
    int yearsAmount = 5;
    int monthsAmount = 12;
    float input[5][12] = {
        {3.2, 1.2, 3.3, 3.5, 5.3, 2.1, 4.4, 3.5, 3.2, 7.3, 7.7, 8.7},
        {3.2, 1.2, 3.3, 3.5, 5.3, 2.1, 4.4, 3.5, 3.2, 7.3, 7.7, 8.7},
        {3.2, 1.2, 3.3, 3.5, 5.3, 2.1, 4.4, 3.5, 3.2, 7.3, 7.7, 8.7},
        {3.2, 1.2, 3.3, 3.5, 5.3, 2.1, 4.4, 3.5, 3.2, 7.3, 7.7, 8.7},
        {3.2, 1.2, 3.3, 3.5, 5.3, 2.1, 4.4, 3.5, 3.2, 7.3, 7.7, 8.7},
    };

    //========================================================//
    // Year totals
    //========================================================//
    float yearTotal[yearsAmount];
    for (int i = 0; i < yearsAmount; i++) {
        float newAmount = 0;
        for(int j = 0; j < monthsAmount; j++) {
            newAmount += input[i][j];
        }
        yearTotal[i] = newAmount;
    }
    // Printing Year totals result
    printf("YEAR\tRAINFALL(inches)\n");
    for(int i = 0; i < yearsAmount; i++) {
        printf("Year %d\t%.2f\n", i+1,yearTotal[i]);
    }

    //========================================================//
    // Yearly average //
    //========================================================//
    float yearlyAverage = 0;
    for(int i = 0; i < yearsAmount; i++){
        yearlyAverage += yearTotal[i];
    }
    yearlyAverage /= yearsAmount;
    // Printing Yearly average
    printf("\nThe yearly average is %.2f inches\n", yearlyAverage);

    //========================================================//
    // Monthly average
    //========================================================//
    float monthlyAverage[monthsAmount];
    for (int j = 0; j < monthsAmount; j++) {
        float newAmount = 0;
        for(int i = 0; i < yearsAmount; i++) {
            newAmount += input[i][j];
        }
        monthlyAverage[j] = newAmount / yearsAmount;
    }
    // Printing Monthly average
    printf("\nMonthly Average\n");
    printf("Jan\tFeb\tMar\tApr\tMay\tJun\tJul\tAug\tSep\tOct\tNov\tDec\n");
    for (int i = 0; i < monthsAmount; i++) {
        printf("%.2f\t", monthlyAverage[i]);
    }

    return 0;
}