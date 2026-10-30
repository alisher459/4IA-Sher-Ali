#define _POSIX_C_SOURCE 199309L
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h> //intercetta il CONTROL C

/** sposta questo processo dalla CPU alla ready list per tot millisecondi (mettilo in pausa) */
void msSleep(int millis);

/** use an "ASCII escape sequence" to move the cursor at pos (x, y) */
void goTo(int x, int y);
