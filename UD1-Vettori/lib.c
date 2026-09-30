#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"
void stampaVettore(int v[], int dim) {
    printf("\n--- Stampa valori in colonna ---\n");
    for (int i = 0; i < dim; i++) {
        printf(" %d ", v[i]);
    }
    printf("\n");

}

int ValoreMassimo(int v[],int dim){
    int max = 0;
    for(int i = 0; i < dim; i++){
        if(v[i] > max){
            max = v[i];
        }
    }
    return max;
}

int ContaValore(int v[],int dim,int choose){
    int count = 0;    
    for(int i = 0; i < dim; i++){
        if(v[i] == choose){
            count++;
        }
    }
    return count;
}

int ricercaSostituisci(int v[],int dim,int src,int sost){
    int change = 0;
    for(int i = 0; i < dim; i++){
        if(v[i] == src){
            v[i] = sost;
            change++;
        }
    }
    return change;
}

void caricaVettore(int v[],int dim,int min,int max){
    srand(time(NULL));
    for(int i = 0; i < dim; i++){
        v[i] = min + rand() % (max - min + 1);
    }
}

void StampaVettoreRigha(int v[],int dim){
    for(int i = 0; i < dim; i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}

void MediaVettore(int v[],int dim){
    float media = 0;
    for(int i = 0; i < dim; i++){
        media = v[i] + media;
    }
    media = media / dim;
    return media;
}