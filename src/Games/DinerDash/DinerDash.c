#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DinerDash.h"

void DinerDash(){
    time_t t;
    srand((unsigned) time(&t));
    QueueInt makan, durasi, tahan, harga, makan2,durasi2,tahan2,harga2, makan3,durasi3, tahan3,harga3,skor;
    int makanan, memasak, ketahanan, price;
    int n;
    makanan = 0;
    memasak = rand()%5 + 1;
    ketahanan = rand()%5 + 1;
    price = rand()% (50000-10000 + 1) + 10000;
    CreateQueueInt(&makan);
    CreateQueueInt(&durasi);
    CreateQueueInt(&tahan);
    CreateQueueInt(&harga);
    CreateQueueInt(&makan2);
    CreateQueueInt(&durasi2);
    CreateQueueInt(&tahan2);
    CreateQueueInt(&harga2);
    CreateQueueInt(&makan3);
    CreateQueueInt(&durasi3);
    CreateQueueInt(&tahan3);
    CreateQueueInt(&harga3);
    CreateQueueInt(&skor);
    for (int i = 0; i <3; i++){
        enqueueQInt(&makan, makanan);
        makanan++;
        enqueueQInt(&durasi, memasak);
        memasak = rand()%5 + 1;
        enqueueQInt(&tahan, ketahanan);
        ketahanan = rand()%5 + 1;
        enqueueQInt(&harga, price);
        price = rand()%(50000-10000+1)+10000;
    }
    makanan--;
    printf("Selamat Datang di Diner Dash!\n");
    printall( makan,  durasi,  tahan,  harga,  makan2,  durasi2,  makan3,  tahan3,skor);
    char* command;
    //Word currentCMD;
    while (!endgame(skor,harga)){
        int i =0;
        n=0;
        printf("Masukkan Command: ");
        STARTCOMMAND();
        command = WordToString(currentCMD);
        boolean check = false;
        ADVCOMMAND();
        if(!EndWord){
            i = 1;
            while(i<currentCMD.Length){
                if(currentCMD.TabWord[i] >= '0' && currentCMD.TabWord[i] <= '9'){
                    n *= 10;
                    n += (int)(currentCMD.TabWord[i]-48);
                }
                else{
                    check = true;
                }
                i++;
            }
            ADVCOMMAND();
        }
        if(EndWord && (!check)){
            if((command[0] == 'C' ) && (command[1] == 'O') && (command[2] == 'O') && (command[3] == 'K')){
                if (bisacook(harga,makan2,makan, makan3,  tahan3, durasi2, n)){
                cook(&makan2,&durasi2,&tahan2, &harga2,  makan,  durasi,  tahan, harga,n);
                adddaftar(&makan,&durasi,&tahan,&harga,makanan);
                makanan++;
                decrementcook(&makan2,&durasi2,&tahan2,&harga2,&makan3, &durasi3, &tahan3, &harga3);
                decrementserve(&makan3,&tahan3);
                printall( makan,  durasi,  tahan,  harga,  makan2,  durasi2,  makan3,  tahan3,skor);
                }
                else{
                    printf("Tidak ada pesanan M%d atau pesanan M%d sedang diproses\n",n,n);
                }
            }
            else if((command[0] == 'S') && (command[1] == 'E') && (command[2] == 'R') && (command[3] == 'V') && (command[4] == 'E')){
                if (bisaserve( makan3, tahan3)){
                    serve(makan3, &tahan3, harga3, &skor, makan, &harga);
                    adddaftar(&makan,&durasi,&tahan,&harga,makanan);
                    makanan++;
                    decrementcook(&makan2,&durasi2,&tahan2,&harga2,&makan3, &durasi3, &tahan3, &harga3);
                    decrementserve(&makan3,&tahan3);
                    printall( makan,  durasi,  tahan,  harga,  makan2,  durasi2,  makan3,  tahan3,skor);
                }
                else{
                    printf("Tidak ada makanan yang dapat disajikan\n");
                }
            }
            else if ((command[0] == 'S') && (command[1] == 'K') && (command[2] == 'I') && (command[3] == 'P')){
                adddaftar(&makan,&durasi,&tahan,&harga,makanan);
                makanan++;
                decrementcook(&makan2,&durasi2,&tahan2,&harga2,&makan3, &durasi3, &tahan3, &harga3);
                decrementserve(&makan3,&tahan3);
                printall( makan,  durasi,  tahan,  harga,  makan2,  durasi2,  makan3,  tahan3,skor);
            }
            else{
                printf("INVALID COMMAND\n");
            }
        }
        else{
            printf("INVALID COMMAND\n");
        }

    }
    printf("Game Over!\n");
    totalskor(skor);
}

void header1(QueueInt makan, QueueInt durasi, QueueInt tahan, QueueInt harga){
    printf("Daftar Pesanan\n");
    printf("Makanan | Durasi Memasak | Ketahanan | Harga\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i <lengthQInt(makan); i++){
        if(harga.buffer[i] != 0){
            printf("   M%d   |       %d        |     %d     | %d  \n", makan.buffer[i], durasi.buffer[i], tahan.buffer[i], harga.buffer[i]);
        }
    }
}

void header2(QueueInt makan2, QueueInt durasi2){
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("Makanan | Sisa Durasi Memasak\n");
    printf("-----------------------------\n");
    if (isEmptyQInt(makan2)){
        printf("        |               \n");
    }
    else{
        for(int i =0;i<lengthQInt(makan2);i++){
            if (durasi2.buffer[i]>0 ){
                printf("  M%d   |       %d      \n",makan2.buffer[i],durasi2.buffer[i]);
            }
        }
        printf("       |               \n");
    }
}

