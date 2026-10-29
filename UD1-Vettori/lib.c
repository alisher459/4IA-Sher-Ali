#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"
#include <stdbool.h>

// (era caricaVettore) Riempie la matrice con numeri casuali compresi tra min e max, estremi inclusi.
// Chiama srand(time(NULL)) UNA volta sola nel main, prima di questa funzione:
// dentro la funzione, due chiamate nello stesso secondo darebbero gli stessi numeri.
void caricaM(int righe, int colonne, int v[righe][colonne], int min, int max){
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            v[i][j] = min + rand() % (max - min + 1);
        }
    }
}
 
// (era stampaVettore) Stampa la matrice con un'intestazione, una riga della matrice per riga di schermo.
void stampaMatrice(int righe, int colonne, int v[righe][colonne]){
    printf("\n--- Stampa matrice %d x %d ---\n", righe, colonne);
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            printf(" %d ", v[i][j]);
        }
        printf("\n");
    }
}
 
// (era StampaVettoreRigha) Stampa tutti gli elementi della matrice su un'unica riga, leggendola per righe.
void stampaMatriceInLinea(int righe, int colonne, int v[righe][colonne]){
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            printf("%d ", v[i][j]);
        }
    }
    printf("\n");
}
 
 
/* ---------- 2. FUNZIONI "UNIVERSALI" (ricevono una funzione come parametro) ---------- */
   
 
// (nuova) Restituisce quanti elementi della matrice soddisfano la condizione cond
// (cond riceve un int e restituisce true o false).
int contaSeM(int righe, int colonne, int v[righe][colonne], bool (*cond)(int)){
    int cnt = 0;
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            if(cond(v[i][j])){
                cnt++;
            }
        }
    }
    return cnt;
}
 
// (nuova) Sostituisce ogni elemento x della matrice con f(x) (modifica la matrice stessa).
void applicaM(int righe, int colonne, int v[righe][colonne], int (*f)(int)){
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            v[i][j] = f(v[i][j]);
        }
    }
}
 
 
/* ---------- 3. RIEMPIMENTO, COPIA E SOSTITUZIONE ---------- */
 
// (nuova) Riempie tutta la matrice con lo stesso valore (con valore = 0 la azzera).
void riempiM(int righe, int colonne, int v[righe][colonne], int valore){
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            v[i][j] = valore;
        }
    }
}
 
// (nuova) Copia la matrice src nella matrice dst (stesse dimensioni).
void copiaM(int righe, int colonne, int src[righe][colonne], int dst[righe][colonne]){
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            dst[i][j] = src[i][j];
        }
    }
}
 
// (era ricercaSostituisci) Sostituisce con "sost" ogni elemento uguale a "src".
// Restituisce quante sostituzioni ha fatto.
int ricercaSostituisciM(int righe, int colonne, int v[righe][colonne], int src, int sost){
    int change = 0;
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            if(v[i][j] == src){
                v[i][j] = sost;
                change++;
            }
        }
    }
    return change;
}
 
 
/* ---------- 4. CONTEGGI, MASSIMO, MINIMO, RICERCA ---------- */
 
// (era ContaValore) Restituisce quante volte compare il valore "choose" nella matrice.
int contaValoreM(int righe, int colonne, int v[righe][colonne], int choose){
    int count = 0;
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            if(v[i][j] == choose){
                count++;
            }
        }
    }
    return count;
}
 
// (era ValoreMassimo) Restituisce il valore massimo presente nella matrice.
// Parte da v[0][0] e non da 0, così funziona anche se tutti i numeri sono negativi.
int valoreMassimoM(int righe, int colonne, int v[righe][colonne]){
    int max = v[0][0];
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            if(v[i][j] > max){
                max = v[i][j];
            }
        }
    }
    return max;
}
 
// (nuova) Restituisce il valore minimo presente nella matrice.
int valoreMinimoM(int righe, int colonne, int v[righe][colonne]){
    int min = v[0][0];
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            if(v[i][j] < min){
                min = v[i][j];
            }
        }
    }
    return min;
}
 
// (nuova) Scrive in *riga e *colonna la posizione del valore massimo (prima occorrenza, scorrendo per righe).
void posizioneMaxM(int righe, int colonne, int v[righe][colonne], int *riga, int *colonna){
    *riga = 0;
    *colonna = 0;
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            if(v[i][j] > v[*riga][*colonna]){
                *riga = i;
                *colonna = j;
            }
        }
    }
}
 
// (nuova) Scrive in *riga e *colonna la posizione del valore minimo (prima occorrenza, scorrendo per righe).
void posizioneMinM(int righe, int colonne, int v[righe][colonne], int *riga, int *colonna){
    *riga = 0;
    *colonna = 0;
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            if(v[i][j] < v[*riga][*colonna]){
                *riga = i;
                *colonna = j;
            }
        }
    }
}
 
// (nuova) Cerca "valore" nella matrice. Se lo trova restituisce true e scrive in *riga e *colonna
// la posizione della PRIMA occorrenza (scorrendo per righe); altrimenti restituisce false.
bool cercaValoreM(int righe, int colonne, int v[righe][colonne], int valore, int *riga, int *colonna){
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            if(v[i][j] == valore){
                *riga = i;
                *colonna = j;
                return true;
            }
        }
    }
    return false;
}
 
 
/* ---------- 5. SOMME E MEDIE ---------- */
 
