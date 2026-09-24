#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"
#include "lib.c"
#define DIM 10
int main(void){
    int m[DIM][DIM]={
    {0,1,2},
    {10,20,30},
    {60,70,80},
    }
    StampaMatrice(DIM,DIM,m);
    return 0;
}