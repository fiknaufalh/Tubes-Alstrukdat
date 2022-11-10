#include "queueInt.h"
#include <stdio.h>
#include <string.h>

/* *** Kreator *** */
void CreateQueueInt(QueueInt *q){
    (*q).idxHead = IDX_UNDEF;
    (*q).idxTail = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmptyQInt(QueueInt q){
    return ((q).idxHead == IDX_UNDEF) && ((q).idxTail== IDX_UNDEF);
}

boolean isFullQInt(QueueInt q){
    return ((q).idxHead == ((q).idxTail + 1)% CAPACITY);
}

int lengthQInt(QueueInt q){
    if (isEmptyQInt(q)){
        return 0;
    }
    else{
        return (CAPACITY + (q).idxTail - (q).idxHead)%CAPACITY + 1;
    }
}

/* *** Primitif Add/Delete *** */
void enqueueQInt(QueueInt *q, int val){
    if (isEmptyQInt(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        TAIL(*q)=val;

    }
    else{
        IDX_TAIL(*q)=(IDX_TAIL(*q)+1)%CAPACITY;
        TAIL(*q)=val;
    }
    
}

void dequeueQInt(QueueInt *q, int *val){
    (*val)=(*q).buffer[(*q).idxHead];
    if ((*q).idxHead == (*q).idxTail){
        (*q).idxTail = IDX_UNDEF;
        (*q).idxHead = IDX_UNDEF;
    }
    else{
        IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
    }
}

/* *** Display QueueInt *** */
void displayQueueInt(QueueInt q){
    int temp;
    
    printf("[");
    int panjang = lengthQInt(q);

    if (panjang > 0) {
        printf("%d",HEAD(q));
        dequeueQInt(&q,&temp);
        for (int i = 1;i<panjang;i++) {
            printf(",%d",HEAD(q));
            dequeueQInt(&q,&temp);
        }
    }
    printf("]\n");
}