#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"
#include<stdbool.h>



void stampaVettore(int v[], int dim){
    for(int i = 0; i < dim; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

void initVettore(int v[], int dim, int min, int max){
    for(int i = 0; i < dim; i++){
        if(min >= max){
            v[i] = -1;
        }
        else{
            v[i] = min + rand() % (max - min + 1);
        }
    }
}

void ricercaSostituisci(int v[], int dim, int v1, int v2){
    for(int i = 0; i < dim; i++){
        if(v[i] == v1){
            if(v1 % 2 == 0){
                v[i] = v2;
            }
            else{
                v[i] = v[i] + v2;
            }
        }
    }
}

int massimoVettore(int v[], int dim){
    int max = v[0];
    for(int i = 1; i < dim; i++){
        if(v[i] > max){
            max = v[i];
        }
    }
    printf("Il valore massimo %d compare nelle posizioni: ", max);
    for(int i = 0; i < dim; i++){
        if(v[i] == max){
            printf("%d ", i);
        }
    }
    printf("\n");
    return max;
}

int trovaDoppi(int v[], int dim){
    for(int i = 0; i < dim - 1; i++){
        if(v[i] == v[i + 1]){
            return 1;
        }
    }
    return 0;
}