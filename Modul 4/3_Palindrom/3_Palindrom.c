#include <stdio.h>
#include <conio.h>
#include <string.h>

int inputChar();
int konfersiKeHurufKecil();
int pemecahKata();
int main();
void keluar();
void pilihan_ulang();
void setDefault();
void balikKata();
void output();
void menu_utama();

//fungsi inputan char
int inputChar(char kata[100]){
    int i = 0;
    int salah = 0;
    while(kata[i] != '\0'){
        if((kata[i] >= 97 && kata[i] <= 122) || (kata[i] >= 65 && kata[i] <= 90)){
            i++;
        }else{
            salah = 1;
            kata[i] = '\0';
        }
    }
    if(salah == 1){
        return 1;
    }else{
        return 0;
    }
}

//prosedur untuk keluar program
void keluar(){
    printf("\n     Terima Kasih");
	sleep(1);
    system("cls");
    system("exit");
}

//prosedur untuk pemilihan ulang pada program
//strcmp digunakan untuk membandingkan string dengan string lainnya
void pilihan_ulang(){
    char huruf_ulang[1];

    printf("\n     Lakukan lagi? ya/keluar(y/e) : ");
    scanf("%s", &huruf_ulang);
    fflush(stdin);

    if((strcmp(huruf_ulang, "y") != 0) && (strcmp(huruf_ulang, "e") != 0) && (strcmp(huruf_ulang, "Y") != 0) && (strcmp(huruf_ulang, "E") != 0)){
        printf("    Masukan anda salah! Masukan dengan benar\n");
        pilihan_ulang();
    }else if((strcmp(huruf_ulang, "y") == 0)){
        system("cls");
        menu_utama();
     }else if((strcmp(huruf_ulang, "Y") == 0)){
        system("cls");
        menu_utama();
    }else{
        keluar();
    }
}

//fungsi untuk mengkonfersi huruf kecil
int konfersiKeHurufKecil(char kataDuplicate[]){
    int i = 0;
    while(kataDuplicate[i] != '\0'){
        if(kataDuplicate[i] >= 65 && kataDuplicate[i] <= 90){
            kataDuplicate[i] = kataDuplicate[i] + 32;
        }
        i++;
    }

    return i;
}

void setDefault(char detailHuruf[], int jumlahDetailHuruf[], int jumlahKata){
    int i;
    for(i = 0; i < jumlahKata; i++){
        detailHuruf[i] = "";
        jumlahDetailHuruf[i] = 0;
    }
}

int pemecahKata(char kataDuplicate[], char detailHuruf[], int jumlahDetailHuruf[], int jumlahKata){
    int i, j;
    int jumlahHurufTemp;
    int detect;
    int posisiHuruf = 0;

    for(i = 0; i < jumlahKata; i++){
        jumlahHurufTemp = 0;
        detect = 0;

        for(j = 0; j < jumlahKata; j++){
            if(kataDuplicate[i] == detailHuruf[j]){
                detect = 1;
            }
        }

        if(detect == 0){
            jumlahHurufTemp = 1;
            for(j = (i+1); j < jumlahKata; j++){
                if(kataDuplicate[i] == kataDuplicate[j]){
                    jumlahHurufTemp = jumlahHurufTemp + 1;
                }
            }
            detailHuruf[posisiHuruf] = kataDuplicate[i];
            jumlahDetailHuruf[posisiHuruf] = jumlahHurufTemp;
            posisiHuruf = posisiHuruf + 1;
        }
    }

    return posisiHuruf;
}

void balikKata(char kataTerbalik[], int jumlahKata){
    int i, j, k, temp;
    for(i = 0; i < jumlahKata; i++){
        k = jumlahKata - (i + 1);
        for(j = 0; j < k; j++){
            temp = kataTerbalik[j];
            kataTerbalik[j] = kataTerbalik[j+1];
            kataTerbalik[j+1] = temp;
        }
    }
}

