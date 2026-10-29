#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"
#include "lib.c"

#define righe 3
#define colonne 5

int main(void){
    int v[righe][colonne];
    caricaM(righe,colonne,v,10,15);
    stampaM(righe,colonne,v);
    return 0;
}