//Input the value of X & Y coordinates and show which quadrant the input is as the output

#include<stdio.h>

int main(){

    float x,y;
    printf("Enter the value of X: ");
    scanf("%f",&x);
    printf("Enter the value of Y: ");
    scanf("%f",&y);

    if (x>0 && y>0)

    {
        printf("The Coordinates of (%.2f,%.2f) lies in 1st Quadrant",x,y);
    }

    else if (x<0 && y>0)

    {
        printf("The Coordinates of (%.2f,%.2f) lies in 2nd Quadrant",x,y);
    }

    else if (x<0 && y<0)

    {
        printf("The Coordinates of (%.2f,%.2f) lies in 3rd Quadrant",x,y);
    }

    else if (x>0 && y<0)

    {
        printf("The Coordinates of (%.2f,%.2f) lies in 4th Quadrant",x,y);
    }

    else if (x == 0 && y == 0)

    {
        printf("The Coordinates of (%.2f,%.2f) lies in Center",x,y);
    }

    else

    {
        printf("Invalid",x,y);
    }

    return 0;
}
