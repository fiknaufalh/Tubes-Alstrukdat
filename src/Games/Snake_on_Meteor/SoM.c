#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SoM.h"

void SoM()
{
    printf("\nSelamat Datang di Snake on Meteor!\n");
    printf("Men-generate peta, snake, dan makanan...\n");
    printf("Berhasil digenerate!\n\n");

    List Snake;
    CreateEmpty(&Snake);

    Point headPos = generateHeadPosition();
    InsVLast(&Snake, 'H', headPos);

    int initNBodyTail = 2;
    addSnakeTail(&Snake, initNBodyTail);

    while (true)
    {
        printf("Berikut merupakan peta permainan\n");
        PrintMap(Snake);
        Move(&Snake);
    }
}

Point generateHeadPosition()
{
    time_t t;
    srand((unsigned)time(&t));

    Point headPos;
    CreatePoint(&headPos, rand() % 5, rand() % 5);
    // CreatePoint(&headPos, 0,1);
    // printf("Posisi head: ");
    // PrintPoint(headPos);
    // printf("\n");
    return headPos;
}

void addSnakeTail(List *Snake, int nExtraTail)
{
    int i = 0;
    while (i < nExtraTail)
    {
        Point zero;
        CreatePoint(&zero,0,0);

        Point extraTail;
        int extraTailX, extraTailY;
        
        if (canAddLeft(*Snake))
        {
            extraTailX = AbsisN(Last(*Snake)) - 1;
            extraTailY = OrdinatN(Last(*Snake));
        }
        else if (canAddAbove(*Snake))
        {
            extraTailX = AbsisN(Last(*Snake));
            extraTailY = OrdinatN(Last(*Snake)) - 1;
        }
        else if (canAddBelow(*Snake))
        {
            extraTailX = AbsisN(Last(*Snake));
            extraTailY = OrdinatN(Last(*Snake)) + 1;
        }
        else if (canAddRight(*Snake))
        {
            extraTailX = AbsisN(Last(*Snake)) + 1;
            extraTailY = OrdinatN(Last(*Snake));
        }
        else
        {
            // Game kalah => implementasi pada kondisi game kalah
            // implementasi di bawah cuma sementara, 
            // ubah sesuai implementasi game kalah aja
            printf("Game Over!\n");
            break;
        }

        CreatePoint(&extraTail, extraTailX, extraTailY);
        InsVLast(Snake, Length(*Snake), extraTail);
        i++;
        // printf("Panjang snake: %d\n", Length(*Snake));
        // PrintPoint(extraTail);
    }
}

boolean canAddLeft (List Snake)
{
    Point Tail = Pos(Last(Snake));

    Point LeftTail;
    CreatePoint(&LeftTail, Tail.X - 1, Tail.Y);
    address checkLeft = SearchPos(Snake, LeftTail);

    return (checkLeft == Nil && Tail.X != minSize);
}

boolean canAddAbove (List Snake)
{
    Point Tail = Pos(Last(Snake));

    Point AboveTail;
    CreatePoint(&AboveTail, Tail.X, Tail.Y - 1);
    address checkAbove = SearchPos(Snake, AboveTail);

    return (checkAbove == Nil && Tail.Y != minSize);
}

boolean canAddBelow (List Snake)
{
    Point Tail = Pos(Last(Snake));

    Point BelowTail;
    CreatePoint(&BelowTail, Tail.X, Tail.Y + 1);
    address checkBelow = SearchPos(Snake, BelowTail);

    return (checkBelow == Nil && Tail.Y != maxSize);
}

boolean canAddRight (List Snake)
{
    Point Tail = Pos(Last(Snake));

    Point RightTail;
    CreatePoint(&RightTail, Tail.X + 1, Tail.Y);
    address checkRight = SearchPos(Snake, RightTail);

    return (checkRight == Nil && Tail.X != maxSize);
}

