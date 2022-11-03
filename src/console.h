#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include "ADT/arraydin/arraydin.h"
#include "ADT/mesinkarakter/mesinkarakter.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/queue/queue.h"

boolean compareString(char* str1, char* str2);

void STARTBNMO(ArrayDin* GamesList);

void LOADBNMO(ArrayDin* GamesList, char* filename);

int stringLength(char* string);

void stringConcat(char *s1,char *s2,char *sout);

void PLAYGAME(Queue q, Queue q2);

void SKIPGAME(Queue q, Queue q2, int input);

int WordToInt(Word CWord);

char *WordToString(Word CWord);

void HELP();

void QUIT();

#endif
