# include <stdio.h>
# include <stdlib.h>
# include "map.h"

int main()
{
    Map M;
    // Create Map
    CreateScoreBoard(&M);

    // Check if map is empty and is full
    printf("%d\n", IsEmptySB(M));
    printf("%d\n", IsFullSB(M));

    // Print scoreboard
    printf("**** SCOREBOARD GAME TEST****\n");
    PrintScoreBoard(M);

    // Insert Elmt
    printf("Inserting Elmt.....\n");
    InsertSB(&M, "BNMO", 19);
    InsertSB(&M, "Finn", 12);
    InsertSB(&M, "Jake", 58);
    InsertSB(&M, "ABCDEFGHJOFFFFFFjjjjjjjjjjjjjjjjjjjjjj", 40);
    printf("Insert duplicate....\n");
    printf("Test duplicate = ");
    InsertSB(&M, "BNMO", 19);
    printf("\n");
    printf("Test Lower Upper = ");
    InsertSB(&M, "bnMo", 30);

    // Sort map
    printf("Sorting Map.....\n");
    Map sorted = SortSB(M);
    printf("**** SCOREBOARD GAME TEST****\n");
    PrintScoreBoard(sorted);

    // Test insert sorted
    printf("Testing sorted insert...\n");
    InsertSortedDesc(&sorted, "Sun", 100);
    InsertSortedDesc(&sorted, "San", 30);
    InsertSortedDesc(&sorted, "Sin", 50);
    PrintScoreBoard(sorted);
    return 0;
}
