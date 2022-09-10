/*
If a five-digit number is input through the keyboard, write a program to print a new number by adding one to each of its digits. For example, if the number that is input is 12391 then the output should be displayed as 23502.*/

#include <stdio.h>

int main()
{
    int number, newNumber;

    printf("Enter A Five Digit Number: ");
    scanf("%d", &number);

    newNumber = number + 11111;
    printf("The Number After Increasing Each Of Its Digit By 1 Is: %d", newNumber);

    return 0;
}
