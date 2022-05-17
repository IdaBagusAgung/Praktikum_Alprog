#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>
#include <math.h>

float input();
void keluar();
void pilihan_ulang();
void hanoi_rekursif();
void hanoi_iteratif();
void metode_rekursif();
void metode_iteratif();
void menu_utama();
int main();

int langkah_rekursif = 0;

float input(int desimal){
    char masukan[100];
    int i = 0;
    int belakang = 0;
    int isi_depan = 0;
    int isi_belakang = 0;
    int status = 0;
    int titik = 0;
    int salah = 0;
    float hasil;

    scanf("%[^\n]", &masukan);
    fflush(stdin);

    while(masukan[i] != '\0'){
        if(masukan[0] == '.'){
            salah = 1;
            masukan[0] = '\0';
        }else if(masukan[i]>='0' && masukan[i]<='9' || masukan[i] == '.'){
            if((masukan[i] == '.') && (desimal == 1)){
                titik = titik + 1;
                if(titik > 1 || masukan[i+1] == '\0'){
                    salah = 1;
                    masukan[i] = '\0';
                }
                status = 1;
            }else if((masukan[i] == '.') && (desimal == 0)){
                salah = 1;
                masukan[i] = '\0';
            }
            if(masukan[i]>='0' && masukan[i]<='9'){
                if(status == 1){
                    isi_belakang = (isi_belakang * 10) + (masukan[i] - 48);
                    belakang = belakang + 1;
                }else{
                    isi_depan = (isi_depan * 10) + (masukan[i] - 48);
                }
            }
            i++;
        }else{
            salah = 1;
            masukan[i] = '\0';
        }
    }
    if(titik == 1){
        hasil = (float)isi_depan + (isi_belakang / (pow(10, belakang)));
    }else{
        hasil = isi_depan;
    }
    if(salah == 1){
        printf("     Masukkan salah! Masukkan angka yang benar : ");
        return input(desimal);
    }else if(hasil == 0){
        printf("     Masukkan tidak boleh 0! Masukkan nilai yang benar : ");
        return input(desimal);
    }else{
        return hasil;
    }
}

void keluar(){
    printf("\n     Terima Kasih");
	sleep(1);
	printf(".");
    system("cls");
    system("exit");
}

void pilihan_ulang(int target){
    char ulang[1];

    printf("\n     Lakukan lagi? ya/kembali/keluar(y/n/e) : ");
    scanf("%s", &ulang);
    fflush(stdin);

    if((strcmp(ulang, "y") != 0) && (strcmp(ulang, "n") != 0) && (strcmp(ulang, "e") != 0) &&
    (strcmp(ulang, "Y") != 0) && (strcmp(ulang, "N") != 0) && (strcmp(ulang, "E") != 0)){
        printf("     Masukan anda salah! Masukan dengan benar\n");
        pilihan_ulang(target);
    }else if((strcmp(ulang, "y") == 0)){
        system("cls");
        if(target == 1){
            metode_rekursif();
        }else if(target == 2){
            metode_iteratif();
        }
    }else if((strcmp(ulang, "Y") == 0)){
        system("cls");
        if(target == 1){
            metode_rekursif();
        }else if(target == 2){
            metode_iteratif();
        }
    }else if((strcmp(ulang, "n") == 0)){
        system("cls");
        menu_utama();
    }else if((strcmp(ulang, "N") == 0)){
        system("cls");
        menu_utama();
    }else{
        keluar();
    }
}

void hanoi_rekursif(int n, char asal[1], char bantu[1], char tujuan[1]){
    if(n == 0){
        langkah_rekursif++;
    }
    if(n > 0){
        hanoi_rekursif(n - 1, asal, tujuan, bantu);
        printf ("     * Pindahkan piringan ke %d dari %c ke %c\n", n, asal, tujuan);
        hanoi_rekursif(n - 1, bantu, asal, tujuan);
    }
}

void hanoi_iteratif(int jumlah){
    int i;
    for(i = 1; i < (1 << jumlah); i++){
        printf("     * Pindahkan piringan dari %d ke %d\n",(i&i-1)%jumlah + 1,((i|i-1)+1)%jumlah + 1);
    }
}

void metode_rekursif(){
    int jumlah;
	printf(" ================================================== \n");
	printf("|               PROGRAM MENARA HANOI               |\n");
	printf("|                 Metode Rekursif                  |\n");
	printf(" ================================================== \n");
    printf("     Masukan Jumlah Piringan : ");
    jumlah = input(0);
    printf("\n");
    printf("     Perpindahan Piringan    : \n");
    langkah_rekursif = 0;
    hanoi_rekursif(jumlah,'a','b','c');
    printf("\n");
    printf("     Total Langkah Minimum   : %d\n", langkah_rekursif - 1);
	printf(" ================================================== \n");
    pilihan_ulang(1);
}

void metode_iteratif(){
    int jumlah;
	printf(" ================================================== \n");
	printf("|               PROGRAM MENARA HANOI               |\n");
	printf("|                 Metode Iteratif                  |\n");
	printf(" ================================================== \n");
    printf("     Masukan Jumlah Piringan : ");
    jumlah = input(0);
    printf("\n");
    printf("     Perpindahan Piringan : \n");
    hanoi_iteratif(jumlah);
    printf("\n");
    printf("     Total Langkah Minimum : %d\n", (1 << jumlah) - 1);
	printf(" ================================================== \n");
    pilihan_ulang(2);
}

void menu_utama(){
    int pilihan;
	printf(" ================================================== \n");
	printf("|               PROGRAM MENARA HANOI               |\n");
	printf(" ================================================== \n");
	printf("|    Pilihan :                                     |\n");
	printf("|    1. Metode Rekursif                            |\n");
	printf("|    2. Metode Iteratif                            |\n");
	printf("|    3. Keluar                                     |\n");
	printf(" ================================================== \n");
    printf("     Masukan Pilihan : ");
    pilihan = input(0);

    if(pilihan == 1){
        system("cls");
        metode_rekursif();
    }else if (pilihan == 2){
        system("cls");
        metode_iteratif();
    }else if (pilihan == 3){
        keluar();
    }else{
        printf("\n");
        printf("     Pilihan tidak ada\n");
        printf("     Tekan apa saja untuk input ulang...");
        getch();
        system("cls");
        menu_utama();
    }
}

int main(){
    system("cls");
    menu_utama();

    return 0;
}
