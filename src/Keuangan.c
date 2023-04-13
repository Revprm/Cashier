#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"

void Keuangan(){
    system("cls");
    FILE *FP;
    Inf brng = {"", "", 0, 0, 0, 0, 0};

    if ((FP = fopen("listbrg.dat", "rb")) == NULL){
        printf("File tidak bisa dibuka.\n");
        fclose(FP);
    }
    else{
        bool dapat = false;
        int s_stock = 0;
        int m = 0;
        int b = 0;
        int s = 0;

        while (!feof(FP)){
            if (fread(&brng, sizeof(Inf), 1, FP)){
                if (strcmp(brng.name, "") && strcmp(brng.kode, "0")){
                    if (dapat == false){
                        printf("Keuangan Toko\n");
                        printf("%-7s%-14s%-7s%-13s%-13s%-13s%s\n", "Kode", "Nama Barang", "Stok", "Harga Jual", "Pengeluaran", "Pendapatan", "Laba/Rugi");
                    }
                    printf("%-7s%-14s%4d%13d%14d%12d%12d\n", brng.kode, brng.name, brng.stok, brng.harga_j, brng.modal, brng.modal_b, brng.stat);

                    s_stock+=brng.stok;
                    m+=brng.modal;
                    b+=brng.modal_b;
                    dapat = true;
                }
            }
        }
        if (dapat == false){
            printf("Belum ada barang yang dimasukkan.\n");
        }
        else{
            printf("Stok yang tersisa   : %d\n", s_stock);
            printf("Total pengeluaran   : Rp%d\n", m);
            printf("Total Pendapatan    : Rp%d\n", b);
            printf("Rugi/Untung         : ");
            s = b - m;
            if (s < 0){
                s*=-1;
                printf("Rugi Rp%d\n\n", s);
            }
            else if (s >= 0){
                printf("Untung Rp%d\n\n", s);
            }
        }
        fclose(FP);
    }
}