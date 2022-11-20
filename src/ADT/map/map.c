# include "map.h"
# include <stdio.h>
#include "../../console.h"

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateScoreBoard(Map *M)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */
{
    (*M).Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySB(Map M)
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */
{
    return M.Count == Nil;
}

boolean IsFullSB(Map M)
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */
{
    return M.Count == MaxEl;
}

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k)
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */
{
    valuetype val;
    val = Undefined;
    int i = 0,loc;
    boolean found = false;
    if(!IsEmptySB(M))
    {
        while(!found && i < M.Count)
        {
            if(M.Elements[i].Key == k)
            {
                found = true;
                loc = i;
            }
            i++;
        }
    }
    if(found)
    {
        val = M.Elements[loc].Value;
    }
    return val;
}

void InsertSB(Map *M, keytype k, valuetype v)
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
{
    if(!IsMemberSB(*M,k))
    {
        (*M).Elements[(*M).Count].Key = k;
        (*M).Elements[(*M).Count].Value = v; 
        (*M).Count++;
    }
    else
    {
        printf("Nama sudah ada, silahkan input nama baru.\n");
    }
}

void DeleteSB(Map *M, keytype k)
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
{
    boolean found = false;
    int i = 0,j,loc;
    while(!found && i < (*M).Count)
    {
        if((*M).Elements[i].Key == k)
        {
            found = true;
            loc = i;
        }
        i++;
    }
    if(found)
    {
        for(j = loc; j < (*M).Count - 1; j++)
        {
            (*M).Elements[j] = (*M).Elements[j+1];
        }
        (*M).Count--;
    }

}

boolean IsMemberSB(Map M, keytype k)
/* Mengembalikan true jika k adalah member dari M */
{
    boolean found = false;
    int i = 0;
    while(!found && i < M.Count)
    {
        if(M.Elements[i].Key == k)
        {
            found = true;
        }
        i++;
    }
    return found;
}

void PrintScoreBoard(Map M)
{
    int maxnamelength = MaxNameLength(M);
    if (maxnamelength == 0)
    {
        printf("| %-10s | %-10s |\n", "NAMA", "SCORE");
        printf("-----SCOREBOARD KOSONG-----\n");
    }
    else
    {
        printf("| NAMA");
        for (int i = 0; i < maxnamelength + 2 ; i++)
        {
            printf(" ");
        }
        printf(" | %-10s |\n", "SCORE");
        for (int i = 0; i < maxnamelength + 23; i++)
        {
            printf("-");
        }
        printf("\n");
        for (int i = 0; i < M.Count; i++)
        {
            printf("| %s", M.Elements[i].Key);
            for (int j = 0; j < maxnamelength - (stringLength(M.Elements[i].Key) - 6); j++)
            {
                printf(" ");
            }
            printf(" | %-10d |\n", M.Elements[i].Value);
        }
    }
}

/* ********** Operator Lain ********* */

int MaxNameLength(Map M)
{
    int i,max = 0;
    for(i = 0; i < M.Count; i++)
    {
        if(stringLength(M.Elements[i].Key) > max)
        {
            max = stringLength(M.Elements[i].Key);
        }
    }
    return max;
}

Map SortSB(Map M)
{
    int i,j;
    infotype temp;
    for(i = 0; i < M.Count; i++)
    {
        for(j = 0; j < M.Count - 1; j++)
        {
            if(M.Elements[j].Value < M.Elements[j+1].Value)
            {
                temp = M.Elements[j];
                M.Elements[j] = M.Elements[j+1];
                M.Elements[j+1] = temp;
            }
        }
    }
    return M;
}