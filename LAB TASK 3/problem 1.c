//Write a C program that can take input a number and then decide whether the number is
//positive, negative or neutral.

#include<stdio.h>

int main()
{

    float number;

    printf("Enter A Number: ");
    scanf("%f", &number);

    if ( number > 0)

    {
        printf("The Number Is Positive");
    }

    else if ( number < 0)

    {
        printf("The Number Is Negative");
    }

    else

    {
        printf("The Number Is Neutral");
    }

    return 0;

}
