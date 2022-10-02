/* If the ages of Arif and Joy are input through the keyboard, write a program to determine the youngest of them.*/

#include<stdio.h>

int main(){

    int arif_age, joy_age;

    printf ("Enter Arif's age: ");
    scanf ("%d", &arif_age);

    printf ("Enter Joy's Age: ");
    scanf ("%d", &joy_age);

    if (arif_age > joy_age)

    {

    printf ("Joy is the youngest.", joy_age);

    }

    else

    {
        printf ("Arif is the youngest.", arif_age);

    }

    return 0;
}
