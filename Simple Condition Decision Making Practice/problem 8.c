/*Write a C program to determine whether a given number is Zero (0) or not.*/

#include<stdio.h>

int main(){

    float number;

    printf ("Enter A Number: ");
    scanf ("%f", &number);

    if ( number == 0)

    {
        printf ("The Given Number %.2f Is Zero", number);
    }

    else

    {
        printf ("The Given Number %.2f Is Not Zero", number);
    }

    return 0;
}
