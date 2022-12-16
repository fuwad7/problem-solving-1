//Convert degree celsius to fahrenheit & fahrenheit to celsius

#include<stdio.h>

int main (){

    int choice;
    float fahrenheit, celsius;

    printf("\n1.Celsius to Fahrenheit \n2.Fahrenheit to Celsius\nChoose Option: ");
    scanf("%d",&choice);

    if (choice==1)

    {

    printf("Enter temperature in Celcius: ");
    scanf("%f",&celsius);
    printf("%.2f Celsius is %.2f Fahrenheit",celsius,(celsius*1.8)+32);

    }


    else if (choice == 2)

   {

    printf("Enter temperature in Fahrenheit: ");
    scanf("%f",&fahrenheit);
    printf("%.2f Fahrenheit is %.2f Celsius",fahrenheit,(fahrenheit-32)*5/9);

   }

    else

    {
        printf("Invalid Input");
    }

    return 0;

}
