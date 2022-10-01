/*
If the marks obtained by a student in five different subjects are input through the keyboard, find out the aggregate marks and percentage marks obtained by the student. Assume that the maximum marks that can be obtained by a student in each subject is 100.
*/

#include <stdio.h>

int main()
{

    float stracturedProgramming, industry4, webDevEssential, english, artOfLiving, aggregatedMark, percentageMark;

    printf("Enter the mark of SP: ");
    scanf("%f", &stracturedProgramming);
    printf("Enter the mark of Industry 4.0: ");
    scanf("%f", &industry4);
    printf("Enter the mark of Web Development Essential: ");
    scanf("%f", &webDevEssential);
    printf("Enter the mark of English: ");
    scanf("%f", &english);
    printf("Enter the mark of Art of Living: ");
    scanf("%f", &artOfLiving);

    aggregatedMark = stracturedProgramming + industry4 + webDevEssential + english + artOfLiving;
    percentageMark = aggregatedMark / 5;

    printf("Total mark is: %.2f \n", aggregatedMark);
    printf("Percentage mark is: %.2f", percentageMark);

    return 0;
}
