//A cashier has currency notes of denominations 10, 50 and 100. This program will find the total number of currency notes of each denomination the cashier will have to give to the with-drawer

#include<stdio.h>
int main(){
    int amount,a,b,c;

    printf("Please enter the withdraw amount = ");
    scanf("%d",&amount);

    a=amount/100;
    amount=amount%100;
    b=amount/50;
    amount=amount%50;
    c=amount/10;

    printf("Note of 100 = %d",a);
    printf("\nNote of 50 = %d",b);
    printf("\nNote of 10 = %d",c);

    return 100;

}
