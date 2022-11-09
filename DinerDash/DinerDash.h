#ifndef DINERDASH_H
#define DINERDASH_H

#include "mesinkata.h"
#include "queue.h"
void header1(Queue makan, Queue durasi, Queue tahan, Queue harga);
void header2(Queue makan2, Queue durasi2);
void header3(Queue makan3, Queue tahan3);
void cook(Queue *makan2,Queue *durasi2,Queue* tahan2, Queue *harga2, Queue makan, Queue durasi, Queue tahan,Queue harga,int n);
boolean bisacook(Queue harga,Queue makan2,Queue makan,Queue makan3, Queue tahan3,Queue durasi2,int n);
void printall(Queue makan, Queue durasi, Queue tahan, Queue harga, Queue makan2, Queue durasi2, Queue makan3, Queue tahan3,Queue skor);
void adddaftar(Queue *makan, Queue *durasi, Queue *tahan, Queue *harga, ElType makanan);
void decrementcook(Queue*makan2,Queue *durasi2,Queue *tahan2,Queue *harga2,Queue *makan3, Queue *durasi3, Queue * tahan3, Queue * harga3);
void decrementserve(Queue * makan3, Queue * tahan3);
void serve(Queue makan3, Queue * tahan3, Queue  harga3, Queue * skor, Queue makan, Queue * harga);
boolean bisaserve(Queue makan3,Queue tahan3);
void totalskor(Queue skor);
boolean endgame(Queue skor, Queue harga);
boolean compareString(char* str1, char* str2);
int stringLength(char* string);
void DinerDash();
#endif