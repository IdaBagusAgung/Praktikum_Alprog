#include <stdio.h>
#include <string.h>

float input();
int pertanyaanHapus();
int validasiNim();
int cek_nim();
int cek_nim_edit();
int proses_read_data_tmp();
int main();
void keluar();
void menu_utama();
void setDefaultDataTmp();
void proses_tambah_data();
void proses_lihat_data();
void proses_perbaharui_data();
void proses_hapus_data();
void tambah_data();
void lihat_data();
void perbaharui_data();
void hapus_data();

struct Mahasiswa{
    int nim;
	char nama[50];
};

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
    system("cls");
    system("exit");
}

void menu_utama(){
    int pilihan;
	printf(" ==================================================\n");
	printf("|============  PROGRAM DATA MAHASISWA  ============|\n");
	printf("|==================================================|\n");
	printf("|   1. Tambah Data Mahasiswa                       |\n");
	printf("|   2. Lihat Data Mahasiswa                        |\n");
	printf("|   3. Perbaharui Data Mahasiswa                   |\n");
	printf("|   4. Hapus Data Mahasiswa                        |\n");
	printf("|   5. Keluar                                      |\n");
	printf(" ==================================================\n");
    printf("    Pilihan : ");
    pilihan = input(0,0,5);

    if(pilihan == 1){
        system("cls");
        tambah_data();
    }else if(pilihan == 2){
        system("cls");
        lihat_data();
    }else if(pilihan == 3){
        system("cls");
        perbaharui_data();
    }else if(pilihan == 4){
        system("cls");
        hapus_data();
    }else if(pilihan == 5){
        keluar();
    }
}

void pilihan_ulang(int ulang){
    char huruf_ulang[1];

    printf("\n    Lakukan lagi? ya/kembali/keluar(Y/N/E) : ");
    scanf("%s", &huruf_ulang);
    fflush(stdin);

    if((strcmp(huruf_ulang, "Y") != 0) && (strcmp(huruf_ulang, "N") != 0) && (strcmp(huruf_ulang, "E") != 0 ) &&
       (strcmp(huruf_ulang, "y") != 0) && (strcmp(huruf_ulang, "n") != 0) && (strcmp(huruf_ulang, "e") != 0)){
        printf("    Masukan anda salah! Masukan dengan benar\n");
        pilihan_ulang(ulang);
    }else if((strcmp(huruf_ulang, "Y") == 0)){
        system("cls");
        if(ulang == 1){
            tambah_data();
        }else if(ulang == 2){
            lihat_data();
        }else if(ulang == 3){
            perbaharui_data();
        }else if(ulang == 4){
            hapus_data();
        }
    }else if((strcmp(huruf_ulang, "y") == 0)){
        system("cls");
        if(ulang == 1){
            tambah_data();
        }else if(ulang == 2){
            lihat_data();
        }else if(ulang == 3){
            perbaharui_data();
        }else if(ulang == 4){
            hapus_data();
        }
    }else if((strcmp(huruf_ulang, "N") == 0)){
        system("cls");
        menu_utama();
    }else if((strcmp(huruf_ulang, "n") == 0)){
        system("cls");
        menu_utama();
    }else{
        keluar();
    }
}

int pertanyaanHapus(){
    char huruf_hapus[1];
    int hasil = 0;

    printf("    Apakah anda yakin ingin menghapus data ini ? (Y/N) : ");
    scanf("%s", &huruf_hapus);
    fflush(stdin);

    if((strcmp(huruf_hapus, "Y") != 0) && (strcmp(huruf_hapus, "N") != 0) &&
       (strcmp(huruf_hapus, "y") != 0) && (strcmp(huruf_hapus, "n") != 0)){
        printf("    Masukan anda salah! Masukan dengan benar\n\n");
        pertanyaanHapus();
    }else if((strcmp(huruf_hapus, "Y") == 0)){
		hasil = 1;
    }else if((strcmp(huruf_hapus, "y") == 0)){
		hasil = 1;
    }else{
		hasil = 0;
    }

    return hasil;
}

void setDefaultDataTmp(struct Mahasiswa data_tmp[]){
    int i;
    for(i = 0; i < 100; i++){
        data_tmp[i].nim = 0;
    }
}

int validasiNim(){
    char masukan[100];
    int i = 0;
    int salah = 0;
    int hasil = 0;

    scanf("%[^\n]", &masukan);
    fflush(stdin);

    while(masukan[i] != '\0'){
        if(masukan[i] >= '0' && masukan[i] <= '9'){
            hasil = (hasil * 10) + (masukan[i] - 48);
            i++;
        }else{
            salah = 1;
            masukan[i] = '\0';
        }
    }

    if(salah == 1){
        printf("      Format Nim salah! Masukkan format yang benar : ");
        return validasiNim();
    }else if(i != 10){
        printf("      Nim harus 10 digit ! Masukkan Nim yang benar : ");
        return validasiNim();
    }else{
        return hasil;
    }
}

