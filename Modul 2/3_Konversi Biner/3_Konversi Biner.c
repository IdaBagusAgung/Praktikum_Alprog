#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>
#include <math.h>

float input();
void menu_utama();
void keluar();
void pilihan_ulang();
int valDesimal();
int valBiner();
int convertToInt();
int rumus_desimal_to_biner();
int rumus_biner_to_desimal();
int hitungDigit();
void desimal_to_biner();
void biner_to_desimal();
int main();

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

void menu_utama(){
    int pilihan;
	printf(" ================================================== \n");
	printf("||       PROGRAM KONVERSI BINER DAN DESIMAL       ||\n");
	printf(" ================================================== \n");
	printf("||MENU :                                          ||\n");
	printf("|| 1. Desimal To Biner                            ||\n");
	printf("|| 2. Biner TO Desimal                            ||\n");
	printf("|| 3. Keluar                                      ||\n");
	printf(" ================================================== \n");
    printf(" Pilih Menu : ");
    pilihan = input(0);

    if(pilihan == 1){
        system("cls");
        desimal_to_biner();
    }else if (pilihan == 2){
        system("cls");
        biner_to_desimal();
    }else if (pilihan == 3){
        keluar();
    }else{
        printf("\n");
        printf(" Menu Pilihan tidak ada\n");
        printf(" Tekan apa saja untuk input ulang...");
        getch();
        system("cls");
    }
}

void keluar(){
    system("cls");
    system("exit");
}

void pilihan_ulang(int target){
    char ulang[1];

    printf("\n Lakukan lagi? ya/kembali/keluar(Y/N/E) : ");
    scanf("%s", &ulang);
    fflush(stdin);

    if((strcmp(ulang, "y") != 0) && (strcmp(ulang, "n") != 0) && (strcmp(ulang, "e") != 0) &&
    (strcmp(ulang, "Y") != 0) && (strcmp(ulang, "N") != 0) && (strcmp(ulang, "E") != 0)){
        printf(" Masukan anda salah! Masukan dengan benar\n");
        pilihan_ulang(target);
    }else if((strcmp(ulang, "y") == 0)){
        system("cls");
        if(target == 1){
            desimal_to_biner();
        }else if(target == 2){
            biner_to_desimal();
        }
    }else if((strcmp(ulang, "Y") == 0)){
        system("cls");
        if(target == 1){
            desimal_to_biner();
        }else if(target == 2){
            biner_to_desimal();
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

int valDesimal(char masukan[]){
    int i = 0;
    int salah = 0;

    while(masukan[i] != '\0'){
        if(masukan[i] >= '0' && masukan[i] <= '9'){
            i++;
        }else{
            salah = 1;
            masukan[i] = '\0';
        }
    }

    if(salah == 1){
        return 0;
    }else{
        return 1;
    }
}

int valBiner(char masukan[]){
    int i = 0;
    int salah = 0;

    while(masukan[i] != '\0'){
        if(masukan[i] == '0' || masukan[i] == '1'){
            i++;
        }else{
            salah = 1;
            masukan[i] = '\0';
        }
    }

    if(salah == 1){
        return 0;
    }else{
        return 1;
    }
}

int convertToInt(char masukan[]){
    int i = 0;
    int hasil = 0;
    while(masukan[i] != '\0'){
        hasil = (hasil * 10) + (masukan[i] - 48);
        i++;
    }

    return hasil;
}

int rumus_desimal_to_biner(int angka_desimal){
    int i, a = 1,b = 0, d;

    for(i = angka_desimal; i >= 1; i /= 2){
        d = i % 2;
        b = b + (a * d);
        a = a * 10;
    }

    return b;
}

int rumus_biner_to_desimal(char angka_biner[]){
    int a = 0;
    int jumlah = 0;
    int hasil = 0;

    while(angka_biner[a] != '\0'){
        jumlah++;
        a++;
    }

    a = 0;

    while(angka_biner[a] != '\0'){
        hasil = hasil + ((angka_biner[a] - 48) * (pow(2,jumlah - 1)));
        jumlah = jumlah - 1;
        a++;
    }

    return hasil;
}

int hitungDigit(int angka){
    int i = angka;
    int digit = 0;
    while(i > 0){
        i = (i - (i % 10)) / 10;
        digit++;
    }

    return digit;
}

void desimal_to_biner(){
    char charDesimal[100];
    int hasilVal;
    int intDesimal;
    int hasilBiner;
    int digit;
    int sisanol;
    int i;

	printf(" ================================================== \n");
	printf("||       PROGRAM KONVERSI DESIMAL TO BINER        ||\n");
	printf(" ================================================== \n");
    printf(" Masukan Bilangan Desimal : ");
    scanf("%[^\n]", &charDesimal);
    fflush(stdin);
    hasilVal = valDesimal(charDesimal);

    while (hasilVal == 0){
        printf(" Format Salah ! Masukan bilangan desimal : ");
        scanf("%[^\n]", &charDesimal);
        fflush(stdin);
        hasilVal = valDesimal(charDesimal);
    }

    printf("\n");

    intDesimal = convertToInt(charDesimal);
    hasilBiner = rumus_desimal_to_biner(intDesimal);

    digit = hitungDigit(hasilBiner);
    sisanol = 4 - (digit % 4);

    printf(" Hasil Konversi : ");
    for(i = 0; i < sisanol; i++){
        printf("0");
    }
    printf("%d\n", hasilBiner);
	printf(" ================================================== \n");
    pilihan_ulang(1);
}

void biner_to_desimal(){
    char charBiner[100];
    int hasilVal;
    int hasilDesimal;
	printf(" ================================================== \n");
	printf("||        PROGRAM KONVERSI BINER TO DESIMAL       ||\n");
	printf(" ================================================== \n");
    printf(" Masukan Bilangan Biner   : ");
    scanf("%[^\n]", &charBiner);
    fflush(stdin);
    hasilVal = valBiner(charBiner);

    while (hasilVal == 0){
        printf(" Format Salah ! Masukan bilangan biner : ");
        scanf("%[^\n]", &charBiner);
        fflush(stdin);
        hasilVal = valBiner(charBiner);
    }

    printf("\n");

    hasilDesimal = rumus_biner_to_desimal(charBiner);

    printf(" Hasil Konversi : %d\n", hasilDesimal);
	printf(" ================================================== \n");
    pilihan_ulang(2);
}

int main(){
    system("cls");
    menu_utama();

    return 0;
}
