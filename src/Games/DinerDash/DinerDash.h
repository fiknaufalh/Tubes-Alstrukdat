#ifndef DINERDASH_H
#define DINERDASH_H

#include "../../ADT/queueInt/queueInt.h"
#include "../../console.h"

void header1(QueueInt makan, QueueInt durasi, QueueInt tahan, QueueInt harga);
void header2(QueueInt makan2, QueueInt durasi2);
void header3(QueueInt makan3, QueueInt tahan3);
void cook(QueueInt *makan2,QueueInt *durasi2,QueueInt* tahan2, QueueInt *harga2, QueueInt makan, QueueInt durasi, QueueInt tahan,QueueInt harga,int n);
boolean bisacook(QueueInt harga,QueueInt makan2,QueueInt makan,QueueInt makan3, QueueInt tahan3,QueueInt durasi2,int n);
void printall(QueueInt makan, QueueInt durasi, QueueInt tahan, QueueInt harga, QueueInt makan2, QueueInt durasi2, QueueInt makan3, QueueInt tahan3,QueueInt skor);
void adddaftar(QueueInt *makan, QueueInt *durasi, QueueInt *tahan, QueueInt *harga, int makanan);
void decrementcook(QueueInt*makan2,QueueInt *durasi2,QueueInt *tahan2,QueueInt *harga2,QueueInt *makan3, QueueInt *durasi3, QueueInt * tahan3, QueueInt * harga3);
void decrementserve(QueueInt * makan3, QueueInt * tahan3);
void serve(QueueInt makan3, QueueInt * tahan3, QueueInt  harga3, QueueInt * skor, QueueInt makan, QueueInt * harga);
boolean bisaserve(QueueInt makan3,QueueInt tahan3);
void totalskor(QueueInt skor);
boolean endgame(QueueInt skor, QueueInt harga);
boolean compareString(char* str1, char* str2);
int stringLength(char* string);
void DinerDash();

#endif