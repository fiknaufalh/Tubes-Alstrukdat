#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SoM.h"

int SoM()
{
    printf("\nSelamat Datang di Snake on Meteor!\n");
    printf("Men-generate peta, snake, dan makanan...\n");
    printf("Berhasil digenerate!\n\n");

    int turn = 1;
    boolean gameOver = false;

    List Snake;
    List Food;
    List Meteor;
    List Obstacle;
    CreateEmpty_LDP(&Snake);
    CreateEmpty_LDP(&Food);
    CreateEmpty_LDP (&Meteor);
    CreateEmpty_LDP (&Obstacle);

    Point headPos = generateHeadPosition();
    InsVLast_LDP(&Snake, 'H', headPos);

    int initNBodyTail = 2;
    addSnakeTail(&Snake, initNBodyTail);

    Point foodposition;
    foodposition = generateFood(Snake,Meteor,Obstacle);
    InsVLast_LDP(&Food,'o',foodposition);

    Point meteorposition;

    Point obstacleposition;
    obstacleposition = generateObstacle(Snake,Food);
    InsVLast_LDP(&Obstacle,'x',obstacleposition);

    while (!gameOver)
    {
        printf("Berikut merupakan peta permainan\n");
        PrintMap(Snake,Food,Meteor,Obstacle);

        boolean canMove = false;
        while (!canMove)
        {
            printf("TURN %d\n",turn);
            printf("Pilihan gerakan :\n");
            printf("Atas (w) | Kiri (a) | Bawah (s) | Kanan (d) \n\n");
            printf("Silahkan masukkan command anda: ");
            
            ResetCMD(&currentCMD);
            STARTCOMMAND();  
            char* cmd = WordToString(currentCMD);
            ADVCOMMAND();

            while (!isCmdMoveValid(cmd) || !EndWord)
            {
                printf("Command tidak valid!\nSilahkan input command menggunakan huruf w/a/s/d.\n\n");
                PrintMap(Snake,Food,Meteor,Obstacle);
                printf("TURN %d\n",turn);
                printf("Pilihan gerakan :\n");
                printf("Atas (w) | Kiri (a) | Bawah (s) | Kanan (d) \n\n");
                printf("Silahkan masukkan command anda: ");
                STARTCOMMAND(); 
                cmd = WordToString(currentCMD);
                ADVCOMMAND();
            }

            /* Kondisi Deadlock Ketika Snack Tidak Dapat Bergerak ke Manapun */
            if (isDeadLock(Snake,Meteor,Obstacle))
            {
                printf("Snake tidak dapat bergerak ke manapun. Game over!\n\n");
                gameOver = true;
                canMove = false;
            } 
            else canMove = Move(&Snake, Meteor, cmd, turn);
            if (!canMove) PrintMap(Snake,Food,Meteor,Obstacle);
        }
        turn++;

        if (gameOver) break;

        if (turn > 1){
            if (foodEaten(Snake,&Food)){
                /* Kondisi Ketika Tail Tidak Dapat Bertambah ke Manapun */
                if (!canAddAbove(Snake) && !canAddBelow(Snake) && !canAddLeft(Snake) && !canAddRight(Snake)){
                    printf("Tail tidak dapat bertambah. Game over!\n\n");
                    gameOver = true;
                } else addSnakeTail(&Snake,1);
                CreateEmpty_LDP(&Food);
                foodposition = generateFood(Snake,Meteor,Obstacle);
                InsVLast_LDP(&Food,'o',foodposition);   
            }
            CreateEmpty_LDP(&Meteor);
            meteorposition = generateMeteor(Snake,Food,Obstacle);
            InsVLast_LDP(&Meteor,'m',meteorposition);

            /* Kondisi Head Terkena Meteor yang Baru Spawned */
            if (EQ( Pos(First(Snake)), Pos(First(Meteor)) )){
                idxtype x;
                printf("Kepala terkena meteor. Game over!\n\n");
                PrintMap(Snake,Food,Meteor,Obstacle);
                DelP_LDP(&Snake,x,meteorposition);
                gameOver = true;
            }
            /* Kondisi Head Terkena Obstacle */
            else if (EQ( Pos(First(Snake)), Pos(First(Obstacle)) )){
                idxtype x;
                printf("Kepala terkena obstacle. Game over!\n\n");
                PrintMap(Snake,Food,Meteor,Obstacle);
                DelP_LDP(&Snake,x,obstacleposition);
                gameOver = true;
            }
            else if (SearchPos_LDP(Snake,meteorposition)){
                idxtype x;
                printf("Anda terkena meteor.\n\n");
                DelP_LDP(&Snake,x,meteorposition);
                RefreshInfo(&Snake);
            }
            else {
                printf("Anda beruntung tidak terkena meteor!\n\n");
            }
        }
    }
    return skorAkhir(Snake);
}

