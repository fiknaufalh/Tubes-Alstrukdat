#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DinerDash.h"

int DinerDash(){
    time_t t;
    srand((unsigned) time(&t));
    QueueInt makan, durasi, tahan, harga; 
    QueueInt makan2,durasi2,tahan2,harga2;
    ArrayDinInt makan3,durasi3, tahan3,harga3;
    QueueInt skor;
    
    int makanan, memasak, ketahanan, price;
    int n; // pesanan ke-n (indeks pesanan)
    
    makanan = 0;
    memasak = rand() % 5 + 1;
    ketahanan = rand() % 5 + 1;
    price = rand() % (50000-10000 + 1) + 10000;

    CreateQueueInt(&makan);
    CreateQueueInt(&durasi);
    CreateQueueInt(&tahan);
    CreateQueueInt(&harga);

    CreateQueueInt(&makan2);
    CreateQueueInt(&durasi2);
    CreateQueueInt(&tahan2);
    CreateQueueInt(&harga2);
    
    makan3 = MakeArrayDin_AInt();
    durasi3 = MakeArrayDin_AInt();
    tahan3 = MakeArrayDin_AInt();
    harga3 = MakeArrayDin_AInt();
    
    CreateQueueInt(&skor);

    for (int i = 0; i < 3; i++){
        enqueueQInt(&makan, makanan);
        makanan++;
        enqueueQInt(&durasi, memasak);
        memasak = rand() % 5 + 1;
        enqueueQInt(&tahan, ketahanan);
        ketahanan = rand() % 5 + 1;
        enqueueQInt(&harga, price);
        price = rand() % (50000-10000+1) + 10000;
    }
    makanan--;
    printf("Selamat Datang di Diner Dash!\n");
    printall(makan, durasi, tahan, harga, makan2, durasi2, makan3, tahan3, skor);
    char* command;

    while (!endgame(skor,harga)){
        int i = 0;
        n = 0;
        printf("Masukkan Command: ");
        STARTCOMMAND();
        command = WordToString(currentCMD);
        boolean check = true;
        ADVCOMMAND();
        Word param2 = currentCMD;
        if(!EndWord){
            if (param2.TabWord[0] == 'M')
            {
                check = false;
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
        }
        if((EndWord && (!check) && (param2.Length > 1)) || (compareString(command,"SKIP") && EndWord)){
            if(compareString(command,"COOK")){
                if (bisacook(harga,makan2,makan, makan3,  tahan3, durasi2, n)){
                    cook(&makan2,&durasi2,&tahan2, &harga2, makan, durasi, tahan, harga,n);
                    adddaftar(&makan,&durasi,&tahan,&harga,makanan);
                    makanan++;
                    decrementcook(&makan2,&durasi2,&tahan2,&harga2,&makan3, &durasi3, &tahan3, &harga3);
                    decrementserve(&makan3,&tahan3);
                    printall(makan, durasi, tahan, harga, makan2, durasi2, makan3, tahan3, skor);
                }
                else{
                    printf("Tidak ada pesanan M%d dalam Daftar Pesanan\n\n",n);
                }
            }
            else if(compareString(command,"SERVE")){
                if (bisaserve(makan, makan3, tahan3, n)){
                    serve(&makan3, &tahan3, &harga3, &makan, &skor, n);
                    adddaftar(&makan,&durasi,&tahan,&harga,makanan);
                    makanan++;
                    decrementcook(&makan2,&durasi2,&tahan2,&harga2,&makan3, &durasi3, &tahan3, &harga3);
                    decrementserve(&makan3,&tahan3);
                    printall(makan, durasi, tahan, harga, makan2, durasi2, makan3, tahan3, skor);
                }
                else if (IsEmpty_AInt(makan3)){
                    printf("Tidak ada makanan yang dapat disajikan\n\n");
                }
                else {
                    printf("M%d belum dapat disajikan karena M%d belum selesai\n\n", n, HEAD(makan));
                }
            }
            else if (compareString(command,"SKIP")){
                adddaftar(&makan,&durasi,&tahan,&harga,makanan);
                makanan++;
                decrementcook(&makan2,&durasi2,&tahan2,&harga2,&makan3, &durasi3, &tahan3, &harga3);
                decrementserve(&makan3,&tahan3);
                printall( makan,  durasi,  tahan,  harga,  makan2,  durasi2,  makan3,  tahan3,skor);
            }
            else{
                printf("INVALID COMMAND\n\n");
            }
        }
        else{
            printf("INVALID COMMAND\n\n");
        }

    }
    printf("Game Over!\n");
    int score;
    totalskor(skor,&score);
    return score;

}

void header1(QueueInt makan, QueueInt durasi, QueueInt tahan, QueueInt harga){
    printf("Daftar Pesanan\n");
    printf("Makanan | Durasi Memasak | Ketahanan | Harga\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i <lengthQInt(makan); i++){
        if(harga.buffer[i] != 0){
            printf("   M%d   |       %d        |     %d     | %d  \n", makan.buffer[(makan.idxHead + i)%CAPACITY], durasi.buffer[(durasi.idxHead + i)%CAPACITY], tahan.buffer[(tahan.idxHead + i)%CAPACITY], harga.buffer[(harga.idxHead + i)%CAPACITY]);
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

void header3(ArrayDinInt makan3, ArrayDinInt tahan3){
    printf("Daftar makanan yang dapat disajikan\n");
    printf("Makanan | Sisa Ketahanan Memasak\n");
    printf("--------------------------------\n");
    if (IsEmpty_AInt(makan3)){
        printf("        |               \n");
    }
    else{
        for(int i = 0;i < Length_AInt(makan3); i++){
            if (tahan3.A[i]>0){
                printf("  M%d   |       %d      \n", makan3.A[i], tahan3.A[i]);
            }
        }
        printf("       |               \n");
    }
}

void cook(QueueInt *makan2,QueueInt *durasi2,QueueInt* tahan2, QueueInt *harga2, QueueInt makan, QueueInt durasi, QueueInt tahan,QueueInt harga,int n){
    printf("berhasil memasak M%d\n\n",n);
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

boolean bisacook(QueueInt harga, QueueInt makan2, QueueInt makan, ArrayDinInt makan3, ArrayDinInt tahan3, QueueInt durasi2, int n){
    boolean found = false;
    int panjang=0;

    int i = 0;
    while (i < lengthQInt(makan) && !found) {
        if (makan.buffer[i] == n) found = true;
        i++;
    }

    for(int i = 0; i <lengthQInt(makan2); i++){
        if((durasi2).buffer[i]>0){
            panjang++;
        }
    }
    return found && n>=0 && harga.buffer[n] != 0 && panjang<=5;
}

void printall(QueueInt makan, QueueInt durasi, QueueInt tahan, QueueInt harga, QueueInt makan2, QueueInt durasi2, ArrayDinInt makan3, ArrayDinInt tahan3, QueueInt skor){
    printf("=======================================================================================\n");
    printf("\n");
    int temp;
    totalskor(skor,&temp);
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

void decrementcook(QueueInt*makan2,QueueInt *durasi2,QueueInt *tahan2,QueueInt *harga2,ArrayDinInt *makan3, ArrayDinInt *durasi3, ArrayDinInt * tahan3, ArrayDinInt * harga3){
    if (!isEmptyQInt(*durasi2)){
        for (int i=0; i<lengthQInt(*durasi2);i++){
            (*durasi2).buffer[i]=(*durasi2).buffer[i]-1;
        }
    }
    for (int i=0; i<lengthQInt(*durasi2);i++){
        if ((*durasi2).buffer[i]==0){
            int j =i;
            printf("Makanan M%d telah selesai dimasak\n\n",(*makan2).buffer[i]);
            InsertLast_AInt(tahan3, tahan2->buffer[i]);
            InsertLast_AInt(makan3, makan2->buffer[i]);
            InsertLast_AInt(durasi3, durasi2->buffer[i]);
            InsertLast_AInt(harga3, harga2->buffer[i]);
        }
    }
}

void decrementserve(ArrayDinInt * makan3, ArrayDinInt * tahan3){
    if (!IsEmpty_AInt(*makan3)){
        for (int i=0; i<Length_AInt(*makan3);i++){
            tahan3->A[i]=tahan3->A[i]-1;
        }
    }
}

void serve(ArrayDinInt * makan3, ArrayDinInt * tahan3, ArrayDinInt * harga3, QueueInt * makan, QueueInt * skor, int n){
    // Serve : Enqueue harga makanan yang diserve, simpan indeks makanan yang diserve

    boolean found = false;
    int i = 0;
    int idx = -1;
    // Mencari indeks makanan yang di serve pada array daftar makanan yang dapat disajikan
    while (i < Length_AInt(*makan3) && !found)
    {
        if (makan3->A[i] == n && tahan3->A[i] > 0)
        {
            found = true;
            idx = i;
        } 
        i++;
    }
    int scoreGain = harga3->A[idx];
    enqueueQInt(skor, scoreGain);
    DeleteAt_AInt(harga3,idx);
    DeleteAt_AInt(tahan3,idx);
    DeleteAt_AInt(makan3,idx);
    int val;
    dequeueQInt(makan,&val);
    printf("Berhasil menyajikan M%d\n\n",val);
}

boolean bisaserve(QueueInt makan, ArrayDinInt makan3, ArrayDinInt tahan3, int n){
    /* Pesanan ke-n bisa di-serve jika terdapat dalam list makanan yang dapat disajikan
       dan merupakan urutan pertama pada list daftar pesanan */ 
    
    boolean found = false;
    int i = 0;
    while (i < Length_AInt(makan3) && !found)
    {
        if (makan3.A[i] == n && tahan3.A[i] > 0) found = true;
        i++;
    }

    return (found && HEAD(makan) == n);
}

void totalskor(QueueInt skor, int *score){
    int total = 0;
    for (int i=0; i<lengthQInt(skor);i++){
        total=total+ skor.buffer[i];
    }
    printf("Saldo: %d\n",total);
    (*score) = total;
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
