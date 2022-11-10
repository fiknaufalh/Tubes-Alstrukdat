#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "console.h"
#include "Games/DinerDash/DinerDash.h"
#include "Games/RNG/RNG.h"

boolean compareString(char *str1, char *str2)
{
    boolean IsSame = (*str1 == *str2);
    while ((*str1 != '\0' && *str2 != '\0') && IsSame)
    {
        str1++; str2++;
        IsSame = (*str1 == *str2);
    }
    return IsSame;
}

int WordToInt(Word CWord)
{
    int result = 0;
    for(int i = 0; i < CWord.Length;i++)
    {
        result = result*10 + (CWord.TabWord[i] - '0');
    }  
    return result;
}

char *WordToString(Word CWord)
{
    char *string;

    string = malloc(CWord.Length * sizeof(char));
    int i = 0;
    while (i < CWord.Length)
    {
        *(string + i) = CWord.TabWord[i];
        i++;
    }
    string[i] = '\0';
    return string;
}

int stringLength(char* string)
{
    int length = 0;
    while (*string != '\0')
    {
        length++;
        string++;
    }
    return length;
}

void stringConcat(char *s1,char *s2,char *sout)
{
    int len,i;

    len=stringLength(s1);
    for(i = 0; i < len;i++)
    {
        sout[i] = s1[i];
    }
    for(i = 0; i < stringLength(s2); i++)
    {
        sout[len+i]=s2[i];
    }
    sout[len+i]='\0';
}

void STARTBNMO(ArrayDin *GamesList)
{
    STARTWORD("./data/config.txt");
    
    int TotalGame = WordToInt(currentWord);
    int i = 1;
    ADVLine();
    while(i <= TotalGame)
    {
        char *line;
        line = WordToString(currentWord);
        InsertLast(GamesList,line);
        ADVLine();
        i++;
    }
    if(!IsEmpty(*GamesList))
    {
        printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
    }
}

void LOADBNMO(ArrayDin* GamesList, char* filename)
{
    char path[50];
    stringConcat("./data/",filename,path);
    FILE *fp = fopen(path,"r");
    if(fp !=NULL)
    {
        fclose(fp);
        STARTWORD(path);
        int TotalGame = WordToInt(currentWord);
        int i = 1;
        ADVLine();
        while(i <= TotalGame)
        {
            char *line;
            line = WordToString(currentWord);
            InsertLast(GamesList,line);
            ADVLine();
            i++;
        }
        if(!IsEmpty(*GamesList))
        {
            printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
        }
    }
    else
    {
        fclose(fp);
        printf("File tidak exist\n");
    }
}

void SAVEBNMO(ArrayDin* GamesList, char* filename)
{
    FILE * fp;
    char path[50];

    stringConcat("./data/",filename,path);
    fp = fopen (path,"w+");
    fprintf(fp,"%d",Length(*GamesList));
    for(int i = 0; i < Length(*GamesList);i++)
    {
        fprintf(fp,"\n%s",(*GamesList).A[i]);
    }
    fclose(fp);

    fp = fopen(path, "r");
    if (fp != NULL)
    {
        printf("Save file berhasil disimpan.\n");
        fclose(fp);
    }
}

void CREATEGAME(ArrayDin* GamesList)
{
    printf("Masukkan nama game yang akan ditambahkan: ");
    STARTCOMMANDGAME();
    // printf("%s",currentCMD);
    char* gameName = WordToString(currentCMD);
    InsertLast(GamesList,gameName);
    // PrintArrayDin(*GamesList);
}

void LISTGAME (ArrayDin GameList) {
    IdxType i;
    printf("Berikut adalah daftar game yang tersedia\n");
    printf("%d. %s",1, GameList.A[0]);
    for (i=1; i<Length(GameList); i++) {
        printf("\n%d. %s",(i+1), GameList.A[i]);
    }
    printf("\n");
}

