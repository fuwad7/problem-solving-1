/*Write a C program to determine whether a number is negative or not.*/

#include<stdio.h>

int main(){

    int number;

    printf ("Enter A Number: ");
    scanf ("%d", &number);

    if ( number < 0)
    {
        printf ("The Given number %d Is Negative", number);
    }

    else

    {
        printf ("The Given Number %d Is Not Negative", number);
    }

    return 0;
}
