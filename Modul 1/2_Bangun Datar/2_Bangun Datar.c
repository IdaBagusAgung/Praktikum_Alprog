#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#define PHI 3.14


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

//pada menu utama jika input selain int
void re_valid_int(int *var, char *prompt){
	while(1){
		printf(prompt);
		if(validasi_int(var))
			break;
		printf("Menu tidak tersedia, masukkan pilihan dengan benar!\n");
		printf("Silahkan coba lagi.\n");
	}
}

float validasi_float(float *var){
	char buff[1024];
	char cek;
	fflush(stdin);
	if(fgets(buff, sizeof(buff), stdin) != NULL){
		if(sscanf(buff, "%f %c", var, &cek) == 1) {
			return 1;
		}
	}
	return 0;
}

//pada input nilai selain tipe data float
void re_valid_float(float *var, char *prompt){
	while(1){
		printf(prompt);
		if(validasi_float(var))
			break;
		printf("Input salah, masukkan angka!\n");
		printf("Silahkan coba lagi.\n\n");
	}
}

void range_valid_int(int *var, int range1, int range2, char *prompt){
	while(1){
		re_valid_int(var, prompt);
		if(*var >= range1  && *var <= range2)
			break;
		printf("\nInput salah! Silahkan coba lagi.\n");
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
		printf("\nInput salah! Silahkan coba lagi.\n");
		}
	}
	if(ext=='n' || ext=='N') return 0;
	return 1; 
}

int UlangHitung(char y, char n, char *prompt){
	char ext;
	while(1){
		printf(prompt);
		fflush(stdin);
		scanf("%c", &ext);
		if((ext=='y' || ext=='Y') || (ext=='n' || ext=='N')){
			if (ext == 'y' || ext == 'Y'){
			}
			break;
		}else{
		printf("\nInput salah! Silahkan coba lagi.\n");
		}
	}
	if(ext=='n' || ext=='N') return 0;
	return 1; 
}

void segitigasembarang(int pilihan, float sisi1, float sisi2, float sisi3){
	do{
		system("cls");
		re_valid_float(&sisi1, "Masukkan Nilai Sisi 1(cm): ");
		while(sisi1<0){
			printf("\nHanya berlaku untuk bilangan positif!\n");
            printf("Silahkan Input Ulang\n");
            re_valid_float(&sisi1, "\nMasukkan Nilai Sisi 1(cm): ");
		}
		re_valid_float(&sisi2, "Masukkan Nilai Sisi 2(cm): ");
		while(sisi2<0){
			printf("\nHanya berlaku untuk bilangan positif!\n");
            printf("Silahkan Input Ulang\n");
            re_valid_float(&sisi2, "\nMasukkan Nilai Sisi 2(cm): ");
		}
		re_valid_float(&sisi3, "Masukkan Nilai Sisi 3(cm): ");
		while(sisi3<0){
			printf("\nHanya berlaku untuk bilangan positif!\n");
            printf("Silahkan Input Ulang\n");
            re_valid_float(&sisi3, "\nMasukkan Nilai Sisi 3(cm): ");
		}
			
		if(pilihan == 1){
			float keliling = sisi1 +  sisi2 +  sisi3;
    		printf("Keliling Segitiga Sembarang %.2f cm", keliling);
		}else{
			float s = (sisi1 + sisi2 + sisi3) / 2;
    		float luas =  sqrt(s * (s - sisi1) * (s - sisi2) * (s - sisi3));
    		printf("Luas Segitiga Sembarang %.2f cm2", luas);
		}
	}while(UlangHitung('y','n', "\nUlang Menghitung? [Y/N] : "));
	system("cls");


}

