/*
| LIBRARY MANAGEMENT SYSTEM |

oleh Kelompok 8 Alprog 01
Anggota Kelompok:
Fadhil Umar (2006529436)
Theonaldo Vincentius A. (2006465722)
Grelyntan Natalia (2006525715)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "panduanPeminjaman.h"
#include "panduanPendaftaran.h"
#include "menu.h"

struct mahasiswa {
	char nama[50];
	char NPM[11];
	int kodeBuku;
	int kodepinjam;
	int dd;
	int mm;
	int yyyy;
	int dd_pengembalian;
	int mm_pengembalian;
	int yyyy_pengembalian;
	struct mahasiswa *next;
};

struct buku {
	char judul[50];
	int kodeBuku;
	int dateValue;
	struct mahasiswa *peminjam;
	struct buku *next;
};


struct treeNode {
	struct treeNode *leftPtr;
	int data;
	struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;


void insertNode (TreeNodePtr *treePtr, int value);
void printTree (TreeNodePtr treePtr, int spacing);
void funcPengembalian(struct mahasiswa * waktupinjam,int n);
void daftarAnggota(char nama[], char npm[]);

int main (void) {
	srand(time(NULL));
	int pilihanMenu = 0;
	int kode = 0;
	
	TreeNodePtr rootPtr = NULL;
	
	//struct untuk linked list
	struct buku *headAddress = NULL;
	struct buku *iteratorPtr;
	struct buku *tempAddressA;
	struct buku *tempAddressB;
	
	struct mahasiswa *headAddress2 = NULL;
	struct mahasiswa *iteratorPtr2;
	struct mahasiswa *tempAddress2;
	
	//membuat linked list untuk 5 buku awal
	struct buku *Kalkulus;
	struct buku *Alin;
	struct buku *Fismek;
	struct buku *RL1;
	struct buku *Elmag;
	
	//membuat node dengan mengalokasikan memory terlebih dahulu
	Kalkulus = malloc(sizeof(struct buku));
	Alin = malloc(sizeof(struct buku));
	Fismek = malloc(sizeof(struct buku));
	RL1 = malloc(sizeof(struct buku));
	Elmag = malloc(sizeof(struct buku));
	
	//memasukan data dan menghubungkan antar node
	strcpy(Kalkulus->judul,"Kalkulus         ");
	Kalkulus->kodeBuku = 101;
	Kalkulus->next = Alin;
	Kalkulus->peminjam = NULL;

	
	strcpy(Alin->judul,"Aljabar Linear  ");
	Alin->kodeBuku = 102;
	Alin->next = Fismek;
	Alin->peminjam = NULL;


	strcpy(Fismek->judul,"Fisika Mekanika ");
	Fismek->kodeBuku = 201;
	Fismek->next = RL1;
	Fismek->peminjam = NULL;

		
	strcpy(RL1->judul,"Rangkaian Listrik 1");
	RL1->kodeBuku = 202;
	RL1->next = Elmag;
	RL1->peminjam = NULL;
	
	strcpy(Elmag->judul,"Elektromagnetika");
	Elmag->kodeBuku = 301;
	Elmag->next = NULL;
	Elmag->peminjam = NULL;		
	
	headAddress = Kalkulus;

	printf("LIBRARY MANAGEMENT SYSTEM\n");
	printf("Program ini bertujuan memudahkan akses peminjaman buku online.\n\n");
	do {
	pilihanMenu = menu ();
		switch (pilihanMenu) {
			case 1: {
				
				if (headAddress != NULL) { //convert tanggal pengembalian ke integer agar dapat disort
					iteratorPtr = headAddress;
					while(iteratorPtr != NULL) {
						if(iteratorPtr->peminjam == NULL){
							iteratorPtr->dateValue = 0;
						}
						else{
							iteratorPtr->dateValue = iteratorPtr->peminjam->dd_pengembalian*1 + iteratorPtr->peminjam->mm_pengembalian*30 + iteratorPtr->peminjam->yyyy_pengembalian*12*30;
						}
						iteratorPtr = iteratorPtr->next;
					}
				}
				
				if(headAddress != NULL) { //bubble sort linked list
					iteratorPtr = headAddress;
					while (iteratorPtr != NULL) {
						tempAddressA = iteratorPtr;
						while(tempAddressA->next != NULL){
							if(tempAddressA->dateValue > tempAddressA->next->dateValue){
								swapList(&headAddress, tempAddressA, tempAddressA->next);
							}
							else {
								tempAddressA = tempAddressA->next;
							}
						}
						iteratorPtr = iteratorPtr->next;
					}
				}
				
				printf("\nDaftar Buku\n");
				printf("Kode\tNama Buku\t\t\tKesediaan\tPengembalian\n");
				if(headAddress != NULL) {
					iteratorPtr = headAddress;
					while (iteratorPtr != NULL) {
						printf("%d\t%s\t\t", iteratorPtr->kodeBuku, iteratorPtr->judul);
						if(iteratorPtr->peminjam == NULL) {
							printf("Tersedia\t-\n");
						}
						else {
							printf("Dipinjam\t%d/%d/%d\n",iteratorPtr->peminjam->dd_pengembalian,iteratorPtr->peminjam->mm_pengembalian,iteratorPtr->peminjam->yyyy_pengembalian);
						}
						iteratorPtr = iteratorPtr->next;
					}
				}
				
				system("pause");
				system("cls");
				break;
			}
			
			case 2: {
				int error = 0;
				printf("| MENU > Peminjaman |\n\n"); 	
				panduanPeminjaman();						
				printf("| MENU > Peminjaman |\n\n"); 
				
				struct mahasiswa *tempAddress;
				tempAddress = malloc(sizeof(struct mahasiswa));
				
				printf("Masukkan Nama Mahasiswa : ");	
				scanf(" %49[^\n]", tempAddress->nama);
				fflush(stdin);
				printf("Masukkan NPM : ");
				scanf(" %10[^\n]", tempAddress->NPM);
				fflush(stdin);
				
				do{
					printf("Kode buku yang ingin dipinjam : ");
					scanf("%d", &tempAddress->kodeBuku);
					if (headAddress != NULL) {
						iteratorPtr = headAddress;
						while(iteratorPtr != NULL) {
							if(iteratorPtr->kodeBuku == tempAddress->kodeBuku) {
								if (iteratorPtr->peminjam != NULL){
									printf(">>ERROR : Buku telah dipinjam, silahkan pilih buku yang lain\n\n");
									break;
								}
								iteratorPtr->peminjam = tempAddress;
								error = 1;
								break;
							}
						iteratorPtr = iteratorPtr->next;
						}
					}
				}while(error == 0);
				
				do { 
					printf("Tanggal Peminjaman : "); 
					scanf("%d/%d/%d", &tempAddress->dd, &tempAddress->mm, &tempAddress->yyyy);
					if (tempAddress->dd <0 || tempAddress->dd >30) 
					printf(">> ERROR : tanggal tidak valid (Harap input ulang)\n\n");
					if (tempAddress->mm <0 || tempAddress->mm >12) 
					printf(">> ERROR : bulan tidak valid (Harap input ulang)\n\n");
					if (tempAddress->yyyy <0) 
					printf(">> ERROR : tahun tidak valid (Harap input ulang)\n\n");
				} while ((tempAddress->dd < 0|| tempAddress->dd >30) || (tempAddress->mm <0 || tempAddress->mm >12) || tempAddress->yyyy <0);
				
				if(headAddress2 == NULL){
					(*tempAddress).next = NULL; 
					headAddress2 = tempAddress;
				}
				else {
					(*tempAddress).next = headAddress2;
					headAddress2 = tempAddress;
				}
				
				kode  = rand()%100;
				printf("kode peminjaman anda adalah : %d\n\n",kode);
				tempAddress->kodepinjam=kode;
				insertNode(&rootPtr, kode);
				
				funcPengembalian(tempAddress,tempAddress->kodepinjam);				
				
				printf("Nama\t\tNPM\t\tKode Buku\t\tPengembalian\n");
				if(headAddress2 != NULL) {
					iteratorPtr2 = headAddress2;
					while (iteratorPtr2 != NULL) {
						printf("%s\t\t%s\t%d\t\t\t%d/%d/%d\n", iteratorPtr2->nama, iteratorPtr2->NPM, iteratorPtr2->kodeBuku, iteratorPtr2->dd_pengembalian,iteratorPtr2->mm_pengembalian,iteratorPtr2->yyyy_pengembalian);
						iteratorPtr2 = iteratorPtr2->next;
					}
				}
				
				if (headAddress != NULL) {
					iteratorPtr = headAddress;
					while(iteratorPtr != NULL) {
						if(iteratorPtr->kodeBuku == tempAddress->kodeBuku) {
							iteratorPtr->peminjam = tempAddress;
							break;
						}
						iteratorPtr = iteratorPtr->next;
					}
				}
							
				system("pause");
				system("cls");
				break;
			}
			
			case 3: {
				int ditemukan = 0;
				int searchKey; 
				printf("| MENU > Rincian Peminjam Buku |\n\n");
				printf("Masukan kode Peminjaman : ");
				scanf("%d", &searchKey);
				
				printf("Binary Tree: \n\n");
				printTree(rootPtr, 0);
				printf("\n\n");
				ditemukan = searchBinary(rootPtr, searchKey);
				if (ditemukan == 1) {
					printf("Kode peminjaman ditemukan, mencari data peminjam...\n\n");
					
					if (headAddress2 != NULL) {
					iteratorPtr2 = headAddress2;
					while(iteratorPtr2 != NULL) {
						if(iteratorPtr2->kodepinjam == searchKey) {
							printf("%s\t\t%s\t%d\t\t\t%d/%d/%d\n", iteratorPtr2->nama, iteratorPtr2->NPM, iteratorPtr2->kodeBuku, iteratorPtr2->dd_pengembalian,iteratorPtr2->mm_pengembalian,iteratorPtr2->yyyy_pengembalian);
							break;
						}
						iteratorPtr2 = iteratorPtr2->next;
					}
				}
				}
				else{
					printf("Kode peminjaman tidak ditemukan!\n\n");
				}
				
				system("pause");
				system("cls");
				break;
			}
			
			case 4: {
				char namaPendaftar[50];
				char npmPendaftar[11];
				int i = 0;
				printf("| MENU > Daftar Anggota |\n\n"); 	
				panduanPendaftaran();						
				printf("| MENU > Daftar Anggota |\n\n"); 
				printf("Masukkan Nama Mahasiswa : ");	
				scanf(" %49[^\n]", &namaPendaftar);
				fflush(stdin);
				printf("Masukkan NPM : ");
				scanf(" %10[^\n]", &npmPendaftar);
				printf("\nTanda kartu anggota:\n");
				daftarAnggota(namaPendaftar, npmPendaftar);
				fflush(stdin);
				system("pause");
				system("cls");
				break;
			}
			
			case 5: {
				printf("Terima Kasih Telah Menggunakan Program!\n\n"); 
				system ("pause");
				break;
			}
		
		} 
	} while (pilihanMenu != 5);
 	return 0;
	
}

void insertNode (TreeNodePtr *treePtr, int value) {
	
	//if tree empty
	if (*treePtr == NULL) {
		*treePtr = malloc(sizeof(TreeNode));
		
		if(*treePtr != NULL) {
			(*treePtr)->data = value;
			(*treePtr)->leftPtr = NULL;
			(*treePtr)->rightPtr = NULL;
		}
		else {
			printf("%d not inserted. No memory available.\n");
		}
	} 
	
	//tree is not empty
	else {
		if(value < (*treePtr)->data) {
			insertNode (&((*treePtr)->leftPtr), value);
		} 
		
		else if (value > (*treePtr)->data) {
			insertNode (&((*treePtr)->rightPtr), value);
		}
		
		else {
			printf("dup");
		}
	}
}

int searchBinary(TreeNodePtr treePtr, int key) {
	if (treePtr != NULL) {
		if(treePtr->data == key) {
			return 1;
		}
		searchBinary(treePtr->leftPtr, key);
		searchBinary(treePtr->rightPtr, key);
	}
}


void printTree (TreeNodePtr treePtr, int spacing) {
	int i;
	if (treePtr != NULL) {
		spacing++;
		printTree(treePtr->rightPtr, spacing);
		for(i=0; i<spacing; i++) {
			printf("\t");
		}
		printf("%d\n", treePtr->data);
		printTree(treePtr->leftPtr, spacing);
	}
}

void daftarAnggota(char nama[], char npm[]){
	printf("\n");
	printf(" _______________________________________________________");
	printf("\n|"); printf("\t\t\t\t\t\t\t|");
	printf("\n|"); printf("\t\t   UNIVERSITAS INDONESIA"); printf("\t\t|");
	printf("\n|"); printf("\t\tVeritas, Probitas, Isutisia"); printf("\t\t|");
	printf("\n|"); printf("\t\t\t\t\t\t\t|");
	printf("\n|-------------------------------------------------------"); printf("|");
	printf("\n|"); printf("\t\t\t\t\t\t\t|");
	printf("\n|"); printf("\t -------"); printf("\t\t\t\t\t|");
	printf("\n|"); printf("\t|  | |  |"); printf("\t%s", nama);
	if(strlen(nama)<8){
		printf("\t\t\t\t|");
	}
	else if(strlen(nama)>=8 && strlen(nama)<16){
		printf("\t\t\t|");
	}
	else if(strlen(nama)>=16 && strlen(nama)<24){
		printf("\t\t|");
	}
	else {
		printf("\t|");
	}
	
	printf("\n|"); printf("\t|--- ---|"); printf("\t%s", npm);
	if(strlen(npm)<8){
		printf("\t\t\t\t|");
	}
	else{
		 printf("\t\t\t|");
	}
	
	printf("\n|"); printf("\t\t\t\t\t\t\t|");
	printf("\n|"); printf("_______________________________________________________|\n");
}

void swapList(struct buku** head_ref, struct buku A, struct buku B){
	struct buku *iteratorPtr;
	struct buku *iteratorPtr2;
	struct buku *tempAddress;
	if (head_ref != NULL) {
		iteratorPtr = *head_ref;
		struct buku *prevA = NULL, *currA = *head_ref;
		struct buku *prevB = NULL, *currB = *head_ref;
		while (currA && currA->kodeBuku != A.kodeBuku) {
			prevA = currA;
		    currA = currA->next;
		}
   		while (currB && currB->kodeBuku != B.kodeBuku) {
			prevB = currB;
        	currB = currB->next;
    	}
		if (prevA != NULL)
	        prevA->next = currB;
	    else 
	        *head_ref = currB;

	    if (prevB != NULL)
	        prevB->next = currA;
	    else 
	        *head_ref = currA;
	 
	    // Swap next pointers
	    struct buku* temp = currB->next;
	    currB->next = currA->next;
	    currA->next = temp;
	}
}	

void funcPengembalian(struct mahasiswa * waktupinjam,int n){
	struct mahasiswa *iteratorPtr;
	if(waktupinjam != NULL){
		iteratorPtr = waktupinjam;
		iteratorPtr->dd_pengembalian = iteratorPtr->dd+7;
		iteratorPtr->mm_pengembalian = iteratorPtr->mm;
		if (iteratorPtr->dd_pengembalian>30){
			iteratorPtr->dd_pengembalian = iteratorPtr->dd_pengembalian-30;
			iteratorPtr->mm_pengembalian++;
		}
		iteratorPtr->yyyy_pengembalian = iteratorPtr->yyyy;
		if (iteratorPtr->mm_pengembalian>12){
			iteratorPtr->mm_pengembalian = iteratorPtr->mm_pengembalian-12;
			iteratorPtr->yyyy_pengembalian++;
		}
	}		
}

