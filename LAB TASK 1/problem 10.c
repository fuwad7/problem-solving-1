/*
In a town, the percentage of men is 52. The percentage of total literacy is 48. If total percentage of literate men is 35 of the total population, write a program to find the total number of illiterate men and women if the population of the town is 80,000
*/

#include <stdio.h>

int main()
{
    int totalPopulation = 80000;

    int totalMen = 80000 * .52;
    int totalWomen = 80000 - totalMen;
    int totalLiteratePeople = 80000 * .48;

    int totalLiterateMen = totalPopulation * .35;
    int totalIlliterateMen = totalMen - totalLiterateMen;

    int totalLiterateWomen = totalLiteratePeople - totalLiterateMen;
    int totalIlliterateWomen = totalWomen - totalLiterateWomen;

    printf("Total Illiterate Men: %d and Total Illiterate Women = %d\nTotal Literate Men: %d and Total Literate Women: %d", totalIlliterateMen, totalIlliterateWomen, totalLiterateMen, totalLiterateWomen);

    return 0;
}
