#include "queue.h"
#include <stdio.h>
#include <string.h>

/* *** Kreator *** */
void CreateQueue(Queue *q){
    (*q).idxHead = IDX_UNDEF;
    (*q).idxTail = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmpty(Queue q){
    return ((q).idxHead == IDX_UNDEF) && ((q).idxTail== IDX_UNDEF);
}

boolean isFull(Queue q){
    return ((q).idxHead == ((q).idxTail + 1)% CAPACITY);
}

int length(Queue q){
    if (isEmpty(q)){
        return 0;
    }
    else{
        return (CAPACITY + (q).idxTail - (q).idxHead)%CAPACITY + 1;
    }
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val){
    if (isEmpty(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        TAIL(*q)=val;

    }
    else{
        IDX_TAIL(*q)=(IDX_TAIL(*q)+1)%CAPACITY;
        TAIL(*q)=val;
    }
    
}

void dequeue(Queue *q, ElType *val){
    (*val)=(*q).buffer[(*q).idxHead];
    if ((*q).idxHead == (*q).idxTail){
        (*q).idxTail = IDX_UNDEF;
        (*q).idxHead = IDX_UNDEF;
    }
    else{
        IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
    }
}

/* *** Display Queue *** */
void displayQueue(Queue q){
    ElType temp;
    
    printf("[");
    int panjang = length(q);

    if (panjang > 0) {
        printf("%s",HEAD(q));
        dequeue(&q,&temp);
        for (int i = 1;i<panjang;i++) {
            printf(",%s",HEAD(q));
            dequeue(&q,&temp);
        }
    }
    printf("]\n");
}