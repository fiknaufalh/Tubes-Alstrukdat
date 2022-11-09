#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "console.h"
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


void RNG (){
    int kesempatan;
    int angka;
    int tebakan;
    int ketebak;
    angka = randomnumber();
    ketebak = 0;
    kesempatan = 10;
    printf("RNG telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    while (ketebak == 0 && kesempatan > 0){
        printf("Tebakan: ");
        scanf("%d",&tebakan);

        if (tebakan < angka){
            printf("Lebih besar\n"); 
            ketebak = 0; 
            kesempatan -= 1;      
        }
        else if (tebakan > angka){
            printf("Lebih kecil\n");
            ketebak = 0;
            kesempatan -= 1;
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
}

/*
I.S : Angka digenerate secara acak dan kesempatan menebak setiap pemain adalah sebanyak 10
F.S : Angka berhasil/tidak berhasil ditebak
*/
