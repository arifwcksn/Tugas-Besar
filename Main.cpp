#include <iostream>
#include "Fitur.cpp"
#include "ADT.h"
using namespace std;

int main() {
   kondisiAwal();

    string id[3]     = {"L001", "L002", "L003"};
    string title[3]  = {"Fix_You", "Someone_Like_You", "Bohemian_Rhapsody"};
    string artist[3] = {"Coldplay", "Adele", "Queen"};
    string genre[3]  = {"Pop", "Pop", "Rock"};
    int duration[3]  = {295, 285, 355};

    for (int i = 0; i < 3; i++) {
        address Lagu = new Song;

        Lagu->lagu.idLagu   = id[i];
        Lagu->lagu.title    = title[i];
        Lagu->lagu.artist   = artist[i];
        Lagu->lagu.genre    = genre[i];
        Lagu->lagu.duration = duration[i];

        Lagu->next = nullptr;
        Lagu->prev = nullptr;

        if (MusicLibrary.First == nullptr) {
            MusicLibrary.First = Lagu;
            MusicLibrary.Last  = Lagu;
        } else {
            Lagu->prev = MusicLibrary.Last;
            MusicLibrary.Last->next = Lagu;
            MusicLibrary.Last = Lagu;
        }
    }

   menuUtama();

    return 0;
}