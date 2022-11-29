# include "arrmap.h"
# include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyArrMap(ArrMap *A)
{
    (*A).Neff = 0;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmtArrMap(ArrMap A)
{
    return A.Neff;
}

/* *** Daya tampung container *** */
int MaxNbElArrMap(ArrMap A)
{
    return IdxMax-1;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdxArrMap(ArrMap A)
{
    return IdxMin;
}

IdxType GetLastIdxArrMap(ArrMap A)
{
    return IsEmptyArrMap(A)? NbElmtArrMap(A) : NbElmtArrMap(A)-1;
}

ArrType GetElmtArrMap(ArrMap A, IdxType i)
{
    return A.TMap[i];
}

/* ********** SELEKTOR SET ********** */
void SetElArrMap(ArrMap *A, IdxType i, ArrType SB)
{
    (*A).TMap[i] = SB;
    (*A).Neff++;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArrMap(ArrMap A)
{
    return NbElmtArrMap(A) == 0;
}

/* *** Test tabel penuh *** */
boolean IsFullArrMap(ArrMap A)
{
    return NbElmtArrMap(A) == MaxNbElArrMap(A);
}