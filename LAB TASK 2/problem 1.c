/* If cost price and selling price of an item is input through the keyboard, write a program to determine whether the seller has made profit or incurred loss. Also determine how much profit he made or loss he incurred.*/

#include<stdio.h>

int main(){

    float item_cost_price, item_selling_price, item_profit;

    printf ("Enter the cost price: ");
    scanf ("%f", &item_cost_price);
    printf ("Enter the selling price: ");
    scanf ("%f", &item_selling_price);

    if (item_cost_price < item_selling_price){

        printf ("The profit is: %.2f", item_selling_price - item_cost_price);
    }

    else {
        printf ("The incurred loss is: %.2f", item_cost_price - item_selling_price);
    }

    return 0;


}
