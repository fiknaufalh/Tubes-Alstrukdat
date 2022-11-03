/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../../boolean.h"
#include "../mesinkarakter/mesinkarakter.h"

#define NMax 50
#define BLANK ' '
#define ENTER '\n'

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word currentWord;
extern Word currentCMD;

/* *** Membaca dari file *** */
void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD(char *filename);
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void PrintWord(Word K); 
/* Mencetak kata ke layar
   I.S. : Kata K terdefinisi
   F.S. : Kata K tercetak pada layar */

void CopyLine();
void ADVLine();
void IgnoreEnter();

/* *** Membaca command dari terminal *** */
void IgnoreBlanksCMD();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK */

void STARTCOMMAND();
/* I.S. : currentChar sembarang 
   F.S. : EndKata = true, dan currentChar = ENTER; 
          atau EndKata = false, currentCMD adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVCOMMAND();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentCMD adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin ENTER
          Jika currentChar = ENTER, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure CopyCommand */

void CopyCommand();
/* Mengakuisisi kata, menyimpan dalam currentCMD
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentCMD berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = ENTER; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

#endif