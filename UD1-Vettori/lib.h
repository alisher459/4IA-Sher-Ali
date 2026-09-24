
/*
/** Stampa i valori dell'array in colonna con indice di cella.
 * @param int* Riferimento al vettore da riempire.
 * @param int Dimensione dell'Array.
 
void printColArray(int _v[], int _dim);


/** Stampa su singola riga i valori del vettore.
 * @param int* Riferimento al vettore da riempire.
 * @param int Dimensione dell'Array.
 
void printRowArray(int _v[], int _dim);


/** Assegna ad ogni cella di un array un valore random tra 1 e 99.
 * @param int* Riferimento al vettore da riempire.
 * @param int Dimensione dell'Array.

void randomInputArray(int _v[], int _dim);


/** Assegna ad ogni cella di un array un valore richiesto in input.
 * @param int* Riferimento al vettore da acquisire.
 * @param int Dimensione dell'Array.
 
void manualInputArray(int _v[], int _dim);


/** Azzera tutte le celle di un array.
 * @param int* Riferimento al vettore da inizializzare
 * @param int Dimensione dell'Array.
 
void initArray(int _v[], int _dim);
*/
/** fornisce il valore massimo in un vettore
 * @param int* Riferimento al vettore da inizializzare
 * @param int Dimensione dell'Array.
 */
int ValoreMassimo(int v[],int dim);

/** conta quante volte appare nel vettore il valore dato da utente
 * @param int* Riferimento al vettore da inizializzare
 * @param int Dimensione dell'Array.
 * @param int e il numero scelto da utente
 */
int ContaValore(int v[],int dim,int choose);

/** conta quante volte appare nel vettore il valore dato da utente
 * @param int* Riferimento al vettore da inizializzare
 * @param int Dimensione dell'Array.
 * @param int valore da sostituire
 * @param int valore con cui sostituire
 */
int ricercaSostituisci(int v[],int dim,int src,int sost);








