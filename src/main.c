#include "console.h"
#include <stdio.h>

int main(){

    ArrayDin GamesList;
    Queue GamesQueue;
    Queue GamesHistory;
    Map RNGScore;
    Map DDScore;
    Map HangmanScore;
    Map TowerScore;
    Map SnakeScore;

    GamesList = MakeArrayDin();
    CreateQueue(&GamesQueue);
    CreateQueue(&GamesHistory);
    CreateScoreBoard(&RNGScore);
    CreateScoreBoard(&DDScore);
    CreateScoreBoard(&HangmanScore);
    CreateScoreBoard(&TowerScore);
    CreateScoreBoard(&SnakeScore);
    

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
                    STARTBNMO(&GamesList);
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
                    LOADBNMO(&GamesList,&GamesHistory,filename,&RNGScore,&DDScore,&HangmanScore,&TowerScore,&SnakeScore);
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
                    CREATEGAME(&GamesList);
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
                    DELETEGAME(&GamesList,GamesQueue);
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
                    PLAYGAME(&GamesQueue,GamesList,&GamesHistory);
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
                    SKIPGAME(&GamesQueue,GamesList,&GamesHistory,nSkip);
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
                    SAVEBNMO(&GamesList,filename);
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
                    SCOREBOARD(RNGScore,DDScore,HangmanScore,TowerScore,SnakeScore);
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
