#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"

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