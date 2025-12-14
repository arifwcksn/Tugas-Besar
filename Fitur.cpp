#include <iostream>
#include "ADT.h"

using namespace std;

// Primitif
// Double linked list untuk menyimpan data lagu dan playlist
// Single linked list untuk menyimpan data playlist
// Queue(DLL) untuk pemutaran lagu

//kamus global
    ListLagu MusicLibrary;
    ListPlaylist UserPlaylist;
    QueuePlay SongQueue;
    addrQ nowPlaying = nullptr;
    addrFav Favorit = nullptr;

void kondisiAwal() {
    MusicLibrary.First = nullptr;
    MusicLibrary.Last  = nullptr;
    UserPlaylist.First = nullptr;
    SongQueue.Head = nullptr;
    SongQueue.Tail = nullptr;
}

address findSong(string keyword) {
    address p = MusicLibrary.First;
    while (p != nullptr) {
        if (p->lagu.title == keyword || p->lagu.artist == keyword || p->lagu.genre == keyword) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}
void addFavorit(address Lagu) {
    addrFav fav = new ElmFavorit;
    fav->data = Lagu;
    fav->next = Favorit;
    Favorit = fav;

    cout << "Lagu ditambahkan ke daftar favorit.\n";
}

// 1. Menu
// Fungsi untuk menampilkan menu utama
void menuUtama() {
    int pilihan;
    do {
        cout << "\n===== MUSIC PLAYER =====\n";
        cout << "1. Login Admin\n";
        cout << "2. Login User\n";
        cout << "3. Exit\n";
        cout << "Pilihan: ";
        cin >> pilihan;

    switch (pilihan) {
        case 1:
            adminLogin();
            break;
        case 2:
            cout << "Login as User!" << endl;
            userMenu();
            break;
        }
    } while (pilihan != 3);
}

// 2. Admin
// Fungsi untuk login sebagai admin
void adminLogin() {
    string username, password;
    cout << "cuma panitia yang boleh masuk" << endl;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;

    if (username == "admin" && password == "admin123") {
        cout << "Login berhasil!" << endl;
        adminMenu();
    } else {
        cout << "Username atau password salah!" << endl;
        menuUtama();
    }
}

// Fungsi untuk menampilkan menu admin
void adminMenu() {
    int pilihan;
    do {
        cout << "\n===== MENU ADMIN =====\n";
        cout << "1. Tambah Lagu\n";
        cout << "2. Hapus Lagu\n";
        cout << "3. Update Lagu\n";
        cout << "4. Tampilkan Lagu\n";
        cout << "5. Logout\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                adminAddSong();
                break;
            case 2:
                adminDeleteSong();
                break;
            case 3:
                adminUpdateSong();
                break;
            case 4:
                viewSongs();
                break;
            case 5:
                cout << "Logout admin.\n";
                break;
            default:
                cout << "Input salah!\n";
        }
    } while (pilihan != 5);
}

