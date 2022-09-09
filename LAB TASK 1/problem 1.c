/*
The distance between Mirpur and Ashulia is input through the keyboard. Write a program to
convert and print this distance in meter, feet, inches and centimeters.
*/

#include <stdio.h>

int main()
{
    float distanceInKm, distanceInMeter, distanceInFeet, distanceInInch, distanceInCentimeters;

    printf("Enter the distance between Mirpur and Asulia = ");
    scanf("%f", &distanceInKm);

    distanceInMeter = distanceInKm * 1000;
    distanceInFeet = distanceInKm * 3280.84;
    distanceInInch = distanceInKm * 39370.1;
    distanceInCentimeters = distanceInKm * 100000;

    printf("The distance is %.2f Kilometers\n", distanceInKm);
    printf("The distance is %.2f Meter\n", distanceInMeter);
    printf("The distance is %.2f Feet\n", distanceInFeet);
    printf("The distance is %.2f Inches\n", distanceInInch);
    printf("The distance is %.2f Centimeters\n", distanceInCentimeters);

    return 0;
}
