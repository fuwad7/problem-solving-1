/*This program calculates the factorial of N1 and N2 numbers and
finally sum the factorials of these numbers as output*/
#include<stdio.h>
int main(){
int num1,num2,N1,N2,f1=1,f2=1;

printf("Please enter first number (N1) = ");
scanf("%d",&num1);
printf("Please enter second number (N2) = ");
scanf("%d",&num2);

if((num1>=0&&num1<=20)&&(num2>=0&&num2<=20)){
    for(N1=num1;N1>=1;N1--){
        f1=f1*N1;
    }
    for(N2=num2;N2>=1;N2--){
        f2=f2*N2;
    }
    printf("%d",(f1+f2));
}else{
    printf("Invalid");
    }
return 0;
}
