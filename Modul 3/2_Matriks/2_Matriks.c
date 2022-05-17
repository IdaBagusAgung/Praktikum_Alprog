#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <windows.h>

float input(int desimal, int min, int batas_akhir){
    char masukan[100];
    int i = 0;
    int belakang = 0;
    int isi_depan = 0;
    int isi_belakang = 0;
    int status = 0;
    int titik = 0;
    int minus = 0;
    int salah = 0;
    float hasil;

    scanf("%[^\n]", &masukan);
    fflush(stdin);

    while(masukan[i] != '\0'){
        if(masukan[0] == '.'){
            salah = 1;
            masukan[0] = '\0';
        }else if(masukan[i]>='0' && masukan[i]<='9' || masukan[i] == '.' || (masukan[0] == '-' && min == 1)){
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

            if(masukan[0] == '-' && min == 1){
                minus = 1;
            }else if(masukan[0] == '-' && min == 0){
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


    if(minus == 1 && min == 1){
        hasil = hasil - (hasil * 2);
    }else if(minus == 1 && min == 0){
        salah = 1;
        masukan[i] = '\0';
    }

    if(salah == 1){
        printf("* Masukan salah! Masukkan angka yang benar : ");
        return input(desimal, min, batas_akhir);
    }else if(min == 0 && hasil == 0){
        printf("* Masukan tidak boleh 0 ! Masukkan nilai yang benar : ");
        return input(desimal, min, batas_akhir);
    }else if(batas_akhir != 0 && hasil > batas_akhir){
        printf("* Masukan tidak boleh lebih dari %d ! Masukkan nilai yang benar : ", batas_akhir);
        return input(desimal, min, batas_akhir);
    }else{

	return hasil;
    }
}

int validasi_matriks(char huruf[]){
    int a = 0;
    int salah = 0;
    int titik = 0;

    while(huruf[a] != '\0'){
        if(huruf[0] == '.'){
            salah = 1;
            huruf[0] = '\0';
        }else if((huruf[a] >= '0' && huruf[a] <= '9') || huruf[a] == '.' || (a == 0 && huruf[0] == '-')){
            if(huruf[a] == '.'){
                titik = titik + 1;
                if(titik > 1 || huruf[a+1] == '\0'){
                    salah = 1;
                    huruf[a] = '\0';
                }
            }else if((huruf[a] == '-') && (huruf[a+1] == '\0')){
                salah = 1;
                huruf[a] = '\0';
			}
            a++;
        }else{
            salah = 1;
            huruf[a] = '\0';
        }
    }
    if(salah == 1){
        return 1;
    }else{
        return 0;
    }
}

float convert_to_float(char huruf[]){
    int a = 0;
    int minus = 0;
    int isi_depan = 0;
    int isi_belakang = 0;
    int status = 0;
    int digit_belakang = 0;
    float hasil = 0;

    while(huruf[a] != '\0'){
        if(huruf[a] == '-'){
            minus = 1;
        }else if(huruf[a] == '.'){
            status = 1;
        }else if(huruf[a] >= '0' && huruf[a] <= '9'){
            if(status == 0){
                isi_depan = (isi_depan * 10) + (huruf[a] - 48);
            }else{
                isi_belakang = (isi_belakang * 10) + (huruf[a] - 48);
                digit_belakang++;
            }
        }
        a++;
    }

    if(status == 1){
        hasil = (float)isi_depan + ((float)isi_belakang / (float)(pow(10, digit_belakang)));
    }else{
        hasil = isi_depan;
    }

    if(minus == 1){
        hasil = hasil - (hasil * 2);
    }
    return hasil;
}

void keluar(){
    printf("\n  Terima Kasih");
	Sleep(1);
	printf(".");
	Sleep(1);
	printf(".");
	Sleep(1);
	printf(".");
	Sleep(1);
	printf(" :)");
	Sleep(1);
    system("cls");
    system("exit");
}

void pilihan_ulang(){
    char ulang[1];

    printf("\nLakukan lagi? (y/n) : ");
    scanf("%s", &ulang);
    fflush(stdin);

    if((strcmp(ulang, "y") != 0) && (strcmp(ulang, "n") != 0) && (strcmp(ulang, "Y") != 0) && (strcmp(ulang, "N") != 0)){
        printf("Masukan anda salah! Masukkan dengan benar\n");
        pilihan_ulang();
    }else if((strcmp(ulang, "y") == 0)){
        system("cls");
        main();
    }else if((strcmp(ulang, "Y") == 0)){
    	system("cls");
    	main();
	}else{
        keluar();
    }
}

void perkalian_matriks(){
    char huruf1[10][10][10], huruf2[10][10][10];
    int matriks1[10][10], matriks2[10][10], hasil[10][10];
    int i, j, k, jml_brs1, jml_klm1, jml_brs2, jml_klm2, jumlah = 0;
    int salah = 0;

    printf("\nPerkalian Matriks\n");
    printf("Masukkan jumlah baris matriks pertama: ");
    jml_brs1 = input(0, 0, 10);
    printf("Masukkan jumlah kolom matriks pertama: ");
    jml_klm1 = input(0, 0, 10);
    printf("Masukkan jumlah baris matriks kedua: ");
    jml_brs2 = input(0, 0, 10);
    printf("Masukkan jumlah kolom matriks kedua: ");
    jml_klm2 = input(0, 0, 10);

    printf("\n");
    if(jml_klm1 != jml_brs2){
        printf("Matriks tidak dapat dikalikan satu sama lain.\n");
    }else{
        printf("Matriks Elemen Pertama\n");
        for(i = 0; i < jml_brs1; i++){
            printf("* Baris Ke %d\n", i+1);
            printf("  - Format : ");
            for(j = 0; j < jml_klm1; j++){
                printf("(kolom%d)", j+1);
                if(j == (jml_klm1 - 1)){
                    printf("(enter)");
                }else{
                    printf("(spasi)");
                }
            }

            printf("\n");
            printf("  - Input  : ");
            for(j = 0; j < jml_klm1; j++){
                scanf("%s", &huruf1[i][j]);
                if(salah == 0){
                    salah = validasi_matriks(huruf1[i][j]);
                }
            }
            while(salah == 1){
                salah = 0;
                printf("    * Masukan Salah : ");
                for(j = 0; j < jml_klm1; j++){
                    scanf("%s", &huruf1[i][j]);
                    if(salah == 0){
                    	salah = validasi_matriks(huruf1[i][j]);
                    }
                }
            }
            for(j = 0; j < jml_klm1; j++){
                matriks1[i][j] = convert_to_float(huruf1[i][j]);
            }
        }

        printf("\nMatriks Elemen Kedua\n");
        for(i = 0; i < jml_brs2; i++){
            printf("* Baris Ke %d\n", i+1);
            printf("  - Format : ", i+1);
            for(j = 0; j < jml_klm2; j++){
                printf("(kolom%d)", j+1);
                if(j == (jml_klm2 - 1)){
                    printf("(enter)");
                }else{
                    printf("(spasi)");
                }
            }

            printf("\n");
            printf("  - Input  : ");
            for(j = 0; j < jml_klm2; j++){
                scanf("%s", &huruf2[i][j]);
                if(salah == 0){
                    salah = validasi_matriks(huruf2[i][j]);
                }
            }
            while(salah == 1){
                salah = 0;
                printf("    * Masukan Salah : ");
                for(j = 0; j < jml_klm2; j++){
                    scanf("%s", &huruf2[i][j]);
                    if(salah == 0){
                        salah = validasi_matriks(huruf2[i][j]);
                    }
                }
            }
            for(j = 0; j < jml_klm2; j++){
                matriks2[i][j] = convert_to_float(huruf2[i][j]);
            }
        }

        for(i = 0; i < jml_brs1; i++){
            for(j = 0; j < jml_klm2; j++){
                for(k = 0; k < jml_brs2; k++){
                    jumlah = jumlah + matriks1[i][k] * matriks2[k][j];
                }
                hasil[i][j] = jumlah;
                jumlah = 0;
            }
        }
        printf("\nHasil perkalian matriks: \n");
        for(i = 0; i < jml_brs1; i++){
            for(j = 0; j < jml_klm1; j++){
                printf("%d\t", hasil[i][j]);
            }
            printf("\n");
        }
    }
    pilihan_ulang();
}

void penjumlahan_matriks(){
    char huruf1[10][10][10], huruf2[10][10][10];
    int matriks1[10][10], matriks2[10][10], hasil[10][10];
    int i, j, jml_brs, jml_klm, jumlah = 0, salah = 0;

	printf("Penjumlahan Matriks\n");
	printf("Masukkan jumlah baris matriks: ");
	jml_brs = input(0, 0, 10);
	printf("Masukkan jumlah kolom matriks: ");
	jml_klm = input(0, 0, 10);

	printf("Masukkan elemen matriks pertama: \n");
    for(i = 0; i < jml_brs; i++){
        printf("* Baris Ke %d\n", i+1);
        printf("  - Format : ", i+1);
        for(j = 0; j < jml_klm; j++){
            printf("(kolom%d)", j+1);
            if(j == (jml_klm - 1)){
                printf("(enter)");
            }else{
                printf("(spasi)");
            }
        }

        printf("\n");
        printf("  - Input  : ");
        for(j = 0; j < jml_klm; j++){
            scanf("%s", &huruf1[i][j]);
            if(salah == 0){
                salah = validasi_matriks(huruf1[i][j]);
            }
        }
        while(salah == 1){
            salah = 0;
            printf("    * Masukan Salah : ");
            for(j = 0; j < jml_klm; j++){
                scanf("%s", &huruf1[i][j]);
                if(salah == 0){
                    salah = validasi_matriks(huruf1[i][j]);
                }
            }
        }
        for(j = 0; j < jml_klm; j++){
            matriks1[i][j] = convert_to_float(huruf1[i][j]);
        }
    }

    printf("\nMasukkan elemen matriks kedua: \n");
        for(i = 0; i < jml_brs; i++){
        printf("* Baris Ke %d\n", i+1);
        printf("  - Format : ", i+1);
        for(j = 0; j < jml_klm; j++){
            printf("(kolom%d)", j+1);
            if(j == (jml_klm - 1)){
                printf("(enter)");
            }else{
                printf("(spasi)");
            }
        }

        printf("\n");
        printf("  - Input  : ");
        for(j = 0; j < jml_klm; j++){
            scanf("%s", &huruf2[i][j]);
            if(salah == 0){
                salah = validasi_matriks(huruf2[i][j]);
            }
        }
        while(salah == 1){
            salah = 0;
            printf("    * Masukan Salah : ");
            for(j = 0; j < jml_klm; j++){
                scanf("%s", &huruf2[i][j]);
                if(salah == 0){
                    salah = validasi_matriks(huruf2[i][j]);
                }
            }
        }
        for(j = 0; j < jml_klm; j++){
            matriks2[i][j] = convert_to_float(huruf2[i][j]);
        }
    }

    printf("\nHasil penjumlahan matriks: \n");
    for (i = 0; i < jml_brs; i++){
        for (j = 0; j < jml_klm; j++){
            hasil[i][j] = matriks1[i][j] + matriks2[i][j];
            printf("%d \t", hasil[i][j]);
        }
        printf("\n");
    }
    pilihan_ulang();
}

void transpose_matriks(){
    char huruf[10][10][10];
    int matriks[10][10];
    int transpose[10][10];
    int i, j, jml_brs, jml_klm, jumlah = 0, salah = 0;

    printf("Transpose Matriks\n");
    printf("Masukkan jumlah baris matriks: ");
    jml_brs = input(0, 0, 10);
    printf("Masukkan jumlah kolom matriks: ");
    jml_klm = input(0, 0, 10);

    printf("Masukkan elemen matriks:\n");
    for(i = 0; i < jml_brs; i++){
        printf("* Baris Ke %d\n", i+1);
        printf("  - Format : ", i+1);
        for(j = 0; j < jml_klm; j++){
            printf("(kolom%d)", j+1);
            if(j == (jml_klm - 1)){
                printf("(enter)");
            }else{
                printf("(spasi)");
            }
        }

        printf("\n");
        printf("  - Input  : ");
        for(j = 0; j < jml_klm; j++){
            scanf("%s", &huruf[i][j]);
            if(salah == 0){
                salah = validasi_matriks(huruf[i][j]);
            }
        }
        while(salah == 1){
            salah = 0;
            printf("    * Masukan Salah : ");
            for(j = 0; j < jml_klm; j++){
                scanf("%s", &huruf[i][j]);
                if(salah == 0){
                    salah = validasi_matriks(huruf[i][j]);
                }
            }
        }
        for(j = 0; j < jml_klm; j++){
            matriks[i][j] = convert_to_float(huruf[i][j]);
        }
    }

    for (i = 0; i < jml_brs; i++){
        for(j = 0; j < jml_klm; j++){
            transpose[j][i] = matriks[i][j];
        }
    }

    printf("\nHasil transpose matriks:\n");
    for (i = 0; i < jml_klm; i ++){
        for(j = 0; j < jml_brs; j++){
            printf("%d\t",transpose[i][j]);
        }
        printf("\n");
    }
    pilihan_ulang();
}

int main(){

	int pilihan;

    printf(" ===============================\n");
	printf("|        PROGRAM MATRIKS        |\n");
	printf(" ===============================\n");
	printf("| Pilihan :                     |\n");
	printf("| 1. Perkalian Matriks          |\n");
	printf("| 2. Penjumlahan Matriks        |\n");
	printf("| 3. Transpose Matriks          |\n");
	printf("| 4. Keluar                     |\n");
	printf(" ===============================\n");
	printf("  Masukkan Pilihan (1-4) : ");
	pilihan = input(0, 0, 0);

    if(pilihan == 1){
    	perkalian_matriks();
    }else if(pilihan == 2){
    	printf("\n");
        penjumlahan_matriks();
    }else if(pilihan == 3){
    	printf("\n");
        transpose_matriks();
    }else if(pilihan == 4){
        keluar();
    }else{
        printf("\n");
        printf("  Pilihan tidak ada\n");
        printf("  Tekan apa saja untuk melanjutkan...");
        getch();
        system("cls");
	    main();
	}
	return 0;
}
