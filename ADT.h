#ifndef ADT_H_INCLUDED
#define ADT_H_INCLUDED
#include <iostream>

using namespace std;

// Primitif
// Double linked list untuk menyimpan data lagu dan playlist
// Single linked list untuk menyimpan data playlist
// Queue(DLL) untuk pemutaran lagu

struct infotype {
    string idLagu;
    string title;
    int duration;
    string artist;
    string genre;
};

typedef struct Song *address;
struct Song {
    infotype lagu;
    address next;
    address prev;
};

struct ListLagu {
    address First;
    address Last;
};

typedef struct ElmPlaylist *addrPL;

struct ElmPlaylist {
    address data;
    addrPL next;
};

struct ListPlaylist {
    addrPL First;
};

typedef struct ElmQueue *addrQ;

struct ElmQueue {
    address data;
    addrQ next;
    addrQ prev;
};

struct QueuePlay {
    addrQ Head;
    addrQ Tail;
};

typedef struct ElmFavorit *addrFav;

struct ElmFavorit {
    address data;
    addrFav next;
};

void adminLogin();
void userMenu();
void adminMenu();
void menuUtama();
void viewSongs();

void kondisiAwal();
address findSong(string id);

void adminAddSong();
void adminDeleteSong();
void adminUpdateSong();
void adminDisplaySongs();

void userFindSong();
void userPlaySong();
void userStopSong();
void userNextSong();
void userPreviousSong();
void userPlaylistMenu();
void currentlyPlayingSong();

void playlistAddSong();
void playlistDeleteSong();
void playlistDisplaySongs();
void playLaguDariPlaylist();

void addFavorit(address Lagu);
void displayFavorit();


//Referensi kamus global antar file atau bisa di bilang penghubung antar file
extern ListLagu MusicLibrary;
extern ListPlaylist UserPlaylist;
extern QueuePlay SongQueue;
extern addrQ nowPlaying;
extern addrFav Favorit;

//perbaikan
bool isIdExist(string id);
bool isInPlaylist(address lagu);
void removeFromFavorit(address lagu);
void removeFromPlaylist(address lagu);


#endif // ADT_H_INCLUDED
