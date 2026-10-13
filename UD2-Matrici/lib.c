#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"
#include<stdbool.h>
//---SCUOLA---//
/*
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
*/

//Che prende in input una matrice di interi e le sue dimensioni, e restituisce il numero di elementi pari presenti nella matrice.
int contaPariM(int i,int j,int v[i][j]) {
    int pari = 0;
    for(int ii = 0; ii < i; ii++){
        for(int jj = 0; jj < j; jj++){
            if(v[ii][jj] % 2 == 0){
                pari = pari + 1;
            }
        }
    }
    return pari;
}

//dice se in una matrice quadrata di interi la somma degli elementi della diagonale principale eguaglia quella degli elementi sulla diagonale secondariadice se in una matrice quadrata di interi la somma degli elementi della diagonale principale eguaglia quella degli elementi sulla diagonale secondaria.
bool diagSumM(int righe,int colonne,int v[righe][colonne]){
    int somma1 = 0;
    int somma2 = 0;
    for(int i = 0; i < righe; i++){
        somma1 = somma1 + v[i][i];
    }
    for(int j = righe; j < 0; j--){
        somma2 = somma2 + v[j][j];
    }
    if(somma1 == somma2){
        return true;
    }else{
        return false;
    }
}

//Vogliamo scrivere una funzione in C che riceve una matrice di interi e le sue dimensioni (righe e colonne), e restituisce il valore massimo presente nella matrice.
int trovaMaxM(int righe,int colonne,int v[righe][colonne]){
    int max = 0;
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            if(max < v[i][j]){
                max = v[i][j];
            }
        }
    }
    return max;
}

//azzerare i valori all'intenro della matrice
void azzeraM(int righe,int colonne,int v[righe][colonne]){
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            v[i][j] = 0;
        }
    }
}

//La funzione deve restituire il numero totale di volte che il numero 0 compare all'interno della matrice.
int contaZeriM(int righe,int colonne,int v[righe][colonne]){
    int cnt = 0;
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            if(v[i][j] == 0){
                cnt++;
            }
        }
    }
    return cnt;
}

//La funzione deve restituire il numero totale di elementi all'interno della matrice che hanno un valore maggiore di 10.
int contaMaggioremaxM(int righe,int colonne,int v[righe][colonne],int max){
    int cnt = 0;
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            if(v[i][j] > 10){
                cnt++;
            }
        }
    }
    return cnt;
}

//La funzione deve restituire 1 se la somma degli elementi della diagonale principale è maggiore della somma degli elementi della diagonale secondaria, altrimenti deve restituire 0.
bool diagSumdiagonaleMaggioreMM(int quad,int v[quad][quad]){
    int somma1 = 0;
    int somma2 = 0;
    for(int i = 0; i < quad; i++){
        somma1 = somma1 + v[i][i];
    }
    for(int j = quad; j < 0; j--){
        somma2 = somma2 + v[j][j];
    }
    if(somma1 > somma2){
        return true;
    }else{
        return false;
    }
}