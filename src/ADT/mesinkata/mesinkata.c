#include <stdio.h>
#include "mesinkata.h"

Word currentWord;
boolean EndWord;
Word currentCMD;

/* *** Membaca dari file *** */
void IgnoreBlanks(){
    while (GetCC() == BLANK){
        ADV();
    }
}

void IgnoreEnter(){
    while (GetCC() == ENTER){
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

void CopyWord(){
    int i = 0;
    currentChar = GetCC();
    while (currentChar != MARK && currentChar != BLANK && currentChar != ENTER && !feof(pita)){
        currentWord.TabWord[i] = currentChar;
        ADV();
        currentChar = GetCC();
        i++;
    }
    
    currentWord.Length = i-1;

    if (i >= NMax) currentWord.Length = NMax;
    else currentWord.Length = i;
}

void PrintWord(Word K){
    for (int i = 0; i < K.Length; i ++) {
        printf("%c", K.TabWord[i]);
    }
}

void ADVLine(){
    IgnoreEnter();
    if (GetCC() == ENTER){
        EndWord = true;
    } else {
        CopyLine();
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

    if (i >= NMax) currentWord.Length = NMax;
    else currentWord.Length = i;
}

/* *** Membaca command dari terminal *** */
void IgnoreBlanksCMD(){
    while (GetCC() == BLANK){
        ADVC();
    }
}

void STARTCOMMAND(){
    COMMAND();
    IgnoreBlanksCMD();
    if (currentChar == ENTER){
        EndWord = true;
    } else {
        EndWord = false;
        CopyCommand();
    }
}

void STARTCOMMANDLINE(){
    COMMAND();
    IgnoreBlanksCMD();
    if(currentChar == ENTER){
        EndWord = true;
    } else {
        EndWord = false;
        CopyCommandLine();
    }
}

void ADVCOMMAND(){
    IgnoreBlanksCMD();
    if (currentChar == ENTER && !EndWord){
        EndWord = true;
    } else{
        CopyCommand();
        IgnoreBlanksCMD();
    }
}

void CopyCommand(){
    int i = 0;
    while ((currentChar != BLANK) && (currentChar != ENTER) && i != NMax) {
        currentCMD.TabWord[i] = currentChar;
        ADVC();
        i++;
    }
    if (i >= NMax) currentCMD.Length = NMax;
    else currentCMD.Length = i;
}

void CopyCommandLine(){
    int i = 0;
    while ((currentChar != ENTER) && i != NMax) {
        currentCMD.TabWord[i] = currentChar;
        ADVC();
        i++;
    }
    if (i >= NMax) currentCMD.Length = NMax;
    else currentCMD.Length = i;
}