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
    EndWord = true;
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

void LOADBNMO(ArrayDin* GamesList, Queue* GamesHistory, char* filename, Map* RNGSB, Map* DinerSB, Map* HangmanSB, Map* TowerSB, Map* SnakeSB)
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
            enqueue(GamesHistory,line);
            ADVLine();
            i++;
        }

        // RNGSB
        int RNGScore = WordToInt(currentWord);
        i = 1;
        while (i <= RNGScore)
        {
            IgnoreEnter();
            ADVWORD();
            char *playername;
            playername = WordToString(currentWord);
            ADVWORD();
            int score = WordToInt(currentWord);
            InsertSB(RNGSB,playername,score);
            i++;
        }

        // DinerDash
        ADVLine();
        int DinerScore = WordToInt(currentWord);
        i = 1;
        while (i <= DinerScore)
        {
            IgnoreEnter();
            ADVWORD();
            char *playername;
            playername = WordToString(currentWord);
            ADVWORD();
            int score = WordToInt(currentWord);
            InsertSB(DinerSB,playername,score);
            i++;
        }

        // HANGMAN
        ADVLine();
        int HangmanScore = WordToInt(currentWord);
        i = 1;
        while (i <= HangmanScore)
        {
            IgnoreEnter();
            ADVWORD();
            char *playername;
            playername = WordToString(currentWord);
            ADVWORD();
            int score = WordToInt(currentWord);
            InsertSB(HangmanSB,playername,score);
            i++;
        }

        // TOWER OF HANOI
        ADVLine();
        int TowerScore = WordToInt(currentWord);
        i = 1;
        while (i <= TowerScore)
        {
            IgnoreEnter();
            ADVWORD();
            char *playername;
            playername = WordToString(currentWord);
            ADVWORD();
            int score = WordToInt(currentWord);
            InsertSB(TowerSB,playername,score);
            i++;
        }

        // SNAKE ON METEOR
        ADVLine();
        int SnakeScore = WordToInt(currentWord);
        i = 1;
        while (i <= SnakeScore)
        {
            IgnoreEnter();
            ADVWORD();
            char *playername;
            playername = WordToString(currentWord);
            ADVWORD();
            int score = WordToInt(currentWord);
            InsertSB(SnakeSB,playername,score);
            i++;
        }
        if(!IsEmpty(*GamesList) && !isEmpty(*GamesHistory) )
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

