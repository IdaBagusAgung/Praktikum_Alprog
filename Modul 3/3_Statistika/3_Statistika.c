#include <stdio.h>
#include <string.h>
#include <windows.h>

float input();
void keluar();
void pilihan_ulang();
float rumus_mean();
float rumus_median();
int rumus_modus();
void sorting_nilai();
void mean();
void median();
void modus();
void menu_utama();
int main();

/* Paramter desimal berisi 0 atau 1, 1 untuk terima angka desimal, atau 0 untuk tidak terima angka desimal */
/* Paramter min berisi 0 atau 1, 1 untuk terima angka minus, atau 0 untuk tidak terima angka minus */
/* Paramter batas akhir berisi 0 atau batas angka yang diinginkan, 0 untuk terima angka tanpa batas, atau angka bebas untuk batasnya */
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
        printf("    Masukkan salah! Masukkan angka yang benar : ");
        return input(desimal, min, batas_akhir);
    }else if(min == 0 && hasil == 0){
        printf("    Masukkan tidak boleh 0 ! Masukkan nilai yang benar : ");
        return input(desimal, min, batas_akhir);
    }else if(batas_akhir != 0 && hasil > batas_akhir){
        printf("    Masukkan tidak boleh lebih dari %d ! Masukkan nilai yang benar : ", batas_akhir);
        return input(desimal, min, batas_akhir);
    }else{
        return hasil;
    }
}

void keluar(){
    printf("\n    Terima Kasih");
	sleep(1);
	printf(".");
	sleep(1);
	printf(".");
	sleep(1);
	printf(".");
	sleep(1);
	printf(" :)");
	sleep(1);
    system("cls");
    system("exit");
}

void pilihan_ulang(int ulang){
    char huruf_ulang[1];

    printf("\n    Lakukan lagi? ya/kembali/keluar(y/n/e) : ");
    scanf("%s", &huruf_ulang);
    fflush(stdin);

    if((strcmp(huruf_ulang, "y") != 0) && (strcmp(huruf_ulang, "n") != 0) && (strcmp(huruf_ulang, "e") != 0)){
        printf("    Masukan anda salah! Masukan dengan benar\n");
        pilihan_ulang(ulang);
    }else if((strcmp(huruf_ulang, "y") == 0)){
        system("cls");
        if(ulang == 1){
            mean();
        }else if(ulang == 2){
            median();
        }else if(ulang == 3){
            modus();
        }
    }else if((strcmp(huruf_ulang, "n") == 0)){
        system("cls");
        menu_utama();
    }else{
        keluar();
    }
}

float rumus_mean(float data[], int jumlah){
    float hasil = 0;
    int i;

    for(i = 0; i < jumlah; i++){
        hasil = hasil + data[i];
    }

    hasil = hasil / jumlah;

    return hasil;
}

float rumus_median(float data[], int jumlah){
    float hasil;
    int tengah = jumlah / 2;

    if(jumlah % 2 == 0){ // jumlah data genap
        hasil = (data[tengah-1] + data[tengah]) / 2; // menambahkan 2 nilai tengah lalu di bagi 2 untuk mendapatkan median
    }else{ // jumlah data ganjil
        hasil = data[tengah]; // mendapatkan median dengan mencari nilai tengah
    }

    return hasil;
}

int rumus_modus(float bil[], int jumlah, float mod[]){
    int n_angka[jumlah];
    int i, j;
    int jumlah_tmp;
    int max = 0;
    int z = 0;
    int status;
    int a = 0;

    for(i = 0; i < jumlah; i++){
        mod[i] = 0;
        jumlah_tmp = 0;
        for(j = 0; j < jumlah; j++){
            if(bil[i] == bil[j]){
                jumlah_tmp++;
            }
        }
        if(jumlah_tmp > max){
            max = jumlah_tmp;
        }
        n_angka[i] = jumlah_tmp;
    }

    // 2, 4,4 , 7, 8, 9,9


    for(i = 0; i < jumlah; i++){
        status = 0;
        if(n_angka[i] == max){
            z++;
            for(j = 0; j < jumlah; j++){
                if(bil[i] == mod[j]){
                    status = 1;
                }
            }
            if(status == 0){
                mod[a] = bil[i];
                a++;
            }
        }
    }

    if(jumlah == z){
        return 0;
    }else{
        return a;
    }
}

void sorting_nilai(float data[], int jumlah){
    int i, j;
    float temp;
    for(i = 0; i < jumlah - 1; i++){
	    for(j = 0; j < jumlah - 1; j++){
		    if(data[j+1] < data[j]){
			    temp      = data[j];
			    data[j]   = data[j+1];
    			data[j+1] = temp;
		    }
    	}
	}
}