void DELETEGAME (ArrayDin *GameList, Queue Q) {
    LISTGAME(*GameList);
    printf("\n");
    printf("Masukkan nomor game yang akan dihapus: ");
    STARTCOMMAND();
    printf("\n");
    int input;
    input = WordToInt(currentCMD);
    if (input<1 || input==1 || input==2 || input==3 || input==4 || input==5 || input>(*GameList).Neff) {
        printf("Game gagal dihapus");
    } else {
        boolean found;
        found = false;
        int j;
        j = 0;
        while (j<length(Q)) {
            if (Q.buffer[j]==(*GameList).A[input-1]) {
                found = true;
                break;
            } j++;
        }
        if (found) {
            printf("Game gagal dihapus");
        } else {
            int i;
            i = input-1;
            while (i<(*GameList).Neff) {
                (*GameList).A[i] = (*GameList).A[i+1];
                i++;  
            } 
            (*GameList).Neff--;
            printf("Game berhasil dihapus");
        }
    }
    printf("\n");
}

void QUEUEGAME (Queue *Q, ArrayDin GameList) {
    // displayQueue(*Q);
    printf("Berikut adalah daftar antrian game-mu\n");
    if (isEmpty(*Q)) {
        printf("Daftar antrian game-mu kosong, silahkan tambahkan game ke antrian.\n");
    } else {
        int i;
        for (i=0; i<length(*Q); i++) {
            printf("%d. %s\n", (i+1), (*Q).buffer[i]);
        }
    }
    printf("\n");
    LISTGAME(GameList);
    int input;
    printf("Nomor Game yang mau ditambahkan ke antrian: ");
    STARTCOMMAND();
    input = WordToInt(currentCMD);
    printf("\n");
    if (input>0 && input<=Length(GameList)) {
        enqueue(Q, GameList.A[input-1]);
        printf("Game berhasil ditambahkan ke dalam daftar antrian.\n");
        // displayQueue(*Q);
    } else {
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
    }
}

void PLAYGAME(Queue *q, ArrayDin GameList, Queue *history){
    if(!isEmpty(*q)){
        time_t t;
        boolean status = true;
        srand((unsigned) time(&t));
        
        // Menampilkan daftar game
        printf("Berikut adalah daftar Game-mu\n");
        int j =0;
        int a = length(*q);
        for(int i=0; i<a; i++){
            printf("%d. %s\n",(j+1),(*q).buffer[i]);
            j++;
        }
        
        int i = 0;
        while(i < Length(GameList) && status){
            if ((HEAD(*q) == GameList.A[i])){
                if (i>1){
                    printf("Loading %s ...\n", HEAD(*q));
                    printf("%d\n", rand());
                    status = false;
                    break;
                }
                else if (i==1){
                    printf("Loading %s ...\n", HEAD(*q));
                    DinerDash();
                    status = false;
                    break;
                }
                else if (i==0 ){
                    printf("Loading %s ...\n", HEAD(*q));
                    RNG();
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

void SKIPGAME(Queue *q, ArrayDin GameList, Queue *history, int input){    
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
            while(i<Length(GameList) && status){
                if (((*q).buffer[input]==GameList.A[i])){
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

void HELP(){
    printf("--------------------------------------------HELP--------------------------------------------");
    printf("\n");
    printf("START \t\t\t: Command yang membaca file konfigurasi untuk menjalankan BNMO.\n");
    printf("LOAD <filename> \t: Command yang membaca save file <filename> yang berisi list game yang dapat dimainkan, histori, dan scoreboard game.\n");
    printf("SAVE <filename> \t: Command yang digunakan untuk menyimpan state game pemain saat ini ke dalam suatu file.\n");
    printf("CREATE GAME \t\t: Command yang digunakan untuk menambahkan game baru pada daftar game.\n");
    printf("LIST GAME \t\t: Command yang digunakan untuk menampilkan daftar game yang disediakan oleh sistem.\n");
    printf("DELETE GAME \t\t: Command yang digunakan untuk menghapus sebuah game dari daftar game.\n");
    printf("QUEUE GAME \t\t: Command yang digunakan untuk mendaftarkan permainan ke dalam list.\n");
    printf("PLAY GAME \t\t: COmmand yang digunakan untuk memainkan sebuah permainan.\n");
    printf("SKIP GAME <n> \t\t: Command yang digunakan untuk melewatkan permainan sebanyak n.\n");
    printf("HELP \t\t\t: Bantuan command command yang ada.\n");
    printf("QUIT \t\t\t: Command untuk keluar dari program.\n");
}

void QUIT(Queue *Q){
    while (!isEmpty(*Q)){
        ElType val;
        dequeue(Q,&val);
    }
    printf("Anda keluar dari game BNMO.\n");
    printf("Bye bye ...");
}

void OTHERCMD(){
    printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
}
