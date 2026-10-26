#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"
#include<stdbool.h>

//---PRADELLA---//
void initStr(int _dim, int _str[]){
    int i=0;
    for(i=0; i<_dim, i++){
        _str[i]='\0';
    }
}
int strLenght(int dim, int str[]){
    int len=0;
    while(str[len]!='\0'){
        len++;
    }
    return len;
}

//---BOTTONI---//
