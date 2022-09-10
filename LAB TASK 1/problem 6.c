/*
Two numbers are input through the keyboard into two locations C and D. Write a program to interchange the contents of C and D.
*/

#include <stdio.h>
int main()
{
    int c, d, x;

    printf("Enter the value of C: ");
    scanf("%d", &c);
    printf("Enter the value of D: ");
    scanf("%d", &d);

    x = c;
    c = d;
    d = x;

    printf("The value of C after interchanging is: %d \n", c);
    printf("The value of D after interchanging is: %d", d);

    return 0;
}
