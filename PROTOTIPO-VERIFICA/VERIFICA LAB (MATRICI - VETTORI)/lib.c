#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"
#include<stdbool.h>

void caricaM(int quad, int m[quad][quad], int min, int max){
    max = max - 1;
    min = min + 1;
    for(int i = 0; i < quad; i++){
        for(int j = 0; j < quad; j++){
            m[i][j] = rand() % (max - min + 1) + min;
        }
    }
}

void caricaV(int v[], int DIM, int min, int max){
    max = max - 1;
    min = min + 1;
    for(int i= 0; i < DIM ; i++){
        v[i] = min + rand() % (max - min + 1);
    }
 }

 void stampaM(int quad, int m[quad][quad]){
    for(int i = 0; i < quad; i++){
        for(int j = 0; j < quad; j++){
            printf(" %d", m[i][j]);
        }
        printf("\n");
    }
}

void stampaV(int v[], int DIM){
    for(int i= 0; i < DIM ; i++){
        printf(" %d", v[i]);
    }
 }

 void ugualiVM(int quad,int DIM,int v[],int m[quad][quad]){
    int cnt = 0;
    for(int i = 0; i < quad; i++){
        cnt = 0;
        for(int j = 0; j < quad; j++){
            if(v[j] == m[i][j]){
                cnt = cnt + 1;
            }
        }
        
        printf("i valori uguali sono %d \n",cnt);
    }
 }

 void celleVM(int quad,int DIM,int v[],int m[quad][quad]){
    int tmp = 0;
        for(int i = 0; i < quad; i++){
            tmp = v[i];
            for(int j = 0; j < quad; j++){
                if( m[i][j] == tmp){
                    printf(" %d ; %d ",i,j);
                }
            }
        }
    }
 
int sommaVM(int quad,int DIM,int v[],int m[quad][quad]){
    int max1 = 0;
    int max2 = 0;
    int cnt = 0;
    for(int s = 0; s < DIM ; s++){
        max1 = max1 + v[s];
    }
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
           max2 = max2 + (m[i][j]);
        }
        if(max2 > max1){
            cnt = cnt + 1;
        }
        max2 = 0;
    }
    return cnt;
}

