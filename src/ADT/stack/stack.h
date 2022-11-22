/* File : stack.h */

#ifndef stackt_H
#define stackt_H

#include "../../boolean.h"

#define UNDEF -1
#define MaxStackEl 100

typedef char* stackElmt;
typedef int address;   


typedef struct { 
  stackElmt T[MaxStackEl]; 
  address TOP;  
} Stack;


/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */

/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxStackEl */
/* jadi indeksnya antara 0.. MaxStackEl */
/* Ciri stack kosong : TOP bernilai UNDEF */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmpty(Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */

boolean IsStackFull(Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, stackElmt X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, stackElmt* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */


void ReverseStack(Stack *S);

#endif