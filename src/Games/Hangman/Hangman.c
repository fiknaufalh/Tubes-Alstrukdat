#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../console.h"
#include "Hangman.h"

char* randomstr(char* filename, int maxLength, int maxKata, char kata[maxKata][maxLength]) {
    srand(time(NULL));
    char path[100];
    char input[maxLength];
    int totalKata;
    totalKata = 0;
    FILE *fp;
    stringConcat("./data/", filename, path);
    fp = fopen(path, "r");
    if (fp==NULL) {
        printf("File gagal dibuka!\n");
    }
    while (fgets(input, maxLength-1, fp)) {
        sscanf(input, "%s", kata[totalKata]);
        totalKata++;
    }
    int idx;
    idx = rand()%totalKata;
    fclose(fp);
    return(kata[idx]);
}

void printQTebakan(Queue qTebakan) {
    ElType temp;
    int panjang = length(qTebakan);
    if (panjang>0) {
        printf("%s",HEAD(qTebakan));
        dequeue(&qTebakan,&temp);
        for (int i = 1;i<panjang;i++) {
            printf("%s",HEAD(qTebakan));
            dequeue(&qTebakan,&temp);
        }
    }
}

Queue deleteQTebakan (Queue qTebakan) {
    ElType temp;
    int panjang = length(qTebakan);
    for (int i=0; i<panjang; i++) {
        dequeue(&qTebakan, &temp);
    }
    return(qTebakan);
}

void addKata (char* filename, char* kataTambahan) {
    FILE *fp;
    char path[100];
    stringConcat("./data/", filename, path);
    fp = fopen(path, "a");
    if (fp==NULL) {
        printf("File gagal dibuka!\n");    
    } else {
        fprintf(fp,"\n");
        fputs(kataTambahan, fp);
        printf("Kata berhasil ditambahkan ke dalam list tebakan!\n");
    }
    fclose(fp);
}

boolean adaDuplikat (Queue qTebakan, char tebakan) {
    boolean found;
    char* temp;
    found = false;
    while (!isEmpty(qTebakan)) {
        if (*HEAD(qTebakan)==tebakan) {
            found = true;
        }
        dequeue(&qTebakan, &temp);
    }
    return found;
}

void HANGMAN() {
    int maxKata;
    int maxLength;
    char kata[maxKata][maxLength];
    char* tebakKata;
    int i;
    int kesempatan;
    int panjangKata;
    char* tebakan;
    int jumlahBenar;
    int prevJumlahBenar;
    int duplikat;
    Queue qTebakan;
    ElType temp;
    Map SB;
    char tebak;
    int score;
    char* jawaban;
    char* kataTambahan;
    char* playerName;
    maxKata = 100;
    maxLength = 30;
    i = 0;
    kesempatan = 10;
    CreateQueue(&qTebakan);
    while (kesempatan!=0) {
        tebakKata = randomstr("daftarkata.txt", maxLength, maxKata, kata);
        int huruf[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        panjangKata = stringLength(tebakKata);
        jumlahBenar = 0;
        while (jumlahBenar<panjangKata && kesempatan!=0) {
            printf("Tebakan sebelumnya: ");
            if (isEmpty(qTebakan)) {
                printf("-\n");
            } else {
                printQTebakan(qTebakan);
                printf("\n");
            }
            printf("Kata: ");
            for (i=0; i<panjangKata; i++) {
                if (huruf[i]==1) {
                    printf("%c", tebakKata[i]);
                } else {
                    printf("_ ");
                }
            } 
            printf("\n");
            printf("Kesempatan: %d\n", kesempatan);
            printf("Masukkan tebakan: ");
            STARTCOMMAND();
            tebakan = WordToString(currentCMD);
            tebak = tebakan[0]-32;
            prevJumlahBenar = jumlahBenar;
            duplikat = 0;
            for (i=0; i<panjangKata; i++) {
                if (huruf[i]==1) {
                    if (tebakKata[i]==tebakan[0] || tebakKata[i]==tebak) {
                        duplikat = 1;
                        break;
                    }
                    continue;
                }
                if (tebakan[0]==tebakKata[i] || tebak==tebakKata[i]) {
                    huruf[i] = 1;
                    jumlahBenar++;
                }
            }
            if (prevJumlahBenar==jumlahBenar && duplikat==0) {
                if (!adaDuplikat(qTebakan, tebakan[0])) {
                    enqueue(&qTebakan, tebakan);
                } else {
                    printf("Kamu sudah pernah menebak huruf ini!\n");
                }
                kesempatan--;
            } else if (duplikat==1 || adaDuplikat(qTebakan, tebakan[0])) {
                printf("Kamu sudah pernah menebak huruf ini!\n");
            } else {
                enqueue(&qTebakan, tebakan);
            }
            printf("\n");
        }
        if (kesempatan==0) {
            printf("Gagal menebak huruf %s!\n", tebakKata);
        } else {
            printf("Berhasil menebak kata %s! Kamu mendapatkan %d poin!\n", tebakKata, panjangKata);
            score = score+panjangKata;
        }
        qTebakan = deleteQTebakan(qTebakan);
        printf("\n");
    } 
    printf("Game HANGMAN sudah selesai.\n");
    printf("Apakah Kamu ingin menambahkan kata ke dalam list tebakan (Y/N)? ");
    STARTCOMMAND();
    jawaban = WordToString(currentCMD);
    if (jawaban[0]=='Y') {
        printf("Masukkan kata yang ingin ditambahkan (Huruf kapital): ");
        STARTCOMMAND();
        kataTambahan = WordToString(currentCMD);
        addKata("daftarkata.txt", kataTambahan);
    } 
    printf("\n");
    printf("Masukkan nama player: ");
    STARTCOMMAND();
    playerName = WordToString(currentCMD);
    printf("\n");
    printf("Terima kasih %s sudah bermain HANGMAN!\n", playerName);
    printf("Bye.. Bye..");
}