////This program shows the total number of illiterate men and women where the population of the town is 80,000

#include<stdio.h>

int main(){

    int popu=80000,popu_men,popu_women,popu_lit,popu_illit,lit_men,illit_men,lit_women,illit_women;

    popu_men=0.52*popu;
    popu_women=popu-popu_men;
    popu_lit=0.48*popu;
    lit_men=0.35*popu;
    lit_women=popu_lit-lit_men;
    illit_men=popu_men-lit_men;
    illit_women=popu_women-lit_women;

    printf("The number of illiterate Men is: %d",illit_men);
    printf("\nThe number of illiterate Women is: %d",illit_women);

    return 0;
}
