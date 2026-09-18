#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 5
int main(void){
    int altezza[DIM];
    // inizializzazione a 0
    for(int i = 0; i < DIM; i++){
        altezza[i] = 0;
    }

    // popolamento manuale di un arrey
    for(int i = 0; i < DIM; i++){
        printf("Inserisci il [%d] valore: ",i+1);
        scanf("%d", &altezza[i]);
    }

}