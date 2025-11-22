#include <iostream>
using namespace std;

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

}
// Fungsi Admin hapus lagu
void adminDeleteSong() {

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
    cout << "Menu User" << endl;
    cout << "1. Cari Lagu" << endl;
    cout << "2. Putar Lagu" << endl;
    cout << "3. Stop Lagu" << endl;
    cout << "4. Next Lagu" << endl;
    cout << "5. Previous Lagu" << endl;
    cout << "6. Playlist" << endl;
    cout << "7. Logout" << endl;
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            // Fungsi cari lagu
            break;
        case 2:
            // Fungsi User putar lagu
            break;
        case 3:
            // Fungsi User stop lagu
            break;
        case 4:
            // Fungsi User next lagu
            break;
        case 5:
            // Fungsi User previous lagu
            break;
        case 6:
            // Fungsi untuk menampilkan menu playlist
            break;
        case 7:
            menuUtama();
            break;
        default:
            cout << "Input salah!" << endl;
            userMenu();
            break;
    }
}

// Fungsi cari lagu
// Fungsi User putar lagu
// Fungsi User stop lagu
// Fungsi User next lagu
// Fungsi User previous lagu

// Fungsi untuk menampilkan menu playlist
// Fungsi nambah lagu ke playlist
// Fungsi hapus lagu dari playlist
// Fungsi tampil playlist




int main() {
   

    return 0;
}