#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"
#include<stdbool.h>

/*
maxSumM(): ritorna il valore massimo degli elementi di una matrice di interi e la somma dei suoi elementi
constantBordersM(): verificare se tutte le celle dei “bordi” di una matrice contengono lo stesso valore
allDifferentM(): dice se tutti gli elementi di una matrice sono diversi;
scacchieraM(): verifica se una matrice quadrata di interi è una "scacchiera", ovvero se vi sono presenti solo 0 e 1 alternati tra loro;
diagSum(): dice se in una matrice quadrata di interi la somma degli elementi della diagonale principale eguaglia quella degli elementi sulla diagonale secondaria;
corniceValoreM(): dice se tutti gli elementi della cornice della matrice quadrata di interi valgono v
*/
void maxSumM(int r, int c, int m[r][c], int *max, int *sum) {
    *max = m[0][0];
    *sum = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(m[i][j] > *max) {
                *max = m[i][j];
            }
            *sum += m[i][j];
        }
    }
}

int constantBordersM(int r, int c, int m[r][c]) {
    int val = m[0][0];
    for(int j = 0; j < c; j++) {
        if(m[0][j] != val || m[r-1][j] != val) return 0;
    }
    for(int i = 0; i < r - 1; i++) {
        if(m[i][0] != val || m[i][c-1] != val) return 0;
    }
    return 1;
}

int allDifferentM(int r, int c, int m[r][c]) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            for(int x = 0; x < r; x++) {
                for(int y = 0; y < c; y++) {
                    if((i != x || j != y) && m[i][j] == m[x][y]) return 0;
                }
            }
        }
    }
    return 1;
}

int scacchieraM(int n, int m[n][n]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(m[i][j] != (i + j + 1) % 2) return 0;
        }
    }
    return 1;
}

int diagSum(int n, int m[n][n]) {
    int d1 = 0, d2 = 0;
    for(int i = 0; i < n; i++) {
        d1 += m[i][i];
        d2 += m[i][n - 1 - i];
    }
    return d1 == d2;
}

int corniceValoreM(int n, int m[n][n], int v) {
    for(int j = 0; j < n; j++) {
        if(m[0][j] != v || m[n-1][j] != v) return 0;
    }
    for(int i = 1; i < n - 1; i++) {
        if(m[i][0] != v) return 0;
    }
    return 1;
}                                         