boolean isCmdMoveValid (char* cmd)
{
    boolean lowerCase = (compareString(cmd,"w") || compareString(cmd,"a") || compareString(cmd,"s") || compareString(cmd,"d"));
    boolean upperCase = (compareString(cmd,"W") || compareString(cmd,"A") || compareString(cmd,"S") || compareString(cmd,"D"));
    return (lowerCase || upperCase);
}

Point generateHeadPosition()
{
    time_t t;
    srand((unsigned)time(&t));

    Point headPos;
    CreatePoint(&headPos, rand() % 5, rand() % 5);
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

        CreatePoint(&extraTail, extraTailX, extraTailY);
        InsVLast_LDP(Snake, LengthList(*Snake), extraTail);
        i++;
    }
}

boolean canAddLeft (List Snake)
{
    Point Tail = Pos(Last(Snake));

    Point LeftTail;
    CreatePoint(&LeftTail, Tail.X - 1, Tail.Y);
    addressN checkLeft = SearchPos_LDP(Snake, LeftTail);

    return (checkLeft == NULL && Tail.X != minSize);
}

boolean canAddAbove (List Snake)
{
    Point Tail = Pos(Last(Snake));

    Point AboveTail;
    CreatePoint(&AboveTail, Tail.X, Tail.Y - 1);
    addressN checkAbove = SearchPos_LDP(Snake, AboveTail);

    return (checkAbove == NULL && Tail.Y != minSize);
}

boolean canAddBelow (List Snake)
{
    Point Tail = Pos(Last(Snake));

    Point BelowTail;
    CreatePoint(&BelowTail, Tail.X, Tail.Y + 1);
    addressN checkBelow = SearchPos_LDP(Snake, BelowTail);

    return (checkBelow == NULL && Tail.Y != maxSize);
}

boolean canAddRight (List Snake)
{
    Point Tail = Pos(Last(Snake));

    Point RightTail;
    CreatePoint(&RightTail, Tail.X + 1, Tail.Y);
    addressN checkRight = SearchPos_LDP(Snake, RightTail);

    return (checkRight == NULL && Tail.X != maxSize);
}

void PrintMap(List Snake, List Food, List Meteor, List Obstacle)
{
    int size = maxSize - minSize + 1;
    addressN P = First(Snake);
    Point meteor;

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

            addressN check = SearchPos_LDP(Snake,checkPos);
            /*  check adalah hasil pencarian apakah koordinat checkPos
                terdapat pada Snake. Jika ada akan menghasilkan addressN
                elemen/node yang sama koordinatnya dengan checkPos.
                Jika tidak ada, maka menghasilkan NULL. */

            addressN checkFood = SearchPos_LDP(Food,checkPos);
            /*  checkFood adalah hasil pencarian apakah koordinat checkPos terdapat 
                Food. Jika ada menghasilkan address elemen/node yang sama koordinatnya dengan checkPos.
                Jika tidak ada, menghasilkan Nil.
            */

            addressN checkMeteor = SearchPos_LDP(Meteor,checkPos);
            /*  checkMeteor adalah hasil pencarian apakah koordinat checkPos terdapat
                pada Meteor. Jika ada, menghasilkan address elemen/node yang sama koordinatnya dengan
                checkpos. Jika tidak ada, menghasilkan Nil.
            */

            addressN checkObstacle = SearchPos_LDP(Obstacle,checkPos);
            /*  checkObstacle adalah hasil pencarian apakah koordinat checkPos terdapat
                pada Obstacle. Jika ada, menghasilkan address elemen/node yang sama koordinatnya dengan
                checkpos. Jika tidak ada, menghasilkan Nil.
            */

            if (checkMeteor != NULL){
                if (checkMeteor == First(Meteor)){
                    printf("  m  |");
                }
            }
            else if (checkObstacle != NULL){
                if (checkObstacle == First(Obstacle)){
                    printf("  x  |");
                }
            }
            else if (check != NULL)
            {
                if (check == First(Snake)) printf("  H  |");
                else printf("  %d  |", Info(check));
            }
            else if (checkFood != NULL){
                if (checkFood == First(Food)){
                    printf("  o  |");
                }
            }

            else printf("     |");
        }
        printf("\n+-----+-----+-----+-----+-----+\n");
    }
}

