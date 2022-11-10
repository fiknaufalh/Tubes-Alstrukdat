# include "mesinkata.h"
# include <stdio.h>

int main()
{
    /* *** Membaca Kata *** */
    // START Mesin Kata
    STARTWORD("../mesinkarakter/pitakar.txt");

    // Check First Word
    Word first = currentWord;
    printf("First Word: ");
    PrintWord(first);   // Tes
    printf("\n");

    // Check ADVWORD()
    ADVWORD();
    Word second = currentWord;
    printf("Second Word: ");
    PrintWord(second);      // pita
    printf("\n");

    // Check if EndWord
    printf("EndWord: %d\n", EndWord);   // 0

    // Print all words until EndWord
    while (!EndWord)            // karakter Blank Alstruk daT
    {
        PrintWord(currentWord);
        printf("\n");
        ADVWORD();
    }
   
    // Check if EndWord is true
   printf("EndWord: %d\n", EndWord);   // 1


    /* *** Membaca baris *** */
    // START Mesin Kata (pitakar2.txt)
    STARTWORD("pitakar2.txt");

    // Check First Line (Total Game) 
    Word firstLine = currentWord;
    printf("First Line: ");
    PrintWord(firstLine);   // 5
    printf("\n");

    // Check Second Line (Game 1)
    ADVLine();
    Word secondLine = currentWord;
    printf("Second Line: ");
    PrintWord(secondLine);  // RNG
    printf("\n");

    // Check Third Line (Game 2)
    ADVLine();
    Word thirdLine = currentWord;
    printf("Third Line: ");
    PrintWord(thirdLine);   // Diner Dash
    printf("\n");

    // Check if feof(pita) is true
    printf("feof(pita): %d\n", feof(pita));   // 0

    // Print all games until feof(pita)
    int i = 2;
    while (!feof(pita))
    {
        printf("Game %d: ", i);
        PrintWord(currentWord);
        printf("\n");
        ADVLine();
        i++;
    }

    // Print last game
    printf("Game %d: ", i);
    PrintWord(currentWord);
    printf("\n");

    // Check if feof(pita) is true
    printf("feof(pita): %d\n", feof(pita));   // non zero value


    /* *** Membaca CMD(Kata) *** */
    // START CMD
    printf("ENTER COMMAND : ");
    STARTCOMMAND();
    
    // Check First Command
    Word firstCMD = currentCMD;
    printf("First Command: ");
    PrintWord(firstCMD);
    printf("\n");

    // Check ADVCommand()
    ADVCOMMAND();
    Word secondCMD = currentCMD;
    printf("Second Command: ");
    PrintWord(secondCMD);
    printf("\n");

    // Check if EndWord
    printf("EndWord: %d\n", EndWord);   // 0
    
    // Print all commands until EndWord
    while (!EndWord)
    {
        PrintWord(currentCMD);
        printf("\n");
        ADVCOMMAND();
    }

    // Check if EndWord is true
    printf("EndWord: %d\n", EndWord);   // 1

    /* *** Membaca CMD(Baris) *** */
    // START CMD
    printf("ENTER COMMAND LINE : ");
    STARTCOMMANDGAME();

    // Check Command
    Word firstCMDLine = currentCMD;
    printf("First Command: ");
    PrintWord(firstCMDLine);
    printf("\n");

    // Check if EndWord is true
    printf("EndWord: %d\n", EndWord);   // 0
    ADVCOMMAND();
    printf("EndWord: %d\n", EndWord);   // 1

    return 0;
}