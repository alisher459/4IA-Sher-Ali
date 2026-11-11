#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"
#include<stdbool.h>

#define ST '\0'
//---PRADELLA---//
//inizializa una stringa a 0
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

//---BOTTONI---//
