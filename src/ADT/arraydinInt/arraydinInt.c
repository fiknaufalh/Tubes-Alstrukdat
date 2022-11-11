#include <stdio.h>
#include <stdlib.h>
#include "arraydinInt.h"

ArrayDinInt MakeArrayDin_AInt()
{
    ArrayDinInt Arr;
    Arr.A = (int *) malloc (InitialSize * sizeof(int));
    Arr.Capacity = InitialSize;
    Arr.Neff = 0;
    return Arr;
}

void DeallocateArrayDin_AInt(ArrayDinInt *array)
{
    free(array->A);
    array->Neff = 0;
}

boolean IsEmpty_AInt(ArrayDinInt array)
{
    return array.Neff == 0;
}

int Length_AInt(ArrayDinInt array)
{
    return array.Neff;
}

int Get_AInt(ArrayDinInt array, IdxType i)
{
    return array.A[i];
}

int GetCapacity_AInt(ArrayDinInt array)
{
    return array.Capacity;
}

void InsertAt_AInt(ArrayDinInt *array, int el, IdxType i)
{
    if (array->Neff == array->Capacity)
    {
        array->Capacity *= 2;
        array->A = (int *) realloc (array->A, array->Capacity * sizeof(int));
    }
    IdxType temp = array->Neff;
    while (temp > i)
    {
        array->A[temp] = array->A[temp - 1];
        temp--;
    }
    array->A[i] = el;
    array->Neff++;
}

void InsertLast_AInt(ArrayDinInt *array, int el)
{
    InsertAt_AInt(array, el, array->Neff);
}

void InsertFirst_AInt(ArrayDinInt *array, int el)
{
    InsertAt_AInt(array, el, 0);
}

void DeleteAt_AInt(ArrayDinInt *array, IdxType i)
{
    IdxType temp = i;
    while (temp < array->Neff - 1)
    {
        array->A[temp] = array->A[temp + 1];
        temp++;
    }

    if (array->Neff > 1)
    {
        array->Neff--;
    }
    else
    {
        array->Neff = 0;
    }
}

void DeleteLast_AInt(ArrayDinInt *array)
{
    DeleteAt_AInt(array, array->Neff - 1);
}

void DeleteFirst_AInt(ArrayDinInt *array)
{
    DeleteAt_AInt(array, 0);
}

void PrintArrayDin_AInt(ArrayDinInt array)
{
    if (array.Neff == 0)
    {
        printf("[]\n");
    }
    else
    {
        IdxType i;
        printf("[");
        for (i = 0; i < array.Neff - 1; i++)
        {
            printf("%d, ", array.A[i]);
        }
        printf("%d]\n", array.A[array.Neff - 1]);
    }
}

void ReverseArrayDin_AInt(ArrayDinInt *array)
{
    IdxType i = array->Neff - 1;
    IdxType count = 0;
    int temp;
    while (count < i)
    {
        temp = array->A[count];
        array->A[count] = array->A[i];  
        array->A[i] = temp;
        count++;
        i--;
    }
}

ArrayDinInt CopyArrayDin_AInt(ArrayDinInt array)
{
    ArrayDinInt ArrCopy;
    ArrCopy = MakeArrayDin_AInt();
    IdxType i;
    for (i = 0; i < array.Neff; i++)
    {
        InsertLast_AInt(&ArrCopy, array.A[i]);
    }
    return ArrCopy;
}

IdxType SearchArrayDin_AInt(ArrayDinInt array, int el)
{
    IdxType i;
    for (i = 0; i < array.Neff; i++)
    {
        if (array.A[i] == el)
        {
            return i;
        }
    }
    return -1;
}