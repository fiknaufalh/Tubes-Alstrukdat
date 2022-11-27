#include "stackInt.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty_SInt(StackInt *S){
    Top(*S) = NilSInt;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElSInt */
/* jadi indeksnya antara 0.. MaxElSInt */
/* Ciri stack kosong : TOP bernilai NilSInt */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty_SInt(StackInt S){
    return Top(S) == NilSInt;
}
/* Mengirim true jika StackInt kosong: lihat definisi di atas */
boolean IsFull_SInt(StackInt S){
    return Top(S) == MaxElSInt -1;
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke StackInt ************ */
void Push_SInt(StackInt * S, int X){
    if (!IsEmpty_SInt(*S)){
        Top(*S) = Top(*S) + 1;
        InfoTop(*S) = X;
    } 
    else{
        Top(*S) = 0;
        InfoTop(*S) = X;
    }    

}
/* Menambahkan X sebagai elemen StackInt S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen StackInt ************ */
void Pop_SInt(StackInt * S, int* X){
    (*X) = InfoTop(*S);
    Top(*S) = Top(*S) - 1;
}
/* Menghapus X dari StackInt S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

int lengthSInt(StackInt S){
    if (!IsEmpty_SInt(S)){
        return Top(S)+1;
    }
    else{
        return 0;
    }
}