#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.c"
#define DIM 10

int main(){
    int vett[DIM];
    caricaVettore(vett,DIM,5,10);
    StampaVettoreRigha(vett,DIM);
    printf("\n");
    return 0;
}