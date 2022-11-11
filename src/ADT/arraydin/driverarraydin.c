# include "arraydin.h"
# include <stdio.h>

int main()
{
    ArrayDin Arr;

    // Alokasi array dinamis
    Arr = MakeArrayDin();

    // Cek apakah array kosong
    if (IsEmpty(Arr))
    {
        printf("Array kosong\n");
    }
    else
    {
        printf("Array tidak kosong\n");
    }

    // Cek panjang dan capacity array
    printf("Length, Capacity: %d, %d\n", Length(Arr),GetCapacity(Arr)); // 0, 10

    // Isi array
    char *temp;
    printf("Masukan string : ");
    scanf("%s", temp);
    InsertLast(&Arr, temp);
    InsertLast(&Arr, "Praktikum");
    InsertLast(&Arr, "Tubes");
    InsertLast(&Arr, "Tucil");
    InsertLast(&Arr, "Tu");
    InsertLast(&Arr, "X");

    // Cek apakah array kosong setelah di isi
    if (IsEmpty(Arr))
    {
        printf("Array kosong\n");
    }
    else
    {
        printf("Array tidak kosong\n");
    }
    printf("Length: %d\n", Length(Arr)); // 6

    // Get elemen dengan index n
    printf("Get: %s\n", Get(Arr, 0)); // stdin
    printf("Get: %s\n", Get(Arr, 1)); // Praktikum

    // Cek Insert elemen
    InsertAt(&Arr, "Tugas", 2);
    printf("Get: %s\n", Get(Arr, 2)); // Tugas
    InsertFirst(&Arr, "Kuliah");
    printf("Get: %s\n", Get(Arr, 0)); // Kuliah

    for (int i = 0; i < 100; i++)
    {
        InsertLast(&Arr, "test");
    }
    
    InsertLast(&Arr, "Milestone");
    printf("Capacity: %d\n", GetCapacity(Arr)); // 160
    printf("Length: %d\n", Length(Arr)); // 109

    PrintArrayDin(Arr); 

    // Cek Delete elemen
    printf("Deleting index 2....\n");
    DeleteAt(&Arr, 2); // Delete Praktikum
    PrintArrayDin(Arr); 

    printf("Get: %s\n", Get(Arr, 2)); // Tugas
    DeleteFirst(&Arr);
    DeleteLast(&Arr);
    PrintArrayDin(Arr); 
    printf("Length: %d\n", Length(Arr)); // 105

    // Reverse array
    printf("Reversing...\n");
    ReverseArrayDin(&Arr);
    PrintArrayDin(Arr); // Print Array

    // Search elemen
    printf("Search Tugas...\nin index : ");
    printf("%d\n",SearchArrayDin(Arr, "Tugas")); // Search Tugas
    printf("Search Tucil...\nin index : ");
    printf("%d\n",SearchArrayDin(Arr, "Tucil")); // Search Tucil
    
    // Dealokasi array
    printf("Deallocating...\n");
    DeallocateArrayDin(&Arr);
    PrintArrayDin(Arr); // Print Array

    return 0;
}