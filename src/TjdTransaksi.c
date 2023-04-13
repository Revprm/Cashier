#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

void Carikod(){
    system("cls");
    FILE *FPlapor;  
    Psn strk = {"", "", 0, 0, 0, 0, 0, 0, 0, 0};
    
    if ((FPlapor = fopen("riwayat.dat", "rb+")) == NULL){
        printf("File tidak bisa dibuka.\n");
        fclose(FPlapor);
    }   
    else{
        while (1){
            FPlapor = fopen("riwayat.dat", "rb+");
            char findkode[5];
            printf("Masukkan kode barang> ");
            scanf("%s", findkode);
            system("cls");
            
            if (!strcmp(findkode, "0")){
                break;
            }
            int t = 0;
            int p = 0;
            while (!feof(FPlapor)){
                if (fread(&strk, sizeof(Psn), 1, FPlapor)){
                    if (!strcmp(strk.kode, findkode)){
                        if (t == 0){
                            printf("%-7s%-14s%6s%14s%20s\t  %8s\n", "Kode", "Nama Barang", "Jumlah", 
							"Total Harga", "Tanggal Transaksi", "Waktu");
                            printf("----------------------------------------------------------------------------\n");
                        }   
                        printf("%-7s%-14s%6d%14d",
                        strk.kode, strk.name, strk.jumlah, strk.harga);
                        if (strk.hari < 10){
                            printf("%11s%d/", "0", strk.hari);
                        }
                        else{
                            printf("%12d/", strk.hari);
                        }
                        if (strk.bulan < 10){
                            printf("0%d/", strk.bulan);
                        }
                        else{
                            printf("%d/", strk.bulan);
                        }
                        printf("%d\t", strk.tahun);
                        if (strk.jam < 10){
                            printf("    0%d:", strk.jam);
                        }
                        else{
                            printf("    %d:", strk.jam);
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
                        t+=strk.jumlah;
                        p+=strk.harga;
                    }
                }
            }
            if (t == 0){
                printf("Transaksi tidak ada.\n");
            }
            else{
                printf("Total barang yang terjual   :   %d\n", t);
                printf("Total uang yang diterima    : Rp%d\n", p);
            }
            printf("\n");
            fclose(FPlapor);
        }
    }
}

void CariTahun(){
    system("cls");
    FILE *FPlapor;  
    Psn strk = {"", "", 0, 0, 0, 0, 0, 0, 0, 0};
    
    if ((FPlapor = fopen("riwayat.dat", "rb+")) == NULL){
        printf("File tidak bisa dibuka.\n");
        fclose(FPlapor);
    }
    else{
        while (1){
            FPlapor = fopen("riwayat.dat", "rb+");
            int tahun;
            printf("Masukkan tahun transaksi terjadi> ");
            scanf("%d", &tahun);
            printf("\n");
            
            if (tahun == 0){
                system("cls");
                break;
            }
            int t = 0;
            int p = 0;
            while (!feof(FPlapor)){
                if (fread(&strk, sizeof(Psn), 1, FPlapor)){
                    if (strk.tahun == tahun){
                        if (t == 0){
                            printf("%-7s%-14s%6s%14s%20s\t  %8s\n", "Kode", "Nama Barang", "Jumlah", 
							"Total Harga", "Tanggal Transaksi", "Waktu");
                            printf("----------------------------------------------------------------------------\n");
                        }
                        printf("%-7s%-14s%6d%14d", 
                        strk.kode, strk.name, strk.jumlah, strk.harga);
                        if (strk.hari < 10){
                            printf("%11s%d/", "0", strk.hari);
                        }
                        else{
                            printf("%12d/", strk.hari);
                        }
                        if (strk.bulan < 10){
                            printf("0%d/", strk.bulan);
                        }
                        else{
                            printf("%d/", strk.bulan);
                        }
                        printf("%d\t", strk.tahun);
                        if (strk.jam < 10){
                            printf("    0%d:", strk.jam);
                        }
                        else{
                            printf("    %d:", strk.jam);
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
                        t+=strk.jumlah;
                        p+=strk.harga;
                    }
                }
            }
            if (t == 0){
                printf("Transaksi tidak ada.\n");
            }
            else{
                printf("Total barang yang terjual   :   %d\n", t);
                printf("Total uang yang diterima    : Rp%d\n", p);
            }
            printf("\n");
            fclose(FPlapor);
        }
    }
}

void CariBulan(){
    system("cls");
    FILE *FPlapor;  
    Psn strk = {"", "", 0, 0, 0, 0, 0, 0, 0, 0};
    
    if ((FPlapor = fopen("riwayat.dat", "rb+")) == NULL){
        printf("File tidak bisa dibuka.\n");
        fclose(FPlapor);
    }
    else{
        while (1){
            FPlapor = fopen("riwayat.dat", "rb+");
            int bulan;
            printf("Masukkan bulan transaksi terjadi> ");
            scanf("%d", &bulan);
            printf("\n");
            
            if (bulan == 0){
                system("cls");
                break;
            }
            int t = 0;
            int p = 0;
            while (!feof(FPlapor)){
                if (fread(&strk, sizeof(Psn), 1, FPlapor)){
                    if (strk.bulan == bulan){
                        if (t == 0){
                            printf("%-7s%-14s%6s%14s%20s\t  %8s\n", "Kode", "Nama Barang", "Jumlah", 
							"Total Harga", "Tanggal Transaksi", "Waktu");
                            printf("----------------------------------------------------------------------------\n");
                        }
                        printf("%-7s%-14s%6d%14d", 
                        strk.kode, strk.name, strk.jumlah, strk.harga);
                        if (strk.hari < 10){
                            printf("%11s%d/", "0", strk.hari);
                        }
                        else{
                            printf("%12d/", strk.hari);
                        }
                        if (strk.bulan < 10){
                            printf("0%d/", strk.bulan);
                        }
                        else{
                            printf("%d/", strk.bulan);
                        }
                        printf("%d\t", strk.tahun);
                        if (strk.jam < 10){
                            printf("    0%d:", strk.jam);
                        }
                        else{
                            printf("    %d:", strk.jam);
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
                        t+=strk.jumlah;
                        p+=strk.harga;
                    }
                }
            }
            if (t == 0){
                printf("Transaksi tidak ada.\n");
            }
            else{
                printf("Total barang yang terjual   :   %d\n", t);
                printf("Total uang yang diterima    : Rp%d\n", p);
            }
            printf("\n");
            fclose(FPlapor);
        }
    }
}

void CariTanggal(){
    system("cls");
    FILE *FPlapor;  
    Psn strk = {"", "", 0, 0, 0, 0, 0, 0, 0, 0};
    
    if ((FPlapor = fopen("riwayat.dat", "rb+")) == NULL){
        printf("File tidak bisa dibuka.\n");
        fclose(FPlapor);
    }
    else{
        while (1){
            FPlapor = fopen("riwayat.dat", "rb+");
            int tahun;
            int bulan;
            int hari;
            printf("Masukkan tahun transaksi terjadi> ");
            scanf("%d", &tahun);
            if (tahun == 0){
                system("cls");
                break;
            }
            printf("Masukkan bulan transaksi terjadi> ");
            scanf("%d", &bulan);
            if (bulan == 0){
                system("cls");
                break;
            }
            printf("Masukkan tanggal transaksi terjadi> ");
            scanf("%d", &hari);
            printf("\n");
            if (hari == 0){
                system("cls");
                break;
            }
            
            int t = 0;
            int p = 0;
            while (!feof(FPlapor)){
                if (fread(&strk, sizeof(Psn), 1, FPlapor)){
                    if (strk.tahun == tahun){
                        if (strk.bulan == bulan){      
                            if (strk.hari == hari){
                                if (t == 0){
                                    printf("%-7s%-14s%6s%14s%20s\t  %8s\n", "Kode", "Nama Barang", "Jumlah", 
							        "Total Harga", "Tanggal Transaksi", "Waktu");
                                    printf("----------------------------------------------------------------------------\n");
                                }
                                printf("%-7s%-14s%6d%14d", 
                                strk.kode, strk.name, strk.jumlah, strk.harga);
                                if (strk.hari < 10){
                                    printf("%11s%d/", "0", strk.hari);
                                }
                                else{
                                    printf("%12d/", strk.hari);
                                }
                                if (strk.bulan < 10){
                                    printf("0%d/", strk.bulan);
                                }
                                else{
                                    printf("%d/", strk.bulan);
                                }
                                printf("%d\t", strk.tahun);
                                if (strk.jam < 10){
                                    printf("    0%d:", strk.jam);
                                }
                                else{
                                    printf("    %d:", strk.jam);
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
                                t+=strk.jumlah;
                                p+=strk.harga;
                            }
                        }
                        
                    }
                    
                }
            }
            if (t == 0){
                printf("Transaksi tidak ada.\n");
            }
            else{
                printf("Total barang yang terjual   :   %d\n", t);
                printf("Total uang yang diterima    : Rp%d\n", p);
            }
            printf("\n");
            fclose(FPlapor);
        }
    }   
}