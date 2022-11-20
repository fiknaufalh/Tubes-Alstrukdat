#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include "ADT/arraydin/arraydin.h"
#include "ADT/mesinkarakter/mesinkarakter.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/queue/queue.h"
#include "ADT/map/map.h"

boolean compareString(char* str1, char* str2);

void STARTBNMO(ArrayDin* GamesList);

void LOADBNMO(ArrayDin* GamesList, Queue* GamesHistory, char* filename, Map* RNGSB, Map* DinerSB, Map* HangmanSB, Map* TowerSB, Map* SnakeSB);

void SAVEBNMO(ArrayDin GamesList, char* filename, Queue GamesHistory, Map RNGSB, Map DinerSB, Map HangmanSB, Map TowerSB, Map SnakeSB);

int stringLength(char* string);

void stringConcat(char *s1,char *s2,char *sout);

void CREATEGAME(ArrayDin* GamesList);

void LISTGAME (ArrayDin GameList);
/* Prosedur untuk menampilkan daftar game yang disediakan oleh sistem. 

I.S GameList terdefinisi, GameList tidak kosong, dan GameList mungkin penuh. 
F.S Output berupa daftar game yang tersedia. */

void DELETEGAME (ArrayDin *GameList, Queue Q);
/* Prosedur yang menghapus game dari daftar game. 
GameList merupakan daftar game dan Q merupakan antrian game.

I.S Q terdefinisi, Q mungkin kosong, dan Q tidak penuh.
    GameList terdefinisi, GameList tidak mungkin kosong, GameList mungkin penuh.
F.S Jika input valid (input tidak bernilai 1-5, tidak melebihi banyaknya nomor urutan daftar game, dan game dengan nomor tersebut 
    tidak ada dalam antrian game), game berhasil dihapus dan memberikan pesan berhasil.
    Jika input tidak valid, game gagal dihapus dan memberikan pesan error. */

void QUEUEGAME (Queue *Q, ArrayDin GameList);
/* Prosedur yang menambahkan sebuah game yang terdefinisi dalam daftar game ke daftar antrian game.
Input merupakan nomor urutan game di daftar game yang ingin ditambahkan ke antrian game.
GameList merupakan daftar game yang tersedia.

I.S Q terdefinisi, Q mungkin kosong, dan Q tidak penuh.
    GameList terdefinisi, GameList tidak mungkin kosong, dan GameList mungkin penuh.
F.S Jika input valid (input tidak melebihi banyaknya nomor urutan game), 
    game akan ditambahkan ke Q dan memberikan pesan berhasil.
    Jika input tidak valid, game tidak dapat ditambahkan dan memberikan pesan error. */

void PLAYGAME(Queue *q, ArrayDin GameList, Queue* history);

void SKIPGAME(Queue *q, ArrayDin GameList, Queue *history, int input);

int WordToInt(Word CWord);

char *WordToString(Word CWord);

void HELP();

void QUIT(Queue *Q);

void OTHERCMD();

void SCOREBOARD(Map RNGSB, Map DinerSB, Map HangmanSB, Map TowerSB, Map SnakeSB);

void RESETSCOREBOARD(Map *RNGSB, Map *DinerSB, Map *HangmanSB, Map *TowerSB, Map *SnakeSB);

void HISTORY(Queue GamesHistory, int nHistory);

void RESETHISTORY(Queue *GamesHistory);

#endif
