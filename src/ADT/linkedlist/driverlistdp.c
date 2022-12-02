# include <stdio.h>
# include "listdp.h"

int main()
{
    List L,L2;

    // Create List DP
    CreateEmpty_LDP(&L);
    CreateEmpty_LDP(&L2);

    // Check if list is empty
    printf("Is empty : %d\n",IsEmpty_LDP(L));

    // Test Alokasi
    printf("Alokasi P...\n");
    addressN P;
    Point p1,p2,p3;
    CreatePoint(&p1, 10, 11);
    CreatePoint(&p2, 20, 5);
    CreatePoint(&p3, 5, 7);

    P = Alokasi_LDP(15, p1);

    if (P != NULL)
    {
        printf("Alokasi berhasil\n");
    }
    else
    {
        printf("Alokasi gagal\n");
    }

    // Test Insert
    printf("\nInserting.....\n");
    InsVFirst_LDP(&L, 5, p2);
    InsVLast_LDP(&L, 20, p3);
    InsVLast_LDP(&L, 30, p3);
    InsVLast_LDP(&L, 40, p3);
    InsVLast_LDP(&L, 50, p3);
    InsVLast_LDP(&L, 60, p3);
    InsVLast_LDP(&L, 70, p3);
    printf("First = %d\n",Info(First(L)));
    printf("Next(First) = %d\n",Info(Next(First(L))));
    printf("Prev(Last) = %d\n",Info(Prev(Last(L))));
    printf("Last = %d\n",Info(Last(L)));
    
    PrintForward_LDP(L);
    printf("\n");
    PrintBackward_LDP(L);

    Point temp;
    idxtype temp2;

    // Test Delete
    printf("\n\nDeleting.....\n");
    DelVFirst_LDP(&L,&temp2);
    printf("\nidxtype deleted = %d\n",temp2);
    DelVLast_LDP(&L,&temp);
    printf("Point deleted = ");
    PrintPoint(temp);
    printf("First = %d\n",Info(First(L)));
    printf("Next(First) = %d\n",Info(Next(First(L))));
    printf("Prev(Last) = %d\n",Info(Prev(Last(L))));
    printf("Last = %d\n",Info(Last(L)));

    PrintForward_LDP(L);
    printf("\n");
    PrintBackward_LDP(L);

    // Test Search
    addressN X = Search_LDP(L,40);
    if (X != NULL)
    {
        printf("\nInfo address = %d\n",Info(X));
    }
    else
    {
        printf("Tidak ditemukan address dengan idxtype yang dicari.\n");
    }
    
    X = Search_LDP(L, 90);
    if (X != NULL)
    {
        printf("\nInfo address = %d\n",Info(X));
    }
    else
    {
        printf("Tidak ditemukan address dengan idxtype yang dicari.\n");
    }

    X = SearchPos_LDP(L, p1);
    if (X != NULL)
    {
        printf("\nInfo address = ");
        PrintPoint(Pos(X));
    }
    else
    {
        printf("Tidak ditemukan address dengan point yang dicari.\n");
    }

    X = SearchPos_LDP(L, p3);
    if (X != NULL)
    {
        printf("Info address = ");
        PrintPoint(Pos(X));
    }
    else
    {
        printf("Tidak ditemukan address dengan point yang dicari.\n");
    }

    return 0;
}