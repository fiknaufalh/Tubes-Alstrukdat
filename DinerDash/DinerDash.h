#ifndef DINERDASH_H
#define DINERDASH_H

#include "queue.h"
void header1(Queue makan, Queue durasi, Queue tahan, Queue harga);
void header2(Queue makan2, Queue durasi2);
void header3(Queue makan3, Queue tahan3);
void cook(Queue makan3,Queue tahan3,Queue *makan2,Queue *durasi2,Queue* tahan2, Queue *harga2, Queue makan, Queue durasi, Queue tahan,Queue harga,int n);
void printall(Queue makan, Queue durasi, Queue tahan, Queue harga, Queue makan2, Queue durasi2, Queue makan3, Queue tahan3);
void adddaftar(Queue *makan, Queue *durasi, Queue *tahan, Queue *harga, ElType makanan);
void decrementcook(Queue*makan2,Queue *durasi2,Queue *tahan2,Queue *harga2,Queue *makan3, Queue *durasi3, Queue * tahan3, Queue * harga3);
void decrementserve(Queue * makan3, Queue * tahan3);
void serve(Queue makan3, Queue * tahan3, Queue  harga3, Queue * skor, Queue makan, Queue * harga);
void totalskor(Queue skor);
void DinerDash();
#endif