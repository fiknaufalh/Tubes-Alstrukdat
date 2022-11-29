# include <stdio.h>
# include "stack.h"

int main()
{
    Stack S,S2;
    stackElmt X;

    // Create Stack
    printf("Creating stack.....\n");
    CreateEmptyStack(&S);
    CreateEmptyStack(&S2);

    // Check if stack is empty
    printf("Is Empty = %d\n", IsStackEmpty(S));

    // Push string to stack
    printf("Push Elmt to stack......\n")
    Push(&S, "HANGMAN");
    Push(&S, "CHESS");
    Push(&S, "SUDOKU");
    Push(&S, "MAHJONG");
    Push(&S, "TETRIS");
    Push(&S, "PUZZLE");
    Push(&S, "SNAKE");
    Push(&S, "PACMAN");
    Push(&S, "TIC TAC TOE");

    // Check if stack is empty and is full
    printf("Is Empty = %d\n", IsStackEmpty(S));

    printf("Is Full = %d\n", IsStackFull(S));

    // Print stack Elmt
    Pop(&S, &X);
    printf("Pop S = %s\n", X);
    
    printf("Is Empty S2 = %d\n", IsStackEmpty(S2));
    Push(&S2, X);
    printf("Is Empty S2 = %d\n", IsStackEmpty(S2));
    Pop(&S2, &X);
    printf("Pop S2 = %s\n", X);
    printf("S Top index = %d\n", Top(S));
    printf("S Top Elmt = %s\n", InfoTop(S));

    // Reverse stack
    printf("Reversing stack....\n");
    ReverseStack(&S);
    Pop(&S, &X);
    printf("Pop S = %s\n", X);
    Pop(&S, &X);
    printf("Pop S = %s\n", X);

    return 0;
}