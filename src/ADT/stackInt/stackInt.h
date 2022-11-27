/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef __STACK_INT_H__
#define __STACK_INT_H__

#include "../../boolean.h"

#define NilSInt -1
#define MaxElSInt 100
/* NilSIn adalah stack dengan elemen kosong . */

typedef int address;   /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
  int T[MaxElSInt]; /* tabel penyimpan elemen */
  address TOP;  /* alamat TOP: elemen puncak */
} StackInt;
/* Definisi stack S kosong : S.TOP = NilSIn */
/* Elemen yang dipakai menyimpan nilai StackInt T[0]..T[MaxElSInt-1] */
/* Jika S adalah StackInt maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty_SInt(StackInt *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElSInt */
/* jadi indeksnya antara 0.. MaxElSInt */
/* Ciri stack kosong : TOP bernilai NilSIn */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty_SInt(StackInt S);
/* Mengirim true jika StackInt kosong: lihat definisi di atas */
boolean IsFull_SInt(StackInt S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke StackInt ************ */
void Push_SInt(StackInt * S, int X);
/* Menambahkan X sebagai elemen StackInt S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen StackInt ************ */
void Pop_SInt(StackInt * S, int* X);
/* Menghapus X dari StackInt S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

int lengthSInt(StackInt S);


#endif