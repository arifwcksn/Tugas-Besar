#include <iostream>
using namespace std;

// Primitif
// Double linked list untuk menyimpan data lagu dan playlist
// Single linked list untuk menyimpan data playlist
// Queue(DLL) untuk pemutaran lagu 


void KondisiAwal() {
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
    if (nowPlaying == nullptr) {
        cout << "\nNow Playing: [Tidak ada lagu yang sedang di putar]\n";
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
        return;
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
             << cari->lagu.genre << << " | " 
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
    }else {
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
    }
}
// Fungsi User putar lagu
void userPlaySong() {
    string idLagu;
    cout << "Masukkan ID Lagu yang ingin diputar: ";
    cin >> idLagu;
    // Proses memutar lagu dari database
    cout << "▶ Memutar lagu dengan ID: " << idLagu << endl;
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

    if (nowPlaying->next != nullptr) {
        nowPlaying = nowPlaying->next;
        cout << "Memutar lagu berikutnya: "
             << nowPlaying->data->lagu.title
             << " - " << nowPlaying->data->lagu.artist << endl;
        return;
    }

    if (nowPlaying->data->next != nullptr) {
        addrQ q = new ElmQueue;
        q->data = nowPlaying->data->next;
        q->next = nullptr;
        q->prev = nowPlaying;
        nowPlaying->next = q;
        SongQueue.Tail = q;
        nowPlaying = q;

        cout << "Memutar lagu berikutnya: "
             << nowPlaying->data->lagu.title
             << " - " << nowPlaying->data->lagu.artist << endl;
        return;
    }

    cout << "Tidak ada lagu selanjutnya.\n";
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