boolean Move(List* Snake, List Meteor, char* cmd, int turn)
{
    /* Pergerakan ke Atas */
    if (compareString(cmd,"w") || compareString(cmd,"W"))
    {
        if (!isMoveHitBody(*Snake,cmd))
        {
            if (turn > 1)
            {
                if (!isMoveHitMeteor(*Snake,Meteor,cmd))
                {
                    addressN P = Last(*Snake);
                    while (P != First(*Snake))
                    {
                        Pos(P) = Pos(Prev(P));
                        P = Prev(P);
                    }
                    OrdinatN(First(*Snake)) = (OrdinatN(First(*Snake)) - 1 + 5) % 5;
                    return true;
                }
                else {
                    printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut\n");
                    printf("Silahkan input command yang lain\n\n");
                    return false;
                }
            }
            else {
                addressN P = Last(*Snake);
                while (P != First(*Snake))
                {
                    Pos(P) = Pos(Prev(P));
                    P = Prev(P);
                }
                OrdinatN(First(*Snake)) = (OrdinatN(First(*Snake)) - 1 + 5) % 5;
                return true;
            }
        }
        else {
            printf("Anda tidak dapat bergerak ke tubuh anda sendiri!\nSilahkan input command yang lain\n\n");
            return false;
        }
    }

    /* Pergerakan ke Kiri */
    else if (compareString(cmd,"a") || compareString(cmd,"A"))
    {
        if (!isMoveHitBody(*Snake,cmd))
        {
            if (turn > 1)
            {
                if (!isMoveHitMeteor(*Snake,Meteor,cmd))
                {
                    addressN P = Last(*Snake);
                    while (P != First(*Snake))
                    {
                        Pos(P) = Pos(Prev(P));
                        P = Prev(P);
                    }
                    AbsisN(First(*Snake)) = (AbsisN(First(*Snake)) - 1 + 5)% 5;
                    return true;
                }
                else {
                    printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut\n");
                    printf("Silahkan input command yang lain\n\n");
                    return false;
                }
            }
            else {
                addressN P = Last(*Snake);
                while (P != First(*Snake))
                {
                    Pos(P) = Pos(Prev(P));
                    P = Prev(P);
                }
                AbsisN(First(*Snake)) = (AbsisN(First(*Snake)) - 1 + 5)% 5;
                return true;
            }
        }
        else {
            printf("Anda tidak dapat bergerak ke tubuh anda sendiri!\nSilahkan input command yang lain\n\n");
            return false;
        }
    }

    /* Pergerakan ke Bawah */
    else if (compareString(cmd,"s") || compareString(cmd,"S"))
    {
        if (!isMoveHitBody(*Snake,cmd))
        {
            if (turn > 1)
            {
                if (!isMoveHitMeteor(*Snake,Meteor,cmd))
                {
                    addressN P = Last(*Snake);
                    while (P != First(*Snake))
                    {
                        Pos(P) = Pos(Prev(P));
                        P = Prev(P);
                    }
                    OrdinatN(First(*Snake)) = (OrdinatN(First(*Snake)) + 1) % 5;
                    return true;
                }
                else {
                    printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut\n");
                    printf("Silahkan input command yang lain\n\n");
                    return false;
                }
            }
            else {
                addressN P = Last(*Snake);
                while (P != First(*Snake))
                {
                    Pos(P) = Pos(Prev(P));
                    P = Prev(P);
                }
                OrdinatN(First(*Snake)) = (OrdinatN(First(*Snake)) + 1) % 5;
                return true;
            }
        }
        else {
            printf("Anda tidak dapat bergerak ke tubuh anda sendiri!\nSilahkan input command yang lain\n\n");
            return false;
        }
    }

    /* Pergerakan ke Kanan */
    else if (compareString(cmd,"d") || compareString(cmd,"D"))
    {
        if (!isMoveHitBody(*Snake,cmd))
        {
            if (turn > 1)
            {
                if (!isMoveHitMeteor(*Snake,Meteor,cmd))
                {
                    addressN P = Last(*Snake);
                    while (P != First(*Snake))
                    {
                        Pos(P) = Pos(Prev(P));
                        P = Prev(P);
                    }
                    AbsisN(First(*Snake)) = (AbsisN(First(*Snake)) + 1) % 5;
                    return true;
                }
                else {
                    printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut\n");
                    printf("Silahkan input command yang lain\n\n");
                    return false;
                }
            }
            else {
                addressN P = Last(*Snake);
                while (P != First(*Snake))
                {
                    Pos(P) = Pos(Prev(P));
                    P = Prev(P);
                }
                AbsisN(First(*Snake)) = (AbsisN(First(*Snake)) + 1) % 5;
                return true;
            }
        }
        else {
            printf("Anda tidak dapat bergerak ke tubuh anda sendiri!\nSilahkan input command yang lain\n\n");
            return false;
        }
    }
}

