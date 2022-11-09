#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "PLAYGAME.h"

void PLAYGAME(Queue *q, Queue q2, Queue *history){
    if(!isEmpty(*q)){
        time_t t;
        boolean status = true;
        srand((unsigned) time(&t));
        printf("Berikut adalah daftar Game-mu\n");
        int j =0;
        int a = length(*q);
        for(int i=0; i<a; i++){
            printf("%d. %s\n",(j+1),(*q).buffer[i]);
            j++;
        }
        int i =0;
        while(i<length(q2) && status){
            if ((HEAD(*q)==q2.buffer[i])){
                if (i>1){
                    printf("Loading %s ...\n", HEAD(*q));
                    printf("%d\n", rand());
                    status = false;
                    break;
                }
                else if (i==1){
                    printf("Loading %s ...\n", HEAD(*q));
                    printf("diner\n"); // MANGGIL DINER
                    status = false;
                    break;
                }
                else if (i==0 ){
                    printf("Loading %s ...\n", HEAD(*q));
                    printf("rng\n"); //MANGGIL RNG
                    status = false;
                    break;
                }
            }
            i++;
        }
        if (status){
            printf("Game %s masih dalam maintenance, belum dapat dimainkan.\n", HEAD(*q));
        }
        ElType val;
        dequeue(q,&val);
        enqueue(history,val);
    }
    else{
        printf("Anda belum men-queue game apapun!\n");
    } 
}
