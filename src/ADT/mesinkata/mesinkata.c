#include <stdio.h>
#include "mesinkata.h"

Word currentWord;
boolean EndWord;

char GetCC(){
    return currentChar;
}

boolean IsEOP(){
    return currentChar == MARK;
}

void IgnoreBlanks(){
    while (GetCC() == BLANK){
        ADV();
    }
}

void STARTWORD(){
    START();
    IgnoreBlanks();
    if (GetCC() == MARK){
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD(){
    IgnoreBlanks();
    if (GetCC() == MARK){
        EndWord = true;
    } else {
        CopyWord();
    }
    IgnoreBlanks();
}

void CopyWord(){
    int i = 0;
    currentChar = GetCC();
    while (currentChar != MARK && currentChar != BLANK){
        currentWord.TabWord[i] = currentChar;
        ADV();
        currentChar = GetCC();
        i++;
    }
    
    currentWord.Length = i;

    if (i >= NMax){
        currentWord.Length = NMax;
    } else {
        currentWord.Length = i;
    }
}
