#include <stdio.h>

int validasi_int(int *var){
	char buff[1024];
	char cek;
	fflush(stdin);
	if(fgets(buff, sizeof(buff), stdin) != NULL){
		if(sscanf(buff, "%d %c", var, &cek) == 1) {
			return 1;
		}
	}
	return 0;
}

void re_valid_int(int *var, char *prompt){
	while(1){
		printf(prompt);
		if(validasi_int(var))
			break;
		printf("\nInput Salah, Silahkan Coba Kembali!\n\n");
	}
}

int tryAgain(char y, char n, char *prompt){
	char ext;
	while(1){
		printf(prompt);
		fflush(stdin);
		scanf("%c", &ext);
		if((ext=='y' || ext=='Y') || (ext=='n' || ext=='N')){
			if (ext == 'y' || ext == 'Y'){
				system("cls");
			}
			break;
		}else{
			printf("\t\t\t Input salah! Silahkan coba lagi.\n");
		}
	}
	if(ext=='n' || ext=='N') return 0;
	return 1;
}

int main(){

    int pokokPinjaman;
    int bungaSetahun;
    int lamaPinjaman;
    int angsuranPokok;
    int bungaBulanan;
    int angsuranBulanan;
    int totalBunga;
    int totalAngsuran;
    int i;

    do{
        system("cls");
        printf("=========================================================================\n");
        printf("||------------ Modul II No.VI - Program Menghitung Angsuran -----------||\n");
        printf("||--------------------------- By Kelompok 22 --------------------------||\n");
        printf("=========================================================================\n\n");

        re_valid_int(&pokokPinjaman, "Pokok Pinjaman (Rp)\t\t : ");
        while(pokokPinjaman<0){
            printf("\nMasukkan Jumlah Pokok Pinjaman dengan Benar!\n");
            printf("Silahkan Input Ulang!\n\n");
            re_valid_int(&pokokPinjaman, "Pokok Pinjaman (Rp)\t\t : ");
        }

        re_valid_int(&bungaSetahun, "Besar Bunga (%%)\t\t\t : ");
        while(bungaSetahun<0 || bungaSetahun>100){
            printf("\nMasukkan Jumlah Bunga dengan Benar!\n");
            printf("Silahkan Input Ulang!\n\n");
            re_valid_int(&bungaSetahun, "Besar Bunga (%%)\t\t\t : ");
        }

        re_valid_int(&lamaPinjaman, "Lama Pinjaman (Bulan)\t\t : ");
        while(lamaPinjaman<=0){
            printf("\nMasukkan Lama Peminjaman dengan Benar!\n");
            printf("Silahkan Input Ulang!\n\n");
            re_valid_int(&lamaPinjaman, "Lama Pinjamana (Bulan)\t\t : ");
        }

        printf("\n=========================================================================\n");
        printf("||  Bulan  ||   Bunga   ||   Angsuran Pokok   ||   Angsuran Perbulan   ||\n");
        printf("=========================================================================\n");

        for (i = 1; i<=lamaPinjaman; i++){
            angsuranPokok = pokokPinjaman/lamaPinjaman;
            bungaBulanan = (pokokPinjaman - ((i-1)*angsuranPokok)) * bungaSetahun/100/12;
            angsuranBulanan = bungaBulanan + angsuranPokok;
            totalBunga += bungaBulanan;
            totalAngsuran += angsuranBulanan;
            printf("||    %d    ||  %d  ||    Rp.%d     ||      Rp.%d      ||\n",i,bungaBulanan,angsuranPokok,angsuranBulanan);
        }
        printf("=========================================================================\n");
        printf("||Total Bunga                                 : Rp.%d               ||\n", totalBunga);
        printf("||Total Angsuran                              : Rp.%d             ||\n", totalAngsuran);
        printf("=========================================================================\n");

        }while(tryAgain('y','n', "\nApakah Anda Ingin Menghitung Angsuran Kembali? [Y/N] : "));

}
