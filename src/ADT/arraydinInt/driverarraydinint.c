# include "arraydinint.h"
# include <stdio.h>

int main()
{
    ArrayDinInt ArrInt;

    // Alokasi array dinamis
    ArrInt = MakeArrayDin_AInt();

    // Cek apakah array kosong
    if (IsEmpty_AInt(ArrInt))
    {
        printf("Array kosong\n");
    }
    else
    {
        printf("Array tidak kosong\n");
    }

    // Cek panjang dan capacity array
    printf("Panjang array: %d\n", Length_AInt(ArrInt));
    printf("Capacity : %d\n", GetCapacity_AInt(ArrInt));

    // Isi array
    printf("Inserting...\n");
    for (int i = 0; i < 15; i++)
    {
        InsertLast_AInt(&ArrInt, 1+i);
    }

    // Cek panjang dan capacity array
    printf("Panjang array: %d\n", Length_AInt(ArrInt));
    printf("Capacity : %d\n", GetCapacity_AInt(ArrInt));

    printf("Isi array: ");
    PrintArrayDin_AInt(ArrInt);

    // Get elemen array dengan index n
    printf("Array index ke %d: %d\n", 5, Get_AInt(ArrInt, 5));
    printf("Array index ke %d: %d\n", 10, Get_AInt(ArrInt, 10));

    // Check insert elemen array
    InsertFirst_AInt(&ArrInt, 100);
    InsertAt_AInt(&ArrInt, 200, 5);
    printf("Array index ke %d: %d\n", 5, Get_AInt(ArrInt, 5));
    printf("Isi array: ");
    PrintArrayDin_AInt(ArrInt);

    // Check delete elemen array
    printf("Deleting index 5...\n");
    DeleteAt_AInt(&ArrInt, 5);
    printf("Isi array: ");
    PrintArrayDin_AInt(ArrInt);

    printf("Deleting last...\n");
    DeleteLast_AInt(&ArrInt);
    printf("Deleting first...\n");
    DeleteFirst_AInt(&ArrInt);
    printf("Isi array: ");
    PrintArrayDin_AInt(ArrInt);

    // Reverse array
    ReverseArrayDin_AInt(&ArrInt);
    printf("Isi array: ");
    PrintArrayDin_AInt(ArrInt);

    // Searching array
    printf("Searching 5...\nin idx: %d\n", SearchArrayDin_AInt(ArrInt, 5));
    printf("Searching 10...\nin idx: %d\n", SearchArrayDin_AInt(ArrInt, 10));
    printf("Searching 99...\nin idx: %d\n", SearchArrayDin_AInt(ArrInt, 99));

    // Copy array
    ArrayDinInt CopyDinInt = CopyArrayDin_AInt(ArrInt);
    printf("Isi array awal: ");
    PrintArrayDin_AInt(ArrInt);
    printf("Isi array copy: ");
    PrintArrayDin_AInt(CopyDinInt);

    // Dealokasi array
    printf("Dealokasi array awal...\n");
    DeallocateArrayDin_AInt(&ArrInt);
    PrintArrayDin_AInt(ArrInt);


    return 0;
}