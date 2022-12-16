//A Program to create BMI with input

#include<stdio.h>
int main(){

    float height, weight, bmi;
    printf("Enter your Height (Meter): ");
    scanf("%f",&height);
    printf("Enter your Weight (KG): ");
    scanf("%f",&weight);

    bmi= weight/(height*height);

    if (bmi< 18.5)

    {
        printf("Your BMI is %.1f \nStatus: Underweight",bmi);
    }

    else if (bmi>= 18.5 && bmi<= 24.9)

    {
        printf("Your BMI is %.1f \nStatus: Normal",bmi);
    }

    else if (bmi>= 25 && bmi<= 29.9)

    {
        printf("Your BMI is %.1f \nStatus: Overweight",bmi);
    }

    else if (bmi>= 30 && bmi<= 34.9)

    {
        printf("Your BMI is %.1f \nStatus: Obese",bmi);
    }

    else

    {
        printf("Your BMI is %.1f \nStatus: Extremely Obese",bmi);
    }

    return 0;
}
