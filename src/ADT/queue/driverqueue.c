# include "queue.h"
# include <stdio.h>

int main()
{
    Queue q;

    /* *** Create Queue *** */
    CreateQueue(&q);

    /* *** IsEmpty Queue *** */
    printf("IsEmpty Queue: %d\n", isEmpty(q)); // 1 (true)

    /* *** IsFull Queue *** */
    printf("IsFull Queue: %d\n", isFull(q)); // 0 (false)

    /* *** Enqueue Queue *** */
    enqueue(&q, "Praktikum");
    enqueue(&q, "Tubes");
    enqueue(&q, "Tucil");
    enqueue(&q, "Tu");
    enqueue(&q, "X");
    
    /* *** Display Queue *** */
    displayQueue(q); // [Praktikum, Tubes, Tucil, Tu, X]
    /* *** Dequeue Queue *** */
    char *temp;
    dequeue(&q, &temp);
    printf("Dequeue: %s\n", temp); // Dequeue: Praktikum
    displayQueue(q); // [Tubes,Tucil,Tu,X]

    /* *** Length Queue *** */
    printf("Length Queue: %d\n", length(q)); // 4

    /* *** IsEmpty Queue *** */
    printf("IsEmpty Queue: %d\n", isEmpty(q)); // 0 (false)

    /* *** IsFull Queue *** */
    for (int i = 0; i < 96; i++)
    {
        enqueue(&q, "test");
    }
    printf("IsFull Queue: %d\n", isFull(q)); // 1 (true)
    printf("Length Queue: %d\n", length(q)); // 100
    displayQueue(q); // [Tubes,Tucil,Tu,X,test,test,...,test]
    return 0;
}