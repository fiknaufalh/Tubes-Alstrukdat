#include "console.h"
#include <stdio.h>

int main(){

    ArrayDin GamesList;
    Queue GamesQueue;

    GamesList = MakeArrayDin();
    CreateQueue(&GamesQueue);

    boolean EndProgram = false;
    char* command;

    printf("====================  SELAMAT DATANG DI BNMO! ====================\n");
    printf("Masukkan command LOAD <filename> untuk memuat konfigurasi games\n");
    printf("Kemudian, masukkan command START untuk memulai permainan!\n");
    
    while (!EndProgram)
    {
        printf("\nENTER COMMAND: ");
        STARTCOMMAND();

        command = WordToString(currentCMD);

        if (IsEmpty(GamesList))
        {
            if (compareString(command, "START"))
            {
                STARTBNMO(&GamesList);
            }
            else if (compareString(command, "LOAD"))
            {
                ADVCOMMAND();
                char* filename = WordToString(currentCMD);
                LOADBNMO(&GamesList,filename);
            } 
            else 
            {
                printf("Belum ada konfigurasi games yang dimuat\n");
                printf("Muat konfigurasi games terlebih dahulu dengan command LOAD <filename>\n");
            }
        }
        else /* Games sudah terkonfigurasi */
        {
            if (compareString(command,"CREATE"))
            {
                ADVCOMMAND();
                command = WordToString(currentCMD);
                if (!compareString(command,"GAME")) continue;

                CREATEGAME(&GamesList);
            }
        }
    }


    return 0;
}