/** Stampa Matrice
 * @param int Riferimento alla matrice
 * @param int righe
 * @param int colonne
 */
void StampaMatrice(int righe, int colonne, int m[righe][colonne]);

/** carica matrice
 * @param int Riferimento alla matrice
 * @param int righe
 * @param int colonne
 */
void caricamatrice(int righe,int colonne,int m[righe][colonne]);

/* provare a creare le funzioni per le seguenti richieste:.
2. Stampa della matrice con somma totale di ogni singola riga.
3. Somma totale del triangolo inferiore e del triangolo superiore.
*/

/** Calcolo del valor medio della matrice
 * @param int righe 
 * @param int colonne
 * @return valore medio
 */
int Mediomatrice(int righe,int colonne,int m[righe][colonne]);

/*
  Realizzare quindi il gioco per funzioni:
    - creaCodiceSegreto.
    - richiediCodiceUtente.
    - verificaStampaCodice.
    il tutto inserito in un ciclo do-while per la ripetizione finche codice non è esatto.
*/