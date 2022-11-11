#ifndef DINERDASH_H
#define DINERDASH_H

#include "../../ADT/queueInt/queueInt.h"
#include "../../ADT/arraydinInt/arraydinInt.h"
#include "../../console.h"

void header1(QueueInt makan, QueueInt durasi, QueueInt tahan, QueueInt harga);

void header2(QueueInt makan2, QueueInt durasi2);

void header3(ArrayDinInt makan3, ArrayDinInt tahan3);

void cook(QueueInt *makan2,QueueInt *durasi2,QueueInt* tahan2, QueueInt *harga2, QueueInt makan, QueueInt durasi, QueueInt tahan,QueueInt harga,int n);

boolean bisacook(QueueInt harga, QueueInt makan2, QueueInt makan, ArrayDinInt makan3, ArrayDinInt tahan3, QueueInt durasi2, int n);

void printall(QueueInt makan, QueueInt durasi, QueueInt tahan, QueueInt harga, QueueInt makan2, QueueInt durasi2, ArrayDinInt makan3, ArrayDinInt tahan3,QueueInt skor);

void adddaftar(QueueInt *makan, QueueInt *durasi, QueueInt *tahan, QueueInt *harga, int makanan);

void decrementcook(QueueInt*makan2,QueueInt *durasi2,QueueInt *tahan2,QueueInt *harga2,ArrayDinInt *makan3, ArrayDinInt *durasi3, ArrayDinInt * tahan3, ArrayDinInt * harga3);

void decrementserve(ArrayDinInt * makan3, ArrayDinInt * tahan3);

void serve(ArrayDinInt * makan3, ArrayDinInt * tahan3, ArrayDinInt * harga3, QueueInt * makan, QueueInt * skor, int n);

boolean bisaserve(QueueInt makan, ArrayDinInt makan3,ArrayDinInt tahan3, int n);

void totalskor(QueueInt skor);

boolean endgame(QueueInt skor, QueueInt harga);

boolean compareString(char* str1, char* str2);

int stringLength(char* string);

void DinerDash();

#endif