void belahketupat(int pilihan, float sisi, float d1, float d2){
	do{
		system("cls");
		if(pilihan == 1){
			re_valid_float(&sisi, "Masukkan Nilai Sisi(cm): ");
			while(sisi<0){
				printf("\nHanya berlaku untuk bilangan positif!\n");
            	printf("Silahkan Input Ulang\n");
            	re_valid_float(&sisi, "\nMasukkan Nilai Sisi(cm): ");
			}
			float keliling = 4 * sisi;
    		printf("Keliling Belah Ketupat %.2f cm", keliling);
		}else{
			re_valid_float(&d1, "Masukkan Nilai Diagonal 1(cm): ");
			while(d1<0){
				printf("\nHanya berlaku untuk bilangan positif!\n");
            	printf("Silahkan Input Ulang\n");
            	re_valid_float(&d1, "\nMasukkan Nilai Diagonal 1(cm): ");
			}
			re_valid_float(&d2, "Masukkan Nilai Diagonal 2(cm): ");
			while(d2<0){
				printf("\nHanya berlaku untuk bilangan positif!\n");
            	printf("Silahkan Input Ulang\n");
            	re_valid_float(&d2, "\nMasukkan Nilai Diagonal 2(cm): ");
			}
			float luas = d1 * d2 / 2;
    		printf("Luas Belah Ketupat %.2f cm2", luas);
		}
	}while(UlangHitung('y','n', "\nUlang Menghitung? [Y/N] : "));
	system("cls");

}

void jajargenjang(int pilihan, float alas, float tinggi, float sisimiring){
	do{
		system("cls");
		re_valid_float(&alas, "Masukkan Nilai Alas(cm): ");
		while(alas<0){
			printf("\nHanya berlaku untuk bilangan positif!\n");
            printf("Silahkan Input Ulang\n");
            re_valid_float(&alas, "\nMasukkan Nilai Alas(cm): ");
		}
	
		if(pilihan == 1){
			re_valid_float(&sisimiring, "Masukkan Nilai Sisi Miring(cm): ");
			while(sisimiring<0){
				printf("\nHanya berlaku untuk bilangan positif!\n");
            	printf("Silahkan Input Ulang\n");
            	re_valid_float(&sisimiring, "\nMasukkan Nilai Sisi Miring(cm): ");
			}
			float keliling = 2 * (alas + sisimiring);
    		printf("Keliling Jajar Genjang %.2f cm", keliling);
		}else{
			re_valid_float(&tinggi, "Masukkan Nilai Tinggi(cm): ");
			while(tinggi<0){
				printf("\nHanya berlaku untuk bilangan positif!\n");
            	printf("Silahkan Input Ulang\n");
            	re_valid_float(&tinggi, "\nMasukkan Nilai Tinggi(cm): ");
			}
			float luas = alas * tinggi;
    		printf("Luas Jajar Genjang %.2f cm2", luas);
		}
	}while(UlangHitung('y','n', "\nUlang Menghitung? [Y/N] : "));
	system("cls");

}

void trapesium(int pilihan, float a, float b, float c, float d, float tinggi){
	do{
		system("cls");
		re_valid_float(&a, "Masukkan Nilai Sisi a(cm): ");
		while(a<0){
			printf("\nHanya berlaku untuk bilangan positif!\n");
            printf("Silahkan Input Ulang\n");
            re_valid_float(&a, "\nMasukkan Nilai Sisi a(cm): ");
		}
		re_valid_float(&b, "Masukkan Nilai Sisi b(cm): ");
		while(b<0){
			printf("\nHanya berlaku untuk bilangan positif!\n");
            printf("Silahkan Input Ulang\n");
            re_valid_float(&b, "\nMasukkan Nilai Sisi b(cm): ");
		}
	
		if(pilihan == 1){
			re_valid_float(&c, "Masukkan Nilai Sisi c(cm): ");
			while(c<0){
				printf("\nHanya berlaku untuk bilangan positif!\n");
            	printf("Silahkan Input Ulang\n");
            	re_valid_float(&c, "\nMasukkan Nilai Sisi c(cm): ");
			}
			re_valid_float(&d, "Masukkan Nilai Sisi d(cm): ");
			while(d<0){
				printf("\nHanya berlaku untuk bilangan positif!\n");
            	printf("Silahkan Input Ulang\n");
            	re_valid_float(&d, "\nMasukkan Nilai Sisi d(cm): ");
			}
			float keliling = a + b + c + d;
    		printf("Keliling Trapesium %.2f cm", keliling); 
		}else{
			re_valid_float(&tinggi, "Masukkan Nilai Tinggi(cm): ");
			while(tinggi<0){
				printf("\nHanya berlaku untuk bilangan positif!\n");
            	printf("Silahkan Input Ulang\n");
            	re_valid_float(&tinggi, "\nMasukkan Nilai Tinggi(cm): ");
        	}
			float luas = 0.5 * (a + b) * tinggi;
    		printf("Luas Trapesium %.2f cm2", luas);
		}
	}while(UlangHitung('y','n', "\nUlang Menghitung? [Y/N] : "));
	system("cls");

}

