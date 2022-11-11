#include "console.h"
#include <stdio.h>

int main(){

    ArrayDin GamesList;
    Queue GamesQueue;
    Queue GamesHistory;

    GamesList = MakeArrayDin();
    CreateQueue(&GamesQueue);
    CreateQueue(&GamesHistory);

    boolean EndProgram = false;
    char* command;

    printf("                          '########::'##::: ##:'##::::'##::'#######::\n");
    printf("                           ##.... ##: ###:: ##: ###::'###:'##.... ##:\n");
    printf("                           ##:::: ##: ####: ##: ####'####: ##:::: ##:\n");
    printf("                           ########:: ## ## ##: ## ### ##: ##:::: ##:\n");
    printf("                           ##.... ##: ##. ####: ##. #: ##: ##:::: ##:\n");
    printf("                           ##:::: ##: ##:. ###: ##:.:: ##: ##:::: ##:\n");
    printf("                           ########:: ##::. ##: ##:::: ##:. #######::\n");
    printf("                          ........:::..::::..::..:::::..:::.......:::\n");

    printf("==================================  SELAMAT DATANG DI BNMO! ==================================\n");
    printf("Masukkan command START atau LOAD <filename> untuk memulai permainan!\n");
    printf("Note: START untuk konfigurasi default dan LOAD <filename> untuk konfigurasi sesuai filename.\n");
    
    while (!EndProgram)
    {
        printf("\nENTER COMMAND: ");
        STARTCOMMAND();

        command = WordToString(currentCMD);

        if (IsEmpty(GamesList))
        {
            /* *** START *** */
            if (compareString(command, "START"))
            {
                STARTBNMO(&GamesList);
            }

            /* *** LOAD *** */
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

            /* *** End Command *** */
            while (!EndWord)
            {
                ADVCOMMAND();
            }
        }
        else /* Games sudah terkonfigurasi */
        {
            /* *** CREATE GAME *** */
            if (compareString(command,"CREATE"))
            {
                ADVCOMMAND();
                command = WordToString(currentCMD);
                if (!compareString(command,"GAME")) {
                    OTHERCMD(); continue;
                }

                CREATEGAME(&GamesList);
            }

            /* *** LIST GAME *** */
            else if (compareString(command,"LIST"))
            {
                ADVCOMMAND();
                command = WordToString(currentCMD);
                if (!compareString(command,"GAME")) {
                    OTHERCMD(); continue;
                }

                LISTGAME(GamesList);
            }

            /* *** DELETE GAME *** */
            else if (compareString(command,"DELETE"))
            {
                ADVCOMMAND();
                command = WordToString(currentCMD);
                if (!compareString(command,"GAME")) {
                    OTHERCMD(); continue;
                }

                DELETEGAME(&GamesList,GamesQueue);
            }

            /* *** QUEUE GAME *** */
            else if (compareString(command,"QUEUE"))
            {
                ADVCOMMAND();
                command = WordToString(currentCMD);
                if (!compareString(command,"GAME")) {
                    OTHERCMD(); continue;
                }

                QUEUEGAME(&GamesQueue,GamesList);
                // displayQueue(GamesQueue);
            }
            
            /* *** PLAY GAME *** */
            else if (compareString(command,"PLAY"))
            {
                ADVCOMMAND();
                command = WordToString(currentCMD);
                if (!compareString(command,"GAME")) {
                    OTHERCMD(); continue;
                }

                PLAYGAME(&GamesQueue,GamesList,&GamesHistory);
            }
            
            /* *** SKIP GAME *** */
            else if (compareString(command,"SKIP"))
            {
                ADVCOMMAND();
                command = WordToString(currentCMD);
                if (!compareString(command,"GAME")) {
                    OTHERCMD(); continue;
                }

                ADVCOMMAND();
                int nSkip = WordToInt(currentCMD);

                SKIPGAME(&GamesQueue,GamesList,&GamesHistory,nSkip);
            }

            /* *** HELP *** */
            else if (compareString(command,"HELP"))
            {
                HELP();
            }

            /* *** SAVE *** */
            else if (compareString(command, "SAVE"))
            {
                ADVCOMMAND();
                char* filename = WordToString(currentCMD);
                SAVEBNMO(&GamesList,filename);
            }

            /* *** QUIT *** */
            else if (compareString(command,"QUIT"))
            {
                QUIT(&GamesQueue);
                EndProgram = true;
            }

            /* *** OTHER COMMAND *** */
            else
            {
                OTHERCMD();
            }
            
            /* *** End Command *** */
            while (!EndWord)
            {
                ADVCOMMAND();
            }
        }
    }

    return 0;
}
