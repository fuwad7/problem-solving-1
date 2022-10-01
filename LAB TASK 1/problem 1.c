/*
Niloy's basic salary is input through the keyboard. His dearness allowance is 40% of his basic
salary and house rent is 20% of his basic salary. Write a program to calculate his gross salary.
*/

#include <stdio.h>

int main()
{
    float basic_salary, dearness_allowance, house_rent, gross_salary;

    printf("Enter Basic Salary: ");
    scanf("%f", &basic_salary);

    dearness_allowance = .4 * basic_salary;
    house_rent = .2 * basic_salary;

    gross_salary = basic_salary + dearness_allowance + house_rent;

    printf("The gross salary of Niloy is %.2f", gross_salary);
    return 0;
}
