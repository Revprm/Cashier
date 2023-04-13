#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"

void strkTransaksi(){
    FILE *FPstrng;
    Psn strk = {"", "", 0, 0, 0, 0, 0, 0, 0, 0};

    if ((FPstrng = fopen("strk.dat", "rb")) == NULL){
        printf("File tidak bisa dibuka.\n");
        fclose(FPstrng);
    }
    else{
        system("cls");
        bool dam = true;
        printf("Struk Transaksi\n");
        while (!feof(FPstrng)){
            if (fread(&strk, sizeof(Psn), 1, FPstrng)){
                if (strcmp(strk.kode, "0")){
                    if (dam == true){
                        printf("Tanggal dan Waktu: ");
                        if (strk.hari < 10){
                            printf("0%d/", strk.hari);
                        }
                        else{
                            printf("%d/", strk.hari);
                        }
                        if (strk.bulan < 10){
                            printf("0%d/", strk.bulan);
                        }
                        else{
                            printf("%d/", strk.bulan);
                        }
                        printf("%d\t", strk.tahun);
                        if (strk.jam < 10){
                            printf("0%d:", strk.jam);
                        }
                        else{
                            printf("%d:", strk.jam);
                        }
                        if (strk.menit < 10){
                            printf("0%d:", strk.menit);
                        }
                        else{
                            printf("%d:", strk.menit);
                        }
                        if (strk.detik < 10){
                            printf("0%d\n\n", strk.detik);
                        }
                        else{
                            printf("%d\n\n", strk.detik);
                        }
                        printf("---------------------------------------------------------------------\n");
                        printf("|%-7s\t\t%-14s\t\t%-12s   %s|\n", "Kode", "Nama Barang", "Jumlah", "Harga");
                        printf("---------------------------------------------------------------------\n");
                        dam = false;
                    }
                    printf("|%-7s\t\t%-14s\t\t%6d\t%11d |\n", strk.kode, strk.name, strk.jumlah, strk.harga);
                }
                
            }
            
        }
        fclose(FPstrng);
        printf("---------------------------------------------------------------------\n");
        printf("|%29s\t\t\t\t  %9d |\n", "Total Belanja:Rp ", t_harga);
        printf("|%29s\t\t\t\t  %9d |\n", "Uang yang dibayar:Rp ", pay);
        printf("|%29s\t\t\t\t  %9d |\n", "Kembalian:Rp ", change);
        printf("---------------------------------------------------------------------\n\n\n\n");
    }
}