void header3(QueueInt makan3, QueueInt tahan3){
    printf("Daftar makanan yang dapat disajikan\n");
    printf("Makanan | Sisa Ketahanan Memasak\n");
    printf("--------------------------------\n");
    if (isEmptyQInt(makan3)){
        printf("        |               \n");
    }
    else{
        for(int i =0;i<lengthQInt(makan3);i++){
            if (tahan3.buffer[i]>0){
                printf("  M%d   |       %d      \n",makan3.buffer[i],tahan3.buffer[i]);
            }
        }
        printf("       |               \n");
    }
}

void cook(QueueInt *makan2,QueueInt *durasi2,QueueInt* tahan2, QueueInt *harga2, QueueInt makan, QueueInt durasi, QueueInt tahan,QueueInt harga,int n){
    printf("berhasil memasak M%d\n",n);
    int val, val2, val3, val4;
    val=makan.buffer[n];
    val2=durasi.buffer[n]+1;
    val3=tahan.buffer[n]+1;
    val4=harga.buffer[n];
    enqueueQInt(makan2,val);
    enqueueQInt(durasi2,val2);
    enqueueQInt(tahan2,val3);
    enqueueQInt(harga2,val4);
}

boolean bisacook(QueueInt harga,QueueInt makan2,QueueInt makan,QueueInt makan3, QueueInt tahan3,QueueInt durasi2,int n){
    boolean found = false;
    boolean found2 = false;
    int panjang=0;
    for (int i = 0; i <lengthQInt(makan2); i++){
        if (makan.buffer[n]==(makan2).buffer[i] && (durasi2).buffer[i]>0){
            found = true;
        }
    }
    for (int i = 0; i <lengthQInt(makan3); i++){
        if (makan.buffer[n]==(makan3).buffer[i] && (tahan3).buffer[i]>0){
            found2 = true;
        }
    }
    for(int i = 0; i <lengthQInt(makan2); i++){
        if((durasi2).buffer[i]>0){
            panjang++;
        }
    }
    return !found2 && !found && n>=0 && harga.buffer[n] != 0 && panjang<=5;
}

void printall(QueueInt makan, QueueInt durasi, QueueInt tahan, QueueInt harga, QueueInt makan2, QueueInt durasi2, QueueInt makan3, QueueInt tahan3, QueueInt skor){
    printf("=======================================================================================\n");
    printf("\n");
    totalskor(skor);
    printf("\n");
    header1(makan,durasi,tahan,harga);
    printf("\n");
    header2(makan2,durasi2);
    printf("\n");
    header3(makan3,tahan3);
    printf("\n");
}

void adddaftar(QueueInt *makan, QueueInt *durasi, QueueInt *tahan, QueueInt *harga, int makanan){
    int ketahanan, price, memasak;
    price = rand()%(50000-10000+1)+10000;
    makanan++;
    memasak = rand()%5 + 1;
    ketahanan = rand()%5 + 1;
    enqueueQInt(makan, makanan);
    enqueueQInt(durasi, memasak);
    enqueueQInt(tahan, ketahanan);
    enqueueQInt(harga, price);
}

void decrementcook(QueueInt*makan2,QueueInt *durasi2,QueueInt *tahan2,QueueInt *harga2,QueueInt *makan3, QueueInt *durasi3, QueueInt * tahan3, QueueInt * harga3){
    if (!isEmptyQInt(*durasi2)){
        for (int i=0; i<lengthQInt(*durasi2);i++){
            (*durasi2).buffer[i]=(*durasi2).buffer[i]-1;
        }
    }
    for (int i=0; i<lengthQInt(*durasi2);i++){
        if ((*durasi2).buffer[i]==0){
            int j =i;
            printf("Makanan M%d telah selesai dimasak\n",(*makan2).buffer[i]);
            enqueueQInt(tahan3,(*tahan2).buffer[i]);
            enqueueQInt(makan3,(*makan2).buffer[i]);
            enqueueQInt(durasi3,(*durasi2).buffer[i]+1);
            enqueueQInt(harga3,(*harga2).buffer[i]);  
        }
    }
}

void decrementserve(QueueInt * makan3, QueueInt * tahan3){
    if (!isEmptyQInt(*makan3)){
        for (int i=0; i<lengthQInt(*makan3);i++){
            (*tahan3).buffer[i]=(*tahan3).buffer[i]-1;
        }
    }
}

void serve(QueueInt makan3, QueueInt * tahan3, QueueInt  harga3, QueueInt * skor, QueueInt makan, QueueInt * harga){
    int makanan;
    for (int i =0; i<lengthQInt(makan3);i++){
        if((*tahan3).buffer[i]>0){
            (*tahan3).buffer[i]=0;
            enqueueQInt(skor,harga3.buffer[i]);
            makanan = makan3.buffer[i];
            printf("Berhasil menyajikan M%d\n",makan3.buffer[i]);
            break;
        }
    }
    
    for (int i =0; i<lengthQInt(makan);i++){
        if ((makan).buffer[i]==makanan){
            (*harga).buffer[i]=0;
        }
    }
}

boolean bisaserve(QueueInt makan3,QueueInt tahan3){
    boolean found=false;
    for (int i =0; i<lengthQInt(makan3);i++){
        if((tahan3).buffer[i]>0){
            found = true;
            break;
        }
    }
    return found;
}

void totalskor(QueueInt skor){
    int total = 0;
    for (int i=0; i<lengthQInt(skor);i++){
        total=total+ skor.buffer[i];
    }
    printf("Saldo: %d\n",total);
}

boolean endgame(QueueInt skor, QueueInt harga){
    int panjang=0;
    for (int i=0; i<lengthQInt(harga);i++){
        if (harga.buffer[i]>0){
            panjang++;
        }
    }
    return panjang>7 || lengthQInt(harga)>=15;
}