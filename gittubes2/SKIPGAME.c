#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "SKIPGAME.h"
void SKIPGAME(Queue q, Queue q2, Queue history, int input){    
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
    if (input+1 <= 0 || input+1>length(q)){
            printf("Tidak ada permainan lagi dalam daftar game-mu atau input < 0.\n");
    }
    else{
        int i =0;
        while(i<length(q2) && status){
            if ((q.buffer[input]==q2.buffer[i])){
                if (i>1){
                    printf("Loading %s ...\n", q.buffer[length(q) - input-1]);
                    printf("%d\n", rand());
                    status = false;
                    break;
                }
                else if (i==1){
                    printf("Loading %s ...\n", q.buffer[length(q) - input-1]);
                    printf("diner");
                    status = false;
                    break;
                }
                else if (i==0 ){
                    printf("Loading %s ...\n", q.buffer[length(q) - input-1]);
                    printf("rng");
                    status = false;
                    break;
                }
            }
            i++;
        }
        if (status){
            printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n", q.buffer[ length(q) - input-1]);
        }
        ElType val;
        i=0;
        while (i<input+1){
            dequeue(&q,&val);
            enqueue(&history, val);
            i++;
        }
        
    }
}
