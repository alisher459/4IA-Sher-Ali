#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"
#include<stdbool.h>


/* ---------- 1. UTILITÀ GENERALI (riusabili ovunque) ---------- */
 
// Riempie la matrice con numeri casuali compresi tra min e max (estremi inclusi).
// Ricordati di chiamare srand(time(NULL)) UNA volta sola nel main, prima di questa funzione.
void caricaM(int righe, int colonne, int v[righe][colonne], int min, int max){
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            v[i][j] = rand() % (max - min + 1) + min;
        }
    }
}
 
// Stampa la matrice a schermo, una riga per ogni riga della matrice.
void stampaM(int righe, int colonne, int v[righe][colonne]){
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            printf(" %d", v[i][j]);
        }
        printf("\n");
    }
}
 
// Azzera tutti gli elementi della matrice.
void azzeraM(int righe, int colonne, int v[righe][colonne]){
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            v[i][j] = 0;
        }
    }
}
 
// Restituisce il valore massimo presente nella matrice.
int trovaMaxM(int righe, int colonne, int v[righe][colonne]){
    int max = v[0][0];   // parto dal primo elemento (e non da 0, così funziona anche con numeri negativi)
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            if(v[i][j] > max){
                max = v[i][j];
            }
        }
    }
    return max;
}
 
// Restituisce quanti elementi della matrice sono strettamente maggiori di soglia.
int contaMaggioremaxM(int righe, int colonne, int v[righe][colonne], int soglia){
    int cnt = 0;
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            if(v[i][j] > soglia){
                cnt++;
            }
        }
    }
    return cnt;
}
 
// Restituisce quanti elementi pari ci sono nella matrice.
int contaPariM(int righe, int colonne, int v[righe][colonne]){
    int pari = 0;
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            if(v[i][j] % 2 == 0){
                pari++;
            }
        }
    }
    return pari;
}
 
// Restituisce quante volte compare lo 0 nella matrice.
int contaZeriM(int righe, int colonne, int v[righe][colonne]){
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
 
 // Restituisce quanti elementi della matrice soddisfano la condizione cond
// (cond riceve un int e restituisce true/false).
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
 
// Restituisce true se TUTTI gli elementi della matrice soddisfano la condizione cond.
bool tuttiM(int righe, int colonne, int v[righe][colonne], bool (*cond)(int)){
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            if(!cond(v[i][j])){
                return false;
            }
        }
    }
    return true;
}
 
// Sostituisce ogni elemento x della matrice con f(x) (modifica la matrice stessa).
void applicaM(int righe, int colonne, int v[righe][colonne], int (*f)(int)){
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            v[i][j] = f(v[i][j]);
        }
    }
}
 
 
/* ---------- 2. RIEMPIMENTO E COPIA ---------- */
 
// Riempie tutta la matrice con lo stesso valore (azzeraM è il caso valore = 0).
void riempiM(int righe, int colonne, int v[righe][colonne], int valore){
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            v[i][j] = valore;
        }
    }
}
 
// Copia la matrice src nella matrice dst (stesse dimensioni).
void copiaM(int righe, int colonne, int src[righe][colonne], int dst[righe][colonne]){
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            dst[i][j] = src[i][j];
        }
    }
}
 
// Trasforma una matrice quadrata nella matrice identità (1 sulla diagonale principale, 0 altrove).
void identitaM(int quad, int v[quad][quad]){
    for(int i = 0; i < quad; i++){
        for(int j = 0; j < quad; j++){
            v[i][j] = (i == j) ? 1 : 0;
        }
    }
}
 
 
/* ---------- 3. STATISTICHE E RICERCA ---------- */
 
// Restituisce il valore minimo presente nella matrice.
int trovaMinM(int righe, int colonne, int v[righe][colonne]){
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
 
// Restituisce la somma di tutti gli elementi della matrice (long per evitare overflow).
long sommaTotaleM(int righe, int colonne, int v[righe][colonne]){
    long somma = 0;
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            somma += v[i][j];
        }
    }
    return somma;
}
 
