/* File: Point.h */

#ifndef POINT_H
#define POINT_H

#include "../../boolean.h"

typedef struct { 
	int X; /* absis   */
	int Y; /* ordinat */
} Point;

/* *** Selektor Point *** */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y

#define POINT_UNDEF (-1)

/* *** Konstruktor *** */
void CreatePoint (Point * P, int X, int Y);
/* Membentuk sebuah Point dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void PrintPoint (Point P);
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */                


/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
Point NextX (Point P);
/* Mengirim salinan P dengan absis ditambah satu */              
Point NextY (Point P);
/* Mengirim salinan P dengan ordinat ditambah satu */
Point PlusDelta (Point P, int deltaX, int deltaY);
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
void shiftPoint (Point *P, int deltaX, int deltaY);
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */

boolean EQ (Point P1, Point P2);
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */

#endif