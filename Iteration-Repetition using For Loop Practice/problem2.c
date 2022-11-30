/*This program print ASCII values and their equivalent characters*/
#include<stdio.h>
int main(){
int a;

for(a=0;a<=255;a++){
    printf("\nASCII value of character %c = %d",a,a);
}
return 0;
}
