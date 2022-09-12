/*Write a program to check if the area of the triangle is greater than the perimeter of the triangle.*/

#include<stdio.h>

int main(){

    int left_length, right_length, base_length, height, perimeter;
    float area;

    printf ("Enter The Right Length: ");
    scanf ("%d", &right_length);

    printf ("Enter The Left Length: ");
    scanf ("%d", &left_length);

    printf ("Enter The Height: ");
    scanf ("%d", &height);

    printf ("Enter The Base Length: ");
    scanf ("%d", &base_length);

    area = .5 * base_length * height;
    perimeter = left_length + right_length + base_length;

    if ( area > perimeter)

    {
        printf ("The Area %.2f Is Greater Than The Perimeter %d", area, perimeter);
    }

    else

    {
        printf ("The Perimeter %d Is Greater Than The Area %f", perimeter, area);
    }

    return 0;
}
