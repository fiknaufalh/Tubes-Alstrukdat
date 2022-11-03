#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "console.h"

boolean compareString(char *str1, char *str2)
{
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2) return false;
        str1++; str2++;
    }
    return true;
}

int WordToInt(Word CWord)
{
    int result = 0;
    for(int i = 0; i < CWord.Length;i++)
    {
        result = result*10 + (CWord.TabWord[i] - '0');
    }  
    return result;
}

char *WordToString(Word CWord)
{
    char *string;

    string = malloc(CWord.Length * sizeof(char));
    int i = 0;
    while (i < CWord.TabWord[i])
    {
        *(string + i) = CWord.TabWord[i];
        i++;
    }
    string[i] = '\0';
    return string;
}

void STARTBNMO(ArrayDin *GamesList)
{
    STARTWORD("./data/config.txt");
    int TotalGame = WordToInt(currentWord);
    char *temp;
    int i = 0;
    // printf("%d\n",TotalGame);
    while(i <= TotalGame)
    {
        // printf("%d\n",i);
        IgnoreBlanks();
        int length = 0;
        char *line = (char*) malloc (50 * sizeof(char));
        while(currentChar != '\n' && currentChar != MARK)
        {
            if(currentChar == '\n')
            {
                printf("newline\n");
            }
            else
            {
                // printf("%c\n",currentChar);
                line[length] = currentChar;
            } 
            ADV();
            length++;  
        }
        // printf("%d\n",length);
        // printf("%s\n",line);
        if(!EOP)
        {
            InsertLast(GamesList,line);
            PrintArrayDin(*GamesList);
        }
        i++;
    }
    if(!IsEmpty(*GamesList))
    {
        printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
    }
}

// Q2 HARUS URUT GABOLEH ACAK [RNG,DINER,CREATESHIT]
void PLAYGAME(Queue q, Queue q2)
{
    time_t t;
    int input;
    boolean status = true;
    srand((unsigned)time(&t));
    printf("Berikut adalah daftar Game-mu\n");
    for (int j = 0; j < length(q); j++)
    {
        printf("%d. %s\n", (j + 1), q.buffer[j]);
    }
    while (status)
    {
        printf("ENTER GAME:");
        scanf("%d", &input);
        if (input <= 0 || input > length(q))
        {
            printf("masukkan salah, silahkan ulangi kembali\n");
        }
        else
        {
            int i = 0;
            while (i < length(q2) && status)
            {
                if ((q.buffer[input - 1] == q2.buffer[i]))
                {
                    if (i > 1)
                    {
                        printf("Loading %s ...\n", q.buffer[input - 1]);
                        printf("%d\n", rand());
                        status = false;
                        break;
                    }
                    else if (i == 1)
                    {
                        printf("Loading %s ...\n", q.buffer[input - 1]);
                        printf("diner");
                        status = false;
                        break;
                    }
                    else if (i == 0)
                    {
                        printf("Loading %s ...\n", q.buffer[input - 1]);
                        printf("rng");
                        status = false;
                        break;
                    }
                }
                i++;
            }
            if (status)
            {
                printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n", q.buffer[input - 1]);
            }
        }
    }
}

void SKIPGAME(Queue q, Queue q2, int input)
{
    time_t t;
    boolean status = true;
    srand((unsigned)time(&t));
    printf("Berikut adalah daftar Game-mu\n");
    for (int j = 0; j < length(q); j++)
    {
        printf("%d. %s\n", (j + 1), q.buffer[j]);
    }
    if (input + 1 <= 0 || input + 1 > length(q))
    {
        printf("salah\n");
    }
    else
    {
        int i = 0;
        while (i < length(q2) && status)
        {
            if ((q.buffer[input] == q2.buffer[i]))
            {
                if (i > 1)
                {
                    printf("Loading %s ...\n", q.buffer[input]);
                    printf("%d\n", rand());
                    status = false;
                    break;
                }
                else if (i == 1)
                {
                    printf("Loading %s ...\n", q.buffer[input]);
                    printf("diner");
                    status = false;
                    break;
                }
                else if (i == 0)
                {
                    printf("Loading %s ...\n", q.buffer[input]);
                    printf("rng");
                    status = false;
                    break;
                }
            }
            i++;
        }
        if (status)
        {
            printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n", q.buffer[input]);
        }
    }
}

void HELP(){
    printf("----------------------------HELP-------------------------");
    printf("\n");
    printf("Start : Command yang membaca file konfigurasi untuk menjalankan BNMO.\n");
    printf("LOAD <filename> : Command yang membaca save file <filename> yang berisi list game yang dapat dimainkan, histori, dan scoreboard game.\n");
    printf("SAVE <filename> : Command yang digunakan untuk menyimpan state game pemain saat ini ke dalam suatu file.\n");
    printf("CREATEGAME : Command yang digunakan untuk menambahkan game baru pada daftar game.\n");
    printf("LISTGAME : Command yang digunakan untuk menampilkan daftar game yang disediakan oleh sistem.\n");
    printf("DELETEGAME : Command yang digunakan untuk menghapus sebuah game dari daftar game.\n");
    printf("QUEUEGAME : Command yang digunakan untuk mendaftarkan permainan ke dalam list.\n");
    printf("PLAYGAME : COmmand yang digunakan untuk memainkan sebuah permainan.\n");
    printf("SKIPGAME <n> : Command yang digunakan untuk melewatkan permainan sebanyak n.\n");
    printf("QUIT : Command untuk keluar dari program.\n");
    printf("HELP : Bantuan command command yang ada.\n");
}

void QUIT(){
    printf("Anda keluar dari game BNMO.\n");
    printf("Bye bye ...");
}

/* ini kayanya entar langsung di main aja dehh
void commandlain(char *command){
    if (strcmp(command, "START") == 0){
        START();
    }
    else if (strcmp(command,"LOAD") == (strcmp(command,"LOAD") - strcmp("LOAD","LOAD"))){
        LOAD();

    }
    else if (strcmp(command,"SAVE") == (strcmp(command,"SAVE") - strcmp("SAVE","SAVE"))){
        SAVE();
    }
    else if (strcmp(command,"CREATE GAME") == 0){
        CREATEGAME();
    }
    else if (strcmp(command,"LISTGAME") == 0){
        LISTGAME();
    }
    else if (strcmp(command,"DELETE GAME") == 0){
        DELETEGAME();
    }
    else if (strcmp(command,"QUEUE GAME") == 0){
        QUEUEGAME();
    }
    else if (strcmp(command, "PLAY GAME") == 0){
        PLAYGAME();
    }
    else if (strcmp(command, "SKIPGAME") == (strcmp(command,"SKIPGAME") - strcmp("SKIPGAME", "SKIPGAME"))){
        SKIPGAME();
    }
    else if (strcmp(command, "QUIT") == 0){
        QUIT();
    }
    else {
        printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
        printf("ENTER COMMAND:");
        scanf("%s", &command);
    }
}

*/
