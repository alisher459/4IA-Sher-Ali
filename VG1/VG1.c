#include "VG1.h"

/** sposta questo processo dalla CPU alla ready list per tot millisecondi (mettilo in pausa) */

void msSleep(int millis) {
	struct timespec delay;

    delay.tv_sec = millis / 1000;
    delay.tv_nsec = (millis % 1000) * 1000000L;

    nanosleep(&delay, NULL); //... call nanosleep();
}

void goTo(int x,int y){
    printf("\033[%d;%dH",y+1,x+1);
    fflush(stdout);
}

void clear(){
    printf("\033[2J]\033[H");
    fflush(stdout);
}