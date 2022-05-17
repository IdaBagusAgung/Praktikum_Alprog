#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

float input();
int sorting();
void keluar();
void pilihan_ulang();
void acak_array();
void tampil_array();
void rumus_insertion_sort();
void rumus_bubble_sort();
void rumus_quick();
void insertion_sort();
void bubble_sort();
void quick_sort();
void sequential_search();
void binary_search();
void menu_utama();
int main();

//fungsi validasi inputan 
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

//prosedur untuk keluar (exit)
void keluar(){
    system("cls");
    printf("\n    Terima Kasih");
	sleep(1);
    system("exit");
}

//prosedur untuk memilih ulang kembali
void pilihan_ulang(int ulang){
    char huruf_ulang[1];

    printf("\n    Lakukan lagi? ya/kembali/keluar(y/n/e) : ");
    scanf("%s", &huruf_ulang);
    fflush(stdin);
	
	//validasi inputan pengulangan
    if((strcmp(huruf_ulang, "y") != 0) && (strcmp(huruf_ulang, "n") != 0) && (strcmp(huruf_ulang, "e") != 0) &&
    (strcmp(huruf_ulang, "Y") != 0) && (strcmp(huruf_ulang, "N") != 0) && (strcmp(huruf_ulang, "E") != 0)){
        printf("    Masukan anda salah! Masukan dengan benar\n");
        pilihan_ulang(ulang);
    }else if((strcmp(huruf_ulang, "y") == 0)){
        system("cls");
        if(ulang == 1){
            insertion_sort();
        }else if(ulang == 2){
            bubble_sort();
        }else if(ulang == 3){
            quick_sort();
        }else if(ulang == 4){
            sequential_search();
        }else if(ulang == 5){
            binary_search();
        }
    }else if((strcmp(huruf_ulang, "Y") == 0)){
        system("cls");
        if(ulang == 1){
            insertion_sort();
        }else if(ulang == 2){
            bubble_sort();
        }else if(ulang == 3){
            quick_sort();
        }else if(ulang == 4){
            sequential_search();
        }else if(ulang == 5){
            binary_search();
        }
    }else if((strcmp(huruf_ulang, "n") == 0)){
        system("cls");
        menu_utama();
    }else if((strcmp(huruf_ulang, "N") == 0)){
        system("cls");
        menu_utama();
    }else{
        keluar();
    }
}

//fungsi untuk sorting
int sorting(){
    char huruf_sorting[1];
    int hasil;

    printf("\n    Apakah anda ingin mengurutkan ? ya/tidak(y/n) : ");
    scanf("%s", &huruf_sorting);
    fflush(stdin);
    if((strcmp(huruf_sorting, "y") != 0) && (strcmp(huruf_sorting, "n") != 0) &&
    (strcmp(huruf_sorting, "Y") != 0) && (strcmp(huruf_sorting, "N") != 0)){
        printf("    Masukan anda salah! Masukan dengan benar");
        sorting();
    }else if(strcmp(huruf_sorting, "y") == 0){
    	hasil = 1;
    }else if(strcmp(huruf_sorting, "Y") == 0){
    	hasil = 1;
    }else{
    	hasil = 0;
    }

    return hasil;
}

//fungsi untuk searching
int searching(){
    char huruf_sorting[1];
    int hasil;

    printf("\n    Masukan angka yang ingin dicari : ");
    hasil = input(0,0,0);
    fflush(stdin);

    return hasil;
}

//prosedur menampilkan bilangan acak
void acak_array (int array[], int jumlah_acak){
    int i;
    for(i = 0; i < jumlah_acak; i++){
        array[i] = rand() % jumlah_acak + 1;
    }
}

//prosedur menampilkan bilangan acak
void tampil_array(int array[], int jumlah){
    int i;
    for(i = 0; i < jumlah; i++){
        printf("    - Angka ke - %d : %d\n", i + 1, array[i]);
    }
}

//prosedur dari rumus insertion sort
void rumus_insertion_sort(int array[], int jumlah){
    int i, j;
    int temp;
    for(i = 0; i < jumlah; i++){
		for(j = i; j > 0 && array[j] < array[j-1]; j--){
		    temp = array[j-1];
		    array[j-1] = array[j];
	        array[j] = temp;
    	}
	}
}

