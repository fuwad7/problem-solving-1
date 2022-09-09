/*
The length & Width of a rectangle and radius of a circle are input through the keyboard. Write a program to calculate the area & perimeter of the rectangle, and the area & circumference of the circle.
*/

#include <stdio.h>

int main()
{
    float pi = 3.1416;

    float rectLength, rectWidth, circleRadius, rectArea, rectParameter, circleArea, circleCircumference;

    printf("Enter the Length of Rectangle: ");
    scanf("%f", &rectLength);
    printf("Enter the Width of Rectangle: ");
    scanf("%f", &rectWidth);
    printf("Enter the Radius of a Circle: ");
    scanf("%f", &circleRadius);

    rectArea = rectLength * rectWidth;
    rectParameter = 2 * (rectLength + rectWidth);

    circleArea = pi * circleRadius * circleRadius;
    circleCircumference = 2 * pi * circleRadius;

    printf("The area of rectangle is %.2f \n", rectArea);
    printf("The parameter of rectangle is %.2f \n", rectParameter);
    printf("The area of circle is %.2f \n", circleArea);
    printf("The circumference of circle is %.2f \n", circleCircumference);

    return 0;
}
