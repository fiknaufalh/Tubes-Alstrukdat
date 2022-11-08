#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "DinerDash.h"

void header1(Queue makan, Queue durasi, Queue tahan, Queue harga){
    printf("Daftar Pesanan\n");
    printf("Makanan | Durasi Memasak | Ketahanan | Harga\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i <length(makan); i++){
        if(harga.buffer[i] != 0){
            printf("   M%d   |       %d        |     %d     | %d  \n", makan.buffer[i], durasi.buffer[i], tahan.buffer[i], harga.buffer[i]);
        }
    }
}

void header2(Queue makan2, Queue durasi2){
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("Makanan | Sisa Durasi Memasak\n");
    printf("-----------------------------\n");
    if (isEmpty(makan2)){
        printf("        |               \n");
    }
    else{
        for(int i =0;i<length(makan2);i++){
            if (durasi2.buffer[i]>0 ){
                printf("  M%d   |       %d      \n",makan2.buffer[i],durasi2.buffer[i]);
            }
        }
        printf("       |               \n");
    }
}

void header3(Queue makan3, Queue tahan3){
    printf("Daftar makanan yang dapat disajikan\n");
    printf("Makanan | Sisa Ketahanan Memasak\n");
    printf("--------------------------------\n");
    if (isEmpty(makan3)){
        printf("        |               \n");
    }
    else{
        for(int i =0;i<length(makan3);i++){
            if (tahan3.buffer[i]>0){
                printf("  M%d   |       %d      \n",makan3.buffer[i],tahan3.buffer[i]);
            }
        }
        printf("       |               \n");
    }
}

void cook(Queue makan3,Queue tahan3,Queue *makan2,Queue *durasi2,Queue* tahan2, Queue *harga2, Queue makan, Queue durasi, Queue tahan,Queue harga,int n){
    boolean found = false;
    boolean found2 = false;
    for (int i = 0; i <length(*makan2); i++){
        if (makan.buffer[n]==(*makan2).buffer[i] && (*durasi2).buffer[i]>0){
            found = true;
        }
    }
    for (int i = 0; i <length(makan3); i++){
        if (makan.buffer[n]==(makan3).buffer[i] && (tahan3).buffer[i]>0){
            found2 = true;
        }
    }
    if (n>=0 && harga.buffer[n] != 0 && !found  && !found2 ){
        printf("berhasil memasak M%d\n",n);
        ElType val, val2, val3, val4;
        val=makan.buffer[n];
        val2=durasi.buffer[n]+1;
        val3=tahan.buffer[n]+1;
        val4=harga.buffer[n];
        enqueue(makan2,val);
        enqueue(durasi2,val2);
        enqueue(tahan2,val3);
        enqueue(harga2,val4);
    }
    else{
        printf("Tidak ada pesanan M%d\n",n);
    }
}

void printall(Queue makan, Queue durasi, Queue tahan, Queue harga, Queue makan2, Queue durasi2, Queue makan3, Queue tahan3){
    header1(makan,durasi,tahan,harga);
    printf("\n");
    header2(makan2,durasi2);
    printf("\n");
    header3(makan3,tahan3);
    printf("\n");
}

void adddaftar(Queue *makan, Queue *durasi, Queue *tahan, Queue *harga, ElType makanan){
    ElType ketahanan, price, memasak;
    price = rand()%(50000-10000+1)+10000;
    makanan++;
    memasak = rand()%5 + 1;
    ketahanan = rand()%5 + 1;
    enqueue(makan, makanan);
    enqueue(durasi, memasak);
    enqueue(tahan, ketahanan);
    enqueue(harga, price);
}

void decrementcook(Queue*makan2,Queue *durasi2,Queue *tahan2,Queue *harga2,Queue *makan3, Queue *durasi3, Queue * tahan3, Queue * harga3){
    if (!isEmpty(*durasi2)){
        for (int i=0; i<length(*durasi2);i++){
            (*durasi2).buffer[i]=(*durasi2).buffer[i]-1;
        }
    }
    for (int i=0; i<length(*durasi2);i++){
        if ((*durasi2).buffer[i]==0){
            int j =i;
            enqueue(tahan3,(*tahan2).buffer[i]);
            enqueue(makan3,(*makan2).buffer[i]);
            enqueue(durasi3,(*durasi2).buffer[i]+1);
            enqueue(harga3,(*harga2).buffer[i]);  
        }
    }
}

void decrementserve(Queue * makan3, Queue * tahan3){
    if (!isEmpty(*makan3)){
        for (int i=0; i<length(*makan3);i++){
            (*tahan3).buffer[i]=(*tahan3).buffer[i]-1;
        }
    }
}

void serve(Queue makan3, Queue * tahan3, Queue  harga3, Queue * skor, Queue makan, Queue * harga){
    ElType makanan;
    boolean found=false;
    for (int i =0; i<length(makan3);i++){
        if((*tahan3).buffer[i]>0){
            (*tahan3).buffer[i]=0;
            enqueue(skor,harga3.buffer[i]);
            makanan = makan3.buffer[i];
            printf("Berhasil menyajikan M%d\n",makan3.buffer[i]);
            found = true;
            break;
        }
    }
    if (!found){
        printf("Tidak ada makanan yang dapat disajikan\n");
    }
    for (int i =0; i<length(makan);i++){
        if ((makan).buffer[i]==makanan){
            (*harga).buffer[i]=0;
        }
    }
}

