#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "SKIPGAME.h"
void SKIPGAME(Queue *q, Queue q2, Queue *history, int input){    
    if (!isEmpty(*q)){
        time_t t;
        boolean status = true;
        srand((unsigned) time(&t));
        printf("Berikut adalah daftar Game-mu\n");
        displayQueue(*q);
        int a = length(*q);
        int j =0;
        a = length(*q);
        for(int i=0;i<a;i++){
            printf("%d. %s\n",(j+1),(*q).buffer[i]);
            j++;
        }
        if (input+1 <= 0 || input+1>length(*q)){
                printf("Tidak ada permainan lagi dalam daftar game-mu atau input < 0.\n");
        }
        else{
            int i =0;
            while(i<length(q2) && status){
                if (((*q).buffer[input]==q2.buffer[i])){
                    if (i>1){
                        printf("Loading %s ...\n", (*q).buffer[input]);
                        printf("%d\n", rand());
                        status = false;
                        break;
                    }
                    else if (i==1){
                        printf("Loading %s ...\n", (*q).buffer[input]);
                        printf("diner\n"); //MANGGIL DINER
                        status = false;
                        break;
                    }
                    else if (i==0 ){
                        printf("Loading %s ...\n", (*q).buffer[input]);
                        printf("rng\n"); //MANGGIL RNG
                        status = false;
                        break;
                    }
                }
                i++;
            }
            if (status){
                printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n", (*q).buffer[ input]);
            }
            
        }
        ElType val;
        int i=0;
        if (input+1<length(*q) && input>=0){
            while (i<input+1){
                dequeue(q,&val);
                enqueue(history, val);
                i++;
            }
        }
        else if (input+1>length(*q)){
            int panjang = length(*q);
            while (i<panjang){
                dequeue(q,&val);
                enqueue(history, val);
                i++;
            }
        }
    }
    else{
        printf("Anda belum men-queue game apapun!\n");
    }
}
