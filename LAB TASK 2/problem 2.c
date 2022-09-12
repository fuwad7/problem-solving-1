/* Any integer is input through the keyboard. Write a program to find out whether itis an odd number or even number.*/

#include<stdio.h>

int main(){

    int number;

    printf ("Enter the number: ");
    scanf ("%d", &number);

    if ( number % 2 == 0){
        printf ("The number %d is even", number);
    }

    else
    {
        printf ("The number %d is odd", number);
    }
    return 0;
}
