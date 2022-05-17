#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>
#include <math.h>

float input();
void keluar();
void pilihan_utama();
int fibonacci_rekursif();
void fibonacci_iteratif();
void menu_utama();
void menu_metode_rekursif();
void menu_metode_iteratif();
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
            menu_metode_rekursif();
        }else if(target == 2){
            menu_metode_iteratif();
        }
    }else if((strcmp(ulang, "Y") == 0)){
        system("cls");
        if(target == 1){
            menu_metode_rekursif();
        }else if(target == 2){
            menu_metode_iteratif();
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

int fibonacci_rekursif(int n){
    if(n == 0 || n == 1){
        return n;
    }else{
        return (fibonacci_rekursif(n-1) + fibonacci_rekursif(n-2));
    }
}

void fibonacci_iteratif(int n){
    int i, a = 0, b = 1, c;
    for(i = 0; i < n; i++){
        if(i == 0){
            printf("%d", a);
        }else if(i == 1){
            printf(", %d", b);
        }else{
            c = a + b;
            printf(", %d", c);
            a = b;
            b = c;
        }
    }
}

void menu_metode_rekursif(){
    int deret, i, j = 0;
    printf(" ===================================================\n");
	printf("|               PROGRAM DERET FIBONACCI             |\n");
	printf("|                   Metode Rekursif                 |\n");
    printf(" ===================================================\n");
    printf("   INPUT\n");
    printf("   - Masukan jumlah bilangan fibonacci : ");
    deret = input(0);
    printf("\n");
    printf("   HASIL\n");
    printf("   - Deret fibonacci metode rekursif : \n");
    printf("     ");
    for(i = 1; i <= deret; i++){
        if(i != deret){
            printf("%d, ", fibonacci_rekursif(j));
        }else{
            printf("%d", fibonacci_rekursif(j));
        }
        j++;
    }
    printf("\n");
    printf(" ===================================================");
    pilihan_ulang(1);
}

void menu_metode_iteratif(){
    int deret;
    printf(" ===================================================\n");
	printf("|               PROGRAM DERET FIBONACCI             |\n");
	printf("|                   Metode Iteratif                 |\n");
    printf(" ===================================================\n");
    printf("   INPUT\n");
    printf("   - Masukan jumlah bilangan fibonacci : ");
    deret = input(0);
    printf("\n");
    printf("   HASIL\n");
    printf("   - Deret fibonacci metode iteratif : \n");
    printf("     ");
    fibonacci_iteratif(deret);
    printf("\n");
    printf(" ===================================================");
    pilihan_ulang(2);
}

void menu_utama(){
    int pilihan;
    printf(" ===================================================\n");
	printf("|               PROGRAM DERET FIBONACCI             |\n");
    printf(" ===================================================\n");
	printf("|    Pilihan Meode :                                |\n");
	printf("|    1. Metode Rekursif                             |\n");
	printf("|    2. Metode Iteratif                             |\n");
	printf("|    3. Keluar                                      |\n");
    printf(" ===================================================\n");
    printf("     Masukan Pilihan : ");
    pilihan = input(0);

    if(pilihan == 1){
        system("cls");
        menu_metode_rekursif();
    }else if (pilihan == 2){
        system("cls");
        menu_metode_iteratif();
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
