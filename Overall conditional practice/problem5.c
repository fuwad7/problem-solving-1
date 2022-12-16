//If integer variable currentNumber is odd,This program changes a integers value so that it is now 3 times the value plus 1, otherwise change its value so that it is now half of the value

#include<stdio.h>

int main()
{

    int current_number;
    printf("Enter a Number: ");
    scanf("%d",&current_number);

    if ((current_number %2)!=0)
    {
        printf("The value of number is %d",(current_number*3)+1);
    }

    else
    {
        printf("The value of number is %d",current_number/2);
    }

    return 0;

}
