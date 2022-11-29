#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../console.h"
#include "RNG.h"

int randomnumber(){
/*
Fungsi yang mengenerate angka acak dan mengembalikan angka tersebut
*/
    int angka;
    srand(time(NULL));
    angka = rand()%100+1;    
    return angka;
}


int RNG (){
    int kesempatan;
    int angka;
    int tebakan;
    int ketebak;
    int skor = 100;
    angka = randomnumber();
    ketebak = 0;
    kesempatan = 10;
    printf("RNG telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    while (ketebak == 0 && kesempatan > 0){
        printf("\nTebakan: ");
        STARTCOMMAND();
        tebakan = WordToInt(currentCMD);

        if (tebakan < angka){
            printf("Lebih besar\n"); 
            ketebak = 0; 
            kesempatan -= 1;
            skor -= 10;
        }
        else if (tebakan > angka){
            printf("Lebih kecil\n");
            ketebak = 0;
            kesempatan -= 1;
            skor -= 10;
        }
        else {
            ketebak = 1;
            printf("\n");
            printf("Ya, X adalah %d.\n", tebakan);
        }
    }
    //jika tidak berhasil menebak dalam 10 kesempatan
    if (ketebak == 0 && kesempatan == 0){
        printf("Maaf kesempatan untuk menebak sudah habis.\n");
        printf("Jawaban yang benar adalah %d.\n", angka);
    }
    return skor;
}

/*
I.S : Angka digenerate secara acak dan kesempatan menebak setiap pemain adalah sebanyak 10
F.S : Angka berhasil/tidak berhasil ditebak
*/
