#include "PLAYGAME.h"

int main(){
    Queue Q, Q2;
    CreateQueue(&Q);
    CreateQueue(&Q2);
    char *val = "RNG";
    char *val2 = "Diner Dash";
    char *val3 = "extra1";
    char *val4 = "riseWOMAN";
    enqueue(&Q, val);
    enqueue(&Q, val2);
    enqueue(&Q2, val);
    enqueue(&Q2, val2);
    enqueue(&Q2, val3);
    enqueue(&Q,val3);
    enqueue(&Q, val4);
    PLAYGAME(Q,Q2);
    return 0;
}