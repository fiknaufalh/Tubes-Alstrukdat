# include "queueInt.h"
# include <stdio.h>

int main()
{
    QueueInt Q;

    // Alokasi queue
    CreateQueueInt(&Q);

    // Cek apakah queue kosong
    if (isEmptyQInt(Q))
    {
        printf("Queue kosong\n");
    }
    else
    {
        printf("Queue tidak kosong\n");
    }

    // Cek panjang queue
    printf("Panjang QueueInt : %d\n", lengthQInt(Q)); // 0
    printf("Display QueueInt : ");
    displayQueueInt(Q);

    // Isi queue
    enqueueQInt(&Q, 1);
    enqueueQInt(&Q, 2);
    enqueueQInt(&Q, 3);
    enqueueQInt(&Q, 4);
    displayQueueInt(Q);

    // Cek apakah queue kosong setelah di enqueue
    if (isEmptyQInt(Q))
    {
        printf("Queue kosong\n");
    }
    else
    {
        printf("Queue tidak kosong\n");
    }

    // Isi queue sampai full
    for(int i = 5; i < 101; i++)
    {
        enqueueQInt(&Q, i);
    }

    printf("Panjang QueueInt : %d\n", lengthQInt(Q)); // 100

    // Cek apakah queue penuh
    if (isFullQInt(Q))
    {
        printf("Queue penuh\n");
    }
    else
    {
        printf("Queue tidak penuh\n");
    }

    printf("Display QueueInt : ");
    displayQueueInt(Q);

    // Cek dequeue
    int val;
    dequeueQInt(&Q, &val);
    printf("val : %d\n", val); // 1
    dequeueQInt(&Q, &val);
    printf("val : %d\n", val); // 2

    printf("Panjang QueueInt : %d\n", lengthQInt(Q)); // 98


}