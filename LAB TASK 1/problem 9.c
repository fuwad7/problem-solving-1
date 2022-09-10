/* If a four-digit number is input through the keyboard, write a program to obtain the sum of the
first and last digit of this number. */

#include <stdio.h>

int main(){

    int a, b, c, d, sum;

    printf ("Enter four digit number: ");
    scanf("%1d%1d%1d%1d", &a, &b, &c, &d);


    printf ("The sum of the first and last digit of given number: %d", sum = a + d );

    return 0;
}