void output(char kataAsli[], int jumlahKata, char detailHuruf[], int jumlahDetailHuruf[], char kataTerbalik[], char kataDuplicate[], int posisiHuruf){
    int i;
    FILE *output = fopen("kamuskata.txt","a");
	fprintf(output,"%s(%d) : ",kataAsli, jumlahKata);

    /* Menampilkan jumlah detail huruf */
    for(i = 0; i < posisiHuruf; i++){
        fprintf(output,"%c=", detailHuruf[i]);
        fprintf(output,"%d ", jumlahDetailHuruf[i]);
    }

    /* Deteksi Palinfrom dengan membandingkan kataTerbalik dengan kataDuplicate */
    if(strcmp(kataTerbalik, kataDuplicate) == 0){
        fprintf(output,": Palindrom\n");
    }else{
        fprintf(output,": Bukan Palindrom\n");
    }
	fclose(output);
}

void menu_utama(){
    int angka = 0;
    char kataAsli[100];
    char kataDuplicate[100];
    char kataTerbalik[100];
    int jumlahKata = 0;
    int posisiHuruf;
    int i, j, k, temp;

	printf(" =================================================\n");
	printf("|             PROGRAM KATA PALINDROM              |\n");
	printf(" =================================================\n");
    printf("     Masukan Kata : ");
    scanf("%[^\n]", &kataAsli);
    angka = inputChar(kataAsli);

    /* Mendeteksi validasi jika berniali 1 maka harus mengulang input, jika 0 maka lewat */
    while(angka == 1){
        printf("     Masukkan salah! Masukkan format kata yang benar : ");
        scanf("%[^\n]", &kataAsli);
        angka = inputChar(kataAsli);
    }

    /* Membuat duplicate kataAsli untuk dijadikan huruf kecil semua supaya bisa tidak sensitif huruf */
    strcpy(kataDuplicate, kataAsli);

    /* Membuat huruf dalam kataDuplicate menjadi huruf kecil semua */
    jumlahKata = konfersiKeHurufKecil(kataDuplicate);

    /* Pendeklarasian variabel untuk menyimpan detail huruf */
    char detailHuruf[jumlahKata];
    int jumlahDetailHuruf[jumlahKata];

    /* Set nilai dari detailHuruf dan jumlahDetailHuruf  menjadi kosong, agar tidak ada nilai acak */
    setDefault(detailHuruf, jumlahDetailHuruf, jumlahKata);

    /* Proses mendapat jumlah per huruf */
    posisiHuruf = pemecahKata(kataDuplicate, detailHuruf, jumlahDetailHuruf, jumlahKata);

    /* Menyalin isi dari kata duplicate ke kata terbalik agar kata yang dibalik terpisah dengan kata asli untuk dibandingkan Palindromnya */
    strcpy(kataTerbalik, kataDuplicate);

    /* Membalikan karakter di kata */
    balikKata(kataTerbalik, jumlahKata);

    /* Proses output ke file txt */
    output(kataAsli, jumlahKata, detailHuruf, jumlahDetailHuruf, kataTerbalik, kataDuplicate, posisiHuruf);

    printf("\n     Output:\n");
    printf("       %s(%d) : ",kataAsli, jumlahKata);

    for(i = 0; i < posisiHuruf; i++){
        printf("%c=", detailHuruf[i]);
        printf("%d ", jumlahDetailHuruf[i]);
    }

    /* Deteksi Palinfrom dengan membandingkan kataTerbalik dengan kataDuplicate */
    if(strcmp(kataTerbalik, kataDuplicate) == 0){
        printf(": Palindrom\n");
    }else{
        printf(": Bukan Palindrom\n");
    }
    printf("     * Data sudah dimasukan ke kamuskata.txt\n");
	printf(" =================================================");
    pilihan_ulang();
}

int main(){
    system("cls");
    menu_utama();

    return 0;
}
