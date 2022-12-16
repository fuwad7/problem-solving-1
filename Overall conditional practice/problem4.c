//A Program to create a simple calculator that cam do sum, substract, division, multipication according to users choice

#include<stdio.h>

int main(){

    int choice;
    float number1, number2;

    printf("Enter the First number: ");
    scanf("%f",&number1);
    printf("Enter the Second number: ");
    scanf("%f",&number2);

    printf(" 1.Summation \n 2.Subtraction \n 3.Division \n 4.Multipication \n\nEnter Your Choice: ");
    scanf("%d",&choice);

    if (choice==1)

    {
        printf("\nThe Summation of %.2f & %.2f is %.2f",number1,number2,number1+number2);
    }

    else if (choice==2)

    {
        printf("\nThe Subtraction of %.2f & %.2f is %.2f",number1,number2,number1-number2);
    }

    else if (choice==3)

    {
        printf("\nThe Division of %.2f & %.2f is %.2f",number1,number2,number1/number2);
    }

    else if (choice==4)

    {
        printf("\nThe Multipication of %.2f & %.2f is %.2f",number1,number2,number1*number2);
    }

    else

    {
        printf("\nInvalid Number");
    }
    return 0;

}