// Fungsi Admin nambah lagu
void adminAddSong() {
    address newSong = new Song;
    // Admin memasukan lagu baru
    cout << "Input Id Lagu Baru: ";
    cin >> newSong->lagu.idLagu;
    cout << "Nama Lagu Baru: ";
    cin >> newSong->lagu.title;
    cout << "Nama Artis lagu: ";
    cin >> newSong->lagu.artist;
    cout << "Durasi Lagu (dalam detik): ";
    cin >> newSong->lagu.duration;
    cout << "Genre Lagu: ";
    cin >> newSong->lagu.genre;

    // proses insert lagu ke database
    newSong->next = nullptr;
    newSong->prev = nullptr;

    if (MusicLibrary.First == nullptr) {
        MusicLibrary.First = newSong;
        MusicLibrary.Last = newSong;
    } else {
        newSong->prev = MusicLibrary.Last;
        MusicLibrary.Last->next = newSong;
        MusicLibrary.Last = newSong;
    }

    cout << "Lagu berhasil ditambahkan!" << endl;
}
// Fungsi Admin hapus lagu
void adminDeleteSong() {
     viewSongs();

    string id;
    cout << "Masukkan ID Lagu yang ingin dihapus: ";
    cin >> id;

    address p = MusicLibrary.First;

    while (p != nullptr && p->lagu.idLagu != id) {
        p = p->next;
    }

    if (p == nullptr) {
        cout << "Lagu tidak ditemukan!" << endl;
        adminMenu();
        return;
    }

    // Jika hanya satu lagu
    if (p == MusicLibrary.First && p == MusicLibrary.Last) {
        MusicLibrary.First = nullptr;
        MusicLibrary.Last  = nullptr;
    }
    // Jika di awal
    else if (p == MusicLibrary.First) {
        MusicLibrary.First = p->next;
        MusicLibrary.First->prev = nullptr;
    }
    // Jika di akhir
    else if (p == MusicLibrary.Last) {
        MusicLibrary.Last = p->prev;
        MusicLibrary.Last->next = nullptr;
    }
    // Jika di tengah
    else {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }

    delete p;
    cout << "Lagu berhasil dihapus!" << endl;
}

// Fungsi Admin update lagu
void adminUpdateSong() {
    viewSongs();
    string id;
    cout << "Masukkan ID Lagu yang ingin diupdate: ";
    cin >> id;

    address p = MusicLibrary.First;

    while (p != nullptr && p->lagu.idLagu != id) {
        p = p->next;
    }

    if (p == nullptr) {
        cout << "Lagu tidak ditemukan!" << endl;
        adminMenu();
        return;
    }

    cout << "Judul Baru   : ";
    cin >> p->lagu.title;
    cout << "Artis Baru   : ";
    cin >> p->lagu.artist;
    cout << "Durasi Baru  : ";
    cin >> p->lagu.duration;
    cout << "Genre Baru   : ";
    cin >> p->lagu.genre;

    cout << "Data lagu berhasil diperbarui!" << endl;
}

// 3. User
// Fungsi untuk menampilkan menu User
void userMenu() {
   int pilihan;
    do {
        currentlyPlayingSong();

        cout << "\n===== MENU USER =====\n";
        cout << "1. Tampilkan Lagu\n";
        cout << "2. Cari Lagu\n";
        cout << "3. Putar Lagu\n";
        cout << "4. Stop Lagu\n";
        cout << "5. Next Lagu\n";
        cout << "6. Previous Lagu\n";
        cout << "7. Playlist\n";
        cout << "8. Favorit\n";
        cout << "9. Logout\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                viewSongs();
                break;
            case 2:
                userFindSong();
                break;
            case 3:
                userPlaySong();
                break;
            case 4:
                userStopSong();
                break;
            case 5:
                userNextSong();
                break;
            case 6:
                userPreviousSong();
                break;
            case 7:
                userPlaylistMenu();
                break;
            case 8:
                displayFavorit();
                break;
            case 9:
                cout << "Logout user.\n";
                break;
            default:
                cout << "Input salah!\n";
        }
    } while (pilihan != 9);
}

// Fungsi untuk menampilkan lagu yang sedang diputar
void currentlyPlayingSong() {
    // Proses menampilkan lagu yang sedang diputar
    if (nowPlaying == nullptr) {
        cout << "\nTidak ada lagu yang sedang di putar\n";
    } else {
        cout << "\nLagu yang sedang di putar: "
             << nowPlaying->data->lagu.title
             << "oleh " << nowPlaying->data->lagu.artist << endl;
    }
}

