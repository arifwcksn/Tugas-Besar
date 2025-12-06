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

struct Song {
    infotype lagu;
    Song* next;
    Song* prev;
};

typedef struct elmLagu *address;

struct elmLagu {
    infotype info;
    address next;
    address prev;
};

struct ListLagu {
    address First;
    address Last;
};

ListLagu MusicLibrary;

typedef struct ElmPlaylist *addrPL;

struct ElmPlaylist {
    address data;           
    addrPL next;
};

struct ListPlaylist {
    addrPL First;
};

ListPlaylist UserPlaylist;

typedef struct ElmQueue *addrQ;

struct ElmQueue {
    address data;           
    addrQ next;
};

struct QueuePlay {
    addrQ Head;
    addrQ Tail;
};

QueuePlay SongQueue;

address nowPlaying = nullptr;

void KondisiAwal() {
    MusicLibrary.First = nullptr;
    MusicLibrary.Last  = nullptr;
    UserPlaylist.First = nullptr;
    SongQueue.Head = nullptr;
    SongQueue.Tail = nullptr;
}

// 1. Menu
// Fungsi untuk menampilkan menu utama
void menuUtama() {
    int pilihan;
    cout << "App Music Player" << endl;
    cout << "1. Login as Admin" << endl;
    cout << "2. Login as User" << endl;
    cout << "3. Exit" << endl;
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            adminLogin();
            break;
        case 2:
            cout << "Login as User!" << endl;
            userMenu();
            break;
        case 3:
            cout << "Logout!" << endl;
            break;
        default:
            cout << "Input salah!" << endl;
            menuUtama();
            break;
    }
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
    cout << "Menu Admin" << endl;
    cout << "1. Tambah Lagu" << endl;
    cout << "2. Hapus Lagu" << endl;
    cout << "3. Update Lagu" << endl;
    cout << "4. Tampil Lagu" << endl;
    cout << "5. Logout" << endl;
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
            adminDisplaySongs();
            break;
        case 5:
            menuUtama();
            break;
        default:
            cout << "Input salah!" << endl;
            adminMenu();
            break;
    }
}

// Fungsi Admin nambah lagu
void adminAddSong() {
    string namaLagu, namaArtis, genreLagu, idLagu;
    int durasiLagu;
    // Admin memasukan lagu baru
    cout << "Input Id Lagu Baru: ";
    cin >> idLagu;
    cout << "Nama Lagu Baru: ";
    cin >> namaLagu;
    cout << "Nama Artis lagu: ";
    cin >> namaArtis;
    cout << "Durasi Lagu (dalam detik): ";
    cin >> durasiLagu;
    cout << "Genre Lagu: ";
    cin >> genreLagu;

    // proses insert lagu ke database

    cout << "Lagu" << namaLagu << "berhasil ditambahkan!" << endl;
}
// Fungsi Admin hapus lagu
void adminDeleteSong() {
    viewSongs();
}

// Fungsi Admin update lagu
void adminUpdateSong() {

}

// Fungsi Admin tampil lagu
void adminDisplaySongs() {

}

// 3. User
// Fungsi untuk menampilkan menu User
void userMenu() {
    int pilihan;

    // Tampilkan lagu yang saat ini di play
    currentlyPlayingSong();

    cout << "Menu User" << endl;
    cout << "1. Tampilkan Semua Lagu" << endl;
    cout << "2. Cari Lagu" << endl;
    cout << "3. Putar Lagu" << endl;
    cout << "4. Stop Lagu" << endl;
    cout << "5. Next Lagu" << endl;
    cout << "6. Previous Lagu" << endl;
    cout << "7. Playlist" << endl;
    cout << "8. Logout" << endl;
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
            menuUtama();
            break;
        default:
            cout << "Input salah!" << endl;
            userMenu();
            break;
    }
}

// Fungsi untuk menampilkan lagu yang sedang diputar
void currentlyPlayingSong() {
    // Proses menampilkan lagu yang sedang diputar
    cout << "Lagu yang sedang diputar: [Judul Lagu] oleh [Artis]" << endl;
}

// Fungsi untuk menampilkan semua lagu dari database
void viewSongs() {
    // Proses menampilkan lagu dari database
    cout << "Menampilkan semua lagu dari database..." << endl;
}
// Fungsi cari lagu
void userFindSong() {
    string keyword;
    cout << "Masukkan kata kunci untuk mencari lagu: ";
    cin >> keyword;
    // Proses pencarian lagu dari database
    cout << "Mencari lagu dengan kata kunci: " << keyword << endl;
}
// Fungsi User putar lagu
void userPlaySong() {
    string idLagu;
    cout << "Masukkan ID Lagu yang ingin diputar: ";
    cin >> idLagu;
    // Proses memutar lagu dari database
    cout << "Memutar lagu dengan ID: " << idLagu << endl;
}
// Fungsi User stop lagu
void userStopSong() {
    // Proses menghentikan lagu yang sedang diputar
    cout << "Menghentikan lagu yang sedang diputar..." << endl;
}
// Fungsi User next lagu
void userNextSong() {
    // Proses memutar lagu selanjutnya
    cout << "Memutar lagu selanjutnya..." << endl;
}
// Fungsi User previous lagu
void userPreviousSong() {
    // Proses memutar lagu sebelumnya
    cout << "Memutar lagu sebelumnya..." << endl;
}

// Playlist
// Fungsi untuk menampilkan menu playlist user
void userPlaylistMenu() {
    int pilihan;
    cout << "Menu Playlist" << endl;
    cout << "1. Tambah Lagu ke Playlist" << endl;
    cout << "2. Hapus Lagu dari Playlist" << endl;
    cout << "3. Tampilkan Playlist" << endl;
    cout << "4. Kembali ke Menu User" << endl;
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            // Fungsi nambah lagu ke playlist
            break;
        case 2:
            // Fungsi hapus lagu dari playlist
            break;
        case 3:
            // Fungsi tampil playlist
            break;
        case 4:
            userMenu();
            break;
        default:
            cout << "Input salah!" << endl;
            userPlaylistMenu();
            break;
    }
}
// Fungsi untuk menampilkan menu playlist
// Fungsi nambah lagu ke playlist
// Fungsi hapus lagu dari playlist
// Fungsi tampil playlist



int main() {
   

    return 0;
}