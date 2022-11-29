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

boolean canAddLeft (List Snake);
// Fungsi untuk mengecek apakah dapat dilakukan penambahan ekor ke kiri

boolean canAddAbove (List Snake);
// Fungsi untuk mengecek apakah dapat dilakukan penambahan ekor ke atas

boolean canAddBelow (List Snake);
// Fungsi untuk mengecek apakah dapat dilakukan penambahan ekor ke bawah

boolean canAddRight (List Snake);
// Fungsi untuk mengecek apakah dapat dilakukan penambahan ekor ke kanan

void PrintMap(List Snake,List Food,List Meteor,List Obstacle);
// Prosedur untuk mencetak map permainan

void Move (List *Snake);
// Prosedur untuk pergerakan Snake

boolean isMoveHitBody(List Snake, char* cmd);
// Fungsi yang menghasilkan true jika pergerakan mengenai badan (handler)


Point generateFood(List Snake);
//Fungsi yang men-generate makanan berupa point secara random

boolean foodEaten(List Snake, List *Food);
//Fungsi yang mengembalikan true jika makanan berhasil kemakan

Point generateMeteor (List Snake, List Food,List Obstacle);
//Fungsi yang men-generate meteor

Point generateObstacle(List Snake,List Food);
//Fungsi yang men-generate obstacle

boolean isMeteorHitSnake(List Snake, Point meteor);
//Fungsi yang menghasilkan true jika meteor mengenai snake

void skorakhir (List Snake);
//Fungsi yang mengembalikan skor akhir

#endif
