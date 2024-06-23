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

![Struktur File](struktur/file.jpg)

