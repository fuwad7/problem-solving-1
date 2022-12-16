//Input the age of father, mother and uncle and show who is oldest, the youngest and who is in between as the output

#include<stdio.h>

    int main(){

    int father_age, mother_age,uncle_age;

    printf("Enter Father age: ");
    scanf("%d",&father_age);
    printf("Enter Mother age: ");
    scanf("%d",&mother_age);
    printf("Enter Uncle age: ");
    scanf("%d",&uncle_age);

    if (father_age>mother_age && mother_age>uncle_age)

    {
        printf("Father is the oldest. \n Uncle is the youngest. \n Mother is in between youngest and oldest.");
    }

    else if (father_age>uncle_age && uncle_age>mother_age)

    {
        printf(" Father is the oldest. \n Mother is the youngest. \n Uncle is in between youngest and oldest.");
    }

    else if (mother_age>father_age && father_age>uncle_age)

    {
        printf(" Mother is the oldest. \n Uncle is the youngest. \n Father is in between youngest and oldest.");
    }

    else if (mother_age>uncle_age && uncle_age>father_age)

    {
        printf(" Mother is the oldest. \n Father is the youngest. \n Uncle is in between youngest and oldest.");
    }

    else if (uncle_age>father_age && father_age<mother_age)

    {
        printf(" Uncle is the oldest. \n Father is the youngest. \n Mother is in between youngest and oldest.");
    }

    else if (uncle_age>mother_age && mother_age>father_age)

    {
        printf(" Uncle is the oldest. \n Mother is the youngest. \n Father is in between youngest and oldest.");
    }

    else

    {
        printf("Invalid Input");
    }

    return 0;

    }
