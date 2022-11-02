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

void STARTBNMO(ArrayDin* GamesList){}

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