#ifndef __MESIN_KAR_H__
#define __MESIN_KAR_H__

#include <stdio.h>
#include "boolean.h"

/* Macro */
#define MARK '.'
#define ENTER '\n'

/* State Mesin */
extern char currentChar;
extern boolean EOP;
extern FILE *pita;

/* *** Membaca dari file *** */
void START(char *directory);
    /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
    Karakter pertama yang ada pada pita posisinya adalah pada jendela.
    Pita baca diambil dari stdin.
    I.S. : sembarang
    F.S. : currentChar adalah karakter pertama pada pita
            Jika currentChar != MARK maka EOP akan padam (false)
            Jika currentChar = MARK maka EOP akan menyala (true) */

void ADV();
    /* Pita dimajukan satu karakter.
    I.S. : Karakter pada jendela = currentChar, currentChar != MARK
    F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
            currentChar mungkin = MARK
            Jika  currentChar = MARK maka EOP akan menyala (true) */

char GetCC();
/* Mengirimkan currentChar */

boolean IsEOP();
/* Mengirimkan true jika currentChar = MARK */

/* *** Membaca dari terminal */
void COMMAND();
/*  Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
    Karakter pertama yang ada pada pita posisinya adalah pada jendela.
    filename merupakan nama file yang berisi pita karakter
    I.S. : sembarang
    F.S. : currentChar adalah karakter pertama pada pita
    Jika currentChar != ENTER maka EOP akan padam (false)
    Jika currentChar = ENTER maka EOP akan menyala (true) */

void ADVC();
/* Pita dimajukan satu karakter.
I.S. : Karakter pada jendela = currentChar, currentChar != ENTER
F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
currentChar mungkin = ENTER
Jika currentChar = ENTER maka EOP akan menyala (true) */

#endif