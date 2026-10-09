#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"
#include<stdbool.h>

void StampaMatrice(int righe, int colonne, int m[righe][colonne]) {
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            if(i == 0){
                 printf(" [ ");
            }
            printf("%d ", m[i][j]);
        }
        printf(" ] ");
        printf("\n"); 
    }
}

void caricamatrice(int righe,int colonne,int m[righe][colonne]){
    int i,j;
    srant(time(NULL));
    for(int i = 0 ; i < righe ; i++){
        for(int j = 0 ; j < righe ; j++){
             m[righe][colonne] = 1 + rand() % 25;
    }
    }
}

float MediaMatrice(int righe, int colonne, int m[righe][colonne]) {
    int som = 0;
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            som += m[i][j];
        }
    }
    return (float) som / (righe * colonne);
}

void SommaRighe(int righe, int colonne, int m[righe][colonne]) {
    for(int i = 0; i < righe; i++) {
        int som = 0;
        for(int j = 0; j < colonne; j++) {
            som += m[i][j];
        }
        printf("La somma della riga %d e': %d\n", i, som);
    }
}

bool verificaVettoreInMatrice(int righe, int colonne, int matrice[righe][colonne], int vettore[]) {
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            if (matrice[i][j] != vettore[j]) {
                return true;
            }
        }
    return false;
}