void totalskor(Queue skor){
    ElType total = 0;
    for (int i=0; i<length(skor);i++){
        total=total+ skor.buffer[i];
    }
    printf("Total skor anda adalah %d\n",total);
}

void DinerDash(){
    time_t t;
    srand((unsigned) time(&t));
    Queue makan, durasi, tahan, harga, makan2,durasi2,tahan2,harga2, makan3,durasi3, tahan3,harga3,skor;
    ElType makanan, memasak, ketahanan, price;
    makanan = 0;
    memasak = rand()%5 + 1;
    ketahanan = rand()%5 + 1;
    price = rand()% (50000-10000 + 1) + 10000;
    CreateQueue(&makan);
    CreateQueue(&durasi);
    CreateQueue(&tahan);
    CreateQueue(&harga);
    CreateQueue(&makan2);
    CreateQueue(&durasi2);
    CreateQueue(&tahan2);
    CreateQueue(&harga2);
    CreateQueue(&makan3);
    CreateQueue(&durasi3);
    CreateQueue(&tahan3);
    CreateQueue(&harga3);
    CreateQueue(&skor);
    for (int i = 0; i <3; i++){
        enqueue(&makan, makanan);
        makanan++;
        enqueue(&durasi, memasak);
        memasak = rand()%5 + 1;
        enqueue(&tahan, ketahanan);
        ketahanan = rand()%5 + 1;
        enqueue(&harga, price);
        price = rand()%(50000-10000+1)+10000;
    }
    makanan--;
    printf("Selamat Datang di Diner Dash!\n");
    printall( makan,  durasi,  tahan,  harga,  makan2,  durasi2,  makan3,  tahan3);

    /*BUAT TEST*/
    /*
    //1 KALI COOK
    cook( makan3, tahan3,&makan2,&durasi2,&tahan2, &harga2,  makan,  durasi,  tahan, harga,0);
    adddaftar(&makan,&durasi,&tahan,&harga,makanan);
    makanan++;
    decrementcook(&makan2,&durasi2,&tahan2,&harga2,&makan3, &durasi3, &tahan3, &harga3);
    decrementserve(&makan3,&tahan3);
    printall( makan,  durasi,  tahan,  harga,  makan2,  durasi2,  makan3,  tahan3);

    //1 KALI COOK
    cook( makan3, tahan3,&makan2,&durasi2,&tahan2, &harga2,  makan,  durasi,  tahan, harga,1);
    adddaftar(&makan,&durasi,&tahan,&harga,makanan);
    makanan++;
    decrementcook(&makan2,&durasi2,&tahan2,&harga2,&makan3, &durasi3, &tahan3, &harga3);
    decrementserve(&makan3,&tahan3);
    printall( makan,  durasi,  tahan,  harga,  makan2,  durasi2,  makan3,  tahan3);

    //1 KALI COOK
    cook( makan3, tahan3,&makan2,&durasi2,&tahan2, &harga2,  makan,  durasi,  tahan, harga,2);
    adddaftar(&makan,&durasi,&tahan,&harga,makanan);
    makanan++;
    decrementcook(&makan2,&durasi2,&tahan2,&harga2,&makan3, &durasi3, &tahan3, &harga3);
    decrementserve(&makan3,&tahan3);
    printall( makan,  durasi,  tahan,  harga,  makan2,  durasi2,  makan3,  tahan3);

    //1 KALI COOK
    cook( makan3, tahan3,&makan2,&durasi2,&tahan2, &harga2,  makan,  durasi,  tahan, harga,3);
    adddaftar(&makan,&durasi,&tahan,&harga,makanan);
    makanan++;
    decrementcook(&makan2,&durasi2,&tahan2,&harga2,&makan3, &durasi3, &tahan3, &harga3);
    decrementserve(&makan3,&tahan3);
    printall( makan,  durasi,  tahan,  harga,  makan2,  durasi2,  makan3,  tahan3);

    //1 KALI COOK
    cook( makan3, tahan3,&makan2,&durasi2,&tahan2, &harga2,  makan,  durasi,  tahan, harga,4);
    adddaftar(&makan,&durasi,&tahan,&harga,makanan);
    makanan++;
    decrementcook(&makan2,&durasi2,&tahan2,&harga2,&makan3, &durasi3, &tahan3, &harga3);
    decrementserve(&makan3,&tahan3);
    printall( makan,  durasi,  tahan,  harga,  makan2,  durasi2,  makan3,  tahan3);

    //1 KALI SERVE
    serve(makan3, &tahan3, harga3, &skor, makan, &harga);
    adddaftar(&makan,&durasi,&tahan,&harga,makanan);
    makanan++;
    decrementcook(&makan2,&durasi2,&tahan2,&harga2,&makan3, &durasi3, &tahan3, &harga3);
    decrementserve(&makan3,&tahan3);
    printall( makan,  durasi,  tahan,  harga,  makan2,  durasi2,  makan3,  tahan3);


    //1 KALI SKIP  
    adddaftar(&makan,&durasi,&tahan,&harga,makanan);
    makanan++;
    decrementcook(&makan2,&durasi2,&tahan2,&harga2,&makan3, &durasi3, &tahan3, &harga3);
    decrementserve(&makan3,&tahan3);
    printall( makan,  durasi,  tahan,  harga,  makan2,  durasi2,  makan3,  tahan3);

    //PRINT SKOR
    totalskor(skor);
    */
}