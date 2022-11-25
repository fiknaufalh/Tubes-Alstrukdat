#include "stackInt.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty_SInt(StackInt *S){
    Top(*S) = Nil;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty_SInt(StackInt S){
    return Top(S) == Nil;
}
/* Mengirim true jika StackInt kosong: lihat definisi di atas */
boolean IsFull_SInt(StackInt S){
    return Top(S) == MaxEl -1;
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke StackInt ************ */
void Push_SInt(StackInt * S, infotype X){
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
void Pop_SInt(StackInt * S, infotype* X){
    (*X) = InfoTop(*S);
    Top(*S) = Top(*S) - 1;
}
/* Menghapus X dari StackInt S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */