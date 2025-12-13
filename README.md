# Tugas-Besar

🎵 Aplikasi Musik Player Berbasis Struktur Data
Deskripsi Program:

Aplikasi Music Player ini merupakan program berbasis bahasa C++ yang dibuat untuk memenuhi Tugas Besar Mata Kuliah Struktur Data.
Program ini mensimulasikan pemutaran lagu dengan memanfaatkan beberapa struktur data utama, yaitu Double Linked List, Single Linked List, dan Queue (berbasis Double Linked List).

Pengguna dapat melihat daftar lagu, mencari lagu, memutar lagu, berpindah ke lagu berikutnya atau sebelumnya, mengelola playlist, serta menyimpan lagu favorit. Selain itu, tersedia juga menu Admin untuk mengelola data lagu dalam library.

Tujuan dari pembuatan program ini adalah:

   1. Menerapkan konsep struktur data linear secara nyata dalam sebuah aplikasi.

   2. Mengimplementasikan Double Linked List untuk pengelolaan data lagu.

   3.  Mengimplementasikan Queue untuk antrian pemutaran lagu.

   4. Mengimplementasikan Single Linked List untuk menyimpan lagu favorit.

   5. Melatih pemahaman tentang pointer, traversal, dan manipulasi node.

Struktur Data yang Digunakan
1. Double Linked List (DLL)

Digunakan untuk:

    Menyimpan database lagu (MusicLibrary)

    Memudahkan navigasi lagu menggunakan pointer next dan prev

2. Queue (berbasis Double Linked List)

Digunakan untuk:

    Menyimpan antrian pemutaran lagu

    Menentukan urutan lagu yang diputar

3. Single Linked List (SLL)

Digunakan untuk:

    Menyimpan daftar lagu favorit
    Menyimpan daftar lagu playlist

Fitur Aplikasi
Fitur Admin

    Login sebagai Admin

    Menambahkan lagu ke library

    Menghapus lagu dari library

    Memperbarui data lagu

    Menampilkan seluruh lagu di library

Fitur User

    Menampilkan semua lagu

    Mencari lagu berdasarkan judul, artist, atau genre

    Memutar lagu berdasarkan ID atau judul

    Menghentikan pemutaran lagu

    Memutar lagu berikutnya (Next Song)

    Memutar lagu sebelumnya (Previous Song)

    Mengelola playlist user

    Menandai lagu sebagai favorit

    Menampilkan daftar lagu favorit

Cara Menjalankan Program (Menggunakan Code::Blocks)
1. Membuka Project

    Jalankan aplikasi Code::Blocks.

    Pilih menu File → New → Project.

    Pilih Console Application, lalu klik Next.

    Pilih bahasa C++, kemudian klik Next.

    Tentukan nama project dan lokasi penyimpanan, lalu klik Finish.

2. Menambahkan File ke Project

    Klik kanan pada nama project → Add files…

    Tambahkan file berikut:

    main.cpp

    header.h

    source.cpp

    Isi masing-masing file dengan kode program Aplikasi Musik Player yang sesuai

3. Menghubungkan Header dan Source serta main
    Caranya adalah dengan menggunakan command #include "ADT.h"
    Terkadang juga harus menambahkan using namespace std ke semua file 

4. Build dan Run Program

    Pilih menu Build → Build and Run
    atau tekan F9.

    Jika tidak ada error, jendela console akan terbuka otomatis.

    Program Musik Player siap digunakan.

5. Penggunaan Program

    Pilih Login sebagai Admin untuk mengelola data lagu.

    Pilih Login sebagai User untuk:

    Menampilkan dan mencari lagu

    Memutar lagu

    Menggunakan fitur Next dan Previous

    Mengelola playlist dan lagu favorit


    Navigasi menu dilakukan dengan memasukkan angka sesuai pilihan.