// Fungsi untuk menampilkan semua lagu dari database
void viewSongs() {
    // Proses menampilkan lagu dari database
    address p = MusicLibrary.First;
    if (p == nullptr) {
        cout << "Library kosong!\n";
    }
    cout << "\n===== Music Library =====\n";
    while (p != nullptr) {
        cout << "[" << p->lagu.idLagu << "] "
             << p->lagu.title << " - " << p->lagu.artist
             << " | " << p->lagu.genre
             << " | " << p->lagu.duration << "s\n";
        p = p->next;
    }
    cout << "=========================\n";
}
// Fungsi cari lagu
void userFindSong() {
    string keyword;
    cout << "Masukkan kata kunci untuk mencari lagu: ";
    cin >> keyword;
    address cari = findSong(keyword);
    // Proses pencarian lagu dari database
    cout << "Mencari lagu dengan kata kunci: " << keyword << endl;
    if (cari->lagu.title == keyword) {
        cout << "Lagu ditemukan" << endl;
        cout << "[" << cari->lagu.idLagu << "] "
             << cari->lagu.title << " - "
             << cari->lagu.artist << " | "
             << cari->lagu.genre<< " | "
             << cari->lagu.duration << endl;
    } else if (cari->lagu.artist == keyword) {
        cout << "\nDaftar lagu dengan artist" << keyword << ":\n";
        address p = MusicLibrary.First;
        while (p != nullptr) {
            if (p->lagu.artist == keyword) {
                cout << "[" << p->lagu.idLagu << "] "
                     << p->lagu.title << " - " << p->lagu.artist
                     << " | " << p->lagu.genre
                     << " | " << p->lagu.duration << "s\n";
            }
            p = p->next;
        }
    }else if (cari->lagu.genre == keyword) {
        cout << "\nDaftar lagu dengan genre" << keyword << ":\n";
        address p = MusicLibrary.First;
        while (p != nullptr) {
            if (p->lagu.genre == keyword) {
                cout << "[" << p->lagu.idLagu << "] "
                     << p->lagu.title << " - " << p->lagu.artist
                     << " | " << p->lagu.genre
                     << " | " << p->lagu.duration << "s\n";
            }
            p = p->next;
        }
    } else {
        cout << "Lagu tidak ditemukan";
    }
}
// Fungsi User putar lagu
void userPlaySong() {
    string keyword;
    cout << "Masukkan ID/judul Lagu yang ingin diputar: ";
    cin >> keyword;
    // Proses memutar lagu dari database
    address Lagu = MusicLibrary.First;
    while (Lagu != nullptr && (Lagu->lagu.idLagu != keyword && Lagu->lagu.title != keyword)) {
        Lagu = Lagu->next;
    }

    if (Lagu == nullptr) {
        cout << "Lagu tidak ditemukan!" << endl;
        return;
    }

    addrQ antrian = new ElmQueue;
    antrian->data = Lagu;
    antrian->next = nullptr;
    antrian->prev = nullptr;

    if (SongQueue.Head == nullptr) {
        SongQueue.Head = SongQueue.Tail = antrian;
    } else {
        antrian->prev = SongQueue.Tail;
        SongQueue.Tail->next = antrian;
        SongQueue.Tail = antrian;
    }

    nowPlaying = antrian;

    cout << "Memutar lagu: "
         << Lagu->lagu.title
         << " - " << Lagu->lagu.artist << endl;
    char favorit;
    cout << "Apakah Lagu ini favorit anda [y/n]?";
    cin >> favorit;
    if (favorit == 'y' || favorit == 'Y') {
        addFavorit(Lagu);
    }
}
// Fungsi User stop lagu
void userStopSong() {
    // Proses menghentikan lagu yang sedang diputar
    nowPlaying = nullptr;
    cout << "⏹ Lagu dihentikan\n";
}
// Fungsi User next lagu
void userNextSong() {
    // Proses memutar lagu selanjutnya
    if (nowPlaying == nullptr) {
        cout << "Belum ada lagu yang diputar.\n";
        return;
    }

    address laguSekarang = nowPlaying->data;
    address p = laguSekarang->next;

    while (p != nullptr) {
        if (p->lagu.genre == laguSekarang->lagu.genre ||
            p->lagu.artist == laguSekarang->lagu.artist) {

            addrQ nodeBaru = new ElmQueue;
            nodeBaru->data = p;
            nodeBaru->next = nullptr;
            nodeBaru->prev = nowPlaying;

            nowPlaying->next = nodeBaru;
            SongQueue.Tail = nodeBaru;
            nowPlaying = nodeBaru;

            cout << "Memutar lagu berikutnya: "
                 << nowPlaying->data->lagu.title
                 << " - " << nowPlaying->data->lagu.artist << endl;
            return;
        }
        p = p->next;
    }

    if (MusicLibrary.First == nullptr) {
        cout << "Library kosong.\n";
        return;
    }

    addrQ nodeBaru = new ElmQueue;
    nodeBaru->data = MusicLibrary.First;
    nodeBaru->next = nullptr;
    nodeBaru->prev = nowPlaying;

    nowPlaying->next = nodeBaru;
    SongQueue.Tail = nodeBaru;
    nowPlaying = nodeBaru;

    cout << "Memutar lagu berikutnya: "
         << nowPlaying->data->lagu.title
         << " - " << nowPlaying->data->lagu.artist << endl;
}

