#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

void inpBarang(){
    system("cls");
    FILE *FP;
    Inf brng = {"", "", 0, 0, 0, 0, 0};
    
    if ((FP = fopen("listbrg.dat", "rb+")) == NULL){
        printf("File tidak bisa dibuka.\n");
        fclose(FP);
    }
    else{
        while(1){
            printf("Masukkan kode barang> ");
            scanf("%s", brng.kode);
            if (!strcmp(brng.kode, "0")){
                system("cls");
                break;	
            }
            
            printf("Masukkan nama barang> ");
            scanf(" %[^\n]s", brng.name);
            
            int kd = atoi(brng.kode);

            fseek(FP, (kd - 1) * sizeof(Inf), SEEK_SET);
            fwrite(&brng, sizeof(Inf), 1, FP);
            fclose(FP);
            system("cls");
        }
    }
}

