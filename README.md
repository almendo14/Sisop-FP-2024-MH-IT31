# Sisop-FP-2024-MH-IT31


# DiscorIT - Final Praktikum Sistem Operasi 2024

# Deskripsi Proyek

DiscorIT adalah sebuah aplikasi chatting yang terdiri dari tiga komponen utama: client (discorit), server (server), dan monitor (monitor). Aplikasi ini memungkinkan pengguna untuk mendaftar, login, membuat channel, bergabung ke dalam channel dan room, serta mengirim, mengedit, dan menghapus pesan dalam room. Aplikasi ini juga mendukung peran pengguna seperti ROOT, ADMIN, USER, dan BANNED. Program ini berinteraksi melalui socket dan server berjalan sebagai daemon.

# Cara Menjalankan Program
1. Menjalankan Server
    
    Jalankan server sebagai daemon:

    ./server

2. Menjalankan Client (discorit)

    Daftar user baru:

    ./discorit REGISTER <username> -p <password>

    Login user:

    ./discorit LOGIN <username> -p <password>

3. Menjalankan Monitor

    Monitor room secara real-time:

    ./monitor <username> -channel <channel_name> -room <room_name>

# Penjelasan Struktur File




# Revisi Soal Final Praktikum Sistem Operasi 2024
Bagian Server
Sebelumnya, terdapat kendala pada bagian server yang belum dapat terhubung dengan client. Setelah dilakukan revisi, bagian server sekarang sudah berhasil terhubung dan dapat berkomunikasi dengan client secara efektif.

Revisi Detail
* Deskripsi Perubahan:

    * Kondisi Sebelumnya: Server tidak dapat terhubung dengan client, menyebabkan client tidak bisa mengirim dan menerima request ke/dari server.
    * Kondisi Sekarang: Server telah diperbaiki dan dapat terhubung dengan client. Client dapat mengirim request ke server dan menerima response dari server sesuai ketentuan soal.

* Perubahan yang Dilakukan:

    * Penyesuaian Kode: Bagian kode yang mengatur koneksi antara server dan client telah diperbaiki.
    * Pengujian Koneksi: Telah dilakukan pengujian untuk memastikan bahwa server dapat menerima dan merespons request dari client.

* Pengujian dan Hasil
Pengujian Koneksi: Server diuji dengan beberapa client untuk memastikan bahwa koneksi dapat terjalin dengan baik.
    * Hasil: Server berhasil menerima request dari client dan mengembalikan response yang sesuai.
    * Kesimpulan: Server dan client sekarang dapat berkomunikasi dengan baik melalui socket.

Kesimpulan
Dengan revisi ini, masalah koneksi pada bagian server telah terselesaikan. 

Changelog
[28/06/2024]: Server yang belum dapat terhubung sekarang sudah terhubung dengan client.







