#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;
static FILE *pita;
static int retval;

void START(char *directory) {
    /* Mesin siap dioperasikan. Pita disiapkan ... */
    pita = fopen(directory, "r");
    ADV();
}

void ADV() {
    /* Pita dimajukan satu karakter. ... */
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == MARK);
    if (EOP) {
        fclose(pita);
    }
}

char GetCC() {
    /* Mengirimkan currentChar */
    return currentChar;
}

boolean IsEOP() {
    /* Mengirimkan true jika currentChar = MARK */
    return EOP;
}