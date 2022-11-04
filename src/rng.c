#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomnumber(){
/*
Fungsi yang mengenerate angka acak dan mengembalikan angka tersebut
*/
    int angka;
    srand(time(NULL));
    angka = rand()%100;    
    return angka;
}


int RNG (){
    int score;
    score = 1000;
    int angka;
    int tebakan;
    int ketebak;
    angka = randomnumber();
    ketebak = 0;
    printf("RNG telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    while (ketebak == 0 && score > 0){
        printf("Tebakan: ");
        scanf("%d",&tebakan);

        if (tebakan < angka){
            printf("Lebih besar\n"); 
            ketebak = 0; 
            score -= 10;      
        }
        else if (tebakan > angka){
            printf("Lebih kecil\n");
            ketebak = 0;
            score -= 10;
        }
        else {
            ketebak = 1;
            printf("\n");
            printf("Ya, X adalah %d.\n", tebakan);
            break;
        }
    }
    return score;
}

/*
I.S score awal : 1000 
F.S score akhir pemain yang mana akan berkurang sebanyak 10 poin jika menebak salah pada setiap giliran
Kesempatan akan habis jika score pemain sudah 0
*/
