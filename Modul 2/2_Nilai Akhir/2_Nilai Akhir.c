#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>

int main();
float input();
void program_utama();
void keluar();
void pilihan_keluar();

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
    }else if(hasil < 0){
        printf("     Masukkan tidak boleh kurang dari 0! Masukkan nilai yang benar : ");
        return input(desimal);
    }else if(hasil > 100){
        printf("     Masukkan tidak boleh lebih dari 100 ! Masukkan nilai yang benar : ");
        return input(desimal);
    }else{
        return hasil;
    }
}


void keluar(){
    printf("\n   Terima Kasih");
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

void pilihan_ulang(){
    char ulang[1];

    printf("\n   Lakukan lagi? ya/keluar(y/e) : ");
    scanf("%s", &ulang);
    fflush(stdin);

    if((strcmp(ulang, "y") != 0) && (strcmp(ulang, "e") != 0)){
        printf("   Masukan anda salah! Masukan dengan benar\n");
        pilihan_ulang();
    }else if((strcmp(ulang, "y") == 0)){
        system("cls");
        program_utama();
    }else{
        keluar();
    }
}

void program_utama(){
    int bk;
    float tugas1, tugas2, tugas3, quiz, uts, uas, nilai_akhir,nilai_akhir1;
	printf(" ============================================\n");
	printf("|        PROGRAM PENGHITUNG NILAI AKHIR      |\n");
	printf("|                Kelompok 22                 |\n");
	printf("|        AYO TENTUKAN NILAI AKHIR KAMU       |\n");
	printf(" ============================================\n");
    printf("   Input : \n");
    printf("   * Masukan Banyak Kehadiran (0-15) : ");
    bk = input(0);

    while(bk > 15){
        printf("     Kehadiran max. 15! Masukan Ulang : ");
        bk = input(0);
    }

    if(bk == 0){
        nilai_akhir = 0;
        printf("\n   Hasil : \n");
        printf("   * Total Nilai Akhir : %.2f\n", nilai_akhir);
        printf("   * Nilai Huruf       : E");
    
	}else if(bk<=12){
        printf("   * Masukan Nilai Tugas 1   (0-100) : ");
        tugas1 = input(1);
        printf("   * Masukan Nilai Tugas 2   (0-100) : ");
        tugas2 = input(1);
        printf("   * Masukan Nilai Tugas 3   (0-100) : ");
        tugas3 = input(1);
        printf("   * Masukan Nilai Quiz      (0-100) : ");
        quiz = input(1);
        printf("   * Masukan Nilai UTS       (0-100) : ");
        uts = input(1);
        printf("   *Nilai UAS = 0 ");
        
        nilai_akhir1 = (0,05 * (bk / 15)) + (0.2 * ((tugas1 + tugas2 + tugas3) / 3)) +  (0.15 * quiz) + (0.3 * uts);

        
        printf("\n   Hasil : \n");
        printf("   * Total Nilai Akhir : %.2f\n", nilai_akhir1);
        printf("   * Nilai Huruf       : ");
        if ((nilai_akhir1 >= 0) && (nilai_akhir1 < 45)){
            printf("E");
        }else if((nilai_akhir1 >= 45) && (nilai_akhir1 < 50)){
            printf("D");
        }else if((nilai_akhir1 >= 50) && (nilai_akhir1 < 55)){
            printf("D+");
        }else if((nilai_akhir1 >= 55) && (nilai_akhir1 < 60)){
            printf("C");
        }else if((nilai_akhir1 >= 60) && (nilai_akhir1 < 65)){
            printf("C+");
        }else if((nilai_akhir1 >= 65) && (nilai_akhir1 < 75)){
            printf("B");
        }else if((nilai_akhir1 >= 75) && (nilai_akhir1 < 80)){
            printf("B+");
        }else if((nilai_akhir1 >= 80) && (nilai_akhir1 <= 100)){
            printf("A");
        }else{
            printf("Tidak Ada");
        }
     
    }else{
        printf("   * Masukan Nilai Tugas 1   (0-100) : ");
        tugas1 = input(1);
        printf("   * Masukan Nilai Tugas 2   (0-100) : ");
        tugas2 = input(1);
        printf("   * Masukan Nilai Tugas 3   (0-100) : ");
        tugas3 = input(1);
        printf("   * Masukan Nilai Quiz      (0-100) : ");
        quiz = input(1);
        printf("   * Masukan Nilai UTS       (0-100) : ");
        uts = input(1);
        printf("   * Masukan Nilai UAS       (0-100) : ");
        uas = input(1);

        nilai_akhir = (0,05 * (bk / 15)) + (0.2 * ((tugas1 + tugas2 + tugas3) / 3)) +  (0.15 * quiz) + (0.3 * uts) + (0.3 * uas);
		
        printf("\n   Hasil : \n");
        printf("   * Total Nilai Akhir : %.2f\n", nilai_akhir);
        printf("   * Nilai Huruf       : ");

        if((nilai_akhir >= 0) && (nilai_akhir < 45)){
            printf("E");
        }else if((nilai_akhir >= 45) && (nilai_akhir < 50)){
            printf("D");
        }else if((nilai_akhir >= 50) && (nilai_akhir < 55)){
            printf("D+");
        }else if((nilai_akhir >= 55) && (nilai_akhir < 60)){
            printf("C");
        }else if((nilai_akhir >= 60) && (nilai_akhir < 65)){
            printf("C+");
        }else if((nilai_akhir >= 65) && (nilai_akhir < 75)){
            printf("B");
        }else if((nilai_akhir >= 75) && (nilai_akhir < 80)){
            printf("B+");
        }else if((nilai_akhir >= 80) && (nilai_akhir <= 100)){
            printf("A");
        }else{
            printf("Tidak Ada");
        }
    }

    printf("\n");
    pilihan_ulang();
}

int main(){
	system("cls");
    program_utama();

    return 0;
}