void mean(){
    int jumlah; // variabel yang digunakan untuk menyimpan brapa jumlah data yang ingin kita inputkan
    int i; // variabel yang digunakan untuk acuan fungsi perulangan seperti for dll
    float hasil_mean; // variabel yang digunakan untuk menyimpan hasil dari mean
	printf(" =========================================\n");
	printf("|           PROGRAM STATISTIKA            |\n");
	printf("|                  Mean                   |\n");
	printf(" =========================================\n");
    printf("    Masukan jumlah data : ");
    jumlah = input(0, 0, 0); // inputan jumlah data menggunakan validasi, jumlah data tersebut disimpan ke variabel jumlah

    float data[jumlah]; // variabel tempat kita menyimpan data data angka. Variabel ini adalah array
    float *alamat; // pembuatan variabel pointer atau variabel tempat menyimpan alamat memori
    alamat = &data; // pengisian variabel pointer dengan alamat memori dari variabel "data"

    printf("\n");
    printf("    Masukan Data\n");
    for(i = 0; i < jumlah; i++){
        printf("    * Masukan Data Angka ke - %d : ", i+1);
        alamat[i] = input(1,0,0);
        // pengisian nilai ke variabel "alamat", yang dimana alamat ini sudah berisi alamat memori
        // jadi ketika melakukan pengisian nilai pada "alamat", maka nilai tersebut akan dikirimkan ke alamat memori yang terdapat pada variabel tersebut yang dimana alamat memori tersebut diarahkan ke variabel "data"
    }

    // menghitung mean dari angka yang sudah diinputkan
    // perhitungan dilakukan di dalam fungsi rumus_mean dengan membawa 2 data dalam parameternya, yaitu data dan jumlah
    // kenapa yang dibawa itu variabel data? kenapa bukan alamat?
    // Jawabannya :
    // 1. Di dalam soal hanya menuliskan metode pointer itu digunakan dalam penginputan angka, jadi kita bisa tidak menggunakan metode pointer tersebut di perhitungan mean nya
    // 2. Ketika kita mengirimkan alamat maka yang akan dikirimkan adalah alamat memorinya, dan itu sering terjadi error data
    hasil_mean = rumus_mean(data, jumlah);

    // Output hasill yang sudah di hitung dari fungsi rumus_mean
    printf("\n");
    printf("    Hasil\n");
    printf("    * Mean dari data tersebut adalah %.2f\n", hasil_mean);
	printf(" =========================================\n");

    pilihan_ulang(1);
}

void median(){
    int jumlah;
    int i;
    float hasil_median;
	printf(" =========================================\n");
	printf("|           PROGRAM STATISTIKA            |\n");
	printf("|                 Median                  |\n");
	printf(" =========================================\n");
    printf("    Masukan jumlah data : ");
    jumlah = input(0, 0, 0);

    float data[jumlah]; // variabel penyimpan angka
    float *alamat; // variabel penyimpan alamat memori
    alamat = &data; // mengisi variabel alamat dengan alamat memori dati data

    printf("\n");
    printf("    Masukan Data\n");
    for(i = 0; i < jumlah; i++){
        printf("    * Masukan Data Angka ke - %d : ", i+1);
        alamat[i] = input(1,0,0); // pengisian nilai ke alamat memori "data" yang terdapat pada variabel "alamat". Jika mengisikan nilai pada alamat memori nya maka akan otomatis berubah di variabel utamanya yaitu data
    }

    sorting_nilai(data, jumlah);// fungsinya agar data nya terurut sebelum dicari nilai tengahnya(median)

    printf("\n");
    printf("    Hasil data terurut\n");
    for(i = 0; i < jumlah; i++){
        printf("    * Angka ke - %d : %.2f\n", i+1, data[i]);
    }

    hasil_median = rumus_median(data, jumlah);

    printf("\n");
    printf("    Hasil\n");
    printf("    * Median dari data tersebut adalah %.2f\n", hasil_median);
	printf(" =========================================\n");

    pilihan_ulang(2);
}

void modus(){
    int jumlah;
    int i;
    float hasil_modus;
	printf(" =========================================\n");
	printf("|           PROGRAM STATISTIKA            |\n");
	printf("|                  Modus                  |\n");
	printf(" =========================================\n");
    printf("    Masukan jumlah data : ");
    jumlah = input(0, 0, 0);

    float data[jumlah]; // variabel penyimpan angka
    float *alamat; // variabel penyimpan alamat memori
    alamat = &data; // mengisi variabel alamat dengan alamat memori dati data

    printf("\n");
    printf("    Masukan Data\n");
    for(i = 0; i < jumlah; i++){
        printf("    * Masukan Data Angka ke - %d : ", i+1);
        alamat[i] = input(1,0,0); // pengisian nilai ke alamat memori "data" yang terdapat pada variabel "alamat". Jika mengisikan nilai pada alamat memori nya maka akan otomatis berubah di variabel utamanya yaitu data
    }

    float mod[jumlah];

    hasil_modus = rumus_modus(data, jumlah, mod);

    printf("\n");
    printf("    Hasil\n");
    if(hasil_modus == 0){
        printf("    * Tidak ada modus di data tersebut\n");
    }else{
        printf("    * Modus : ");
        for(i = 0; i < hasil_modus; i++){
            if(i == 0){
                printf("%.2f", mod[i]);
            }else{
                printf(", %.2f", mod[i]);
            }
        }
    }
	printf("\n =========================================\n");

    pilihan_ulang(3);
}

void menu_utama(){
    int pilihan;
	printf(" =========================================\n");
	printf("|           PROGRAM STATISTIKA            |\n");
	printf(" =========================================\n");
	printf("|   Pilihan :                             |\n");
	printf("|   1. Mean                               |\n");
	printf("|   2. Median                             |\n");
	printf("|   3. Modus                              |\n");
	printf("|   4. Keluar                             |\n");
	printf(" =========================================\n");
	printf("    Pilihan : ");
    pilihan = input(0,0,4);

    if(pilihan == 1){
        system("cls");
        mean();
    }else if(pilihan == 2){
        system("cls");
        median();
    }else if(pilihan == 3){
        system("cls");
        modus();
    }else if(pilihan == 4){
        keluar();
    }
}

int main(){
    system("cls");
    menu_utama();

    return 0;
}
