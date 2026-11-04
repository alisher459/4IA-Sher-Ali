
/** carica vettore con valori random compresi tra min e max(esclusi) dati per riferimento
 * @param int Riferimento al vettore
 * @param int dim
 * @param int min
 * @param int max
 */
void caricaV(int v[], int DIM, int min, int max);

/** carica matrice con valori random compresi tra min e max(esclusi) dati per riferimento
 * @param int quad
 * @param int Riferimento alla matrice
 * @param int min
 * @param int max
 */
void caricaM(int quad, int m[quad][quad], int min, int max);

/** stampa vettore 
 * @param int Riferimento al vettore
 *  @param int dim 
 */
void stampaV(int v[], int DIM);

/** stampa matrice 
 * @param int quad 
 * @param int Riferimento alla matrice
 */
void stampaM(int quad, int m[quad][quad]);

/** comunica per ogni valore del vettore in quali celle della matrice si trova stampando gli indici 
 * @param int quad 
 * @param int dim 
 * @param int Riferimento al vettore
 * @param int Riferimento alla matrice 
 */
void celleVM(int quad,int DIM,int v[],int m[quad][quad]);

/** comunica per ogni quanti valori del vettore sono uguali a quelli nella matrice nella stessa posizione 
 * @param int quad 
 * @param int dim 
 * @param int Riferimento al vettore
 * @param int Riferimento alla matrice 
 */
void ugualiVM(int quad,int DIM,int v[],int m[quad][quad]);

/** restituisce in quante righe della matrice hanno sommma dei valori superiore alla somma del vettore 
 * @param int dim 
 * @param int Riferimento al vettore
 * @param int Riferimento alla matrice 
 */int sommaVM(int quad,int DIM,int v[],int m[quad][quad]);
