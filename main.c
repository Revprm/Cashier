#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main(){
    while (1){
        int perintah;
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("|                                                        Tevyat mart                                                   |\n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("|                                               Selamat datang di toko kami!                                           |\n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
		printf("|                                                  Menu yang dapat dilihat                                             |\n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("|(1)                                                     Transaksi                                                     |\n");
        printf("|(2)                                                  Struk Transaksi                                                  |\n");
        printf("|(3)                                            Transaksi yang Sudah Terjadi                                           |\n");
        printf("|(4)                                                    Data Barang                                                    |\n");
        printf("|(5)                                                   Keuangan Toko                                                   |\n");
        printf("|(0)                                                        Exit                                                       |\n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("Silahkan pilih angka sesuai menu yang ingin dilihat\n");
        printf("> ");
        scanf("%d", &perintah);

        if (perintah == 1){
            transaksi();
        }
        else if (perintah == 2){
            strkTransaksi();
        }
        else if (perintah == 3){
            system("cls");
            while (1){
                int mana;
                printf("------------------------------------------------------------------------------------------------------------------------\n");
                printf("|                                           Transaksi yang Sudah Terjadi                                               |\n");
                printf("------------------------------------------------------------------------------------------------------------------------\n");
                printf("|(1)                                           Cari Sesuai Kode Barang                                                 |\n");   
                printf("|(2)                                         Cari Sesuai Tahun Transaksi                                               |\n");
                printf("|(3)                                         Cari Sesuai Bulan Transaksi                                               |\n");
                printf("|(4)                                         Cari Sesuai Tanggal Transaksi                                             |\n");
                printf("|(0)                                            Kembali Ke Menu Utama                                                  |\n");
                printf("------------------------------------------------------------------------------------------------------------------------\n");
                printf("Silahkan pilih angka sesuai menu yang ingin dilihat\n");
                printf("> ");
                scanf("%d", &mana);
                
                if (mana == 1){
                    Carikod();
                }
                else if (mana == 2){
                    CariTahun();
                }
                else if (mana == 3){
                    CariBulan();
                }
                else if (mana == 4){
                    CariTanggal();
                }
                else if (mana == 0){
                    system("cls");
                    break;
                }
                else{
                    printf("Masukkan angka yang sesuai!\n\n");
                }
            }
        }
        else if (perintah == 4){
            system("cls");
            while (1){
                int mana;
                printf("------------------------------------------------------------------------------------------------------------------------\n");
                printf("|                                                   Data Barang                                                        |\n");
                printf("------------------------------------------------------------------------------------------------------------------------\n");
                printf("|(1)                                               Input Barang                                                        |\n");
                printf("|(2)                                            Tambah Stok Barang                                                     |\n");
                printf("|(3)                                                Ubah Nama                                                          |\n");
                printf("|(4)                                                Ubah Harga                                                         |\n");
                printf("|(5)                                       Lihat Data Barang yang Tersedia                                             |\n");
                printf("|(0)                                            Kembali ke Menu Utama                                                  |\n");
                printf("------------------------------------------------------------------------------------------------------------------------\n");
                printf("Silahkan pilih angka sesuai menu yang ingin dilihat\n");
                printf("> ");
                scanf("%d", &mana);

                if (mana == 1){
                	inpBarang();
				}
                else if (mana == 2){
                	inpStok();
				}
                else if (mana == 3){
                    ubahnama();
                }
                else if (mana == 4){
                    ubahharga();
                }
                else if (mana == 5){
                	lihbarang();
				}
                else if (mana == 0){
                    system("cls");
                    break;
                }
                else{
                    printf("Masukkan angka yang sesuai!\n\n");
                }
            }
        }
        else if (perintah == 5){
            Keuangan();
        }
        else if (perintah == 0){
            system("cls");
            break;
        }
        else{
            printf("Masukkan angka yang sesuai!\n\n");
        }
    }
}