void lingkaran(int pilihan, float jarijari){
	do{
		system("cls");
		re_valid_float(&jarijari, "Masukkan Nilai Jari-jari(cm): ");
		while(jarijari<0){
			printf("\nHanya berlaku untuk bilangan positif!\n");
            printf("Silahkan Input Ulang\n");
            re_valid_float(&jarijari, "\nMasukkan Nilai Jari-jari(cm): ");
		}
			
		if(pilihan == 1){
			float keliling = 2 * PHI * jarijari;
    		printf("Keliling Lingkaran %.2f cm", keliling);
		}else{
			float luas =  PHI * jarijari * jarijari;
    		printf("Luas Lingkaran %.2f cm2", luas);
		}
	}while(UlangHitung('y','n', "\nUlang Menghitung? [Y/N] : "));
	system("cls");

}

int main(){
	int menu, submenu;
	float a, b, c, d, tinggi;
	float jarijari, alas, sisi1, sisi2, sisi3, sisi;
	float sisimiring, d1, d2;
	printf("SELAMAT DATANG DALAM PROGRAM MENGHITUNG KELILING DAN LUAS BANGUN DATAR\n");
		printf("Oleh Kelompok Praktikum Alprog 22\n");
	do{
		printf("=======================================\n");
		printf("|	Pilihan Bangun Datar	      |\n");
		printf("|=====================================|\n");
		printf("|	1. Segitiga Sembarang	      |\n");
		printf("|=====================================|\n");
		printf("|	2. Belah Ketupat	      |\n");
		printf("|=====================================|\n");
		printf("|	3. Jajar Genjang	      |\n");
		printf("|=====================================|\n");
		printf("|	4. Trapesium	      	      |\n");
		printf("|=====================================|\n");
		printf("|	5. Lingkaran	       	      |\n");
		printf("|=====================================|\n");
		printf("|	6. Exit	       	      	      |\n");
		printf("|=====================================|\n");
		range_valid_int(&menu, 1, 6, "\n\nPilih Menu : ");
		system("cls");
		
		if(menu==6){
			exit(0);
		}
		
		printf("Pilihlah Operasi Perhitungan Apa Yang Anda Inginkan : \n");
		printf("|========================|\n");
		printf("|   1. Keliling 	 |\n");
		printf("|========================|\n");
		printf("|   2. Luas		 | \n");
		printf("|========================|\n");

        range_valid_int(&submenu, 1, 2, "\n\nMasukkan Pilihan yang anda inginkan :" );
        
        system("cls");
        
        	if(menu==1){
			
        		segitigasembarang(submenu, sisi1, sisi2, sisi3);
        		
        	}else if(menu==2){
			
        		belahketupat(submenu, sisi, d1, d2);
        		
        	}else if(menu==3){
			
        		jajargenjang(submenu, alas, tinggi, sisimiring);
        		
        	}else if(menu==4){
		
        		trapesium(submenu, a, b, c, d, tinggi);
        		
        	}else if(menu==5){
			
        		lingkaran(submenu, jarijari);
        		
        	}
	}while(tryAgain('y','n', "\nUlang Program? [Y/N] : "));
}
	
