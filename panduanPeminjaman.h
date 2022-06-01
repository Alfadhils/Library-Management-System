#include <stdio.h>

void panduanPeminjaman (void);

void panduanPeminjaman (void) {
	printf("Panduan : ");
	printf("\n- Program akan meminta input berupa nama mahasiswa, NPM, tanggal peminjaman, dan kode buku yang ingin dipinjam.");
	printf("\n- Kode buku yang ingin dipinjam dapat dilihat di menu 1. Daftar Buku.");
	printf("\n- Anda dapat meminjam hanya 1 buku.");
	printf("\n- Buku harus dikembalikan maksimal 7 hari setelah tanggal peminjaman.");
	printf("\n- Program akan memberikan batas hari pengembalian buku.");
	printf("\n- Anda dapat melihat detail peminjaman dengan memasukkan kode peminjaman di menu 3. Rincian Peminjam Buku.\n\n");
	system("pause");
	system("cls");
}
