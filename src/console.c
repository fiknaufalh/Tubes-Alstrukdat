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
    CopyWord();
    char *string = NULL;

    string = malloc(CWord.Length * sizeof(char));
    int i = 0;
    while (i < CWord.Length)
    {
        *(string+ i) = CWord.TabWord[i];
        i++;
    }
    return string;
}

void STARTBNMO(ArrayDin* GamesList)
{
    printf("%d\n",IsEmpty(*GamesList));
    STARTWORD("./data/config.txt");
    printf("%d\n",IsEmpty(*GamesList));
    Word FirstWord = currentWord;
    // for(int i = 0;i < FirstWord.Length;i++)
    // {
    //     printf("%c",FirstWord.TabWord[i]);
    // }

    int TotalGame = WordToInt(FirstWord);
    printf("%d",TotalGame);
    char *Game;

    for(int i = 0; i < TotalGame; i++)
    {
        ADVWORD();
        Game = WordToString(currentWord);
        InsertLast(GamesList,Game);
    }
    if(!IsEmpty(*GamesList))
    {
        printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.");
    }
    else
    {
        printf("tes");
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