// Restituisce la media di tutti gli elementi della matrice.
double mediaM(int righe, int colonne, int v[righe][colonne]){
    return (double) sommaTotaleM(righe, colonne, v) / (righe * colonne);
}
 
// Restituisce quante volte compare "valore" nella matrice.
int contaOccorrenzeM(int righe, int colonne, int v[righe][colonne], int valore){
    int cnt = 0;
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            if(v[i][j] == valore){
                cnt++;
            }
        }
    }
    return cnt;
}
 
// Cerca "valore" nella matrice. Se lo trova restituisce true e scrive in *riga e *colonna
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
 
// Scrive in *riga e *colonna la posizione del valore massimo (prima occorrenza).
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
 
// Restituisce la somma della diagonale principale di una matrice quadrata.
int sommaDiagPrincipaleM(int quad, int v[quad][quad]){
    int somma = 0;
    for(int i = 0; i < quad; i++){
        somma += v[i][i];
    }
    return somma;
}
 
// Restituisce la somma della diagonale secondaria di una matrice quadrata.
int sommaDiagSecondariaM(int quad, int v[quad][quad]){
    int somma = 0;
    for(int i = 0; i < quad; i++){
        somma += v[i][quad - 1 - i];
    }
    return somma;
}
 
/* ---------- 2. VERIFICHE SU TUTTA LA MATRICE ---------- */
 
// Restituisce true se tutti gli elementi della matrice sono diversi tra loro (nessun duplicato).
bool allDifferentM(int righe, int colonne, int v[righe][colonne]){
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            for(int i1 = 0; i1 < righe; i1++){
                for(int j1 = 0; j1 < colonne; j1++){
                    // confronto solo celle diverse (anche se hanno stessa riga o stessa colonna)
                    if((i != i1 || j != j1) && v[i][j] == v[i1][j1]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
 
// Restituisce true se tutte le righe della matrice sono uguali tra loro (uguali alla prima riga).
bool equalRowsM(int righe, int colonne, int v[righe][colonne]){
    for(int i = 1; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            if(v[i][j] != v[0][j]){
                return false;
            }
        }
    }
    return true;
}
 
// Restituisce true se tutte le celle del bordo (prima/ultima riga e prima/ultima colonna)
// contengono lo stesso valore.
bool constantBordersM(int righe, int colonne, int v[righe][colonne]){
    int check = v[0][0];
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            bool bordo = (i == 0 || j == 0 || i == righe - 1 || j == colonne - 1);
            if(bordo && v[i][j] != check){
                return false;
            }
        }
    }
    return true;
}
 
// Restituisce true se tutte le celle del bordo (la "cornice") della matrice sono uguali al valore dato.
bool corniceUgualeM(int righe, int colonne, int valore, int v[righe][colonne]){
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            bool bordo = (i == 0 || j == 0 || i == righe - 1 || j == colonne - 1);
            if(bordo && v[i][j] != valore){
                return false;
            }
        }
    }
    return true;
}
 
 
/* ---------- 3. VERIFICHE SU RIGHE E COLONNE ---------- */
 
// Restituisce true se almeno una riga è composta interamente da numeri maggiori di zero.
bool matricePositivaM(int righe, int colonne, int v[righe][colonne]){
    for(int i = 0; i < righe; i++){
        bool tuttiPositivi = true;
        for(int j = 0; j < colonne; j++){
            if(v[i][j] <= 0){
                tuttiPositivi = false;
            }
        }
        if(tuttiPositivi){
            return true;
        }
    }
    return false;
}
 
// Restituisce true se almeno una colonna è composta interamente da numeri pari.
bool colonnapariM(int righe, int colonne, int v[righe][colonne]){
    for(int j = 0; j < colonne; j++){
        bool tuttiPari = true;
        for(int i = 0; i < righe; i++){
            if(v[i][j] % 2 != 0){
                tuttiPari = false;
            }
        }
        if(tuttiPari){
            return true;
        }
    }
    return false;
}
 
