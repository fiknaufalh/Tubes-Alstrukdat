#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "console.h"
#include "Games/games.h"


void STARTBNMO(ArrayDin *GamesList, ArrMap* ScoreBoard)
{
    STARTWORD("./data/config.txt");
    EndWord = true;
    int TotalGame = WordToInt(currentWord);
    int i = 0;
    ADVLine();
    while(i < TotalGame)
    {
        char *line;
        line = WordToString(currentWord);
        InsertLast(GamesList,line);
        Map SB;
        CreateScoreBoard(&SB);
        SB.MapName = line;
        SetElArrMap(ScoreBoard,i,SB);
        ADVLine();
        i++;
    }
    if(!IsEmpty(*GamesList))
    {
        printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
    }
}

void LOADBNMO(ArrayDin* GamesList, Stack* GamesHistory, char* filename, ArrMap* Scoreboard)
{
    char path[50];
    stringConcat("./data/",filename,path);
    FILE *fp = fopen(path,"r");
    if(fp !=NULL)
    {
        fclose(fp);
        STARTWORD(path);
        // List Game
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

        // History
        int TotalHistory = WordToInt(currentWord);
        i = 1;
        ADVLine();
        while(i <= TotalHistory)
        {
            char *line;
            line = WordToString(currentWord);
            Push(GamesHistory,line);
            ADVLine();
            i++;
        }
        ReverseStack(GamesHistory);

        // Scoreboard
        i = 0;
        while(i < TotalGame)
        {
            int TotalScore = WordToInt(currentWord);
            int j = 1;
            Map SB;
            CreateScoreBoard(&SB);
            while(j <= TotalScore)
            {
                char *playername;

                IgnoreEnter();
                ADVWORD();
                playername = WordToString(currentWord);
                ADVWORD();
                int score = WordToInt(currentWord);
                InsertSB(&SB,playername,score);
                j++;
            }
            char *MapName;
            MapName = Get(*GamesList,i);
            SB.MapName = MapName;
            SetElArrMap(Scoreboard,i,SB);
            ADVLine();
            i++;
        }

        if(!IsEmpty(*GamesList) && !IsStackEmpty(*GamesHistory) && !IsEmptyArrMap(*Scoreboard))
        {
            printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
        }
        EndWord = true;
    }
    else
    {
        fclose(fp);
        printf("File tidak exist\n");
    }
}

void SAVEBNMO(ArrayDin GamesList, char* filename, Stack GamesHistory, ArrMap Scoreboard)
{
    FILE * fp;
    char path[50];

    stringConcat("./data/",filename,path);
    fp = fopen (path,"w+");

    // List Game
    fprintf(fp,"%d",Length(GamesList));
    for(int i = 0; i < Length(GamesList);i++)
    {
        fprintf(fp,"\n%s",(GamesList).A[i]);
    }

    // History
    int countHistory = Top(GamesHistory) + 1;
    char* val;
    fprintf(fp,"\n%d",countHistory);
    for(int i = 0; i < countHistory;i++)
    {
        Pop(&GamesHistory,&val);
        fprintf(fp,"\n%s",val);
    }

    // Scoreboard
    for(int i = 0; i < NbElmtArrMap(Scoreboard);i++)
    {
        Map SB = GetElmtArrMap(Scoreboard,i);
        int maplength = SB.Count;
        fprintf(fp,"\n%d", maplength);
        for(int j = 0; j < maplength ;j++)
        {
            fprintf(fp,"\n%s %d",SB.Elements[j].Key, SB.Elements[j].Value);
        }
    }

    if (fp != NULL)
    {
        printf("Save file berhasil disimpan.\n");
        fclose(fp);
    }
}

