
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"
#include<stdbool.h>

#define N 8   // la griglia è N x N (8 x 8): ovunque trovi N, il computer legge 8
 
// Valori delle celle: 0 = acqua, 1 = nave, 2 = nave colpita, 3 = colpo mancato
 
// Mette tutte le celle della griglia a 0 (acqua).
void azzera(int griglia[N][N]){
    // scorro tutte le righe (i) e tutte le colonne (j)
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            griglia[i][j] = 0;
        }
    }
}
 
// Piazza UNA nave lunga "lunghezza" in un punto casuale della griglia, in orizzontale o in verticale.
// Prova posizioni a caso finché ne trova una libera.
void piazzaNave(int griglia[N][N], int lunghezza){
    int piazzata = 0;   // 0 = nave non ancora piazzata, 1 = piazzata
 
    while(piazzata == 0){
        int direzione = rand() % 2;   // 0 = orizzontale, 1 = verticale
        int riga;
        int colonna;
        int libero = 1;               // 1 = tutte le celle sono libere (lo supponiamo, poi controlliamo)
 
        if(direzione == 0){
            // ORIZZONTALE: la nave sta su una riga sola e occupa più colonne vicine.
            // La colonna di partenza non può essere troppo a destra, altrimenti la nave esce dalla griglia.
            riga = rand() % N;
            colonna = rand() % (N - lunghezza + 1);
 
            // controllo che le celle che la nave occuperebbe siano tutte acqua
            for(int k = 0; k < lunghezza; k++){
                if(griglia[riga][colonna + k] != 0){
                    libero = 0;
                }
            }
 
            // se sono tutte libere, scrivo la nave
            if(libero == 1){
                for(int k = 0; k < lunghezza; k++){
                    griglia[riga][colonna + k] = 1;
                }
                piazzata = 1;
            }
        }
        else{
            // VERTICALE: la nave sta su una colonna sola e occupa più righe vicine.
            // La riga di partenza non può essere troppo in basso.
            riga = rand() % (N - lunghezza + 1);
            colonna = rand() % N;
 
            // controllo che le celle che la nave occuperebbe siano tutte acqua
            for(int k = 0; k < lunghezza; k++){
                if(griglia[riga + k][colonna] != 0){
                    libero = 0;
                }
            }
 
            // se sono tutte libere, scrivo la nave
            if(libero == 1){
                for(int k = 0; k < lunghezza; k++){
                    griglia[riga + k][colonna] = 1;
                }
                piazzata = 1;
            }
        }
    }
}
 
// Piazza le 3 navi della flotta (lunghe 4, 3 e 2).
void piazzaNavi(int griglia[N][N]){
    piazzaNave(griglia, 4);
    piazzaNave(griglia, 3);
    piazzaNave(griglia, 2);
}
 
// Stampa la griglia. Se nascondi vale 1, le navi non colpite non si vedono.
// Simboli: N = nave, X = colpita, o = acqua colpita, . = niente
void stampa(int griglia[N][N], int nascondi){
    // prima riga: i numeri delle colonne (se cambi N, cambia anche questa riga)
    printf("   1 2 3 4 5 6 7 8\n");
 
    for(int i = 0; i < N; i++){
        printf("%c  ", 'A' + i);   // lettera della riga: A, B, C...
        for(int j = 0; j < N; j++){
            // scelgo il simbolo in base al valore della cella
            if(griglia[i][j] == 1 && nascondi == 0){
                printf("N ");
            }
            else if(griglia[i][j] == 2){
                printf("X ");
            }
            else if(griglia[i][j] == 3){
                printf("o ");
            }
            else{
                printf(". ");
            }
        }
        printf("\n");   // a capo alla fine di ogni riga
    }
}
 
// Spara in [r][c]. Restituisce -1 se la cella era già stata colpita, 1 se colpisce una nave, 0 se è acqua.
int spara(int griglia[N][N], int r, int c){
    // celle 2 e 3 = già colpite: colpo non valido
    if(griglia[r][c] >= 2){
        return -1;
    }
 
    // c'era una nave: la segno come colpita
    if(griglia[r][c] == 1){
        griglia[r][c] = 2;
        return 1;
    }
 
    // altrimenti era acqua: segno il colpo mancato
    griglia[r][c] = 3;
    return 0;
}
 
// Restituisce quanti pezzi di nave non colpiti restano (0 = tutte affondate).
int naviRimaste(int griglia[N][N]){
    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            // conto solo le celle con una nave ancora intera
            if(griglia[i][j] == 1){
                cnt++;
            }
        }
    }
    return cnt;
}
 
int main(void){
    srand(time(NULL));   // inizializzo i numeri casuali, una volta sola
 
    // preparo le due griglie: la mia e quella del computer
    int mia[N][N];
    int nemica[N][N];
    azzera(mia);
    azzera(nemica);
    piazzaNavi(mia);
    piazzaNavi(nemica);
 
    printf("BATTAGLIA NAVALE - spara scrivendo una coordinata (es. B5)\n");
 
    // ogni giro del ciclo = un turno del giocatore + un turno del computer
    while(1){
        // mostro le due griglie (quella nemica con le navi nascoste)
        printf("\nFlotta nemica:\n");
        stampa(nemica, 1);
        printf("\nLa tua flotta:\n");
        stampa(mia, 0);
 
        // --- turno del giocatore ---
        int r;
        int c;
        int esito;
        char lettera;
        int numero;
 
        // chiedo il colpo finché la coordinata non è valida
        while(1){
            printf("\nIl tuo colpo: ");
            int letti = scanf(" %c%d", &lettera, &numero);
            if(letti == EOF){
                return 0;                         // input finito
            }
            if(letti != 2){
                while(getchar() != '\n');         // svuota il resto della riga sbagliata
                printf("Coordinata non valida.\n");
                continue;
            }
            if(lettera >= 'a' && lettera <= 'z'){
                lettera = lettera - 'a' + 'A';    // da minuscola a maiuscola
            }
            // trasformo la coordinata in indici della matrice (la lettera A diventa 0, il numero 1 diventa 0)
            r = lettera - 'A';
            c = numero - 1;
            // controllo che sia dentro la griglia
            if(r < 0 || r >= N || c < 0 || c >= N){
                printf("Coordinata non valida.\n");
                continue;
            }
            // sparo; se avevo già sparato lì chiedo un'altra cella
            esito = spara(nemica, r, c);
            if(esito == -1){
                printf("Hai già sparato lì.\n");
                continue;
            }
            break;   // colpo valido, esco dal ciclo di richiesta
        }
 
        if(esito == 1){
            printf("Colpito!\n");
        }
        else{
            printf("Acqua.\n");
        }
 
        // se il computer non ha più navi, ho vinto
        if(naviRimaste(nemica) == 0){
            printf("\nHAI VINTO!\n");
            break;
        }
 
        // --- turno del computer ---
        // spara a caso in una cella non ancora colpita (ripete se sceglie una cella già colpita)
        do {
            r = rand() % N;
            c = rand() % N;
            esito = spara(mia, r, c);
        } while(esito == -1);
 
        if(esito == 1){
            printf("Il computer spara in %c%d: colpita una tua nave!\n", 'A' + r, c + 1);
        }
        else{
            printf("Il computer spara in %c%d: acqua.\n", 'A' + r, c + 1);
        }
 
        // se non ho più navi, ho perso
        if(naviRimaste(mia) == 0){
            printf("\nHAI PERSO!\n");
            break;
        }
    }
    return 0;
}