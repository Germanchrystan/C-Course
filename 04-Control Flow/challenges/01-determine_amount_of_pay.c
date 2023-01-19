#include<stdio.h>

/**
 * Create a C program that calculates your weekly pay
 * 
 * The program should ask the user to enter the number of hours worked in a week 
 * via the keyboard.
 * 
 * The program should display as output the gross pay, the taxes and the net pay
 * 
 * The following assumptions should be made:
 * - Basic pay rate = $12.00/hr
 * - Overtime (in excess of 40 hours) = time and a half
 * - Tax rate:
 *      - 15% of the first $300.
 *      - 20% of the next $150.
 *      - 25% of the rest.
 * 
 * You will need to utilize if/else statements.
 */

// Pay rate constants
#define PAYRATE 12.00
#define MAX_HOURS 40

int main()
{       
    // Tax constants
    const int first300Pg = 15;
    const int next20Pg = 20;
    const int restPg = 25; 

    // variables
    int hoursWorked;
    float grossPay;

    printf("Please enter how many hours you worked this week\n");
    scanf("%d", &hoursWorked);

    // Gross pay calculation
    if(hoursWorked > MAX_HOURS)
    {
        int extraHoursWorked = hoursWorked - MAX_HOURS;
        float extraHoursPay = (PAYRATE * 1.5) * extraHoursWorked;
        grossPay = (MAX_HOURS * PAYRATE) + extraHoursPay;
        printf("You worked %d extra hours this week\n", extraHoursWorked);
        printf("The amount of gross pay you get from these extra hours: $%.2f\n", extraHoursPay);   
    } 
    else
    {
        grossPay = hoursWorked * PAYRATE;
    }
    printf("Gross pay: $%.2f\n", grossPay);

    // Taxes calculation
    float taxAmount = 0;
    float taxedAmount = grossPay;
    float netPay;

    taxedAmount -= 300; 
    if(taxedAmount >= 0)
    {
        taxAmount += 300 / 100 * first300Pg;
    
        taxedAmount -= 150;
        if(taxedAmount >= 0)
        {
            taxAmount += 150 / 100 * next20Pg;
            
            if(taxedAmount > 0)
            {
                taxAmount += taxedAmount / 100 * restPg;
            }
        }
    }
    else 
    {
        taxAmount = grossPay / 100 * first300Pg;
    }
    
    netPay = grossPay - taxAmount;
    printf("Tax amount: $%.2f\n",taxAmount);
    printf("Net Pay: $%.2f\n", netPay);

    return 0;
}