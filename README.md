# Library-Management-System
This repo is for Final Project of our group in Algorithm and Programming course

### Sistem Manajemen Perpustakaan
Program ini bertujuan memudahkan akses peminjaman buku secara daring. Program dilengkapi dengan empat fitur utama, yaitu display daftar buku yang tersedia untuk dipinjam, peminjaman buku, detail peminjam buku dan tanggal pengembaliannya, serta display kartu anggota perpustakaan. Berdasarkan ketentuan proyek akhir, kami telah menerapkan struktur data Linked List dan Binary Tree dengan penjelasan lebih lanjut pada video berikut.
### Link video: (link)
Dalam program ini, kami menggunakan struktur data linked list untuk menyimpan daftar buku beserta spesifikasinya, yaitu kode buku, status dipinjam/tersedia dan peminjamnya. Serta tanggal pengembaliannya. Penambahan dan pembacaan node dari struktur data ini digunakan pada fungsi peminjam yang bertambah dan diurutkan tanggal pengembaliannya.
### Menu Daftar Buku
Menu ini akan menampilkan daftar buku yang dapat dipinjam dengan status ketersediaan dan tanggal pengembalian dair buku yang sedang dipinjam. Case ini menggunakan fungsi sort untuk linked list agar dapat menampilkan buku berurutan berdasarkan tanggal pengembaliannya.
### Menu Peminjaman Buku
Menu ini akan meminta input data user yang ingin meminjam berupa nama, NPM, tanggal peminjaman, serta kode buku. Program lalu akan memberi tanggal pengembalian dan kode peminjaman bila buku tersedia dan apabila buku sedang dipinjam, program akan menampilkan pesan error. Case ini memanfaatkan struktur linked list yang bisa ditambahkan nodenya dengan peminjam baru sebagai node baru.
### Menu Rincian Peminjam Buku
Menu akan meminta input berupa kode peminjaman dari user dan menampilkan rincian data berupa data peminjam, kode buku yang dipinjam, dan tanggal pengembaliannya. Case ini memanfaatkan searching yang diterapkan di binary tree.
### Menu Daftar Anggota
Menu ini akan meminta input data user yang ingin mendaftar sebagai anggota dari perpustakaan dan menampilkan kartu perpustakaan. Case ini memanfaatkan array satu dimensi yang dipassing ke dalam fungsi display kartu.

