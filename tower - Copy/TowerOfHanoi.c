#include <stdio.h>
#include <stdlib.h>
#include "TowerOfHanoi.h"
int length(Stack S){
    if (!IsEmpty(S)){
        return Top(S)+1;
    }
    else{
        return 0;
    }
}
void tipe0(){
    printf ("       |       ");
}
void tipe1(){
    printf ("       *       ");
}
void tipe2(){
    printf ("      ***      ");
}
void tipe3(){
    printf ("     *****     ");
}
void tipe4(){
    printf ("    *******    ");
}
void tipe5(){
    printf ("   *********   ");
}
void base(){
    printf ("---------------               ---------------               --------------- ");
}

void spasi(){
    printf ("               ");
}

void printTower(Stack S, Stack S2, Stack S3){
    printf("\n");
    printf("\n");
    
    
    for (int i = 5; i>0;i--){
        if (i<length(S)){
            if (S.T[i]==1){
                tipe1();
                spasi();
            }
            else if (S.T[i]==2){
                tipe2();
                spasi();
            }
            else if (S.T[i]==3){
                tipe3();
                spasi();
            }
            else if (S.T[i]==4){
                tipe4();
                spasi();
            }
            else if (S.T[i]==5){
                tipe5();
                spasi();
            }
        }
        else{
            tipe0();
            spasi();
        }
        if(i<length(S2)){
            if (S2.T[i]==1){
                tipe1();
                spasi();
            }
            else if (S2.T[i]==2){
                tipe2();
                spasi();
            }
            else if (S2.T[i]==3){
                tipe3();
                spasi();
            }
            else if (S2.T[i]==4){
                tipe4();
                spasi();
            }
            else if (S2.T[i]==5){
                tipe5();
                spasi();
            }
        }
        else{
            tipe0();
            spasi();
        }
        if(i<length(S3)){
            if (S3.T[i]==1){
                tipe1();
                spasi();
            }
            else if (S3.T[i]==2){
                tipe2();
                spasi();
            }
            else if (S3.T[i]==3){
                tipe3();
                spasi();
            }
            else if (S3.T[i]==4){
                tipe4();
                spasi();
            }
            else if (S3.T[i]==5){
                tipe5();
                spasi();
            }
        }
        else{
            tipe0();
            spasi();
        }
        printf("\n");
    }
    base();
    printf("\n");
    printf("    TIANG A                       TIANG B                       TIANG C\n");
    printf("\n");
}
boolean bisapindah(Stack S1, Stack S2){
    if (InfoTop(S2)==6){
        return true;
    }
    if(!IsEmpty(S2)){
        return InfoTop(S2)>InfoTop(S1);
    }
    else{
        return true;
    }
}
void pindah(Stack *A, Stack *B, Stack *C, char* asal,char* tujuan, int *steps){
    if (asal[0] =='A' && tujuan[0] =='B' && bisapindah(*A,*B)){
        infotype x;
        Pop(A,&x);
        Push(B,x);
        *steps+=1;
    }
    else if (asal[0] == 'A' && tujuan[0] =='C'&& bisapindah(*A,*C)){
        infotype x;
        Pop(A,&x);
        Push(C,x);
        *steps+=1;
    }
    else if (asal[0] == 'B' && tujuan[0] =='A'&& bisapindah(*B,*A)){
        infotype x;
        Pop(B,&x);
        Push(A,x);
        *steps+=1;
    }
    else if (asal[0] == 'B' && tujuan[0] =='C'&& bisapindah(*B,*C)){
        infotype x;
        Pop(B,&x);
        Push(C,x);
        *steps+=1;
    }
    else if (asal[0] == 'C' && tujuan[0] =='A'&& bisapindah(*C,*A)){
        infotype x;
        Pop(C,&x);
        Push(A,x);
        *steps+=1;
    }
    else if (asal[0] == 'C' && tujuan[0] =='B'&& bisapindah(*C,*B)){
        infotype x;
        Pop(C,&x);
        Push(B,x);
        *steps+=1;
    }
    else{
        printf("INPUT INVALID\n");
    }
}

boolean endgame(Stack C){
    int i;
    Stack cek;
    CreateEmpty(&cek);
    for(i=6; i>0; i--){
        Push(&cek,i);
    }
    boolean win = true;
    infotype x;
    while(!IsEmpty(cek) && !IsEmpty(C)){
        if(InfoTop(C) != InfoTop(cek)){
            win = false;
        }
        Pop(&C,&x);
        Pop(&cek,&x);
    }
    if(IsEmpty(C) && IsEmpty(cek)){
        return win;
    }
    else{
        return false;
    }
}


char *WordToString(Word CWord){
    char *string;

    string = malloc(CWord.Length * sizeof(char));
    int i = 0;
    while (i < CWord.Length)
    {
        *(string + i) = CWord.TabWord[i];
        i++;
    }
    string[i] = '\0';
    return string;
}

void TowerOfHanoi(){
    Stack A, B, C;
    int steps = 0;
    //infotype y = 7;
    CreateEmpty(&A);
    CreateEmpty(&B);
    CreateEmpty(&C);
    infotype x = 6;
    Push(&B,x);
    Push(&C,x);
    for(int i=6;i>0;i--){
        Push(&A,x);
        x--;
    }
    
    while (!endgame(C)){
        char *asal;
        char *tujuan;
        printTower(A,B,C);
        printf("TIANG ASAL:");
        STARTCOMMAND();
        asal=WordToString(currentCMD);
        printf("TIANG TUJUAN:");
        STARTCOMMAND();
        tujuan=WordToString(currentCMD);
        pindah( &A,  &B,  &C,  asal, tujuan, &steps);
        
    }
    printTower(A,B,C);
    printf("Skor anda: %d\n",310/steps);
}

/*
    pindah(&A,&B,&C,'A','C',&steps);
    printTower(A,B,C);

*/