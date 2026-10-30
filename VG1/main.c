#include "VG1.c"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(){
    clear();
    printf("aspetta");
    fflush(stdout);
    msSleep(1*1000);
    printf("un attimo ");
    goTo(5,10);
    printf("    1????????? ??? ??   \n");
    return 0;
}