#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"
#include "lib.c"
#define DIM 5
#define quad 5
int main(void){
    srand(time(NULL));
    int v[DIM];
    int m[quad][quad];
    int min, max;
    int funzione2 = sommaVM(quad,DIM,v,m);
    //richiedo min e max
    printf("Inserisci il valore minimo: ");
    scanf("%d", &min);
    printf("Inserisci il valore massimo: ");
    scanf("%d", &max);
    printf(" vettore \n");
    //stampo e carico il vettore
    caricaV(v, DIM, min, max);
    stampaV(v, DIM);
    printf("\n matrice \n");
    //stampo e carico la matrice
    caricaM(quad,m,min,max);
    stampaM(quad,m);
    printf("\n");
    //1 funzione 
    ugualiVM(quad ,DIM ,v ,m);
    //2 funzione
    printf("%d \n",funzione2);
    //3 funzione
    celleVM(quad ,DIM ,v ,m);
}