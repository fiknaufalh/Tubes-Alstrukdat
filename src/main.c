#include "console.h"
#include <stdio.h>

int main(){

    ArrayDin GamesList;
    Queue GamesQueue;
    Stack GamesHistory;
    ArrMap ScoreBoard;

    GamesList = MakeArrayDin();
    CreateQueue(&GamesQueue);
    CreateEmptyStack(&GamesHistory);
    MakeEmptyArrMap(&ScoreBoard);
   
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
                ADVCOMMAND();
                if (EndWord == true) 
                {
                    STARTBNMO(&GamesList, &ScoreBoard);
                }
                else
                {
                    OTHERCMD(); 
                }
            }

            /* *** LOAD *** */
            else if (compareString(command, "LOAD"))
            {
                ADVCOMMAND();
                char* filename = WordToString(currentCMD);

                ADVCOMMAND();
                if (EndWord == true) 
                {
                    // LOADBNMO(&GamesList,filename);
                    LOADBNMO(&GamesList,&GamesHistory,filename,&ScoreBoard);
                }
                else
                {
                    OTHERCMD(); 
                }   
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

                ADVCOMMAND();
                if (EndWord == true) 
                {
                    CREATEGAME(&GamesList,&ScoreBoard);
                }
                else
                {
                    OTHERCMD();
                }
            }

            /* *** LIST GAME *** */
            else if (compareString(command,"LIST"))
            {
                ADVCOMMAND();
                command = WordToString(currentCMD);
                if (!compareString(command,"GAME")) {
                    OTHERCMD(); continue;
                }

                ADVCOMMAND();
                if (EndWord == true) 
                {
                    LISTGAME(GamesList);
                }
                else
                {
                    OTHERCMD(); 
                }
            }

            /* *** DELETE GAME *** */
            else if (compareString(command,"DELETE"))
            {
                ADVCOMMAND();
                command = WordToString(currentCMD);
                if (!compareString(command,"GAME")) {
                    OTHERCMD(); continue;
                }
                ADVCOMMAND();
                if (EndWord == true) 
                {
                    DELETEGAME(&GamesList,GamesQueue, &ScoreBoard, &GamesHistory);
                }
                else
                {
                    OTHERCMD(); 
                } 
            }

            /* *** QUEUE GAME *** */
            else if (compareString(command,"QUEUE"))
            {
                ADVCOMMAND();
                command = WordToString(currentCMD);
                if (!compareString(command,"GAME")) {
                    OTHERCMD(); continue;
                }

                ADVCOMMAND();
                if (EndWord == true) 
                {
                    QUEUEGAME(&GamesQueue,GamesList);
                }
                else
                {
                    OTHERCMD(); 
                }
            }
            
            /* *** PLAY GAME *** */
            else if (compareString(command,"PLAY"))
            {
                ADVCOMMAND();
                command = WordToString(currentCMD);
                if (!compareString(command,"GAME")) {
                    OTHERCMD(); continue;
                }

                ADVCOMMAND();
                if (EndWord == true) 
                {
                    PLAYGAME(&GamesQueue,GamesList,&GamesHistory,&ScoreBoard);
                }
                else
                {
                    OTHERCMD();
                } 
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

                ADVCOMMAND();
                if (EndWord == true) 
                {
                    SKIPGAME(&GamesQueue,GamesList,&GamesHistory,nSkip,&ScoreBoard);
                }
                else
                {
                    OTHERCMD(); 
                }  
            }

            /* *** HELP *** */
            else if (compareString(command,"HELP"))
            {
                ADVCOMMAND();
                if (EndWord == true) 
                {
                    HELP();
                }
                else
                {
                    OTHERCMD(); 
                }  
            }

            /* *** SAVE *** */
            else if (compareString(command, "SAVE"))
            {
                ADVCOMMAND();
                char* filename = WordToString(currentCMD);

                ADVCOMMAND();
                if (EndWord == true) 
                {
                    SAVEBNMO(GamesList, filename, GamesHistory, ScoreBoard);
                }
                else
                {
                    OTHERCMD(); 
                }      
            }

            /* *** QUIT *** */
            else if (compareString(command,"QUIT"))
            {
                ADVCOMMAND();
                if (EndWord == true) 
                {
                    QUIT(&GamesQueue);
                    EndProgram = true;
                }
                else
                {
                    OTHERCMD(); 
                }    
            }

            /* *** SCOREBOARD *** */
            else if (compareString(command,"SCOREBOARD"))
            {
                ADVCOMMAND();
                if (EndWord == true) 
                {
                    SCOREBOARD(ScoreBoard);
                }
                else
                {
                    OTHERCMD(); 
                }    
            }

            /* *** RESET SCOREBOARD & RESET HISTORY *** */
            else if (compareString(command,"RESET"))
            {
                ADVCOMMAND();
                command = WordToString(currentCMD);
                if (compareString(command,"SCOREBOARD")) {
                    ADVCOMMAND();
                    if (EndWord == true) 
                    {
                        RESETSCOREBOARD(&ScoreBoard);
                    }
                    else
                    {
                        OTHERCMD(); 
                    }    
                }
                else if (compareString(command,"HISTORY"))
                {
                    ADVCOMMAND();
                    if (EndWord == true) 
                    {
                        RESETHISTORY(&GamesHistory);
                    }
                    else
                    {
                        OTHERCMD(); 
                    }    
                }
                else
                {
                    OTHERCMD(); 
                }
            }

            /* *** HISTORY *** */
            else if(compareString(command,"HISTORY"))
            {
                ADVCOMMAND();
                if (!EndWord)
                {
                    int nHistory = WordToInt(currentCMD);

                    ADVCOMMAND();
                    if (EndWord == true)
                    {
                        HISTORY(GamesHistory,nHistory);
                    }
                    else
                    {
                        OTHERCMD(); 
                    }
                }
                else
                {
                    OTHERCMD();
                }

            }

            /* *** OTHER COMMAND *** */
            else
            {
                OTHERCMD();
            }
            
            /* *** End Command *** */
            while (EndWord == false)
            {
                ADVCOMMAND();
            }
        }
    }

    return 0;
}
