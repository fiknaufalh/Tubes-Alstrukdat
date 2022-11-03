#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;

FILE *pita;
static FILE *command;
static int retval;

/* *** Membaca dari file *** */
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

/* *** Membaca dari terminal *** */
void COMMAND() {
    /* Mesin siap dioperasikan. Pita command disiapkan ... */
    command = stdin;
    ADVC();
}

void ADVC()
// Pita dimajukan satu karakter.
{
    retval = fscanf(command,"%c",&currentChar);
    // EOP = (currentChar == ENTER);
    // Pita command tidak diclose agar dapat terus terbaca oleh mesin
}