//prosedur dari rumus bubble sort
void rumus_bubble_sort(int array[], int jumlah){
    int i, j;
    int temp;
    for(i = 0; i < jumlah-1; i++){
		for(j = 0; j < jumlah-1; j++){
			if(array[j+1] < array[j]){
				temp       = array[j];
				array[j]   = array[j+1];
    			array[j+1] = temp;
			}
    	}
	}
}

//prosedur dari rumus quick sort
void rumus_quick_sort(int array[], int awal, int akhir){
    int i = awal;
    int j = akhir;
    int temp;
    int pivot = array[awal];

    do{
        while(array[i] < pivot){
            i++;
        }
        while(array[j] > pivot){
            j--;
        }
        if(i <= j){
            temp     = array[i];
            array[i] = array[j];
            array[j] = temp;

            i++;
            j--;
        }
    }while(i <= j);

    if (awal < j){
        rumus_quick_sort(array, awal, j);
    }
    if (i < akhir){
        rumus_quick_sort(array, i, akhir);
    }
}

//prosedur dari rumus sequential search
void rumus_sequential_search(int array[], int jumlah, int cari){
    int i = 0;
    int ketemu = 0;
    int index = 0;
    while (i < jumlah && ketemu != 1){
        if(array[i] == cari){
            ketemu = 1;
            index = i;
        }else{
            i++;
        }

    }

    printf("\n\n    HASIL PENCAHARIAN : \n");
    if(ketemu == 1){
        printf("    Angka ditemukan pada angka ke %d dan index array ke %d \n", index+1, index);
    }else{
        printf("    Tidak ditemukan angka %d pada kumpulan angka \n", cari);
    }
}

//prosedur dari rumus binary search
void rumus_binary_search(int array[], int jumlah, int cari){
    int awal = 0;
    int akhir = jumlah;
    int ketemu = 0;
    int tengah;

    while(awal <= akhir && ketemu != 1){
        tengah = (awal + akhir) / 2;
        if(array[tengah] == cari){
            ketemu = 1;
        }else if(array[tengah] < cari){
            awal = tengah + 1;
        }else{
            akhir = tengah - 1;
        }
    }

    printf("\n\n    HASIL PENCAHARIAN : \n");
    if(ketemu == 1){
        printf("    Angka ditemukan pada angka ke %d dan index array ke %d \n", tengah+1, tengah);
    }else{
        printf("    Tidak ditemukan angka %d pada kumpulan angka \n", cari);
    }
}

//prosedur tampilan dan perhitungan dari insertion sort
void insertion_sort(){
    int jumlah_angka;
    int status_acak;

    time_t start_acak, end_acak;
    time_t start_sort, end_sort;

    double total_acak, total_sort, total_waktu;

	printf(" =========================================\n");
	printf("|             PROGRAM SORTING       	  |\n");
	printf("|             Insertion Sort              |\n");
	printf(" =========================================\n");
    printf("    Masukan Jumlah Angka : ");
    jumlah_angka = input(0,0,0);

    int array_insertion[jumlah_angka];

    printf("\n    Sedang Mengacak %d Angka...", jumlah_angka);
    start_acak = clock();
    acak_array(array_insertion, jumlah_angka);

    printf("\n");
    printf("    HASIL ANGKA ACAK :\n");
    tampil_array(array_insertion, jumlah_angka);
    end_acak = clock();
    status_acak = sorting();

    if(status_acak == 1){
        printf("\n    Sedang mengurutkan %d angka dengan metode Insertion Sort...", jumlah_angka);
        start_sort = clock();
        rumus_insertion_sort(array_insertion, jumlah_angka);
        end_sort = clock();

        printf("\n");
        printf("    HASIL ANGKA URUT :\n");
        tampil_array(array_insertion, jumlah_angka);
        end_sort = clock();
    }else{
        start_sort = 0;
        end_sort = 0;
    }

    total_acak = (double)(end_acak - start_acak) / CLOCKS_PER_SEC;
    total_sort = (double)(end_sort - start_sort) / CLOCKS_PER_SEC;
    total_waktu = total_acak + total_sort;

    printf("\n    SELESAI\n");
    printf("    - Waktu Pengacakan Angka : %.2f s\n", total_acak);
    printf("    - Waktu Pengurutan Angka : %.2f s\n", total_sort);
    printf("                               ----- +\n");
    printf("    - Total Waktu            : %.2f s\n", total_waktu);
	printf(" =========================================\n");

    pilihan_ulang(1);
}

