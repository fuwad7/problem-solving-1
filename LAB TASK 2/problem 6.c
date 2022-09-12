/*Write program to determine whether a number is positive or not.*/

#include<stdio.h>

int main(){

    int number;

    printf ("Enter A Number: ");
    scanf ("%d", &number);

    if ( number > 0)
    {
        printf ("The Given Number %d is Positive", number);
    }

    else

    {
        printf ("The Given Number %d is not positive", number);
    }

    return 0;
}