boolean isDeadLock(List Snake, List Meteor, List Obstacle)
{
    Point Head = Pos(First(Snake));

    Point AboveHead;
    CreatePoint(&AboveHead,Head.X,Head.Y - 1);
    boolean checkAboveSnack = (SearchPos_LDP(Snake,AboveHead) != NULL);
    boolean checkAboveMeteor = (SearchPos_LDP(Meteor,AboveHead) != NULL);
    boolean checkAboveObstacle = (SearchPos_LDP(Obstacle,AboveHead) != NULL);
    boolean checkAbove = (checkAboveSnack || checkAboveMeteor || checkAboveObstacle);

    Point BelowHead;
    CreatePoint(&BelowHead,Head.X,Head.Y + 1);
    boolean checkBelowSnack = (SearchPos_LDP(Snake,BelowHead) != NULL);
    boolean checkBelowMeteor = (SearchPos_LDP(Meteor,BelowHead) != NULL);
    boolean checkBelowObstacle = (SearchPos_LDP(Obstacle,BelowHead) != NULL);
    boolean checkBelow = (checkBelowSnack || checkBelowMeteor || checkBelowObstacle);

    Point LeftHead;
    CreatePoint(&LeftHead,Head.X - 1,Head.Y);
    boolean checkLeftSnack = (SearchPos_LDP(Snake,LeftHead) != NULL);
    boolean checkLeftMeteor = (SearchPos_LDP(Meteor,LeftHead) != NULL);
    boolean checkLeftObstacle = (SearchPos_LDP(Obstacle,LeftHead) != NULL);
    boolean checkLeft = (checkLeftSnack || checkLeftMeteor || checkLeftObstacle);
    
    Point RightHead;
    CreatePoint(&RightHead,Head.X + 1,Head.Y);
    boolean checkRightSnack = (SearchPos_LDP(Snake,RightHead) != NULL);
    boolean checkRightMeteor = (SearchPos_LDP(Snake,RightHead) != NULL);
    boolean checkRightObstacle = (SearchPos_LDP(Snake,RightHead) != NULL);
    boolean checkRight = (checkRightSnack || checkRightMeteor || checkRightObstacle);

    return (checkAbove && checkBelow && checkLeft && checkRight);
}

boolean isMoveHitBody(List Snake, char* cmd)
{
    Point Head = Pos(First(Snake));

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

    return (SearchPos_LDP(Snake,Head) != NULL);
}

boolean isMoveHitMeteor(List Snake, List Meteor, char* cmd)
{
    Point Head = Pos(First(Snake));
    
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
    
    return (EQ(Head, Pos(First(Meteor))));
}

Point generateFood(List Snake, List Meteor, List Obstacle){
    srand(time(0));
    Point food;
    CreatePoint(&food, rand() % 5, rand() % 5);

    while ((SearchPos_LDP(Snake,food) != NULL) || (SearchPos_LDP(Meteor,food) != NULL) || (SearchPos_LDP(Obstacle,food) != NULL)){
        CreatePoint(&food, rand() % 5, rand() % 5);
    }
    
    return food;
}

boolean foodEaten(List Snake, List *Food){
    return (EQ(Pos(First(*Food)),Pos(First(Snake))));
}

Point generateMeteor(List Snake,List Food,List Obstacle){
    srand(time(0));
    Point meteor;
    CreatePoint(&meteor,rand() % 5, rand() % 5);
    while (SearchPos_LDP(Food,meteor) != NULL || SearchPos_LDP(Obstacle,meteor) != NULL){
        CreatePoint(&meteor,rand() % 5, rand() % 5);
    }
    return meteor;
}

Point generateObstacle(List Snake,List Food){
    srand(time(0));
    Point obstacle;
    CreatePoint(&obstacle,rand() % 5, rand() % 5);
    while (SearchPos_LDP(Food,obstacle) != NULL || SearchPos_LDP(Snake,obstacle) != NULL){
        CreatePoint(&obstacle,rand() % 5, rand() % 5);
    }
    return obstacle;
}

boolean isMeteorHitSnake(List Snake, Point meteor){
    addressN checkHit = SearchPos_LDP(Snake,meteor);
    return (checkHit != NULL);
}

void RefreshInfo(List* Snake)
{
    int i = 1;
    addressN P = Next(First(*Snake));
    while (P != NULL)
    {
        Info(P) = i;
        i++;
        P = Next(P);
    }
}

int skorAkhir (List Snake){
    int skor;
    skor = (LengthList(Snake)) * 2;
    printf("Skor : %d", skor);
    printf("\n");
    return skor;
}