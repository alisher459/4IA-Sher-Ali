#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"
#include "lib.c"

#define dim 15
int main(void){
    int choose = 0;
    int src = 0;
    int sost = 0;
    int v[dim];
    srand(time(NULL));
    for (int i = 0; i < dim; i++) {
        v[i] = 1 + rand() % 25;
    }
    stampaVettore(v, dim);
    printf("Il valore massimo e': %d\n", ValoreMassimo(v, dim));
    do{
        printf("fornisci un valore compreso tra 1 e 25 compresi \n");
        scanf("%d",& choose);
    }while(choose == 0 || choose > 25);
    printf("Il valore e apparso %d volte \n", ContaValore(v,dim,choose));
    printf("fornire un valore src \n");
    scanf("%d",& src);
    printf("fornire un valore src \n");
    scanf("%d",& sost);
    printf("Il valore %d e stato sostituito %d volte \n",src ,  ricercaSostituisci(v,dim,src,sost));
    stampaVettore(v, dim);
    return 0;
}