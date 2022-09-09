/*
Temperature of a city in Fahrenheit degrees is input through the keyboard. Write a program to convert this temperature into Centigrade degrees.
*/

#include <stdio.h>

int main()
{

    float tempInFahrenheit, tempInCentigrade;

    printf("Enter the temperature in Fahrenheit: ");
    scanf("%f", &tempInFahrenheit);

    tempInCentigrade = (tempInFahrenheit - 32) * 5 / 9;

    printf("%f Fahrenheit is %.2f Centigrade", tempInFahrenheit, tempInCentigrade);

    return 0;
}