void SAVEBNMO(ArrayDin GamesList, char* filename, Queue GamesHistory, Map RNGSB, Map DinerSB, Map HangmanSB, Map TowerSB, Map SnakeSB)
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
    fprintf(fp,"\n%d",length(GamesHistory));
    for(int i = 0; i < length(GamesHistory);i++)
    {
        fprintf(fp,"\n%s",GamesHistory.buffer[i]);
    }

    // RNGSB
    fprintf(fp,"\n%d",(RNGSB).Count);
    for(int i = 0; i < (RNGSB).Count;i++)
    {
        fprintf(fp,"\n%s %d",(RNGSB).Elements[i].Key,(RNGSB).Elements[i].Value);
    }

    // DinerDash
    fprintf(fp,"\n%d",(DinerSB).Count);
    for(int i = 0; i < (DinerSB).Count;i++)
    {
        fprintf(fp,"\n%s %d",(DinerSB).Elements[i].Key,(DinerSB).Elements[i].Value);
    }

    // HANGMAN
    fprintf(fp,"\n%d",(HangmanSB).Count);
    for(int i = 0; i < (HangmanSB).Count;i++)
    {
        fprintf(fp,"\n%s %d",(HangmanSB).Elements[i].Key,(HangmanSB).Elements[i].Value);
    }

    // TOWER OF HANOI
    fprintf(fp,"\n%d",(TowerSB).Count);
    for(int i = 0; i < (TowerSB).Count;i++)
    {
        fprintf(fp,"\n%s %d",(TowerSB).Elements[i].Key,(TowerSB).Elements[i].Value);
    }

    // SNAKE ON METEOR
    fprintf(fp,"\n%d",(SnakeSB).Count);
    for(int i = 0; i < (SnakeSB).Count;i++)
    {
        fprintf(fp,"\n%s %d",(SnakeSB).Elements[i].Key,(SnakeSB).Elements[i].Value);
    }

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
    char* gameName = WordToString(currentCMD);
    InsertLast(GamesList,gameName);
    printf("Game berhasil ditambahkan\n");
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
        int a;
        for(a = 0; a < length(*q); a++){
            printf("%d. %s\n",(a+1),(*q).buffer[(a+(q->idxHead))%CAPACITY]);
        }
        int i;
        i = 0;
        while(i < Length(GameList) && status){
            if ((HEAD(*q) == GameList.A[i])){
                if (i > 4){
                    printf("\nLoading %s ...\n", HEAD(*q));
                    printf("Game over! \nFinal Score : ");
                    printf("%d\n", rand());
                    status = false;
                    // break;
                }
                else if (i == 1){
                    printf("\nLoading %s ...\n", HEAD(*q));
                    DinerDash();
                    status = false;
                    // break;
                }
                else if (i == 0){
                    printf("\nLoading %s ...\n", HEAD(*q));
                    RNG();
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

        ElType val;
        dequeue(q,&val);
        enqueue(history,val);
    }
    else{
        printf("Tidak ada game dalam antrian permainan Anda!\n");
    } 
}

void SKIPGAME(Queue *q, ArrayDin GameList, Queue *history, int input){    
    if (!isEmpty(*q)){
        ElType val;
        int i = 0;
        if (input+1 <= length(*q) && input >= 0){
            while (i < input){
                dequeue(q,&val);
                enqueue(history, val);
                i++;
            }
        }
        else if (input+1 >= length(*q)){
            int panjang = length(*q);
            while (i < panjang){
                dequeue(q,&val);
                enqueue(history, val);
                i++;
            }
        }
        PLAYGAME(q,GameList,history);
    } else {
        printf("Tidak ada permainan lagi dalam daftar game-mu\n");
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
    printf("PLAY GAME \t\t: Command yang digunakan untuk memainkan sebuah permainan.\n");
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

void SCOREBOARD(Map RNGSB, Map DinerSB, Map HangmanSB, Map TowerSB, Map SnakeSB)
{
    printf("**** SCOREBOARD GAME RNG ****\n");
    PrintScoreBoard(SortSB(RNGSB));
    printf("\n");
    printf("**** SCOREBOARD GAME Diner Dash ****\n");
    PrintScoreBoard(SortSB(DinerSB));
    printf("\n");
    printf("**** SCOREBOARD GAME HANGMAN ****\n");
    PrintScoreBoard(SortSB(HangmanSB));
    printf("\n");
    printf("**** SCOREBOARD GAME Tower OF HANOI ****\n");
    PrintScoreBoard(SortSB(TowerSB));
    printf("\n");
    printf("**** SCOREBOARD GAME SNAKE ON METEOR ****\n");
    PrintScoreBoard(SortSB(SnakeSB));
    printf("\n");
}

void RESETSCOREBOARD(Map *RNGSB, Map *DinerSB, Map *HangmanSB, Map *TowerSB, Map *SnakeSB)
{
    printf("DAFTAR SCOREBOARD:\n");
    printf("0. All\n");
    printf("1. RNG\n");
    printf("2. Diner DASH\n");
    printf("3. HANGMAN\n");
    printf("4. TOWER OF HANOI\n");
    printf("5. SNAKE ON METEOR\n\n");
    char* command;
    printf("SCOREBOARD YANG INGIN DIHAPUS: ");
    STARTCOMMAND();
    int input = WordToInt(currentCMD);

    switch(input)
    {
        case 0 :
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ALL (YA/TIDAK)? ");
            STARTCOMMAND();
            command = WordToString(currentCMD);
            if (compareString(command,"YA"))
            {
                ADVCOMMAND();
                if (EndWord == true)
                {
                    CreateScoreBoard(RNGSB);
                    CreateScoreBoard(DinerSB);
                    CreateScoreBoard(HangmanSB);
                    CreateScoreBoard(TowerSB);
                    CreateScoreBoard(SnakeSB);
                    if (IsEmptySB(*RNGSB) && IsEmptySB(*DinerSB) && IsEmptySB(*HangmanSB) && IsEmptySB(*TowerSB) && IsEmptySB(*SnakeSB))
                    {
                        printf("\nScoreboard berhasil di-reset.\n");
                    }
                    else
                    {
                        printf("\nScoreboard gagal di-reset.\n");
                    }
                }
                else
                {
                    OTHERCMD();
                }
            }
            else if (compareString(command,"TIDAK"))
            {
                printf("\nReset SCOREBOARD ALL dibatalkan\n");
            }
            else
            {
                OTHERCMD();
            }
            break;

        case 1 :
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD RNG (YA/TIDAK)? ");
            STARTCOMMAND();
            command = WordToString(currentCMD);
            if (compareString(command,"YA"))
            {
                ADVCOMMAND();
                if (EndWord == true)
                {
                    CreateScoreBoard(RNGSB);
                    if (IsEmptySB(*RNGSB))
                    {
                        printf("\nScoreboard berhasil di-reset.\n");
                    }
                    else
                    {
                        printf("\nScoreboard gagal di-reset.\n");
                    }
                }
                else
                {
                    OTHERCMD();
                }
            }
            else if (compareString(command,"TIDAK"))
            {
                printf("\nReset SCOREBOARD RNG dibatalkan\n");
            }
            else
            {
                OTHERCMD();
            }
            break;

        case 2 :
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD Diner DASH (YA/TIDAK)? ");
            STARTCOMMAND();
            command = WordToString(currentCMD);
            if (compareString(command,"YA"))
            {
                ADVCOMMAND();
                if (EndWord == true)
                {
                    CreateScoreBoard(DinerSB);
                    if (IsEmptySB(*DinerSB))
                    {
                        printf("\nScoreboard berhasil di-reset.\n");
                    }
                    else
                    {
                        printf("\nScoreboard gagal di-reset.\n");
                    }
                }
                else
                {
                    OTHERCMD();
                }
            }
            else if (compareString(command,"TIDAK"))
            {
                printf("\nReset SCOREBOARD Diner DASH dibatalkan\n");
            }
            else
            {
                OTHERCMD();
            }
            break;

        case 3 :
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD HANGMAN (YA/TIDAK)? ");
            STARTCOMMAND();
            command = WordToString(currentCMD);
            if (compareString(command,"YA"))
            {
                ADVCOMMAND();
                if (EndWord == true)
                {
                    CreateScoreBoard(HangmanSB);
                    if (IsEmptySB(*HangmanSB))
                    {
                        printf("\nScoreboard berhasil di-reset.\n");
                    }
                    else
                    {
                        printf("\nScoreboard gagal di-reset.\n");
                    }
                }
                else
                {
                    OTHERCMD();
                }
            }
            else if (compareString(command,"TIDAK"))
            {
                printf("\nReset SCOREBOARD HANGMAN dibatalkan\n");
            }
            else
            {
                OTHERCMD();
            }
            break;

        case 4 :
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD TOWER OF HANOI (YA/TIDAK)? ");
            STARTCOMMAND();
            command = WordToString(currentCMD);
            if (compareString(command,"YA"))
            {
                ADVCOMMAND();
                if (EndWord == true)
                {
                    CreateScoreBoard(TowerSB);
                    if (IsEmptySB(*TowerSB))
                    {
                        printf("\nScoreboard berhasil di-reset.\n");
                    }
                    else
                    {
                        printf("\nScoreboard gagal di-reset.\n");
                    }
                }
                else
                {
                    OTHERCMD();
                }
            }
            else if (compareString(command,"TIDAK"))
            {
                printf("\nReset SCOREBOARD TOWER OF HANOI dibatalkan\n");
            }
            else
            {
                OTHERCMD();
            }
            break;

        case 5 :
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD SNAKE ON METEOR (YA/TIDAK)? ");
            STARTCOMMAND();
            command = WordToString(currentCMD);
            if (compareString(command,"YA"))
            {
                ADVCOMMAND();
                if (EndWord == true)
                {
                    CreateScoreBoard(SnakeSB);
                    if (IsEmptySB(*SnakeSB))
                    {
                        printf("\nScoreboard berhasil di-reset.\n");
                    }
                    else
                    {
                        printf("\nScoreboard gagal di-reset.\n");
                    }
                }
                else
                {
                    OTHERCMD();
                }
            }
            else if (compareString(command,"TIDAK"))
            {
                printf("\nReset SCOREBOARD SNAKE ON METEOR dibatalkan\n");
            }
            else
            {
                OTHERCMD();
            }
            break;

        default :
            printf("Input tidak dikenali.\n");
            break;
    }

    /* *** End Command *** */
    while (!EndWord)
    {
        ADVCOMMAND();
    }
}

