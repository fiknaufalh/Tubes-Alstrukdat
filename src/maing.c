#include "console.h"

int main(){
    Queue Q, Q2;
    CreateQueue(&Q);
    CreateQueue(&Q2);
    char *val = "RNG";
    char *val2 = "Diner Dash";
    char *val3 = "extra1";
    char *val4 = "riseWOMAN";
    char *val5 = "extra2";
    enqueue(&Q, val3);
    enqueue(&Q, val);
    enqueue(&Q2, val);
    enqueue(&Q2, val2);
    enqueue(&Q2, val3);
    enqueue(&Q,val4);
    enqueue(&Q, val2);
    enqueue(&Q2,val5);
    enqueue(&Q, val5);
    //PLAYGAME(Q,Q2);
    SKIPGAME(Q,Q2,4);
    return 0;
}
