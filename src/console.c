#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "console.h"

boolean compareString(char *str1, char *str2)
{
    boolean IsSame = (*str1 == *str2);
    while ((*str1 != '\0' && *str2 != '\0') && IsSame)
    {
        str1++; str2++;
        IsSame = (*str1 == *str2);
    }
    return IsSame;
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
    while (i < CWord.Length)
    {
        *(string + i) = CWord.TabWord[i];
        i++;
    }
    string[i] = '\0';
    return string;
}

int stringLength(char* string)
{
    int length = 0;
    while (*string != '\0')
    {
        length++;
        string++;
    }
    return length;
}

void stringConcat(char *s1,char *s2,char *sout)
{
    int len,i;

    len=stringLength(s1);
    for(i = 0; i < len;i++)
    {
        sout[i] = s1[i];
    }
    for(i = 0; i < stringLength(s2); i++)
    {
        sout[len+i]=s2[i];
    }
    sout[len+i]='\0';
}

void STARTBNMO(ArrayDin *GamesList)
{
    STARTWORD("./data/config.txt");
    
    int TotalGame = WordToInt(currentWord);
    int i = 1;
    // printf("%d\n",TotalGame);
    
    ADVLine();
    while(i <= TotalGame)
    {
        // printf("%s\n",currentWord);
        char *line;
        line = WordToString(currentWord);
        // printf("%s\n",line);
        InsertLast(GamesList,line);
        // PrintArrayDin(*GamesList);
        ADVLine();
        // printf("%s\n",line);
        i++;
    }
    if(!IsEmpty(*GamesList))
    {
        printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
    }
}

void LOADBNMO(ArrayDin* GamesList, char* filename)
{
    char path[50];
    stringConcat("./data/",filename,path);
    // printf("%s",path);
    STARTWORD(path);
    int TotalGame = WordToInt(currentWord);
    int i = 1;
    // printf("%d\n",TotalGame);
    ADVLine();
    while(i <= TotalGame)
    {
        // printf("%s\n",currentWord);
        char *line;
        line = WordToString(currentWord);
        // printf("%s\n",line);
        InsertLast(GamesList,line);
        // PrintArrayDin(*GamesList);
        ADVLine();
        // printf("%s\n",line);
        i++;
    }
    if(!IsEmpty(*GamesList))
    {
        printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
    }
}

void CREATEGAME(ArrayDin* GamesList)
{
    printf("Masukkan nama game yang akan ditambahkan: ");
    STARTCOMMAND();
    char* gameName = WordToString(currentCMD);
    InsertLast(GamesList,gameName);
    // PrintArrayDin(*GamesList);
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
    printf("--------------------------------------------HELP--------------------------------------------");
    printf("\n");
    printf("Start \t\t\t: Command yang membaca file konfigurasi untuk menjalankan BNMO.\n");
    printf("LOAD <filename> \t: Command yang membaca save file <filename> yang berisi list game yang dapat dimainkan, histori, dan scoreboard game.\n");
    printf("SAVE <filename> \t: Command yang digunakan untuk menyimpan state game pemain saat ini ke dalam suatu file.\n");
    printf("CREATE GAME \t\t: Command yang digunakan untuk menambahkan game baru pada daftar game.\n");
    printf("LIST GAME \t\t: Command yang digunakan untuk menampilkan daftar game yang disediakan oleh sistem.\n");
    printf("DELETE GAME \t\t: Command yang digunakan untuk menghapus sebuah game dari daftar game.\n");
    printf("QUEUE GAME \t\t: Command yang digunakan untuk mendaftarkan permainan ke dalam list.\n");
    printf("PLAY GAME \t\t: COmmand yang digunakan untuk memainkan sebuah permainan.\n");
    printf("SKIPGAME <n> \t\t: Command yang digunakan untuk melewatkan permainan sebanyak n.\n");
    printf("HELP \t\t\t: Bantuan command command yang ada.\n");
    printf("QUIT \t\t\t: Command untuk keluar dari program.\n");
}

void QUIT(){
    printf("Anda keluar dari game BNMO.\n");
    printf("Bye bye ...\n");
}