void PrintMap(List Snake)
{
    int size = maxSize - minSize + 1;
    address P = First(Snake);

    printf("+-----+-----+-----+-----+-----+\n");
    for (int row = 0; row < size; row++)
    {
        printf("|");
        for (int col = 0; col < size; col++)
        {
            Point checkPos;
            CreatePoint(&checkPos,col,row);
            /* checkPos sebagai variabel Point untuk pengecekan
               setiap koordinat pada kotak 5x5 */

            address check = SearchPos(Snake,checkPos);
            /* check adalah hasil pencarian apakah koordinat checkPos
               terdapat pada Snake. Jika ada akan menghasilkan address
               elemen/node yang sama koordinatnya dengan checkPos.
               Jika tidak ada, maka menghasilkan Nil. */

            if (check != Nil)
            {
                if (check == First(Snake)) printf("  H  |");
                else printf("  %d  |", Info(check));
            }
            else printf("     |");
        }
        printf("\n+-----+-----+-----+-----+-----+\n");
    }
}

void Move(List* Snake)
{
    printf("Pilihan gerakan :\n");
    printf("Atas (w) | Kiri (a) | Bawah (s) | Kanan (d) \n");
    printf("Silahkan masukkan command anda: ");
    STARTCOMMAND();
    printf("\n");

    char* cmd = WordToString(currentCMD);

    ADVCOMMAND();
    if (!EndWord){
        printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n\n");
    }
    else
    {
        /* Pergerakan ke Atas */
        if (compareString(cmd,"w") || compareString(cmd,"W"))
        {
            if (!isMoveHitBody(*Snake,cmd))
            {
                address P = Last(*Snake);
                while (P != First(*Snake))
                {
                    Pos(P) = Pos(Prev(P));
                    P = Prev(P);
                }
                OrdinatN(First(*Snake)) = (OrdinatN(First(*Snake)) - 1 + 5) % 5;
            }
            else printf("Anda tidak dapat bergerak ke tubuh anda sendiri!\nSilahkan input command yang lain\n\n");
        }

        /* Pergerakan ke Kiri */
        else if (compareString(cmd,"a") || compareString(cmd,"A"))
        {
            if (!isMoveHitBody(*Snake,cmd))
            {
                address P = Last(*Snake);
                while (P != First(*Snake))
                {
                    Pos(P) = Pos(Prev(P));
                    P = Prev(P);
                }
                AbsisN(First(*Snake)) = (AbsisN(First(*Snake)) - 1 + 5)% 5;
            }
            else printf("Anda tidak dapat bergerak ke tubuh anda sendiri!\nSilahkan input command yang lain\n\n");
        }

        /* Pergerakan ke Bawah */
        else if (compareString(cmd,"s") || compareString(cmd,"S"))
        {
            if (!isMoveHitBody(*Snake,cmd))
            {
                address P = Last(*Snake);
                while (P != First(*Snake))
                {
                    Pos(P) = Pos(Prev(P));
                    P = Prev(P);
                }
                OrdinatN(First(*Snake)) = (OrdinatN(First(*Snake)) + 1) % 5;
            }
            else printf("Anda tidak dapat bergerak ke tubuh anda sendiri!\nSilahkan input command yang lain\n\n");
        }

        /* Pergerakan ke Kanan */
        else if (compareString(cmd,"d") || compareString(cmd,"D"))
        {
            if (!isMoveHitBody(*Snake,cmd))
            {
                address P = Last(*Snake);
                while (P != First(*Snake))
                {
                    Pos(P) = Pos(Prev(P));
                    P = Prev(P);
                }
                AbsisN(First(*Snake)) = (AbsisN(First(*Snake)) + 1) % 5;
            }
            else printf("Anda tidak dapat bergerak ke tubuh anda sendiri!\nSilahkan input command yang lain\n\n");
        }
        else
        {
            printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n\n");
        }
    }
}

boolean isMoveHitBody(List Snake, char* cmd)
{
    Point Head = Pos(First(Snake));
    Point FirstBody = Pos(Next(First(Snake)));

    if (compareString(cmd,"w") || compareString(cmd,"W")) {
        Ordinat(Head)--;
    }
    else if (compareString(cmd,"a") || compareString(cmd,"A")) {
        Absis(Head)--;
    }
    else if (compareString(cmd,"s") || compareString(cmd,"S")) {
        Ordinat(Head)++;
    }
    else if (compareString(cmd,"d") || compareString(cmd,"D")) {
        Absis(Head)++;
    }

    return (EQ(Head, FirstBody));
}

int main(){

    SoM();

    return 0;
}