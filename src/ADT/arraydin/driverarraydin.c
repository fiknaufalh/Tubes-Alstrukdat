# include "arraydin.h"
# include <stdio.h>

int main()
{
    ArrayDin Arr;
    Arr = MakeArrayDin();

    if (IsEmpty(Arr))
    {
        printf("Array kosong\n");
    }
    else
    {
        printf("Array tidak kosong\n");
    }

    printf("Length: %d\n", Length(Arr)); // 0
    printf("Capacity: %d\n", GetCapacity(Arr)); // 10

    char *temp;
    scanf("%s", temp);
    InsertLast(&Arr, temp);
    InsertLast(&Arr, "Praktikum");
    InsertLast(&Arr, "Tubes");
    InsertLast(&Arr, "Tucil");
    InsertLast(&Arr, "Tu");
    InsertLast(&Arr, "X");

    if (IsEmpty(Arr))
    {
        printf("Array kosong\n");
    }
    else
    {
        printf("Array tidak kosong\n");
    }
    printf("Length: %d\n", Length(Arr)); // 6

    printf("Get: %s\n", Get(Arr, 0)); // stdin
    printf("Get: %s\n", Get(Arr, 1)); // Praktikum

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
    DeleteAt(&Arr, 2); // Delete Praktikum
    PrintArrayDin(Arr); 

    printf("Get: %s\n", Get(Arr, 2)); // Tugas
    DeleteFirst(&Arr);
    DeleteLast(&Arr);
    PrintArrayDin(Arr); 
    printf("Length: %d\n", Length(Arr)); // 105

    ReverseArrayDin(&Arr);
    PrintArrayDin(Arr); // Print Array

    printf("%d\n",SearchArrayDin(Arr, "Tugas")); // Search Tugas
    printf("%d\n",SearchArrayDin(Arr, "Tucil")); // Search Tucil
    
    DeallocateArrayDin(&Arr);
    PrintArrayDin(Arr); // Print Array

    return 0;
}