// Write a C program to read the value of an integer m and display the value of n is 1 when
//m is larger than 0, 0 when m is 0 and -1 when m is less than 0.

#include<stdio.h>

int main(){

    float m;

    printf("Enter The Value Of M: ");
    scanf("%f",&m);


    if (m>0)

    {
        printf("The Value Of N Is: 1");
    }

    else if (m==0)

    {
        printf("The Value Of N Is: 0");
    }

    else

    {
        printf("The Value Of N Is: -1");
    }

    return 0;

}
