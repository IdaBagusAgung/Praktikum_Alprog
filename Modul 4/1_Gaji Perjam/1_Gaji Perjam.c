#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

typedef struct{
    int totaljamkerja;
    int jamlembur;
    int jampokok;
    int gajipokok;
    int gajilembur;
    int gajitotal;
}Gaji;

int validasiInt(){
    int input, angka;
    char karakter;
    
    input = scanf(" %d%c", &angka, &karakter);
    if(input != 2 || angka <=0 || angka >24 || karakter != '\n'){
    	clear();
        fflush(stdin);
        printf("Input invalid! Mohon Masukkan ulang : ");
        validasiInt();
    }
	else {
        return angka;
	}
}

int clear(){
	while(getchar() != '\n');
	return 1;
}

void kembali(){
    char pil[2];
    printf("\nApakah anda ingin mengulang? (y/n) \n");
    scanf("%s",&pil);
    if(strcmpi(pil,"y")==0){
        system("cls");
        main();
    }else if(strcmpi(pil,"n")==0){
        exit(0);
    }else{
        printf("Silahkan Masukkan Pilihan Yang Benar!! ");
        kembali();
    }
getch();
}

int main(){
    system ("cls");
    system ("color 70");
    const int gpokok = 10625;
    Gaji g;
    g.totaljamkerja=0;
    g.jamlembur=0;
    g.jampokok=0;
    g.gajipokok=0;
    g.gajilembur=0;
    g.gajitotal=0;

     printf("\t\t\t\t+----------------------------------------------+\n"
        "\t\t\t\t|           PROGRAM PENGHITUNG GAJI            |\n"            
        "\t\t\t\t+----------------------------------------------+\n\n");

    printf("Inputkan Jam Kerja Anda: ");
    g.totaljamkerja = validasiInt();

    if(g.totaljamkerja>8){
        g.jampokok=8;
        g.jamlembur=g.totaljamkerja-8;
        g.gajipokok=8*gpokok;
        g.gajilembur=(g.jamlembur*(gpokok*8));

    }else{
        g.gajipokok=gpokok*g.totaljamkerja;
        g.jampokok=g.totaljamkerja;

    }

      g.gajitotal = g.gajilembur + g.gajipokok;
	printf("\n=====================================");
    printf("\nJumlah Jam Kerja      	:%d \n",g.totaljamkerja);
    printf("Jumlah Jam Kerja Pokok  :%d \n",g.jampokok);
    printf("Jumlah Jam Kerja Lembur :%d \n",g.jamlembur);
    printf("=====================================\n");
    printf("Gaji pokok perjam	: Rp %d\n", gpokok);
    printf("Jumlah Gaji Pokok       : Rp %d \n",g.gajipokok);
    printf("Jumlah Gaji Lembur      : Rp %d \n",g.gajilembur);
    printf("Jumlah Gaji Total       : Rp %d \n",g.gajitotal);
	printf("=====================================\n");
    kembali();
    }
