# ifndef __ARRMAP_H__
# define __ARRMAP_H__

# include "../map/map.h"
# include "../../boolean.h"

#define IdxMax 100
#define IdxMin 0
# define IdxUndef -1

typedef int IdxType;
typedef Map ArrType;
typedef char* NameType;

typedef struct 
{
    ArrType TMap[IdxMax];
    int Neff;
} ArrMap;

#define ArrMap(i) (T).TMap[i]
#define ArrMapNeff(A) (A).Neff


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyArrMap(ArrMap *A);

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmtArrMap(ArrMap A);

/* *** Daya tampung container *** */
int MaxNbElArrMap(ArrMap A);

/* *** Selektor INDEKS *** */
IdxType GetFirstIdxArrMap(ArrMap A);
IdxType GetLastIdxArrMap(ArrMap A);
ArrType GetElmtArrMap(ArrMap A, IdxType i);

/* ********** SELEKTOR SET ********** */
void SetElArrMap(ArrMap *A, IdxType i, ArrType SB);

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArrMap(ArrMap A);

/* *** Test tabel penuh *** */
boolean IsFullArrMap(ArrMap A);

# endif


