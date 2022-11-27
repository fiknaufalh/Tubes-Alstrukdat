#ifndef TOWEROFHANOI_H
#define TOWEROFHANOI_H
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/stackInt/stackInt.h"
#include "../../boolean.h"

void printTower(StackInt S, StackInt S2, StackInt S3);
void tipe1();
void tipe2();
void tipe3();
void tipe4();
void tipe5();
void base();
void pindah(StackInt *A, StackInt *B, StackInt *C, char *asal,char *tujuan,int *steps);
boolean bisapindah(StackInt S1, StackInt S2);
boolean endgameToH(StackInt C);
char *WordToString(Word CWord);

void TowerOfHanoi();
#endif