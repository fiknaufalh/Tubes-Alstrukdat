#include <stdio.h>
#include <stdlib.h>
#include "listdp.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty_LDP (List L)
{
    return (First(L) == NULL && Last(L) == NULL && LengthList(L) == 0);
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty_LDP (List *L)
{
    First(*L) = NULL;
    Last(*L) = NULL;
    LengthList(*L) = 0;
}
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
addressN Alokasi_LDP (idxtype X, Point Pos)
{
    addressN P = (addressN) malloc (sizeof(ElmtList));
    if (P != NULL)
    {
        Info(P) = X;
        Pos(P) = Pos;
        Next(P) = NULL;
        Prev(P) = NULL;
        return P;
    }
    else return NULL;
}
/* Mengirimkan addressN hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressN tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=NULL, Prev(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL. */
void Dealokasi_LDP (addressN P)
{
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressN P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressN Search_LDP (List L, idxtype X)
{
    addressN check = NULL;
    if (!IsEmpty_LDP(L))
    {
        addressN P = First(L);
        while((Info(P) != X) && (Next(P) != NULL)){
            P = Next(P);
        }
        if(Info(P) == X) check = P;
    }
    return check;
}
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan addressN elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */

addressN SearchPos_LDP (List L, Point Pos)
{
    addressN check = NULL;
    if (!IsEmpty_LDP(L))
    {
        addressN P = First(L);
        while((!EQ(Pos(P),Pos)) && (Next(P) != NULL)){
            P = Next(P);
        }
        if(EQ(Pos(P),Pos)) check = P;
    }
    return check;
}
/* Mencari apakah ada elemen list dengan Pos(P) = Pos */
/* Jika ada, mengirimkan addressN elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst_LDP (List *L, idxtype X, Point Pos)
{
    addressN P = Alokasi_LDP(X, Pos);
    if(P != NULL){
        InsertFirst_LDP(L,P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast_LDP (List *L, idxtype X, Point Pos)
{
    addressN P = Alokasi_LDP(X, Pos);
    if(P != NULL){
        InsertLast_LDP(L,P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst_LDP (List *L, idxtype *X)
{
    addressN P;
    DelFirst_LDP(L,&P);
    *X = Info(P);
    Dealokasi_LDP(P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast_LDP (List *L, Point *Pos)
{
    addressN P;
    DelLast_LDP(L,&P);
    // *Pos.X = Info(P).X;
    (*Pos).X = Pos(P).X;
    (*Pos).Y = Pos(P).Y;

    Dealokasi_LDP(P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst_LDP (List *L, addressN P)
{
    if (IsEmpty_LDP(*L)) {
        First(*L) = P;
        Last(*L) = P;
        LengthList(*L)++;
    } else {
        InsertBefore_LDP(L,P,First(*L));
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressN P sebagai elemen pertama */
void InsertLast_LDP (List *L, addressN P)
{
    if (IsEmpty_LDP(*L)) {
        InsertFirst_LDP(L,P);
    }
    else InsertAfter_LDP(L,P,Last(*L));
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter_LDP (List *L, addressN P, addressN Prec)
{
    Prev(P) = Prec;
    Next(P) = Next(Prec);
    Next(Prec) = P;
    if (Next(P) == NULL) Last(*L) = P;
    else Prev(Next(P)) = P;
    LengthList(*L)++;
}
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBefore_LDP (List *L, addressN P, addressN Succ)
{
    Prev(P) = Prev(Succ);
    Next(P) = Succ;
    Prev(Succ) = P;
    if(Prev(P) == NULL) First(*L) = P;
    else Next(Prev(P)) = P;
    LengthList(*L)++;
}
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst_LDP (List *L, addressN *P)
{
    *P = First(*L);
    if(First(*L) == Last(*L)){
        First(*L) = NULL;
        Last(*L) = NULL;
    }
    else{
        First(*L) = Next(First(*L));
        Prev(First(*L)) = NULL;
    }
    Next(*P) = NULL;
    Prev(*P) = NULL;
    LengthList(*L)--;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast_LDP (List *L, addressN *P)
{
    *P = Last(*L);
    if(First(*L) == Last(*L)){
        First(*L) = NULL;
        Last(*L) = NULL;
    }
    else{
        Last(*L) = Prev(Last(*L));
        Next(Last(*L)) = NULL;
    }
    Next(*P) = NULL;
    Prev(*P) = NULL;
    LengthList(*L)--;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelP_LDP (List *L, idxtype X, Point Pos)
{
    addressN search = SearchPos_LDP(*L,Pos);
    if(search != NULL){
        addressN P = First(*L);
        addressN prec = NULL;

        while (P != search){
            prec = P;
            P= Next(P);
        }
        if (prec == NULL){
            DelFirst_LDP(L,&search);
        }
        else {
            DelAfter_LDP(L,&search,prec);
        }
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelAfter_LDP (List *L, addressN *Pdel, addressN Prec)
{
    *Pdel = Next(Prec);
    if(Next(*Pdel) == NULL){
        Next(Prec) = NULL;
        Last(*L) = Prec;
    }
    else{
        Next(Prec) = Next(*Pdel);
        Prev(Next(*Pdel)) = Prec;
        Info(Prec) = Info(*Pdel);
    }
    Prev(*Pdel) = NULL;
    Next(*Pdel) = NULL;
    LengthList(*L)--;

}
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBefore_LDP (List *L, addressN *Pdel, addressN Succ)
{
    *Pdel = Prev(Succ);
    if(Prev(*Pdel) == NULL){
        Prev(Succ) = NULL;
        First(*L) = Succ;
    }
    else{
        Prev(Succ) = Prev(*Pdel);
        Next(Prev(*Pdel)) = Succ;
    }
    Prev(*Pdel) = NULL;
    Next(*Pdel) = NULL;
    LengthList(*L)--;
}
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward_LDP (List L)
{
    if (IsEmpty_LDP(L)) printf("[]");
    else
    {
        printf("[");
        addressN P = First(L);
        while(P != NULL)
        {
            if(P == Last(L)) printf("%d",Info(P));
            else printf("%d,",Info(P));
            P = Next(P);
        }
        printf("]");
    }
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackward_LDP (List L)
{
    if (IsEmpty_LDP(L)) printf("[]");
    else
    {
        printf("[");
        addressN P = Last(L);
        while(P != NULL)
        {
            if(P == First(L)) printf("%d",Info(P));
            else printf("%d,",Info(P));
            P = Prev(P);
        }
        printf("]");
    }
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
