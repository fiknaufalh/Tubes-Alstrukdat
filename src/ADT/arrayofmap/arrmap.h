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
/* I.S. sembarang */
/* F.S. Terbentuk tabel Tmap kosong dengan kapasitas IdxMax */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmtArrMap(ArrMap A);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */

/* *** Daya tampung container *** */
int MaxNbElArrMap(ArrMap A);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */

/* *** Selektor INDEKS *** */
IdxType GetFirstIdxArrMap(ArrMap A);
/* Mengirimkan indeks elemen pertama */

IdxType GetLastIdxArrMap(ArrMap A);
/* Mengirimkan indeks elemen terakhir */
/* Mengirimkan 0 jika tabel kosong */

ArrType GetElmtArrMap(ArrMap A, IdxType i);
/* Prekondisi : Tabel tidak kosong, i antara Tmap[IdxMin]..Tmap[IdxMax-1] */
/* Mengirimkan elemen tabel yang ke-i */

/* ********** SELEKTOR SET ********** */
void SetElArrMap(ArrMap *A, IdxType i, ArrType SB);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen Tmap yang ke-i bernilai SB */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai SB */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArrMap(ArrMap A);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */

/* *** Test tabel penuh *** */
boolean IsFullArrMap(ArrMap A);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

# endif


