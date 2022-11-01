#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "PLAYGAME.h"

void PLAYGAME(Queue q, Queue q2){
    time_t t;
    int input;
    boolean status = true;
    srand((unsigned) time(&t));
    printf("Berikut adalah daftar Game-mu\n");
    displayQueue(q);
    while (status){
        printf("ENTER GAME:");
        scanf("%d", &input);
        if (input <= 0 || input>length(q)){
            printf("masukkan salah, silahkan ulangi kembali\n");
        }
        else{
            for (int i=0; i<length(q2);i++){
                if ((q.buffer[input-1]==q2.buffer[i]) && q2.buffer[i]=="RNG" ){
                    printf("Loading %s ...\n", q.buffer[input-1]);
                    //RNG() 
                    status = false;
                }
                else if ((q.buffer[input-1]==q2.buffer[i]) && q2.buffer[i]=="Diner Dash" ){
                    printf("Loading %s ...\n", q.buffer[input-1]);
                    //DinerDash
                    status = false;
                }
                else if (q.buffer[input-1]==q2.buffer[i]){
                    printf("Loading %s ...\n", q.buffer[input-1]);
                    printf("%d\n", rand());
                    status = false;
                }
            }
            if (status){
                printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n", q.buffer[input-1]);
            }
        }
    }
}