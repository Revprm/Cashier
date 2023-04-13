#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Info{
    char kode[10];  
    char name[50];
    int stok;
    int harga_j;
    int modal;
    int modal_b;
    int stat;
}Inf;

typedef struct Pesan
{
    char kode[10];
    char name[50];
    int jumlah;
    int harga;
    int jam;
    int menit;
    int detik;
    int hari;
    int bulan;
    int tahun;
}Psn;

int t_harga;
int change;
int pay;

void transaksi();
void inpStok();
void inpBarang();
void lihbarang();
void ubahharga();
void ubahnama();
void strkTransaksi();
void Carikod();
void CariTahun();
void CariBulan();
void CariTanggal();
void Keuangan();