// Restituisce true se almeno una colonna contiene almeno uno zero.
bool colonnazeriM(int righe, int colonne, int v[righe][colonne]){
    for(int j = 0; j < colonne; j++){
        for(int i = 0; i < righe; i++){
            if(v[i][j] == 0){
                return true;
            }
        }
    }
    return false;
}
 
// Restituisce true se in ogni colonna l'ultimo elemento è strettamente maggiore di tutti gli altri della colonna.
bool ultimoMaggioreColonneM(int righe, int colonne, int v[righe][colonne]){
    for(int j = 0; j < colonne; j++){
        for(int i = 0; i < righe - 1; i++){
            if(v[righe - 1][j] <= v[i][j]){
                return false;
            }
        }
    }
    return true;
}
 
// Restituisce true se in ogni riga l'ultimo elemento è strettamente maggiore di tutti gli altri della riga.
bool ultimoMaggioreRigheM(int righe, int colonne, int v[righe][colonne]){
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne - 1; j++){
            if(v[i][colonne - 1] <= v[i][j]){
                return false;
            }
        }
    }
    return true;
}
 
// Restituisce true se la prima riga è uguale all'ultima, elemento per elemento.
bool primaUltimaRigaUgualiM(int righe, int colonne, int v[righe][colonne]){
    for(int j = 0; j < colonne; j++){
        if(v[0][j] != v[righe - 1][j]){
            return false;
        }
    }
    return true;
}
 
// Restituisce true se i quattro angoli della matrice hanno lo stesso valore.
bool cornersequalM(int righe, int colonne, int v[righe][colonne]){
    int check = v[0][0];
    return v[0][colonne - 1] == check
        && v[righe - 1][0] == check
        && v[righe - 1][colonne - 1] == check;
}
 
 
/* ---------- 4. MATRICI QUADRATE (diagonali) ---------- */
 
// Restituisce true se la somma della diagonale principale è uguale a quella della diagonale secondaria.
bool diagSumM(int quad, int v[quad][quad]){
    int somma1 = 0;   // diagonale principale
    int somma2 = 0;   // diagonale secondaria
    for(int i = 0; i < quad; i++){
        somma1 += v[i][i];
        somma2 += v[i][quad - 1 - i];
    }
    return somma1 == somma2;
}
 
// Restituisce true se la somma della diagonale principale è maggiore di quella della diagonale secondaria.
bool diagSumdiagonaleMaggioreMM(int quad, int v[quad][quad]){
    int somma1 = 0;   // diagonale principale
    int somma2 = 0;   // diagonale secondaria
    for(int i = 0; i < quad; i++){
        somma1 += v[i][i];
        somma2 += v[i][quad - 1 - i];
    }
    return somma1 > somma2;
}
 
// Inizializza una matrice quadrata: ogni elemento vale la differenza (in valore assoluto) tra indice di riga e di colonna.
void indexesDiffM(int quad, int v[quad][quad]){
    for(int i = 0; i < quad; i++){
        for(int j = 0; j < quad; j++){
            v[i][j] = (i > j) ? (i - j) : (j - i);
        }
    }
}
 
 
/* ---------- 5. RIEMPIMENTI SPECIFICI ---------- */
 
// Riempie la matrice con la tavola pitagorica: v[i][j] = (i+1) * (j+1).
// Esempio: la seconda riga contiene 2, 4, ..., 20 (con quad = 10).
void pitagoricaM(int quad, int v[quad][quad]){
    for(int i = 0; i < quad; i++){
        for(int j = 0; j < quad; j++){
            v[i][j] = (i + 1) * (j + 1);
        }
    }
}
 
// Riempie la matrice a scacchiera alternando 0 e 1 (0 nella cella [0][0]).
// (Ipotesi: nel tuo codice originale la funzione era incompleta, ho scelto questo comportamento.)
void caricaMatriceScacchiera(int righe, int colonne, int v[righe][colonne]){
    for(int i = 0; i < righe; i++){
        for(int j = 0; j < colonne; j++){
            v[i][j] = (i + j) % 2;
        }
    }
}
 

