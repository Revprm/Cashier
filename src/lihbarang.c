#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

void lihbarang(){
    system("cls");
    FILE *FP;
    Inf brng = {"", "", 0, 0, 0, 0, 0};

    if ((FP = fopen("listbrg.dat", "rb")) == NULL){
        printf("File tidak bisa dibuka.\n");
        fclose(FP);
    }
    else{
        int mitsuketa = 0;
        while (!feof(FP)){
            if (fread(&brng, sizeof(Inf), 1, FP)){
                if (strcmp(brng.kode, "0") && strcmp(brng.name, "")){
                    if (mitsuketa == 0){
                    	printf("-------------------------------------------------\n");
                        printf("|        List Barang-barang yang Tersedia       |\n");
                    	printf("-------------------------------------------------\n");
                        printf("|%-7s|%-14s|%-7s|%-14s\t|\n", 
                        "Kode", "Nama Barang", "Stok", "Harga Jual");
                        printf("-------------------------------------------------\n");
                    }	
                    printf("|%-7s|%-14s|%7d|Rp%14d|\n", 
                    brng.kode, brng.name, brng.stok, brng.harga_j);
					mitsuketa = 1;
                }
            }
        }
        printf("-------------------------------------------------\n");
        if (mitsuketa == 0){
            printf("Belum ada barang yang anda masukkan!\n");
        }
        printf("\n");
        fclose(FP);
    }
}

