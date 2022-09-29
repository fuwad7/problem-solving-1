//Write a C program to input basic salary of an employee and calculate its Gross salary

#include<stdio.h>

int main(){

    float basic_salary,house_rent, dearness_allowance, gross_salary;

    printf("Enter Basic Salary: ");
    scanf("%f", &basic_salary);

    if (basic_salary <= 10000)

    {
        house_rent = basic_salary *.20;
        dearness_allowance = basic_salary *.80;
        gross_salary = basic_salary + house_rent + dearness_allowance;

        printf("The Gross Salary Is %.2f",gross_salary);
    }

    else if (basic_salary <= 20000)

    {
         house_rent = basic_salary *.25;
         dearness_allowance = basic_salary *.90;
         gross_salary = basic_salary + house_rent + dearness_allowance;

         printf("The Gross Salary Is %.2f",gross_salary);
    }

    else if (basic_salary > 20000)

    {

         house_rent = basic_salary *.30;
         dearness_allowance = basic_salary *.95;
         gross_salary = basic_salary + house_rent + dearness_allowance;

         printf("The Gross Salary Is %.2f",gross_salary);
    }

    else

    {
        printf("Wrong Input");
    }

    return 0;


}
