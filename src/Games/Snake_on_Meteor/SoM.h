#ifndef __Snake_on_Meteor_H__
#define __Snake_on_Meteor_H__

#include "../../boolean.h"
#include "../../ADT/point/point.h"
#include "../../ADT/linkedlist/listdp.h"
#include "../../ADT/mesinkata/mesinkata.h"
// #include "../../console.h"

#define minSize 0
#define maxSize 4

#define AbsisN(Elmt) (Elmt)->position.X
#define OrdinatN(Elmt) (Elmt)->position.Y

void SoM();
Point generateHeadPosition();
void addSnakeTail(List *Snake, int nExtraTail);
void PrintMap(List Snake);
void Move(List *Snake);
boolean isMoveHitBody(List Snake, char* cmd);
// gcc ../../ADT/point/point.c ../../ADT/linkedlist/listdp.c ../../ADT/mesinkata/mesinkata.c ../../ADT/mesinkarakter/mesinkarakter.c SoM.c -o main

#endif