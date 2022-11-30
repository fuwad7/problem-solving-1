/*This program finds the factorial value of any number entered through the keyboard*/
#include<stdio.h>
int main(){
int num,i,factorial=1;

printf("Please enter the number = ");
scanf("%d",&num);

for(i=num;i>=1;i--){
    factorial=factorial*i;
}
printf("Factorial of %d is = %d",num,factorial);
return 0;
}
