/*This program calculates overtime pay of 10 employees. Overtime is paid at the rate of BDT.
120.00 per hour for every hour worked above 36 hours in a week. The employees do not
work for fractional part of an hour.*/
#include<stdio.h>
int main(){
int num,hour;
float pay;

for(num=1;num<=10;num++){
    printf("\nEnter the working hour of employee no. %d = ",num);
    scanf("%d",&hour);
    pay=(hour-36)*120;
    if(hour>36){
        printf("\nEmployee no. %d overpay is = %.2f BDT\n",num,pay);
    }else{
        printf("\nYou have to work for more than 36 hours to get over time pay\n");
        }
    }
return 0;
}
