#include "console.h"

int main(){

    ArrayDin GamesList;
    Queue GamesQueue;

    GamesList = MakeArrayDin();
    CreateQueue(&GamesQueue);

    boolean EndProgram = false;
    char* command;

    printf("===============  SELAMAT DATANG DI BNMO! ===============\n");
    printf("Masukkan command LOAD <filename> untuk memuat konfigurasi games\n");
    printf("Kemudian, masukkan command START untuk memulai permainan!");
    
    while (!EndProgram)
    {
        scanf("\nENTER COMMAND: %s", command);
        if (IsEmpty(GamesList))
        {
            if (compareString(command, "START"))
            {
                START(&GamesList);
            }

            else if (compareString(command, "LOAD"))
            {
                // LOAD
            } 

            else {
                printf("Belum ada konfigurasi games yang dimuat\n");
                printf("Muat konfigurasi games terlebih dahulu dengan command LOAD <filename>\n");
            }
        }
    }


    return 0;
}