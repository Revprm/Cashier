#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

void inpStok(){
    system("cls");
    FILE *FP;
    Inf brng = {"", "", 0, 0, 0, 0, 0};
    
    if ((FP = fopen("listbrg.dat", "rb+")) == NULL){
        printf("File tidak bisa dibuka.\n");
        fclose(FP);
    }
    else{
        while(1){
            FP = fopen("listbrg.dat", "rb+");
            lihbarang();

            printf("Masukkan Kode barang> ");
            char c_kode[5];
            scanf("%s", c_kode);
            if (strcmp(c_kode, "0") == 0){
                system("cls");
                break;
            }
            while (!feof(FP)){
                fread(&brng, sizeof(Inf), 1, FP);
                if (strcmp(brng.kode, c_kode) == 0){
                    printf("Masukkan jumlah stok yang ingin ditambahkan> ");
                    int t_stok;
                    scanf("%d", &t_stok);
                    brng.stok+=t_stok;

                    int h_beli;
                    printf("Masukkan harga barang tersebut> ");
                    scanf("%d", &h_beli);
                    brng.modal+=h_beli*t_stok;
                    brng.stat = brng.modal_b-brng.modal;
                    
                    if(brng.harga_j == 0){
                    	printf("Masukkan harga jual barang> ");
                    	scanf("%d", &brng.harga_j);
					}
                    int huh = atoi(brng.kode);
                    fseek(FP, (huh - 1) * sizeof(Inf), SEEK_SET);
                    fwrite(&brng, sizeof(Inf), 1, FP);
                    break;
                }
            }
            fclose(FP);
            system("cls");
        }
        
    }
}

