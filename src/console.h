#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include "ADT/arraydin/arraydin.h"
#include "ADT/mesinkarakter/mesinkarakter.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/queue/queue.h"

boolean compareString(char* str1, char* str2);

void STARTBNMO(ArrayDin* GamesList);

void PLAYGAME(Queue q, Queue q2);

void SKIPGAME(Queue q, Queue q2, int input);

#endif