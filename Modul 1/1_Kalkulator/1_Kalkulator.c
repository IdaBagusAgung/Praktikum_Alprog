#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

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

void re_valid_int(int *var, char *prompt){
	while(1){
		printf(prompt);
		if(validasi_int(var))
			break;
		printf("Menu tidak tersedia, masukkan pilihan dengan benar!\n");
		printf("Silahkan coba lagi.\n");
	}
}

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

int main(){
    float a, b;
    int c, d, hasil;
	int opsi, menu;
	printf("Selamat Datang Dalam Program Kalkulator\n");
	printf("Oleh Kelompok Praktikum Alprog 22\n");

	do{
		printf("======================\n");
	    printf("|     Kalkulator     |\n");
	    printf("|====================|\n");
	    printf("|   1. Penjumlahan   |\n");
	    printf("|====================|\n");
	    printf("|   2. Pengurangan   |\n");
	    printf("|====================|\n");
	    printf("|    3. Perkalian    |\n");
	    printf("|====================|\n");
	    printf("|    4. Pembagian    |\n");
	    printf("|====================|\n");
	    printf("|    5. Modulus      |\n");
	    printf("|====================|\n");
	    printf("|    6. Exit         |\n");
	    printf("|====================|\n\n");
	    range_valid_int(&menu, 1, 6, "\nPilih Operasi Yang Anda Inginkan : ");
		system("cls");
	    
	    	if(menu==1){

	    		do{
	    			system("cls");
		        	re_valid_float(&a, "Masukkan Angka Pertama Yang Anda Ingin Hitung : ");
		        	re_valid_float(&b, "Masukkan Angka Kedua Yang Anda Ingin Hitung   : ");
		        	printf("Hasil Penjumlahan Bilangan Anda\n %.1lf + %.1lf = %.1lf \n", a, b, a+b);
				}while(UlangHitung('y','n', "\nUlang Menghitung? [Y/N] : "));

			}	
			else if(menu==2){
			
	    		do{
	    			system("cls");
		        	re_valid_float(&a, "Masukkan Angka Pertama Yang Anda Ingin Hitung : ");
		        	re_valid_float(&b, "Masukan Angka Kedua Yang Anda Ingin Hitung   : ");
		        	printf("Hasil Pengurangan Bilangan Anda\n %.2f - %.2f = %.2f \n", a, b, a-b);
				}while(UlangHitung('y','n', "\nUlang Menghitung? [Y/N] : "));

			}
			
	    	else if(menu==3){
			
	    		do{
	    			system("cls");
		        	re_valid_float(&a, "Masukkan Angka Pertama Yang Anda Ingin Hitung : ");
		        	re_valid_float(&b, "Masukkan Angka Kedua Yang Anda Ingin Hitung   : ");
		        	printf("Hasil Perkalian Bilangan Anda\n %.2f * %.2f = %.2f \n", a, b, a*b);
				}while(UlangHitung('y','n', "\nUlang Menghitung? [Y/N] : "));

			}
			
	    	else if(menu==4){
			
	    		do{
	    			system("cls");
		        	re_valid_float(&a, "Masukkan Angka Pertama Yang Anda Ingin Hitung : ");
		        	re_valid_float(&b, "Masukkan Angka Kedua Yang Anda Ingin Hitung   : ");
		        	printf("Hasil Pembagian Bilangan Anda\n %.2f / %.2f = %.2f \n", a, b, a/b);
				}while(UlangHitung('y','n', "\nUlang Menghitung? [Y/N] : "));

			}
	    	else if(menu==5){
			
	    		do{
	    			system("cls");
		    		re_valid_int(&c, "Masukkan Angka Pertama Yang Anda Ingin Hitung : ");
		    		re_valid_int(&d, "Masukkan Angka Kedua Yang Anda Ingin Hitung   : ");
                    hasil = c % d;
		        	printf("Hasil Sisa Modulus Bilangan Anda\n %i \n", hasil);
				}while(UlangHitung('y','n', "\nUlang Menghitung? [Y/N] : "));

	        }
		
	        else if(menu==6){
			
	        	exit(0);

	    	}	
	}while(tryAgain('y','n', "\nUlang Program? [Y/N] : "));
	
	return 0;
}
