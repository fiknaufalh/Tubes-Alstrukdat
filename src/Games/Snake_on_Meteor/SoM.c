#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SoM.h"

void SoM()
{
    printf("\nSelamat Datang di Snake on Meteor!\n");
    printf("Men-generate peta, snake, dan makanan...\n");
    printf("Berhasil digenerate!\n\n");

    int turn = 1;
    boolean gameOver = false;
    int beforegothit = 0;
    Point hitmeteor;

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
    foodposition = generateFood(Snake);
    InsVLast_LDP(&Food,'o',foodposition);

    Point meteorposition;
    // meteorposition = generateMeteor(Snake,Food);
    // InsVLast(&Meteor,'m',meteorposition);

    Point obstacleposition;
    obstacleposition = generateObstacle(Snake,Food);
    InsVLast_LDP(&Obstacle,'x',obstacleposition);

    while (!gameOver)
    {
        printf("Berikut merupakan peta permainan\n");
        if (foodEaten(Snake,&Food)){
            addSnakeTail(&Snake,1);
            CreateEmpty_LDP(&Food);
            foodposition = generateFood(Snake);
            InsVLast_LDP(&Food,'o',foodposition);   
        }
        PrintMap(Snake, Food, Meteor, Obstacle);
        Move(&Snake);
        turn += 1;
        if (turn > 1){
            if (foodEaten(Snake,&Food)){
                addSnakeTail(&Snake,1);
                CreateEmpty_LDP(&Food);
                foodposition = generateFood(Snake);
                InsVLast_LDP(&Food,'o',foodposition);   
            }
            CreateEmpty_LDP(&Meteor);
            meteorposition = generateMeteor(Snake,Food,Obstacle);
            InsVLast_LDP(&Meteor,'m',meteorposition);


            if (((AbsisN(First(Snake))) == (AbsisN(First(Meteor))) && (OrdinatN(First(Snake))) == (OrdinatN(First(Meteor))))){
                idxtype x;
                printf("Kepala terkena meteor. Game over\n");
                PrintMap(Snake,Food,Meteor,Obstacle);
                DelP_LDP(&Snake,x,meteorposition);
                skorakhir(Snake);
                gameOver = true;
            }
            else if (((AbsisN(First(Snake))) == (AbsisN(First(Obstacle))) && (OrdinatN(First(Snake))) == (OrdinatN(First(Obstacle))))){
                idxtype x;
                printf("Kepala terkena obstacle. Game over\n");
                PrintMap(Snake,Food,Meteor,Obstacle);
                DelP_LDP(&Snake,x,obstacleposition);
                skorakhir(Snake);
                gameOver = true;
            }
            else if (beforegothit == 999){
                if (AbsisN(First(Snake)) == Absis(hitmeteor) && OrdinatN(First(Snake)) == Ordinat(hitmeteor)){
                    printf("Meteor masih panas.\n");
                    beforegothit = 0;
                }
            }

            else if (SearchPos_LDP(Snake,meteorposition)){
                idxtype x;
                Absis(hitmeteor) = Absis(meteorposition);
                Ordinat(hitmeteor) = Ordinat(meteorposition);
                printf("Anda terkena meteor.\n");
                DelP_LDP(&Snake,x,meteorposition);
                beforegothit = 999; 

            }


            else {
                printf("Anda beruntung tidak terkena meteor!\n");
            }
            
            // else {
            //     if (AbsisN(First(Snake)) == Absis(hitmeteor) && OrdinatN(First(Snake)) == Ordinat(hitmeteor)){
            //         printf("Meteor masih panas.\n");
            //         beforegothit = 0;
            //     }
            // }           
        
        }
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
        InsVLast_LDP(Snake, LengthList(*Snake), extraTail);
        i++;
        // printf("Panjang snake: %d\n", LengthList(*Snake));
        // PrintPoint(extraTail);
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
            /* check adalah hasil pencarian apakah koordinat checkPos
               terdapat pada Snake. Jika ada akan menghasilkan addressN
               elemen/node yang sama koordinatnya dengan checkPos.
               Jika tidak ada, maka menghasilkan NULL. */
           addressN checkFood = SearchPos_LDP(Food,checkPos);
            /* checkFood adalah hasil pencarian apakah koordinat checkPos terdapat 
            Food. Jika ada menghasilkan address elemen/node yang sama koordinatnya dengan checkPos.
            Jika tidak ada, menghasilkan Nil.
            */

           addressN checkMeteor = SearchPos_LDP(Meteor,checkPos);
           /*checkMeteor adalah hasil pencarian apakah koordinat checkPos terdapat
           pada Meteor. Jika ada, menghasilkan address elemen/node yang sama koordinatnya dengan
           checkpos.
           Jika tidak ada, menghasilkan Nil.
           */
           
           addressN checkObstacle = SearchPos_LDP(Obstacle,checkPos);
           /*checkObstacle adalah hasil pencarian apakah koordinat checkPos terdapat
           pada Obstacle. Jika ada, menghasilkan address elemen/node yang sama koordinatnya dengan
           checkpos.
           Jika tidak ada, menghasilkan Nil.
           */

            if (checkMeteor != NULL || SearchPos_LDP(Snake,meteor)){
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
                addressN P = Last(*Snake);
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
                addressN P = Last(*Snake);
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
                addressN P = Last(*Snake);
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
                addressN P = Last(*Snake);
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



Point generateFood(List Snake){
    srand(time(0));
    Point food;
    CreatePoint(&food,rand() % 5, rand() % 5);
    while (SearchPos_LDP(Snake,food) != NULL){
        CreatePoint(&food,rand() % 5, rand() % 5);
    }
    return food;
}

boolean foodEaten(List Snake, List *Food){
    return ((AbsisN(First(*Food)) == AbsisN(First(Snake))) && (OrdinatN(First(*Food)) == OrdinatN(First(Snake))));
}

Point generateMeteor(List Snake,List Food,List Obstacle){
    srand(time(0));
    Point meteor;
    CreatePoint(&meteor,rand() % 5, rand() % 5);
    while (SearchPos_LDP(Food,meteor) != NULL || SearchPos_LDP(Obstacle,meteor) != NULL){
        CreatePoint(&meteor,rand() % 5, rand() % 5);
    }
    PrintPoint(meteor);
    printf("\n");
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
    return SearchPos_LDP(Snake,meteor);
}

void skorakhir (List Snake){
    int skor;
    skor = (LengthList(Snake)) * 2;
    printf("Skor : %d", skor);
    printf("\n");
}
