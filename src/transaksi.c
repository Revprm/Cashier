#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "header.h"

void transaksi(){
    FILE *FP, *FPstrng, *FPlapor;
    Inf brng = {"", "", 0, 0, 0, 0, 0};
    Psn strk = {"", "", 0, 0, 0, 0, 0, 0, 0, 0};

    if ((FP = fopen("listbrg.dat", "rb+")) == NULL){
        printf("File tidak bisa dibuka\n");
        fclose(FP);
    }
    else if ((FPstrng = fopen("strk.dat", "wb")) == NULL){
        printf("File tidak bisa dibuka\n");
        fclose(FPstrng);
    }
    else if ((FPlapor = fopen("riwayat.dat", "ab")) == NULL){
        printf("File tidak bisa dibuka\n");
        fclose(FPlapor);
    }
    else{
        int jam;
        int min;
        int det;
        int hari;
        int bln;
        int thn;
        int u_strk = 1;
        bool tcukup = false;
        t_harga = 0;
        while (1){
            FP = fopen("listbrg.dat", "rb+" );
            FPstrng = fopen("strk.dat", "rb+");
            FPlapor = fopen("riwayat.dat", "ab");   
            lihbarang();

            if (tcukup == true){
                printf("Stok kurang!\n\n");
            }
            tcukup = false;

            char findkode[5];
            printf("Masukkan kode barang yang ingin anda beli> ");
            scanf("%s", findkode);

            if (!strcmp(findkode, "0")){
                break;
            }
            else{
                while (!feof(FP)){
                    fread(&brng, sizeof(Inf), 1, FP);
                    if (!strcmp(brng.kode, findkode)){
                        int k_stk;
                        printf("Masukkan jumlah %s yang ingin dibeli> ", brng.name);
                        scanf("%d", &k_stk);

                        if (k_stk > brng.stok){
                            tcukup = true;
                            break;
                        }
                        else{
                            brng.stok-=k_stk;
                            brng.modal_b+=brng.harga_j*k_stk;
                            t_harga+=brng.harga_j*k_stk;
                            brng.stat = brng.modal_b - brng.modal;

                            int a = atoi(brng.kode);
                            fseek(FP, (a - 1) * sizeof(Inf), SEEK_SET);
                            fwrite(&brng, sizeof(Inf), 1, FP);

                            strcpy(strk.kode, brng.kode);
                            strcpy(strk.name, brng.name);
                            strk.jumlah = k_stk;
                            strk.harga = brng.harga_j*k_stk;

                            if (u_strk == 1){
                                time_t waktu_skrg;
                                time(&waktu_skrg);
                                struct tm *local = localtime(&waktu_skrg);
                                jam = local->tm_hour;
                                min = local->tm_min;
                                det = local->tm_sec;
                                hari = local->tm_mday;
                                bln = local->tm_mon + 1;
                                thn = local->tm_year + 1900;
                            }
                            strk.jam = jam;
                            strk.menit = min;
                            strk.detik = det;
                            strk.hari = hari;
                            strk.bulan = bln;
                            strk.tahun = thn;

                            fseek(FPstrng, (u_strk - 1) * sizeof(Psn), SEEK_SET);
                            fwrite(&strk, sizeof(Psn), 1, FPstrng);
                            fwrite(&strk, sizeof(Psn), 1, FPlapor);
                            u_strk++;
                            break;
                        }
                    }
                }
            }
            fclose(FP);
            fclose(FPstrng);
            fclose(FPlapor);
        }
        if (t_harga > 0){
            printf("Total belanjaan anda sebesar: Rp%d\n", t_harga);
            while (1){
                printf("Masukkan jumlah uang yang dibayar> ");
                scanf("%d", &pay);
                change = pay - t_harga;
                if (change > 0){    
                    printf("Kembalian anda sebesar %d", change);
                    break;
                }
                else if (change == 0){
                    printf("Uang anda pas! tidak ada kembalian!\n");
                    break;
                }
                else{
                    printf("Uang yang anda bayar belum cukup!\n");
                }
            }
        }
        else{
            printf("\n");
        }
    }
}