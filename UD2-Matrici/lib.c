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
//sopra sbagliato correggere dopo
 
//La funzione deve restituire 1 se almeno una riga della matrice è composta interamente da numeri maggiori di zero, altrimenti deve restituire 0.
bool matricePositivaM(int righe,int colonne,int v[righe][colonne]){
    int check = 0;
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            if(v[i][j] < check){
                return false;
            }
        }
    }
    return true;
}

//La funzione deve restituire 1 se almeno una colonna della matrice è composta interamente da numeri pari, altrimenti deve restituire 0.
bool colonnapariM(int righe,int colonne,int v[righe][colonne]){
    for(int j = 0; j < colonne;j++){
        int pari = 0;
        for(int i = 0; i < righe; i++){
            if(v[i][j] % 2 != 0){
                pari = 0;
            }
        }
        if(pari = 1){
            return true;
        }
    }
    return false;
}

//La funzione deve restituire 1 se almeno una colonna della matrice contiene almeno uno zero, altrimenti deve restituire 0
bool colonnazeriM(int righe,int colonne,int v[righe][colonne]){
    for(int j = 0; j <  colonne; j++){
        int check = 0;
            for(int i = 0; i < righe; i++){
                if(v[i][j] == 0){
                    check = 1;
                }
            }
            if(check == 1){
                return true; 
            }
    }
    return false;
}

//La funzione deve restituire 1 se tutti e quattro gli angoli della matrice hanno esattamente lo stesso valore, altrimenti deve restituire 0.
bool cornersequalM(int righe,int colonne,int v[righe][colonne]){
    int check = v[0][0];
    if(v[0][0] == check && v[0][colonne - 1] == check && v[righe - 1][0] == check && v[righe - 1][colonne - 1] == check){
        return true;
    }else{
        return false;
    }
}

//La funzione deve restituire 1 se tutti gli elementi della prima riga sono esattamente uguali, uno per uno, agli elementi corrispondenti dell'ultima riga, altrimenti deve restituire 0.
bool priamUltimaRighaUgualiM(int righe,int colonne,int v[righe][colonne]){
    int check = 0;
    for(int i = 0; i < colonne; i++){
    if(v[0][i] == v[righe - 1][i]){
        check = 1;
    }else{
        return false;
    }
    }
    if(check == 1){
        return true;
    }
}

// inizializzare ogni elemento di una matrice quadrata con la differenza tra i suoi indici di riga e colonna;
void indexesDiffM(int quad,int v[quad][quad]){
    int diff = 0;
    for(int i = 0; i < quad ; i++){
        for(int j = 0; j < quad; j++){
            if(j > i){
                diff = j - i;
            }else{
                diff = i - j;
            }
            if(j == i){
                diff = 0;
            }
            v[i][j] = diff;
        }
    }
}

//dire se in ogni colonna di una matrice, l'ultimo elemento è maggiore di tutti gli altri della colonna
bool largestRowM(int righe,int colonne,int v[righe][colonne]){
    for(int j = 0; j < colonne; j++){
        for(int i = 0; i < (righe - 1); i++){
            if(v[righe - 1][j] < v[i][j]){
                return false;
            }
        }
    }
    return true;
}