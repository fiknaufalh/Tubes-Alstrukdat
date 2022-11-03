#include <stdio.h>
#include "mesinkata.h"

Word currentWord;
boolean EndWord;

// char GetCC(){
//     return currentChar;
// }

// boolean IsEOP(){
//     return currentChar == MARK;
// }

void IgnoreBlanks(){
    while (GetCC() == BLANK || GetCC() == ENTER){
        ADV();
    }
}

void IgnoreEnter(){
    while (GetCC() == ENTER)
    {
        ADV();
    }
}

void STARTWORD(char *filename){
    START(filename);
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

void ADVLine(){
    IgnoreEnter();
    if (GetCC() == ENTER){
        EndWord = true;
    } else {
        CopyLine();
    }
}

void CopyWord(){
    int i = 0;
    currentChar = GetCC();
    while (currentChar != MARK && currentChar != BLANK && currentChar != ENTER){
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

void CopyLine(){
    int i = 0;
    currentChar = GetCC();
    while (currentChar != MARK && currentChar != ENTER && !feof(pita)){
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

