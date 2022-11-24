#include <stdio.h>
#include "point.h"

/* *** Konstruktor *** */
void CreatePoint (Point * P, int X, int Y) {
/* Membentuk sebuah Point dari komponen-komponennya */
/* I.S P tidak terdefinisi, F.S P terdefinisi bertipe Point */
// KAMUS LOKAL
//ALGORITMA
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */ 
void PrintPoint (Point P) {
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma. */
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
// KAMUS
// ALGORITMA
    printf("(%d,%d)\n", Absis(P), Ordinat(P));
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */ 
Point NextX (Point P) {
/* Mengirim salinan P dengan absis ditambah satu */
// KAMUS LOKAL
    Point result;
// ALGORITMA
    result = P;
    Absis(result) += 1;
    return result;
}

Point NextY (Point P) {
/* Mengirim salinan P dengan ordinat ditambah satu */
// KAMUS LOKAL
    Point result;
// ALGORITMA
    result = P;
    Ordinat(result) += 1;
    return result;
}

Point PlusDelta (Point P, int deltaX, int deltaY) {
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
// KAMUS LOKAL
    Point result;
// ALGORITMA
    result = P;
    Absis(result) += deltaX;
    Ordinat(result) += deltaY;
    return result;
}

void shiftPoint (Point *P, int deltaX, int deltaY) {
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
// KAMUS LOKAL
// ALGORITMA
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

boolean EQ (Point P1, Point P2) {
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
// KAMUS LOKAL
// ALGORITMA
    if ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2))) {
        return true;
    }
    else {
        return false;
    }
}