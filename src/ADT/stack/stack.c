# include <stdio.h>
# include "stack.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai UNDEF */
{
    Top(*S) = UNDEF;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmpty(Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return Top(S) == UNDEF;
}
boolean IsStackFull(Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return Top(S) == MaxStackEl - 1;
}
/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, stackElmt X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    if (IsStackEmpty(*S))
    {
        Top(*S) = 0;
        InfoTop(*S) = X;
    }
    else
    {
        Top(*S) = Top(*S) + 1;
        InfoTop(*S) = X;
    }

}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, stackElmt* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    (*X) = InfoTop(*S);
    Top(*S) = Top(*S) - 1;
}

void ReverseStack(Stack *S)
{
    Stack S1;
    stackElmt X;
    CreateEmptyStack(&S1);
    while (!IsStackEmpty(*S))
    {
        Pop(S, &X);
        Push(&S1, X);
    }
    *S = S1;
}