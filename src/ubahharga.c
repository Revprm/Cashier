#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void ubahharga(){
    system("cls");
    FILE *FP;
    Inf brng = {"", "", 0, 0, 0, 0, 0};

    if ((FP = fopen("listbrg.dat", "rb+")) == NULL){
        printf("File tidak bisa dibuka.\n");
        fclose(FP);
    }
    else{
        while (1){
            FP = fopen("listbrg.dat", "rb+");
            lihbarang();

            char findkode[5];
            printf("Masukkan kode barang> ");
            scanf("%s", findkode);
            
            if (strcmp(findkode, "0") == 0){
                system("cls");
                break;
            }
            while (!feof(FP)){
                fread(&brng, sizeof(Inf), 1, FP);
                if (!strcmp(brng.kode, findkode)){
                    printf("Masukkan harga jual sekarang> ");
                    scanf("%d", &brng.harga_j);

                    int a = atoi(brng.kode);
                    fseek(FP, (a - 1) * sizeof(Inf), SEEK_SET);
                    fwrite(&brng, sizeof(Inf), 1, FP);
                    break;
                }
            }
            fclose(FP);
            system("cls");
        }
    }
}