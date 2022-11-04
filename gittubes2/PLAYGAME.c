#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "PLAYGAME.h"

void PLAYGAME(Queue q, Queue q2, Queue history){
    time_t t;
    boolean status = true;
    srand((unsigned) time(&t));
    printf("Berikut adalah daftar Game-mu\n");
    int j =0;
    int a = length(q);
    for(a;a>0;a--){
        printf("%d. %s\n",(j+1),q.buffer[a-1]);
        j++;
    }
    int i =0;
    while(i<length(q2) && status){
        if ((TAIL(q)==q2.buffer[i])){
            if (i>1){
                printf("Loading %s ...\n", TAIL(q));
                printf("%d\n", rand());
                status = false;
                break;
            }
            else if (i==1){
                printf("Loading %s ...\n", TAIL(q));
                printf("diner");
                status = false;
                break;
            }
            else if (i==0 ){
                printf("Loading %s ...\n", TAIL(q));
                printf("rng");
                status = false;
                break;
            }
        }
        i++;
    }
    if (status){
            printf("Game %s masih dalam maintenance, belum dapat dimainkan.\n", TAIL(q));
    }
    ElType val;
    dequeue(&q,&val);
    enqueue(&history,val);
    printf("Berikut adalah daftar Game-mu\n");
        j =0;
        a = length(q);
        for(a;a>0;a--){
            printf("%d. %s\n",(j+1),q.buffer[a-1]);
            j++;
        }
}