// Fungsi User previous lagu
void userPreviousSong() {
    // Proses memutar lagu sebelumnya
    if (nowPlaying == nullptr) {
        cout << "Belum ada lagu yang diputar.\n";
        return;
    }

    if (nowPlaying->prev != nullptr) {
        nowPlaying = nowPlaying->prev;
        cout << "Memutar lagu sebelumnya: "
             << nowPlaying->data->lagu.title
             << " - " << nowPlaying->data->lagu.artist << endl;
        return;
    }

    address laguSekarang = nowPlaying->data;
    address p = MusicLibrary.First;

    while (p != nullptr) {
        if (p->lagu.genre == laguSekarang->lagu.genre ||
            p->lagu.artist == laguSekarang->lagu.artist) {

            addrQ nodeBaru = new ElmQueue;
            nodeBaru->data = p;
            nodeBaru->prev = nullptr;
            nodeBaru->next = nowPlaying;

            nowPlaying->prev = nodeBaru;
            SongQueue.Head = nodeBaru;
            nowPlaying = nodeBaru;

            cout << "Memutar lagu sebelumnya: "
                 << nowPlaying->data->lagu.title
                 << " - " << nowPlaying->data->lagu.artist << endl;
            return;
        }
        p = p->next;
    }

    if (MusicLibrary.First == nullptr) {
        cout << "Library kosong.\n";
        return;
    }

    addrQ nodeBaru = new ElmQueue;
    nodeBaru->data = MusicLibrary.First;
    nodeBaru->prev = nullptr;
    nodeBaru->next = nowPlaying;

    nowPlaying->prev = nodeBaru;
    SongQueue.Head = nodeBaru;
    nowPlaying = nodeBaru;

    cout << "Memutar lagu sebelumnya: "
         << nowPlaying->data->lagu.title
         << " - " << nowPlaying->data->lagu.artist << endl;
}

// Playlist
// Fungsi untuk menampilkan menu playlist user
void userPlaylistMenu() {
    int pilihan;
    do {
        cout << "\n===== MENU PLAYLIST =====\n";
        cout << "1. Tambah Lagu ke Playlist\n";
        cout << "2. Hapus Lagu dari Playlist\n";
        cout << "3. Tampilkan Playlist\n";
        cout << "4. Putar Lagu dari Playlist\n";
        cout << "5. Kembali ke Menu User\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                playlistAddSong();
                break;
            case 2:
                playlistDeleteSong();
                break;
            case 3:
                playlistDisplaySongs();
                break;
            case 4:
                playLaguDariPlaylist();
                break;
        }
    } while (pilihan != 5);
}
//fungsi menampilkan semua lagu favorit
void displayFavorit() {
    if (Favorit == nullptr) {
        cout << "Belum ada lagu favorit.\n";
        return;
    }

    cout << "\n===== DAFTAR LAGU FAVORIT =====\n";
    addrFav p = Favorit;
    while (p != nullptr) {
        cout << "[" << p->data->lagu.idLagu << "] "
             << p->data->lagu.title << " - "
             << p->data->lagu.artist << endl;
        p = p->next;
    }
    cout << "==============================\n";
}

