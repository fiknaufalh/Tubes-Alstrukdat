#include <stdio.h>
#include <stdlib.h>
#include "ToH.h"

void ToH(){
    StackInt A, B, C;
    int steps = 0;
    //int y = 7;
    CreateEmpty_SInt(&A);
    CreateEmpty_SInt(&B);
    CreateEmpty_SInt(&C);
    int x = 6;
    Push_SInt(&B,x);
    Push_SInt(&C,x);
    for(int i=6;i>0;i--){
        Push_SInt(&A,x);
        x--;
    }
    
    while (!endgameToH(C)){
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

void printTower(StackInt S, StackInt S2, StackInt S3){
    printf("\n");
    printf("\n");
    
    
    for (int i = 5; i>0;i--){
        if (i<lengthSInt(S)){
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
        if(i<lengthSInt(S2)){
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
        if(i<lengthSInt(S3)){
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
boolean bisapindah(StackInt S1, StackInt S2){
    if (InfoTop(S2)==6){
        return true;
    }
    if(!IsEmpty_SInt(S2)){
        return InfoTop(S2)>InfoTop(S1);
    }
    else{
        return true;
    }
}
void pindah(StackInt *A, StackInt *B, StackInt *C, char* asal,char* tujuan, int *steps){
    if (asal[0] =='A' && tujuan[0] =='B' && bisapindah(*A,*B)){
        int x;
        Pop_SInt(A,&x);
        Push_SInt(B,x);
        *steps+=1;
    }
    else if (asal[0] == 'A' && tujuan[0] =='C'&& bisapindah(*A,*C)){
        int x;
        Pop_SInt(A,&x);
        Push_SInt(C,x);
        *steps+=1;
    }
    else if (asal[0] == 'B' && tujuan[0] =='A'&& bisapindah(*B,*A)){
        int x;
        Pop_SInt(B,&x);
        Push_SInt(A,x);
        *steps+=1;
    }
    else if (asal[0] == 'B' && tujuan[0] =='C'&& bisapindah(*B,*C)){
        int x;
        Pop_SInt(B,&x);
        Push_SInt(C,x);
        *steps+=1;
    }
    else if (asal[0] == 'C' && tujuan[0] =='A'&& bisapindah(*C,*A)){
        int x;
        Pop_SInt(C,&x);
        Push_SInt(A,x);
        *steps+=1;
    }
    else if (asal[0] == 'C' && tujuan[0] =='B'&& bisapindah(*C,*B)){
        int x;
        Pop_SInt(C,&x);
        Push_SInt(B,x);
        *steps+=1;
    }
    else{
        printf("INPUT INVALID\n");
    }
}

boolean endgameToH(StackInt C){
    int i;
    StackInt cek;
    CreateEmpty_SInt(&cek);
    for(i=6; i>0; i--){
        Push_SInt(&cek,i);
    }
    boolean win = true;
    int x;
    while(!IsEmpty_SInt(cek) && !IsEmpty_SInt(C)){
        if(InfoTop(C) != InfoTop(cek)){
            win = false;
        }
        Pop_SInt(&C,&x);
        Pop_SInt(&cek,&x);
    }
    if(IsEmpty_SInt(C) && IsEmpty_SInt(cek)){
        return win;
    }
    else{
        return false;
    }
}
