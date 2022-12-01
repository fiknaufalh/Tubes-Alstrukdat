#ifndef HANGMAN_H
#define HANGMAN_H

#include "../../boolean.h"
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/queue/queue.h"
#include "../../ADT/map/map.h"

char* randomstr(char* filename, int maxLength, int maxKata, char kata[maxKata][maxLength]);

void printQTebakan(Queue qTebakan);

Queue deleteQTebakan (Queue qTebakan);

void addKata (char* filename, char* kataTambahan);

boolean adaDuplikat (Queue qTebakan, char tebakan);

int HANGMAN();

#endif