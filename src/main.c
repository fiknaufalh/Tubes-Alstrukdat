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
        scanf(" %[^\n]s", command);
        if (IsEmpty(GamesList))
        {
            if (compareString(command, "START"))
            {
                STARTBNMO(&GamesList);
            }
            else if (compareString(command, "LOAD"))
            {
                // Take directory argument
                char directory[100];
                int i = 0;
                while (command[i+5] != '\0')
                {
                    directory[i] = command[i+5];
                    i++;
                }

                // LOAD
            } 

            else {
                printf("Belum ada konfigurasi games yang dimuat\n");
                printf("Muat konfigurasi games terlebih dahulu dengan command LOAD <filename>\n");
                printf("%s\n",command);
            }
        }
    }


    return 0;
}