//Write a C program to calculate Grade

#include<stdio.h>

int main(){

    float mark;

    printf("Please Enter Your Mark: ");
    scanf("%f", &mark);


    if (mark >=0 && mark <=100){


        if (mark >=80 && mark <=100)

            {
                printf("A+");
            }

        else if (mark >=75 && mark <=79)

            {
            printf("A");
            }

        else if (mark >=70 && mark <=74)

            {
            printf("A-");
            }

        else if (mark >=65 && mark <=69)

            {
            printf("B+");
            }

        else if (mark >=60 && mark <=64)

            {
            printf("B");
            }

        else if (mark >=55 && mark <=59)

            {
            printf("B-");
            }

        else if (mark >=50 && mark <=54)

            {
            printf("C+");
            }

        else if (mark >=45 && mark <=49)

            {
            printf("C");
            }

        else if (mark >=40 && mark <=44)

            {
            printf("D");
            }

        else

            {
                printf("F");
            }

    }


    else

    {
        printf("The Mark Is Not Valid");
    }



    return 0;



}
