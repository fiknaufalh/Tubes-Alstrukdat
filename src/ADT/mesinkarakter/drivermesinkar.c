# include "mesinkarakter.h"
# include <stdio.h>

int main()
{
    /* *** Membaca File *** */
    // START Mesin Karakter
    START("pitakar.txt");

    // Check First Character
    char first = GetCC();   // T
    printf("%c\n", first);

    // Check ADV() 
    ADV();
    char second = GetCC();      // e
    printf("%c\n", second);
    
    // Check if EOP
    printf("%d\n", IsEOP());    // 0 (false)

    // Print all characters until EOP
    while (!IsEOP())            // es pita karakter Blank Alstruk daT
    {
        printf("%c", GetCC());
        ADV();
    }
    printf("\n");
    
    // Check if EOP is true
    printf("%d\n", IsEOP());    // 1 (true)

    /* *** Membaca Command *** */
    // START Command
    printf("ENTER COMMAND : ");
    COMMAND();     

    // Check First Character
    char firstC = GetCC();
    printf("%c\n", firstC);

    // Check ADVC()
    ADVC();
    char secondC = GetCC();
    printf("%c\n", secondC);

    // Print all characters until EOP (secondC until entered)
    while (GetCC() != ENTER)
    {
        printf("%c", GetCC());
        ADVC();
    }

    return 0;

}
