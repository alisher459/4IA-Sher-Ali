#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"
#include "lib.c"

#define righe 3
#define colonne 5

int main(void){
    srand(time(NULL));

    int v[DIM];
    int min, max, v1, v2, massimo;

    printf("Inserisci il valore minimo: ");
    scanf("%d", &min);
    printf("Inserisci il valore massimo: ");
    scanf("%d", &max);

    initVettore(v, DIM, min, max);
    printf("\nVettore dopo initVettore:\n");
    stampaVettore(v, DIM);

    printf("\nInserisci il valore da cercare (v1): ");
    scanf("%d", &v1);
    printf("Inserisci il valore v2: ");
    scanf("%d", &v2);

    ricercaSostituisci(v, DIM, v1, v2);
    printf("\nVettore dopo ricercaSostituisci:\n");
    stampaVettore(v, DIM);

    printf("\n");
    massimo = massimoVettore(v, DIM);
    printf("Valore massimo restituito al main: %d\n", massimo);
    printf("Vettore dopo massimoVettore:\n");
    stampaVettore(v, DIM);

    printf("\n");
    if(trovaDoppi(v, DIM) == 1){
        printf("Ci sono valori uguali adiacenti.\n");
    }
    else{
        printf("Non ci sono valori uguali adiacenti.\n");
    }
    printf("Vettore dopo trovaDoppi:\n");
    stampaVettore(v, DIM);

    return 0;
}