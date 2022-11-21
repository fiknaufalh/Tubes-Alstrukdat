# include <stdio.h>
# include <stdlib.h>
# include "map.h"

int main()
{
    Map M;
    CreateScoreBoard(&M);
    printf("%d\n", IsEmptySB(M));
    printf("%d\n", IsFullSB(M));
    printf("**** SCOREBOARD GAME TEST****\n");
    PrintScoreBoard(M);
    InsertSB(&M, "BNMO", 19);
    InsertSB(&M, "Finn", 12);
    InsertSB(&M, "Jake", 58);
    InsertSB(&M, "ABCDEFGHJOFFFFFFjjjjjjjjjjjjjjjjjjjjjj", 40);
    InsertSB(&M, "BNMO", 19);

    Map sorted = SortSB(M);
    printf("**** SCOREBOARD GAME TEST****\n");
    PrintScoreBoard(sorted);

    InsertSortedDesc(&sorted, "Sun", 100);
    InsertSortedDesc(&sorted, "San", 30);
    InsertSortedDesc(&sorted, "Sin", 50);
    PrintScoreBoard(sorted);
    return 0;
}
