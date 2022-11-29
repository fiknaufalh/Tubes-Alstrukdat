# include "arrmap.h"
# include <stdio.h>

// gcc driverarrmap.c arrmap.c ../map/map.c ../mesinkata/mesinkata.c ../mesinkarakter/mesinkarakter.c  -o aom
int main()
{
    ArrMap Arr;
    Map A,B,C,D;

    // Create empty array of map
    printf("Create array of map.....\n");
    CreateScoreBoard(&A);
    CreateScoreBoard(&B);
    CreateScoreBoard(&C);
    CreateScoreBoard(&D);
    MakeEmptyArrMap(&Arr);
    InsertSB(&A,"TES1",50);
    InsertSB(&A,"TES2",60);
    InsertSB(&A,"TES3",70);
    InsertSB(&A,"TES4",80);
    InsertSB(&A,"TES5",90);

    printf("NbElmt = %d\n",NbElmtArrMap(Arr));
    printf("MaxNbElmt = %d\n",MaxNbElArrMap(Arr));
    printf("Is Empty arrmap = %d\n",IsEmptyArrMap(Arr));
    printf("Is Full arrmap = %d\n",IsFullArrMap(Arr));
    printf("First idx = %d\n",GetFirstIdxArrMap(Arr));
    printf("Last idx = %d\n",GetLastIdxArrMap(Arr));

    // Set Arr Map Elmt
    printf("Set Elmt.....\n");
    SetElArrMap(&Arr, 0, A);
    SetElArrMap(&Arr, 1, B);
    SetElArrMap(&Arr, 2, C);
    SetElArrMap(&Arr, 3, D);
    printf("NbElmt = %d\n",NbElmtArrMap(Arr));
    printf("Is Empty arrmap = %d\n",IsEmptyArrMap(Arr));
    printf("Is Full arrmap = %d\n",IsFullArrMap(Arr));
    printf("First idx = %d\n",GetFirstIdxArrMap(Arr));
    printf("Last idx = %d\n",GetLastIdxArrMap(Arr));


    // Get Elmt
    printf("Get Elmt......\n");
    Map elmt = GetElmtArrMap(Arr,0);
    PrintScoreBoard(elmt);

    return 0;
}