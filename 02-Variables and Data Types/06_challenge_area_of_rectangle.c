#include<stdio.h>

/**
 * Challenge: 
 * Create a C program that displays the perimeter and area of a rectangle
 * The program should create 4 variables of type double
 * - one variable to stroe the width of the rectangle
 * - one variable to store the height of the rectangle
 * - one variable to store the perimeter of the rectangle
 * - one variable to store the area of the rectangle
 * 
 * The program should perform the calculation for the perimeter of a rectangle
 * - Use the + operator addition and the * operator for multiplication
 * - Perimeter is calculated by adding the height and width and then multiplying by two
 * - Area is calculated by multiplying the width * height variables
 */

int main()
{
    float width, height, area, perimeter;

    printf("Please enter the width of the rectangle\n");
    scanf("%f", &width);

    printf("\nPlease enter the height of the rectangle\n");
    scanf("%f", &height);

    area = width * height;
    perimeter = (width + height) * 2.0f;

    printf("\nArea of the rectangle: %.2f\n", area);
    printf("Perimeter of the rectangle: %.2f\n", perimeter);

    return 0;
}