void CREATEGAME(ArrayDin* GamesList, ArrMap* ScoreBoard)
{
    printf("Masukkan nama game yang akan ditambahkan: ");
    STARTCOMMANDLINE();
    char* gameName = WordToString(currentCMD);
    if (SearchArrayDin(*GamesList,gameName) == -1)
    {
        InsertLast(GamesList, gameName);
        Map SB;
        CreateScoreBoard(&SB);
        SB.MapName = gameName;
        SetElArrMap(ScoreBoard, NbElmtArrMap(*ScoreBoard), SB);
        printf("Game %s berhasil ditambahkan.\n",gameName);
    }
    else
    {
        printf("Game %s sudah ada.\n",gameName);
    }
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

void DELETEGAME (ArrayDin *GameList, Queue Q, ArrMap* ScoreBoard, Stack* GamesHistory) {
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

            // Hapus game dari History
            Stack temp;
            CreateEmptyStack(&temp);
            int stacklength = (*GamesHistory).TOP + 1;
            for (int j = 0;j < stacklength;j++)
            {
                char *val;
                
                Pop(GamesHistory,&val);
                if (!(compareString(val,(*GameList).A[i])))
                {
                    Push(&temp,val);
                }
            }
            ReverseStack(&temp);
            (*GamesHistory) = temp;

            // Hapus game dari scoreboard & listgame
            while (i<(*GameList).Neff) {
                (*GameList).A[i] = (*GameList).A[i+1];
                (*ScoreBoard).TMap[i] = (*ScoreBoard).TMap[i+1];
                i++;  
            } 
            (*GameList).Neff--;
            (*ScoreBoard).Neff--;
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

void PLAYGAME(Queue *q, ArrayDin GameList, Stack *history, ArrMap *arrSB){
    if(!isEmpty(*q)){
        time_t t;
        boolean status = true;
        srand((unsigned) time(&t));
        
        // Menampilkan daftar game
        printf("Berikut adalah daftar Game-mu\n");
        int a;
        for(a = 0; a < length(*q); a++){
            printf("%d. %s\n",(a+1),(*q).buffer[(a+(q->idxHead))%CAPACITY]);
        }
        int i;
        i = 0;
        int score;
        char* playername;
        while(i < Length(GameList) && status){
            if ((HEAD(*q) == GameList.A[i])){
                if (i > 4){
                    printf("\nLoading %s ...\n", HEAD(*q));
                    printf("Game over! \nFinal Score : ");
                    score  = rand();
                    printf("%d\n", score);
                    status = false;
                    // break;
                }
                else if (i == 4){
                    printf("\nLoading %s ...\n", HEAD(*q));
                    score = SoM();
                    status = false;
                    // break;
                }
                else if (i == 3){
                    printf("\nLoading %s ...\n", HEAD(*q));
                    score = ToH();
                    status = false;
                    // break;
                }
                else if (i == 2){
                    printf("\nLoading %s ...\n", HEAD(*q));
                    score = HANGMAN();
                    status = false;
                    // break;
                }
                else if (i == 1){
                    printf("\nLoading %s ...\n", HEAD(*q));
                    score = DinerDash();
                    status = false;
                    // break;
                }
                else if (i == 0){
                    printf("\nLoading %s ...\n", HEAD(*q));
                    score = RNG();
                    status = false;
                    // break;
                } 
                else {
                    printf("\nGame %s masih dalam maintenance, belum dapat dimainkan.\n", HEAD(*q));
                    status = false;
                } 
            }
            i++;
        }
        Map SB;
        SB = GetElmtArrMap(*arrSB, i-1);
        printf("Masukan nama player : ");
        STARTCOMMAND();
        playername = WordToString(currentCMD);
        ADVCOMMAND();

        while (!EndWord || IsMemberSB(SB,playername))
        {   printf("Nama tidak valid! Silahkan input ulang nama player.\n");
            printf("Masukan nama player : ");
            STARTCOMMAND();
            playername = WordToString(currentCMD);
            ADVCOMMAND();
        }

        InsertSortedDesc(&SB,playername,score);
        SetElArrMap(arrSB, i-1, SB);
        (*arrSB).Neff--;
        ElType val;
        dequeue(q,&val);
        Push(history,val);
    }
    else{
        printf("Tidak ada game dalam antrian permainan Anda!\n");
    } 
}

void SKIPGAME(Queue *q, ArrayDin GameList, Stack *history, int input, ArrMap *arrSB){    
    if (!isEmpty(*q)){
        ElType val;
        int i = 0;
        if (input+1 <= length(*q) && input >= 0){
            while (i < input){
                dequeue(q,&val);
                Push(history,val);
                i++;
            }
        }
        else if (input+1 >= length(*q)){
            int panjang = length(*q);
            while (i < panjang){
                dequeue(q,&val);
                Push(history,val);
                i++;
            }
        }
        PLAYGAME(q,GameList,history,arrSB);
    } else {
        printf("Tidak ada permainan lagi dalam daftar game-mu\n");
    }
}

void HELP(){
    printf("--------------------------------------------HELP--------------------------------------------");
    printf("\n");
    printf("START \t\t\t: Command yang membaca file konfigurasi untuk menjalankan BNMO.\n");
    printf("LOAD <filename> \t: Command yang membaca save file <filename> yang berisi list game yang dapat dimainkan, history, dan scoreboard game.\n");
    printf("SAVE <filename> \t: Command yang digunakan untuk menyimpan state game pemain saat ini ke dalam suatu file.\n");
    printf("CREATE GAME \t\t: Command yang digunakan untuk menambahkan game baru pada daftar game.\n");
    printf("LIST GAME \t\t: Command yang digunakan untuk menampilkan daftar game yang disediakan oleh sistem.\n");
    printf("DELETE GAME \t\t: Command yang digunakan untuk menghapus sebuah game dari daftar game.\n");
    printf("QUEUE GAME \t\t: Command yang digunakan untuk mendaftarkan permainan ke dalam list.\n");
    printf("PLAY GAME \t\t: Command yang digunakan untuk memainkan sebuah permainan.\n");
    printf("SKIP GAME <n> \t\t: Command yang digunakan untuk melewatkan permainan sebanyak n.\n");
    printf("SCOREBOARD \t\t: Command yang digunakan untuk menampilkan nama dan skor pemain untuk semua game.\n");
    printf("RESET SCOREBOARD \t: Command yang digunakan untuk melakukan reset terhadap scoreboard game.\n");
    printf("HISTORY <n>\t\t: Command yang digunakan untuk menampilkan sebanyak n permainan yang telah dimainkan.\n");
    printf("RESET HISTORY \t\t: Command yang digunakan untuk menghapus semua history permainan yang dimainkan.\n");
    printf("HELP \t\t\t: Bantuan command-command yang ada.\n");
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

void SCOREBOARD(ArrMap ScoreBoard)
{
    int nbmap = NbElmtArrMap(ScoreBoard);
    int i = 0;

    while (i < nbmap)
    {
        Map SB;
        CreateScoreBoard(&SB);
        SB = GetElmtArrMap(ScoreBoard, i);
        printf("\n**** SCOREBOARD GAME %s ****\n", SB.MapName);
        PrintScoreBoard(SB);
        i++;
    }
}

void RESETSCOREBOARD(ArrMap *ScoreBoard)
{
    int nbmap = NbElmtArrMap(*ScoreBoard);
    printf("DAFTAR SCOREBOARD:\n");
    printf("0. All\n");
    for (int i = 0; i < nbmap; i++)
    {
        printf("%d. %s\n", i + 1, GetElmtArrMap(*ScoreBoard, i).MapName);
    }

    char* command;
    printf("SCOREBOARD YANG INGIN DIHAPUS: ");
    
    STARTCOMMANDLINE();
    int input = WordToInt(currentCMD);

    while (input < 0 || input > nbmap)
    {
        printf("Input tidak valid, silahkan masukkan input yang valid.\n\n");
        printf("SCOREBOARD YANG INGIN DIHAPUS: ");
        STARTCOMMANDLINE();
        input = WordToInt(currentCMD);
    }

    if (input == 0)
    {
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ALL (YA/TIDAK)? ");
        STARTCOMMANDLINE();
        command = WordToString(currentCMD);
        while (compareString(command, "YA") == false && compareString(command, "TIDAK") == false)
        {
            printf("Input tidak valid, silahkan masukkan input yang valid.\n");
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ALL (YA/TIDAK)? ");
            STARTCOMMANDLINE();
            command = WordToString(currentCMD);
        }

        if (compareString(command, "YA") == true)
        {
            int i = 0;
            while (i < nbmap)
            {
                Map SB;
                SB = GetElmtArrMap(*ScoreBoard, i);
                CreateScoreBoard(&SB);
                SetElArrMap(ScoreBoard, i, SB);
                (*ScoreBoard).Neff--;
                i++;
            }
            printf("\nScoreboard berhasil di-reset.\n");
        }
        else
        {
            printf("\nScoreboard gagal di-reset.\n");
        }  
    }
    else
    {
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ALL (YA/TIDAK)? ");
        STARTCOMMANDLINE();
        command = WordToString(currentCMD);
        while (compareString(command, "YA") == false && compareString(command, "TIDAK") == false)
        {
            printf("Input tidak valid, silahkan masukkan input yang valid.\n");
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ALL (YA/TIDAK)? ");
            STARTCOMMANDLINE();
            command = WordToString(currentCMD);
        }
        if (compareString(command, "YA") == true)
        {
            Map SB;
            SB = GetElmtArrMap(*ScoreBoard, input-1);
            CreateScoreBoard(&SB);
            SetElArrMap(ScoreBoard, input-1, SB);
            (*ScoreBoard).Neff--;
            printf("\nScoreboard berhasil di-reset.\n");
        }
        else
        {
            printf("\nScoreboard gagal di-reset.\n");
        }  
    }
}

void HISTORY(Stack GamesHistory, int nHistory)
{
    printf("Berikut adalah daftar Game yang telah dimainkan\n");
    if (IsStackEmpty(GamesHistory))
    {
        printf("Belum ada game yang dimainkan.\n");
    }
    else
    {
        int countHistory = Top(GamesHistory) + 1;

        if (nHistory > countHistory)
        {
            nHistory = countHistory;
        }
        char *val;
        for (int i = 0; i < nHistory; i++)
        {
            printf("%d. %s\n", i + 1, InfoTop(GamesHistory));
            Pop(&GamesHistory,&val);
        }
    }
}

void RESETHISTORY(Stack *GamesHistory)
{
    printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY? (YA/TIDAK) ");
    STARTCOMMANDLINE();
    char* command;
    command = WordToString(currentCMD);
    if (compareString(command,"YA"))
    {
        CreateEmptyStack(GamesHistory);
        if (IsStackEmpty(*GamesHistory))
        {
            printf("\nHistory berhasil di-reset.\n");
        }
        else
        {
            printf("\nHistory gagal di-reset.\n");
        }
    }
    else if (compareString(command,"TIDAK"))
    {
        printf("\nHistory tidak jadi di-reset. ");
        HISTORY(*GamesHistory,CAPACITY);
    }
    else
    {
        OTHERCMD();
    }
}