// (nuova) Restituisce la somma di tutti gli elementi della matrice (long per evitare overflow).
long sommaTotaleM(int righe, int colonne, int v[righe][colonne]){
    long somma = 0;
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            somma += v[i][j];
        }
    }
    return somma;
}
 
// (era MediaVettore) Restituisce la media di tutti gli elementi della matrice.
// Restituisce 0 se la matrice è vuota (evita la divisione per zero).
// Nell'originale la funzione era void ma faceva return: ora restituisce double.
double mediaM(int righe, int colonne, int v[righe][colonne]){
    if(righe <= 0 || colonne <= 0){
        return 0;
    }
    return (double) sommaTotaleM(righe, colonne, v) / (righe * colonne);
}
 
// (nuova) Restituisce la somma degli elementi della riga indicata.
int sommaRigaM(int righe, int colonne, int v[righe][colonne], int riga){
    int somma = 0;
    for(int j = 0; j < colonne; j++){
        somma += v[riga][j];
    }
    return somma;
}
 
// (nuova) Restituisce la somma degli elementi della colonna indicata.
int sommaColonnaM(int righe, int colonne, int v[righe][colonne], int colonna){
    int somma = 0;
    for(int i = 0; i < righe; i++){
        somma += v[i][colonna];
    }
    return somma;
}
 
// (nuova) Restituisce la somma della diagonale principale di una matrice quadrata.
int sommaDiagPrincipaleM(int quad, int v[quad][quad]){
    int somma = 0;
    for(int i = 0; i < quad; i++){
        somma += v[i][i];
    }
    return somma;
}
 
// (nuova) Restituisce la somma della diagonale secondaria di una matrice quadrata.
int sommaDiagSecondariaM(int quad, int v[quad][quad]){
    int somma = 0;
    for(int i = 0; i < quad; i++){
        somma += v[i][quad - 1 - i];
    }
    return somma;
}
 
 
/* ---------- 6. ACCESSO SICURO AGLI ELEMENTI ---------- */
 
// (era getvaloreat) Legge l'elemento in posizione [riga][colonna].
// Restituisce true e scrive il valore in *valore se la posizione esiste;
// restituisce false se riga o colonna sono fuori dai limiti (così non si legge memoria a caso).
bool getValoreAtM(int righe, int colonne, int v[righe][colonne], int riga, int colonna, int *valore){
    if(riga < 0 || riga >= righe || colonna < 0 || colonna >= colonne){
        return false;
    }
    *valore = v[riga][colonna];
    return true;
}
 
// (nuova) Scrive "valore" nella posizione [riga][colonna].
// Restituisce true se la posizione esiste, false se è fuori dai limiti (e in tal caso non scrive nulla).
bool setValoreAtM(int righe, int colonne, int v[righe][colonne], int riga, int colonna, int valore){
    if(riga < 0 || riga >= righe || colonna < 0 || colonna >= colonne){
        return false;
    }
    v[riga][colonna] = valore;
    return true;
}
 
 
/* ---------- 7. OPERAZIONI TRA MATRICI ---------- */
 
// (nuova) Calcola c = a + b (tre matrici con le stesse dimensioni).
void sommaM(int righe, int colonne, int a[righe][colonne], int b[righe][colonne], int c[righe][colonne]){
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}
 
// (nuova) Calcola il prodotto righe per colonne c = a * b.
// a è (r1 x c1), b è (c1 x c2), c risulta (r1 x c2).
void prodottoM(int r1, int c1, int c2, int a[r1][c1], int b[c1][c2], int c[r1][c2]){
    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c2; j++){
            c[i][j] = 0;
            for(int k = 0; k < c1; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
 
 
/* ---------- 8. TRASFORMAZIONI DELLA STRUTTURA ---------- */
 
// (nuova) Scambia tra loro due righe della matrice (in place).
void scambiaRigheM(int righe, int colonne, int v[righe][colonne], int r1, int r2){
    for(int j = 0; j < colonne; j++){
        int tmp = v[r1][j];
        v[r1][j] = v[r2][j];
        v[r2][j] = tmp;
    }
}
 
// (nuova) Scambia tra loro due colonne della matrice (in place).
void scambiaColonneM(int righe, int colonne, int v[righe][colonne], int c1, int c2){
    for(int i = 0; i < righe; i++){
        int tmp = v[i][c1];
        v[i][c1] = v[i][c2];
        v[i][c2] = tmp;
    }
}
 
// (nuova) Scrive in t la trasposta di v (righe e colonne scambiate): t è (colonne x righe).
void trasponiM(int righe, int colonne, int v[righe][colonne], int t[colonne][righe]){
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            t[j][i] = v[i][j];
        }
    }
}
 
// (nuova) Ordina TUTTI gli elementi della matrice in modo crescente, leggendola per righe (bubble sort).
void ordinaM(int righe, int colonne, int v[righe][colonne]){
    int n = righe * colonne;
    for(int a = 0; a < n - 1; a++){
        for(int b = 0; b < n - 1 - a; b++){
            int *x = &v[b / colonne][b % colonne];
            int *y = &v[(b + 1) / colonne][(b + 1) % colonne];
            if(*x > *y){
                int tmp = *x;
                *x = *y;
                *y = tmp;
            }
        }
    }
}

