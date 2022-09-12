/* Write a program to check whether a triangle is valid or not, when the three angles of the triangle are entered through the keyboard. A triangle is valid if the sum of all the three angles is equal to 180 degrees.*/

#include<stdio.h>

int main(){

    int angle_A, angle_B, angle_C, sum;

    printf ("Enter the value of Angle A: ");
    scanf ("%d", &angle_A);

    printf ("Enter the value of Angle B: ");
    scanf ("%d", &angle_B);

    printf ("Enter the value of Angle C: ");
    scanf ("%d", &angle_C);

    sum = angle_A + angle_B + angle_C;

    if (sum == 180)

    {

    printf ("The Triangle is valid");

    }

    else
    {

    printf ("The Triangle is not valid");

    }

    return 0;

}