//prosedur tampilan dan perhitungan dari bubble sort
void bubble_sort(){
    int jumlah_angka;
    int status_acak;

    time_t start_acak, end_acak;
    time_t start_sort, end_sort;

    double total_acak, total_sort, total_waktu;

	printf(" =========================================\n");
	printf("|             PROGRAM SORTING      	  |\n");
	printf("|               Bubble Sort               |\n");
	printf(" =========================================\n");
    printf("    Masukan Jumlah Angka : ");
    jumlah_angka = input(0,0,0);

    int array_bubble[jumlah_angka];

    printf("\n    Sedang Mengacak %d Angka...", jumlah_angka);
    start_acak = clock();
    acak_array(array_bubble, jumlah_angka);


    printf("\n");
    printf("    HASIL ANGKA ACAK :\n");
    tampil_array(array_bubble, jumlah_angka);
    end_acak = clock();

    status_acak = sorting();

    if(status_acak == 1){
        printf("\n    Sedang mengurutkan %d angka dengan metode Bubble Sort...", jumlah_angka);
        start_sort = clock();
        rumus_bubble_sort(array_bubble, jumlah_angka);
        end_sort = clock();

        printf("\n");
        printf("    HASIL ANGKA URUT :\n");
        tampil_array(array_bubble, jumlah_angka);
        end_sort = clock();
    }else{
        start_sort = 0;
        end_sort = 0;
    }

    total_acak = (double)(end_acak - start_acak) / CLOCKS_PER_SEC;
    total_sort = (double)(end_sort - start_sort) / CLOCKS_PER_SEC;
    total_waktu = total_acak + total_sort;

    printf("\n    SELESAI\n");
    printf("    - Waktu Pengacakan Angka : %.2f s\n", total_acak);
    printf("    - Waktu Pengurutan Angka : %.2f s\n", total_sort);
    printf("                               ----- +\n");
    printf("    - Total Waktu            : %.2f s\n", total_waktu);
	printf(" =========================================\n");

    pilihan_ulang(2);
}

//prosedur tampilan dan perhitungan dari quick sort
void quick_sort(){
    int jumlah_angka;
    int status_acak;

    time_t start_acak, end_acak;
    time_t start_sort, end_sort;

    double total_acak, total_sort, total_waktu;

	printf(" =========================================\n");
	printf("|             PROGRAM SORTING       	  |\n");
	printf("|               Quick Sort                |\n");
	printf(" =========================================\n");
    printf("    Masukan Jumlah Angka : ");
    jumlah_angka = input(0,0,0);

    int array_quick[jumlah_angka];

    printf("\n    Sedang Mengacak %d Angka...", jumlah_angka);
    start_acak = clock();
    acak_array(array_quick, jumlah_angka);


    printf("\n");
    printf("    HASIL ANGKA ACAK :\n");
    tampil_array(array_quick, jumlah_angka);
    end_acak = clock();

    status_acak = sorting();

    if(status_acak == 1){
        printf("\n    Sedang mengurutkan %d angka dengan metode Quick Sort...", jumlah_angka);
        start_sort = clock();
        rumus_quick_sort(array_quick, 0, jumlah_angka - 1);


        printf("\n");
        printf("    HASIL ANGKA URUT :\n");
        tampil_array(array_quick, jumlah_angka);
        end_sort = clock();
    }else{
        start_sort = 0;
        end_sort = 0;
    }

    total_acak = (double)(end_acak - start_acak) / CLOCKS_PER_SEC;
    total_sort = (double)(end_sort - start_sort) / CLOCKS_PER_SEC;
    total_waktu = total_acak + total_sort;

    printf("\n    SELESAI\n");
    printf("    - Waktu Pengacakan Angka : %.2f s\n", total_acak);
    printf("    - Waktu Pengurutan Angka : %.2f s\n", total_sort);
    printf("                               ----- +\n");
    printf("    - Total Waktu            : %.2f s\n", total_waktu);
	printf(" =========================================\n");

    pilihan_ulang(3);
}

