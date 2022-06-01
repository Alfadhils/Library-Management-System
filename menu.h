#include <stdio.h>

int menu (void);

int menu (void) {
	int pilihanMenu;
	printf("| MENU |\n\n"); 
	printf("1. Daftar Buku\n");
	printf("2. Peminjaman Buku\n");
	printf("3. Rincian Peminjam Buku\n");
	printf("4. Daftar Anggota Perpustakaan\n");
	printf("5. Keluar\n\n");
	do { //error handling
		printf("Masukan angka untuk memilih menu : ");
		scanf("%i", &pilihanMenu);
		if (pilihanMenu <0 || pilihanMenu >5) 
		printf(">> ERROR : pilihan tidak valid (Harap input ulang)\n\n");
	} while (pilihanMenu <0 || pilihanMenu >5); //batas error handling
	return pilihanMenu;
}
