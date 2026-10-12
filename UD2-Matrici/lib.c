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

void creaCodiceSegretO(int v[],int dim,int min,int max){
    srand(time(NULL));
    for(int i = 0; i < dim; i++){
        v[i] = min + rand() % (max - min + 1);
    }
}

void RichiediUtente(int code){
    printf("forniere il codice di 5 cifre \n");
    scanf("%d",&code);
}

verificaStampaCodice(int v[],int dim,int min,int max){


}
