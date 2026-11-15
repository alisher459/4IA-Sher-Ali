#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h" 
#include<stdbool.h>

#define ST '\0'

void InizializazioneS(int dim, int s[]){
    int i = 0;
    for(i = 0; i < dim; i++){
        s[i] ='\0';
    }
}

//da la lunghezza di una stringa
int LunghezzaS(int DIM, int s[]){
    int len=0;
    while(str[len]!='\0'){
        len++;
    }
    return len;
}

// stampa la stringa al contrario 
void StampaContrarioS(char s[]) {
    int DIM = 0;
    for(int i = 0 ; s[i] != ST; i++){
        DIM++;
    }
    // altra soluzione chiamo funzione
    // DIM = LunghezzaS(DIM,s);
    for(int i = (DIM - 1); i >= 0 ; i--){
        printf("%c", s[i]);
    }
}

//dato un carattere controlla quante volte appare nella stringa principale
void contaCarattereS(char s[],char src[]){
    int cnt = 0;
    int len = 0;
    len = LunghezzaS;
    for(int i = 0; i < len; i++){
        if(s[i] == src[i]){
            cnt++;
        }
    }
}

//conta il numero per cui compare ogni lettera
void VerificaAlfabetoS(char src[]){
    int i;
    char letter;   //lettera da contare che cambiera nel tempo
    letter = 'a';
    for ( int i = 0; i < 26 ; i++){
        printf("%c -> %d ", (letter + 1),contaCarattereS(src(src+i)));

    }
}

//riceve2 parole str1 e str2 e ci da 1 se sono l'anagramma di uno e l'altro e 0 se non lo sono 
//anagramma se sono formate dalle stesse lettere ma in posizioni diverse
bool Anagramma2S (char str1[], char str2[]){
    int len = 0;
    len = LunghezzaS;
    char s[len];
    char src[len];
    s = str2;
    for(int i = 0; i < len; i++){
        contaCarattereS(s ,src);

    }
}

//dice se la stringa s è palindroma(legge uguale da sinistra a destra e da destra a sinistra. La funzione restituisce 1 se lo è, 0 altrimenti.)
bool isPalindrome(char s[]){
    int max = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        max++;
    }
    for (int i = 0; i < max / 2; i++) {
        if (s[i] != s[max - 1 - i]) {
            return false;
        }
    }
    return true;
}

// conta quante vocali(maiuscolo 65 -> e minuscolo) ci sono nella stringa s(a,e,i,o,u)
void countVowels(char s[], int *cnt){
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == 65 || s[i] == 97 || s[i] == 69 || s[i] == 101 || s[i] == 73|| s[i] == 105 || s[i] == 79 || s[i] == 111 || s[i] == 85 || s[i] == 117){
            (*cnt)++;
        }
    }
}

//conta quante parole ci sono nella stringa s
void countWords(char s[], int *n){
    *n = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] != ' ' && (i == 0 || s[i - 1] == ' ')){
            (*n)++;
        }
    }
}

//conta quante volte due caratteri consecutivi di s sono uguali
void countDoubles(char s[], int *n){
    *n = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == s[i + 1]){
            (*n)++;
        }
    }
}

//rende maiuscola la prima lettera di ogni parola e minuscole tutte le altre
void capitalizeWords(char s[]){
    for(int i = 0; s[i] != '\0'; i++){
        if(i == 0 || s[i - 1] == ' '){
            // inizio parola: minuscola -> maiuscola
            if(s[i] > 96 && s[i] < 123){
                s[i] = s[i] - 32;
            }
        } else {
            // dentro la parola: maiuscola -> minuscola
            if(s[i] > 64 && s[i] < 91){
                s[i] = s[i] + 32;
            }
        }
    }
}

//trova la posizione della prima cosa uguale di c in s
void firstIndex(char s[], char c, int *pos){
    *pos = -1;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == c){
            *pos = i;
            break;
        }
    }
}

//dice se i caratteri di s sono in ordine non decrescente(>= da ultimo carattere) 
bool isSorted(char s[]){    //bool perche per me e piu logico   
    for(int i = 1; s[i] != '\0'; i++){
        if(s[i] < s[i - 1]){
            return false;
        }
    }
    return true;   
}

//conta quante volte nella stringa compare la sequenza a seguita subito da b
int countDistinctPairs(char s[], char a, char b){
    int n = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(i > 0){
            if(s[i] == b && s[i - 1] == a){
            n++;
            }
        }
    }
    return n;
}

//sposta tutti i caratteri di una posizione a sinistra, il primo carattere va in fondo
void rotateLeft(char s[]){
    int max = 0;
    for(int i = 0; s[i] != '\0'; i++){
        max++;
    }
    for(int i = 0; i < max; i++){
        if(i == 0){
            s[i] = s[max];
        }
        if(i > 0){
            s[i] = s[i - 1];
        }
    }
}

// inserisci x in s alla posizione pos (s si allunga di uno);
void insertCharAt(char s[], int pos, char x){
    int max = 0;
    for(int i = 0; s[i] != '\0'; i++){
        max++;
    }
    for(int i = max + 1; i > pos; i--){
        s[i] = s[i - 1];
    }
    s[pos] = x;
}

//dice quanti caratteri di s rappresentano numeri
int countNumerals(char s[]){
    int cnt;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] > 47 && s[i] < 58){
            cnt++;
        }
    }
    return cnt;
}

//conta le lettere di s minuscole e MAIUSCOLE;
void countCase(char *s, int *lower, int *upper){
    *lower = 0;
    *upper = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] > 64 && s[i] < 91){
            (*upper)++;
        }
        if(s[i] > 96 && s[i] < 123){
            (*lower)++;
        }
    }
}

//rimuove del da s accorciando
void removeChar(char s[], char del){
    int j = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] != del){
            s[j] = s[i];
            j++;
        }
    }
    s[j] = '\0';
}