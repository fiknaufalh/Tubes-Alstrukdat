/* File : arraydin.h */
/* Definisi ADT Array secara eksplisit dan alokasi dinamis */

#ifndef __ARRAY_INT_DINAMIK__
#define __ARRAY_INT_DINAMIK__

// Boolean
#define boolean unsigned char
#define true 1
#define false 0

#define InitialSize 10

typedef int IdxType;
typedef struct {
    int *A;
    int Capacity;
    int Neff;
} ArrayDinInt;

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDinInt kosong dengan ukuran InitialSize
 */
ArrayDinInt MakeArrayDin_AInt();

/**
 * Destruktor
 * I.S. ArrayDinInt terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin_AInt(ArrayDinInt *array);

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty_AInt(ArrayDinInt array);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length_AInt(ArrayDinInt array);

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
int Get_AInt(ArrayDinInt array, IdxType i);

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity_AInt(ArrayDinInt array);

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt_AInt(ArrayDinInt *array, int el, IdxType i);

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLast_AInt(ArrayDinInt *array, int el);

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirst_AInt(ArrayDinInt *array, int el);

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDinInt
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt_AInt(ArrayDinInt *array, IdxType i);

/**
 * Fungsi untuk menghapus elemen terakhir ArrayDinInt
 * Prekondisi: array tidak kosong
 */
void DeleteLast_AInt(ArrayDinInt *array);

/**
 * Fungsi untuk menghapus elemen pertama ArrayDinInt
 * Prekondisi: array tidak kosong
 */
void DeleteFirst_AInt(ArrayDinInt *array);

/**
 * Fungsi untuk melakukan print suatu ArrayDinInt.
 * Prekondisi: array terdefinisi
 */
void PrintArrayDin_AInt(ArrayDinInt array);

/**
 * Fungsi untuk melakukan reverse suatu ArrayDinInt.
 * Prekondisi: array terdefinisi
 */
void ReverseArrayDin_AInt(ArrayDinInt *array);

/**
 * Fungsi untuk melakukan copy suatu ArrayDinInt.
 * Prekondisi: array terdefinisi
 */
ArrayDinInt CopyArrayDin_AInt(ArrayDinInt array);

/**
 * Fungsi untuk melakukan search suatu ArrayDinInt.
 * Prekondisi: array terdefinisi
 */
IdxType SearchArrayDin_AInt(ArrayDinInt array, int el);

#endif