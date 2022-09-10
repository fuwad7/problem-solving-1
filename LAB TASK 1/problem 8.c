/* f a five-digit number is input through the keyboard, write a program to reverse the number. */

#include<stdio.h>
int main() {

int a, b, c, d, e;

    printf ("Enter a five digit number: ");
    scanf ("%1d%1d%1d%1d%1d", &a, &b, &c, &d, &e);

    printf ("The reverse number is: %d%d%d%d%d \n", e, d, c, b, d);


    return 0;

}