// Fungsi nambah lagu ke playlist
void playlistAddSong() {
    viewSongs();

    string keyword;
    cout << "Masukkan ID / Judul lagu yang ingin ditambahkan ke playlist: ";
    cin >> keyword;

    address lagu = MusicLibrary.First;
    while (lagu != nullptr &&
           lagu->lagu.idLagu != keyword &&
           lagu->lagu.title != keyword) {
        lagu = lagu->next;
    }

    if (lagu == nullptr) {
        cout << "Lagu tidak ditemukan.\n";
        return;
    }

    addrPL nodeBaru = new ElmPlaylist;
    nodeBaru->data = lagu;
    nodeBaru->next = nullptr;

    if (UserPlaylist.First == nullptr) {
        UserPlaylist.First = nodeBaru;
    } else {
        addrPL p = UserPlaylist.First;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = nodeBaru;
    }

    cout << "Lagu berhasil ditambahkan ke playlist.\n";
}

// Fungsi hapus lagu dari playlist
void playlistDeleteSong() {
    if (UserPlaylist.First == nullptr) {
        cout << "Playlist kosong.\n";
        return;
    }

    playlistDisplaySongs();

    string id;
    cout << "Masukkan ID lagu yang ingin dihapus dari playlist: ";
    cin >> id;

    addrPL p = UserPlaylist.First;
    addrPL prev = nullptr;

    while (p != nullptr && p->data->lagu.idLagu != id) {
        prev = p;
        p = p->next;
    }

    if (p == nullptr) {
        cout << "Lagu tidak ditemukan di playlist.\n";
        return;
    }

    if (prev == nullptr) {
        UserPlaylist.First = p->next;
    } else {
        prev->next = p->next;
    }

    delete p;
    cout << "Lagu berhasil dihapus dari playlist.\n";
}
// Fungsi tampil playlist
void playlistDisplaySongs() {
    if (UserPlaylist.First == nullptr) {
        cout << "Playlist masih kosong.\n";
        return;
    }

    cout << "\n===== PLAYLIST USER =====\n";
    addrPL p = UserPlaylist.First;
    while (p != nullptr) {
        cout << "[" << p->data->lagu.idLagu << "] "
             << p->data->lagu.title << " - "
             << p->data->lagu.artist << endl;
        p = p->next;
    }
    cout << "=========================\n";
}

void playLaguDariPlaylist() {
    if (UserPlaylist.First == nullptr) {
        cout << "Playlist masih kosong.\n";
        return;
    }

    playlistDisplaySongs();

    string id;
    cout << "Masukkan ID lagu yang ingin diputar: ";
    cin >> id;

    addrPL p = UserPlaylist.First;
    address laguDipilih = nullptr;

    while (p != nullptr) {
        if (p->data->lagu.idLagu == id) {
            laguDipilih = p->data;
            break;
        }
        p = p->next;
    }

    if (laguDipilih == nullptr) {
        cout << "Lagu tidak ditemukan di playlist.\n";
        return;
    }

    addrQ nodeBaru = new ElmQueue;
    nodeBaru->data = laguDipilih;
    nodeBaru->next = nullptr;
    nodeBaru->prev = nullptr;

    if (SongQueue.Head == nullptr) {
        SongQueue.Head = SongQueue.Tail = nodeBaru;
    } else {
        nodeBaru->prev = SongQueue.Tail;
        SongQueue.Tail->next = nodeBaru;
        SongQueue.Tail = nodeBaru;
    }

    nowPlaying = nodeBaru;

    cout << "Memutar lagu dari playlist: "
         << laguDipilih->lagu.title
         << " - " << laguDipilih->lagu.artist << endl;
}


