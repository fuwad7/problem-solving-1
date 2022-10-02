//Write a c program to display a menu in a restaurant and input user choice.

#include<stdio.h>

int main()
{

    int choice;

    printf("Food Menu\n1.Basmati Kacchi\n2.Chicken Roast\n3.Beef Rezala\n4.Morog Pulao\n5.Coca Cola\n");

    printf("Enter Your Choice: ");
    scanf("%d", &choice);

    if ( choice == 1)

    {
        printf("You Have Choosen Basmati Kacchi");

    }

    else if ( choice == 2)

    {
        printf("You Have Choosen Chicken Roast");
    }

    else if ( choice == 3)

    {
        printf("You Have Choosen Beef Rezala");
    }

    else if ( choice == 4)

    {
        printf("You Have Choosen Morog Pulao");
    }

    else if ( choice == 5)

    {
        printf("You Have Choosen Coca Cola");
    }

    else

    {
        printf("Out Of The Menu");
    }

    return 0;
}