int validasiNama(char masukan[]){
    int i = 0;
    int salah = 0;

    while(masukan[i] != '\0'){
        if((masukan[i] >= 65 && masukan[i] <= 90) || (masukan[i] >= 97 && masukan[i] <= 122) || masukan[i] == ' ' || masukan[i] == '.' || masukan[i] == ','){
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

int cek_nim(struct Mahasiswa data, struct Mahasiswa data_tmp[], int jumlah){
    int i;
    int ditemukan = 0;

    for(i = 0; i < jumlah; i++){
        if(data.nim == data_tmp[i].nim){
            ditemukan = 1;
            break;
        }else{
            ditemukan = 0;
        }
    }

    return ditemukan;
}

int cek_nim_edit(struct Mahasiswa data, struct Mahasiswa data_tmp[], int jumlah, int nomorEdit){
    int i;
    int ditemukan = 0;

    for(i = 0; i < jumlah; i++){
        if((data.nim == data_tmp[i].nim) && (data_tmp[i].nim != data_tmp[nomorEdit].nim)){
            ditemukan = 1;
            break;
        }else{
            ditemukan = 0;
        }
    }

    return ditemukan;
}

int proses_read_data_tmp(struct Mahasiswa data_tmp[]){
    int jumlah = 0;

    FILE *read_tmp = fopen("Mahasiswa.txt","r");
    if(!read_tmp){
        jumlah = 1;
    }else{
	    while(!feof(read_tmp)){
	   	    fscanf(read_tmp,"%d#%[^\n]\n", &data_tmp[jumlah].nim, &data_tmp[jumlah].nama);
            jumlah++;
	    }
    }
	fclose(read_tmp);

    return jumlah;
}

void proses_tambah_data(struct Mahasiswa data){
    FILE *tambah = fopen("Mahasiswa.txt", "a");
	fprintf(tambah,"%d#%s\n", data.nim, data.nama);
	fclose(tambah);
}

void proses_lihat_data(struct Mahasiswa data_tmp[], int jumlah){
    int i;
    if(jumlah == 1 && data_tmp[0].nim == 0){
        printf("    * Tidak ada data mahasiswa\n");
    }else{
        for(i = 0; i < jumlah; i++){
            printf("    %d. %d - %s\n", i+1, data_tmp[i].nim, data_tmp[i].nama);
        }
    }
}

void proses_perbaharui_data(struct Mahasiswa data_edit, struct Mahasiswa data_tmp[], int jumlah, int nomorEdit){
    int i, j;
    data_tmp[nomorEdit].nim = data_edit.nim;
    for(i = 0; i < 50; i++){
        data_tmp[nomorEdit].nama[i] = data_edit.nama[i];
    }

    FILE *perbaharui = fopen("Mahasiswa.txt","w");
    for(i = 0; i < jumlah; i++){
        fprintf(perbaharui, "%d#%s\n", data_tmp[i].nim, data_tmp[i].nama);
    }
    fclose(perbaharui);
}

void proses_hapus_data(struct Mahasiswa data_tmp[], int jumlah, int nomorHapus){
    int i;
    FILE *hapus = fopen("Mahasiswa.txt","w");
    for(i = 0; i < jumlah; i++){
        if(i == nomorHapus){
            continue;
        }else{
            fprintf(hapus, "%d#%s\n", data_tmp[i].nim, data_tmp[i].nama);
        }
    }
    fclose(hapus);
}

void tambah_data(){
    int statusNim;
    int statusNama;
    struct Mahasiswa data;
    struct Mahasiswa data_tmp[100];
    setDefaultDataTmp(data_tmp);

    int jumlah = proses_read_data_tmp(data_tmp);

	printf(" ================================================== \n");
	printf("|============  TAMBAH DATA MAHASISWA  =============|\n");
	printf("|==================================================|\n");
	printf("    Tambah Data \n");
	printf("    * Masukan Nim  : ");
    data.nim = validasiNim();

    statusNim = cek_nim(data, data_tmp, jumlah);
    while(statusNim == 1){
        printf("      Nim sudah ada ! Masukan Nim yang berbeda : ");
        data.nim = validasiNim();
        statusNim = cek_nim(data, data_tmp, jumlah);
    }

	printf("    * Masukan Nama : ");
    scanf("%[^\n]", &data.nama);
    fflush(stdin);

    statusNama = validasiNama(data.nama);
    while(statusNama == 0){
        printf("      Format Nama salah ! Masukan Nama dengan benar : ");
        scanf("%[^\n]", &data.nama);
        fflush(stdin);
        statusNama = validasiNama(data.nama);
    }

    proses_tambah_data(data);

    printf("\n");
    printf("    Hasil\n");
    printf("    * Nim  : %d\n", data.nim);
    printf("    * Nama : %s\n", data.nama);
    printf("      Data tersebut berhasil ditambahkan\n");
	printf(" ==================================================\n");
    pilihan_ulang(1);
}

void lihat_data(){
    struct Mahasiswa data_tmp[100];
    setDefaultDataTmp(data_tmp);

    int jumlah = proses_read_data_tmp(data_tmp);
	printf(" ================================================== \n");
	printf("|===============  DATA MAHASISWA  =================|\n");
	printf("|==================================================|\n");
    printf("    Daftar Data Mahasiswa :\n");
    printf("\n");

    proses_lihat_data(data_tmp, jumlah);

    if(jumlah != 1 || data_tmp[0].nim != 0){
        printf("\n");
        printf("    Jumlah Mahasiswa : %d\n", jumlah);
    }
	printf(" ==================================================\n");
    pilihan_ulang(2);
}

void perbaharui_data(){
    int statusNim, statusNama;
    struct Mahasiswa data_edit;
    struct Mahasiswa data_tmp[100];
    setDefaultDataTmp(data_tmp);
    int jumlah = proses_read_data_tmp(data_tmp);
    int nomorEdit = 0;
	printf(" ================================================== \n");
	printf("|==========  PERBAHARUI DATA MAHASISWA  ===========|\n");
	printf("|==================================================|\n");
    printf("    Daftar Data Mahasiswa :\n");
    printf("\n");

    proses_lihat_data(data_tmp, jumlah);

    printf("\n");
    if(jumlah != 1 || data_tmp[0].nim != 0){
        printf("    Data nomor brapa yang ingin anda perbaharui ? (1 - %d) : ", jumlah);
        nomorEdit = input(0, 0, jumlah);
        nomorEdit = nomorEdit - 1;

        printf("\n");
        printf("    Input Pembaharuan Data\n");
	    printf("    * Masukan Nim  : ");
        data_edit.nim = validasiNim();

        statusNim = cek_nim_edit(data_edit, data_tmp, jumlah, nomorEdit);
        while(statusNim == 1){
            printf("      Nim sudah ada ! Masukan Nim yang berbeda : ");
            data_edit.nim = validasiNim();
            statusNim = cek_nim_edit(data_edit, data_tmp, jumlah, nomorEdit);
        }

	    printf("    * Masukan Nama : ");
        scanf("%[^\n]", &data_edit.nama);
        fflush(stdin);

        statusNama = validasiNama(data_edit.nama);
        while(statusNama == 0){
            printf("      Format Nama salah ! Masukan Nama dengan benar : ");
            scanf("%[^\n]", &data_edit.nama);
            fflush(stdin);
            statusNama = validasiNama(data_edit.nama);
        }

        printf("\n");

        proses_perbaharui_data(data_edit, data_tmp, jumlah, nomorEdit);

	    printf("    Data berhasil diperbaharui\n");
    }else if(jumlah == 1 && data_tmp[0].nim == 0){
        printf("   Masukan data terlebih dahulu\n");
    }
	printf(" ==================================================\n");
    pilihan_ulang(3);
}

void hapus_data(){
    struct Mahasiswa data_tmp[100];
    setDefaultDataTmp(data_tmp);
    int jumlah = proses_read_data_tmp(data_tmp);
    int nomorHapus = 0;
    int yakinHapus = 0;
	printf(" ================================================== \n");
	printf("|=============  HAPUS DATA MAHASISWA  =============|\n");
	printf("|==================================================|\n");
    printf("    Daftar Data Mahasiswa :\n");
    printf("\n");

    proses_lihat_data(data_tmp, jumlah);

    printf("\n");
    if(jumlah != 1 || data_tmp[0].nim != 0){
        printf("    Pilih data yang ingin anda hapus!! (1 - %d) : ", jumlah);
        nomorHapus = input(0, 0, jumlah);
        nomorHapus = nomorHapus - 1;
        yakinHapus = pertanyaanHapus();
        printf("\n");
        if(yakinHapus == 1){
            proses_hapus_data(data_tmp, jumlah, nomorHapus);
            printf("    Data telah di hapus\n");
        }else{
            printf("    Data tidak di hapus\n");
        }
    }else if(jumlah == 1 && data_tmp[0].nim == 0){
        printf("   Masukan data terlebih dahulu\n");
    }
	printf(" ==================================================\n");
    pilihan_ulang(4);
}

int main(){
    system("cls");
    menu_utama();

    return 0;
}
