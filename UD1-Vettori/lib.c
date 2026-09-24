#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"
/*
void printColArray(int _v[], int _dim){
 for(i=0; i<_dim; i++){
 printf("[%d]= %d", i, _v[i]);
 printf("\n");
 }
}

void printRowArray(int _v[], int _dim){
 for(i=0; i<_dim; i++){
 printf("%d ", _v[i]);
 }
}

void randomInputArray(int _v[], int _dim){
 for(i=0; i<_dim; i++){
 // genero altezze da 150 a 190 (intesi come centimetri)
 _v[i] = 1 + (rand() % 99);
 }
}

void manualInputArray(int _v[], int _dim){
 int i;
 char junk;
 for(i=0; i<_dim; i++){
 printf("Inserisci il [%d] valore: ", i+1);
 scanf("%d", &_v[i]);
 junk = getchar();
 }
}

void initArray(int _v[], int _dim){
 int i;
 for(i=0; i<_dim; i++){
 _v[i] = 0;
 }
}

void initArray(int _v[], int _dim){
}

void randomInputArray(int _v[], int _dim){
}

void inizializzaVettore(int v[], int dim) {
    for (int i = 0; i < dim; i++) {
        v[i] = 0;
    }

}

void inputVettore(int v[], int dim) {
    printf("Inserisci %d valori per il vettore:\n", dim);
    for (int i = 0; i < dim; i++) {
        printf("Elemento [%d]: ", i);
        scanf("%d", &v[i]);
    }

}
*/
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

