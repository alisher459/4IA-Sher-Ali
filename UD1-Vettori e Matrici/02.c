#include <stdio.h>

int main() {
    int n = 5;
    float altezze[5] = {1.70, 1.65, 1.80, 1.65, 1.75};
    float min, somma = 0, media, cerca;
    int conteggio = 0;

    printf("ANALISI ARRAY ALTEZZE\n");

    min = altezze[0];
    for (int i = 0; i < n; i++) {
        if (altezze[i] < min) {
            min = altezze[i];
        }
        somma += altezze[i];
    }
    printf("1. Altezza minima: %.2f metri\n", min);
    media = somma / n;
    
    printf("2. Altezza media: %.2f metri\n", media);

    printf("\n3. Inserisci un'altezza da cercare (es. 1.65): ");
    scanf("%f", &cerca);
    
    for (int i = 0; i < n; i++) {
        if (altezze[i] == cerca) {
            conteggio++;
        }
    }
    printf("   L'altezza %.2f compare %d volta/e nell'array.\n", cerca, conteggio);
    printf("\n4. Celle con valori inferiori all'altezza media (%.2f):\n", media);
    int trovati = 0;
    for (int i = 0; i < n; i++) {
        if (altezze[i] < media) {
            printf("   -cella [%d] = %.2f\n", i, altezze[i]);
            trovati++;
        }
    }
    
    if (trovati == 0) {
        printf("   Nessun valore e' inferiore alla media.\n");
    }
    return 0;
}