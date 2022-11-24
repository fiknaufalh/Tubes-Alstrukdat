#ifndef __Snake_on_Meteor_H__
#define __Snake_on_Meteor_H__

#include "../../boolean.h"
#include "../../ADT/point/point.h"
#include "../../ADT/linkedlist/listdp.h"
#include "../../ADT/mesinkata/mesinkata.h"
// #include "../../console.h"

#define minSize 0
#define maxSize 4
// Macro untuk batas ukuran/dimensi pada peta permainan

#define AbsisN(Elmt) (Elmt)->position.X
#define OrdinatN(Elmt) (Elmt)->position.Y
// Macro untuk akses X dan Y dari suatu node (head/body/tail) dalam List Snake

void SoM();
// Program games utama Snake on Meteor

Point generateHeadPosition();
// Fungsi yang men-generate posisi Head berupa Point secara random

void addSnakeTail(List *Snake, int nExtraTail);
// Prosedur untuk menambahkan ekor sebanyak nExtraTail

void PrintMap(List Snake);
// Prosedur untuk mencetak map permainan

void Move(List *Snake);
// Prosedur untuk pergerakan Snake

boolean isMoveHitBody(List Snake, char* cmd);
// Fungsi yang menghasilkan true jika pergerakan mengenai badan (handler)

#endif