//prosedur tampilan dan perhitungan dari sequential search
void sequential_search(){
    int jumlah_angka;
    int i, j;
    int angka_search;

    time_t start_acak, end_acak;
    time_t start_search, end_search;

    double total_acak, total_search, total_waktu;

	printf(" =========================================\n");
	printf("|             PROGRAM SORTING      	  |\n");
	printf("|            Sequential Search            |\n");
	printf(" =========================================\n");
    printf("    Masukan Jumlah Angka : ");
    jumlah_angka = input(0,0,0);

    int array_sequential[jumlah_angka];

    printf("\n    Sedang Mengacak %d Angka...", jumlah_angka);
    start_acak = clock();
    acak_array(array_sequential, jumlah_angka);


    printf("\n");
    printf("    HASIL ANGKA ACAK :\n");
    tampil_array(array_sequential, jumlah_angka);
    end_acak = clock();
    angka_search = searching();

    printf("\n    Sedang mencari angka %d dengan metode Sequential Search...", angka_search);
    start_search = clock();
    rumus_sequential_search(array_sequential, jumlah_angka, angka_search);
    end_search = clock();

    total_acak = (double)(end_acak - start_acak) / CLOCKS_PER_SEC;
    total_search = (double)(end_search - start_search) / CLOCKS_PER_SEC;
    total_waktu = total_acak + total_search;

    printf("\n    SELESAI\n");
    printf("    - Waktu Pengacakan Angka  : %.2f s\n", total_acak);
    printf("    - Waktu Pencaharian Angka : %.2f s\n", total_search);
    printf("                                ----- +\n");
    printf("    - Total Waktu             : %.2f s\n", total_waktu);
	printf(" =========================================\n");

    pilihan_ulang(4);
}

//prosedur tampilan dan perhitungan dari binary search
void binary_search(){
    int jumlah_angka;
    int i, j;
    int angka_search;

    time_t start_acak, end_acak;
    time_t start_sort, end_sort;
    time_t start_search, end_search;

    double total_acak, total_sort, total_search, total_waktu;

	printf(" =========================================\n");
	printf("|             PROGRAM SORTING       	  |\n");
	printf("|              Binary Search              |\n");
	printf(" =========================================\n");
    printf("    Masukan Jumlah Angka : ");
    jumlah_angka = input(0,0,0);

    int array_binary[jumlah_angka];

    start_acak = clock();
    printf("\n    Sedang Mengacak %d Angka...", jumlah_angka);
    acak_array(array_binary, jumlah_angka);

    printf("\n    Sedang mengurutkan %d angka dengan metode Bubble Sort...", jumlah_angka);
    rumus_bubble_sort(array_binary, jumlah_angka);

    printf("\n");
    printf("\n    HASIL ANGKA :\n");
    tampil_array(array_binary, jumlah_angka);
    end_acak = clock();

    angka_search = searching();

    printf("\n    Sedang mencari angka %d dengan metode Binary Search...", angka_search);
    start_search = clock();
    rumus_binary_search(array_binary, jumlah_angka, angka_search);
    end_search = clock();

    total_acak = (double)(end_acak - start_acak) / CLOCKS_PER_SEC;
    total_search = (double)(end_search - start_search) / CLOCKS_PER_SEC;
    total_waktu = total_acak + total_search;

    printf("\n    SELESAI\n");
    printf("    - Waktu Pengacakan Dan Pengurutan  : %.2f s\n", total_acak);
    printf("    - Waktu Pencaharian Angka          : %.2f s\n", total_search);
    printf("                                ----- +\n");
    printf("    - Total Waktu             : %.2f s\n", total_waktu);
	printf(" =========================================\n");

    pilihan_ulang(5);
}

//prosedur menu utama / menu awal
void menu_utama(){
    int pilihan;
	printf(" =========================================\n");
	printf("|       PROGRAM SORTING DAN SEARCHING     |\n");
	printf(" =========================================\n");
	printf("|   Pilihan :                             |\n");
	printf("|   1. Insertion Sort                     |\n");
	printf("|   2. Bubble Sort                        |\n");
	printf("|   3. Quick Sort                         |\n");
	printf("|   4. Sequential Search                  |\n");
	printf("|   5. Binary Search                      |\n");
	printf("|   6. Keluar                             |\n");
	printf(" =========================================\n");
	printf("    Pilihan : ");
    pilihan = input(0,0,6);

    if(pilihan == 1){
        system("cls");
        insertion_sort();
    }else if(pilihan == 2){
        system("cls");
        bubble_sort();
    }else if(pilihan == 3){
        system("cls");
        quick_sort();
    }else if(pilihan == 4){
        system("cls");
        sequential_search();
    }else if(pilihan == 5){
        system("cls");
        binary_search();
    }else if(pilihan == 6){
        keluar();
    }
}

// fungsi main
int main(){
    system("cls");
    menu_utama();

    return 0;
}
