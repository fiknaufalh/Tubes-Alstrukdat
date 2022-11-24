#ifndef TOWEROFHANOI_H
#define TOWEROFHANOI_H
#include "stack.h"
#include "mesinkata.h"

int length(Stack S);
void printTower(Stack S, Stack S2, Stack S3);
void tipe1();
void tipe2();
void tipe3();
void tipe4();
void tipe5();
void base();
void pindah(Stack *A, Stack *B, Stack *C, char *asal,char *tujuan,int *steps);
boolean bisapindah(Stack S1, Stack S2);
boolean endgame(Stack C);
char *WordToString(Word CWord);

void TowerOfHanoi();
#endif