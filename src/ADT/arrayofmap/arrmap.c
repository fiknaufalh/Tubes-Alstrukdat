# include "arrmap.h"
# include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyArrMap(ArrMap *A)
/* I.S. sembarang */
/* F.S. Terbentuk tabel Tmap kosong dengan kapasitas IdxMax */
{
    (*A).Neff = 0;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmtArrMap(ArrMap A)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
    return A.Neff;
}

/* *** Daya tampung container *** */
int MaxNbElArrMap(ArrMap A)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
    return IdxMax-1;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdxArrMap(ArrMap A)
/* Mengirimkan indeks elemen pertama */
{
    return IdxMin;
}

IdxType GetLastIdxArrMap(ArrMap A)
/* Mengirimkan indeks elemen terakhir */
/* Mengirimkan 0 jika tabel kosong */
{
    return IsEmptyArrMap(A)? NbElmtArrMap(A) : NbElmtArrMap(A)-1;
}

ArrType GetElmtArrMap(ArrMap A, IdxType i)
/* Prekondisi : Tabel tidak kosong, i antara Tmap[IdxMin]..Tmap[IdxMax-1] */
/* Mengirimkan elemen tabel yang ke-i */
{
    return A.TMap[i];
}

/* ********** SELEKTOR SET ********** */
void SetElArrMap(ArrMap *A, IdxType i, ArrType SB)
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen Tmap yang ke-i bernilai SB */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai SB */
{
    (*A).TMap[i] = SB;
    (*A).Neff++;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArrMap(ArrMap A)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return NbElmtArrMap(A) == 0;
}

/* *** Test tabel penuh *** */
boolean IsFullArrMap(ArrMap A)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return NbElmtArrMap(A) == MaxNbElArrMap(A);
}