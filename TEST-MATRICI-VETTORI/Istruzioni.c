#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"
#include "lib.c"
 
int main() {
    /*CHIAMATA VOID --> DA SOLA
    int matrice[3][3];
    pitagoricaM(3, matrice);
    */

    /*CHIAMATA INT --> DENTRO VARIABILE
    int matrice[3][3] = {
    {1, 1, 1},
    {1, 1, 1},
    {1, 1, 1}
    };
    int risultato = sommaMatrice(3, 3, matrice);
    printf("La somma totale e': %d\n", risultato);
    */

    /*CHIAMATA BOOL --> DENTO IF-ELSE
    int matrice[3][3];
    if (allDifferentM(3, 3, matrice))
        printf("Tutti gli elementi sono diversi!\n");
    else 
        printf("Ci sono dei doppioni!\n");
    */
   
    return 0;
}