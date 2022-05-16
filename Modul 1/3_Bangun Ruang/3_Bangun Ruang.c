#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdlib.h>
const float phi = 3.14;


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

void range_valid_float(float *var, char *prompt){
	while(1){
		range_valid_float(var, prompt);
		if(*var >0)
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

float lp_tabung(float r, float t){
    float lp_t = 2 * phi* r * (r + t);
    return lp_t;
}

float v_tabung(float r, float t){
    float v_t = phi * r * r * t;
    return v_t;
}

float lp_bola(float r){
    float lp_b = 4 * phi * r * r;
    return lp_b;
}

float v_bola(float r){
    float v_b = (4 * phi * r * r * r)/3;
    return v_b;
}

float lp_limas(float p, float l, float t){
    float lp_l = (p * l) + (2 * 1 * p * t)/2 + (2 * 1 * l * t)/2;
    return lp_l;
}

float v_limas(float p, float l, float t){
    float v_l = (p * l * t)/3;
    return v_l;
}

float lp_prisma(float ts, float as, float t, float ms){
    float lp_p = (2 * ((ts*as)/2) +  (ms + ms + as) * t);
    return lp_p;
}

float v_prisma(float ts, float as, float t){
    float v_p = (ts * as * t)/2;
    return v_p;
}

float lp_kerucut(float r, float s){
    float lp_k = phi * r * (r + s);
    return lp_k;
}

float v_kerucut(float r, float t){
    float v_k = (phi * r * r * t)/3;
    return v_k;
}

int main(){

    int menu_pilihan, menu_awal;
    float r, t, s, p, l, ts, a, as, ms;
    float luas_tabung, luas_bola, luas_limas, luas_prisma, luas_kerucut;
    float volume_tabung, volume_bola, volume_limas, volume_prisma, volume_kerucut;

    do{
		
		menuutama:
			
        system("cls");
        printf("========================================================\n");
        printf("||   Menghitung Luas Permukaan & Volume Bangun Ruang  ||\n");
        printf("========================================================\n");
        printf("||1.  Luas Permukaaan                                 ||\n");
        printf("||2.  Volume                                          ||\n");
        printf("========================================================\n");

        range_valid_int(&menu_awal, 1, 2, "\n\nPilih Operasi : ");

        if (menu_awal == 1){
        	do{
            system("cls");
            printf("========================================================\n");
            printf("||       Menghitung Luas Permukaan Bangun Ruang       ||\n");
            printf("========================================================\n");
            printf("||1.  Luas Permukaan Tabung                           ||\n");
            printf("||2.  Luas Permukaan Bola                             ||\n");
            printf("||3.  Luas Permukaan Limas Segiempat                  ||\n");
            printf("||4.  Luas Permukaan Prisma Segitiga                  ||\n");
            printf("||5.  Luas Permukaan Kerucut                          ||\n");
            printf("||6.  Kembali					      ||\n");
            printf("========================================================\n");

            range_valid_int(&menu_pilihan, 1, 6, "\n\nPilih Menu : ");
			system("cls");
            switch(menu_pilihan){
                case 1:
                	do{
                	    system("cls");
                        printf("\nMenghitung Luas Permukaan Tabung!\n");
                        re_valid_float(&r, "Masukkan Jari Jari Tabung (cm)\t : ");
                        while (r<0){
                            printf("\nHanya berlaku untuk bilangan positif!\n");
                            printf("Silahkan Input Ulang\n");
                            re_valid_float(&r, "\nMasukkan Jari Jari Tabung (cm)\t : ");
                    	}
                        re_valid_float(&t, "Masukkan Tingi Tabung (cm)\t : ");
                        while (t<0){
                            printf("\nHanya berlaku untuk bilangan positif!\n");
                            printf("Silahkan Input Ulang\n");
                            re_valid_float(&t, "\nMasukkan Tingi Tabung (cm)\t : ");
                    	}

                        luas_tabung = lp_tabung(r, t);
                        printf("Luas Permukaan Tabung (cm)\t : %.2f cm kuadrat\n\n", luas_tabung);
                	}while (UlangHitung('y','n', "\nUlang Menghitung? [Y/N] : "));
                	system("cls");

					break;

                case 2:
                	do{
                	    system("cls");
						printf("\nMenghitung Luas Permukaan Bola!\n");
                        re_valid_float(&r, "Masukkan Jari Jari Bola (cm)\t : ");
                        while (r<0){
                            printf("\nHanya berlaku untuk bilangan positif!\n");
                            printf("Silahkan Input Ulang\n");
                            re_valid_float(&r, "\nMasukkan Jari Jari Bola (cm)\t : ");
                    	}

                        luas_bola = lp_bola(r);
                        printf("Luas Permukaan Bola (cm)\t : %.2f cm kuadrat\n\n", luas_bola);
                	}while (UlangHitung('y','n', "\nUlang Menghitung? [Y/N] : "));

                    system("cls");
                        break;

                case 3:
                	do{
                	    system("cls");
                        printf("\nMenghitung Luas Permukaan Limas Segiempat!\n");
                        re_valid_float(&p, "Masukkan Panjang Limas Segiempat (cm)    : ");
                        while (p<0){
                            printf("\nHanya berlaku untuk bilangan positif!\n");
                            printf("Silahkan Input Ulang\n");
                            re_valid_float(&p, "\nMasukkan Panjang Limas Segiempat (cm)    : ");
                    	}
                        re_valid_float(&l, "Masukkan Lebar Limas Segiempat (cm)\t : ");
                        while (l<0){
                            printf("\nHanya berlaku untuk bilangan positif!\n");
                            printf("Silahkan Input Ulang\n");
                            re_valid_float(&l, "\nMasukkan Lebar Limas Segiempat (cm)\t : ");
                    	}
                        re_valid_float(&t, "Masukkan Tinggi Limas Segiempat (cm)\t : ");
                        while (t<0){
                            printf("\nHanya berlaku untuk bilangan positif!\n");
                            printf("Silahkan Input Ulang\n");
                            re_valid_float(&t, "\nMasukkan Tinggi Limas Segiempat (cm)\t : ");
                    	}

                        luas_limas = lp_limas(p, l, t);
                        printf("Luas Permukaan Limas Segiempat (cm)\t : %.2f cm kuadrat\n\n", luas_limas);
                    }while (UlangHitung('y','n', "\nUlang Menghitung? [Y/N] : "));

                    system("cls");
                    break;

                case 4:
                	do{
                	    system("cls");
                        printf("\nMenghitung Luas Permukan Prisma Segitiga!\n");
                        re_valid_float(&ts, "Masukkan Tinggi Segitiga (cm)\t\t : ");
                        while (ts<0){
                            printf("\nHanya berlaku untuk bilangan positif!\n");
                            printf("Silahkan Input Ulang\n");
                            re_valid_float(&ts, "\nMasukkan Tinggi Segitiga (cm)\t : ");
                    	}
                        re_valid_float(&as, "Masukkan Alas Segitiga (cm)\t\t : ");
                        while (as<0){
                            printf("\nHanya berlaku untuk bilangan positif!\n");
                            printf("Silahkan Input Ulang\n");
                            re_valid_float(&as, "\nMasukkan Alas Segitiga (cm)\t\t : ");
                    	}
                        re_valid_float(&t, "Masukkan Tinggi Prisma Segitiga (cm)\t : ");
                        while (t<0){
                            printf("\nHanya berlaku untuk bilangan positif!\n");
                            printf("Silahkan Input Ulang\n");
                            re_valid_float(&t, "\nMasukkan Tinggi Prisma Segitiga (cm)\t : ");
                    	}
                    	re_valid_float(&ms, "Masukkan Sisi Miring Segitiga (cm)\t : ");
                    	while (ms<0){
                            printf("\nHanya berlaku untuk bilangan positif!\n");
                            printf("Silahkan Input Ulang\n");
                            re_valid_float(&ms, "Masukkan Sisi Miring Segitiga (cm)\t : ");
                    	}

                        luas_prisma = lp_prisma(ts, as, t, ms);
                        printf("Luas Permukaan Prisma Segitiga (cm)\t : %.2f cm kuadrat\n\n", luas_prisma);
                	}while (UlangHitung('y','n', "\nUlang Menghitung? [Y/N] : "));

                    system("cls");
					break;

                case 5:
                	do{
                	    system("cls");
                        printf("\nMenghitung Luas Permukaan Kerucut\n");
                        re_valid_float(&r, "Masukkan Jari Jari Kerucut (cm)\t\t : ");
                        while (r<0){
                            printf("\nHanya berlaku untuk bilangan positif!\n");
                            printf("Silahkan Input Ulang\n");
                            re_valid_float(&r, "\nMasukkan Jari Jari Kerucut (cm)\t\t : ");
                    	}
                        re_valid_float(&s, "Masukkan Garis Pelukis Kerucut (cm)\t : ");
                        while (s<0){
                            printf("\nHanya berlaku untuk bilangan positif!\n");
                            printf("Silahkan Input Ulang\n");
                            re_valid_float(&s, "\nMasukkan Garis Pelukis Kerucut (cm)\t : ");
                    	}

                        luas_kerucut = lp_kerucut(r, s);
                        printf("Luas Permukaan Kerucut (cm)\t\t : %.2f cm kuadrat\n\n", luas_kerucut);
                	}while (UlangHitung('y','n', "\nUlang Menghitung? [Y/N] : "));

                    system("cls");
					break;
				case 6:
					goto menuutama;

			}
			}while(tryAgain('y','n', "\nUlang Program Luas? [Y/N] : "));
			system("cls");
		
    	}else{
        	do{
        	menuutama1:
        	system("cls");
            printf("========================================================\n");
            printf("||        Menghitung Volume Bangun Ruang              ||\n");
            printf("========================================================\n");
            printf("||1.  Volume Tabung                                   ||\n");
            printf("||2.  Volume Bola                                     ||\n");
            printf("||3.  Volume Limas Segiempat                          ||\n");
            printf("||4.  Volume Prisma Segitiga                          ||\n");
            printf("||5.  Volume Kerucut                                  ||\n");
            printf("||6.  Kembali					      ||\n");
            printf("========================================================\n");

            range_valid_int(&menu_pilihan, 1, 6, "\n\nPilih Menu : ");
			system("cls");
            switch(menu_pilihan){
                case 1:
                	do{
                	    system("cls");
                    	printf("\nMenghitung Volume Tabung!\n");
                    	re_valid_float(&r, "Masukkan Jari Jari Tabung (cm)\t : ");
                    	while (r<0){
                            printf("\nHanya berlaku untuk bilangan positif!\n");
                            printf("Silahkan Input Ulang\n");
                            re_valid_float(&r, "\nMasukkan Jari Jari Tabung (cm)\t : ");
                    	}
                    	re_valid_float(&t, "Masukkan Tingi Tabung (cm)\t : ");
                    	while (t<0){
                            printf("\nHanya berlaku untuk bilangan positif!\n");
                            printf("Silahkan Input Ulang\n");
                            re_valid_float(&t, "\nMasukkan Tingi Tabung (cm)\t : ");
                    	}

                    	volume_tabung = v_tabung(r, t);
                    	printf("Volume Tabung (cm)\t\t : %.2f cm kubik\n\n", volume_tabung);
                	}while (UlangHitung('y','n', "\nUlang Menghitung? [Y/N] : "));

                    system("cls");
					break;

                case 2:
                	do{
                	    system("cls");
                    	printf("\nMenghitung Volume Bola\n");
                    	re_valid_float(&r, "Masukkan Jari Jari Bola (cm)\t : ");
                    	while (r<0){
                            printf("\nHanya berlaku untuk bilangan positif!\n");
                            printf("Silahkan Input Ulang\n");
                            re_valid_float(&r, "\nMasukkan Jari Jari Bola (cm)\t : ");
                    	}


                    	volume_bola = v_bola(r);
                    	printf("Volume Bola (cm)\t\t : %.2f cm kubik\n\n", volume_bola);
                	}while (UlangHitung('y','n', "\nUlang Menghitung? [Y/N] : "));

                    system("cls");
					break;

                case 3:
                	do{
                	    system("cls");
                    	printf("\nMenghitung Volume Limas Segiempat!\n");
                    	re_valid_float(&p, "Masukkan Panjang Limas Segiempat (cm)    : ");
                    	while (p<0){
                            printf("\nHanya berlaku untuk bilangan positif!\n");
                            printf("Silahkan Input Ulang\n");
                            re_valid_float(&p, "\nMasukkan Panjang Limas Segiempat (cm)    : ");
                    	}
                    	re_valid_float(&l, "Masukkan Lebar Limas Segiempat (cm)\t : ");
                    	while (l<0){
                            printf("\nHanya berlaku untuk bilangan positif!\n");
                            printf("Silahkan Input Ulang\n");
                            re_valid_float(&l, "\nMasukkan Lebar Limas Segiempat (cm)\t : ");
                    	}
                    	re_valid_float(&t, "Masukkan Tinggi Limas Segiempat (cm)\t : ");
                    	while (t<0){
                            printf("\nHanya berlaku untuk bilangan positif!\n");
                            printf("Silahkan Input Ulang\n");
                            re_valid_float(&t, "\nMasukkan Tinggi Limas Segiempat (cm)\t : ");
                    	}

                    	volume_limas = v_limas(p, l, t);
                    	printf("Volume Limas Segiempat (cm)\t\t : %.2f cm kubik\n\n", volume_limas);
                	}while (UlangHitung('y','n', "\nUlang Menghitung? [Y/N] : "));

                    system("cls");
					break;

                case 4:
                	do{
                	    system("cls");
                    	printf("\nMenghitung Volume Prisma Segitiga!\n");
                    	re_valid_float(&ts, "Masukkan Tinggi Alas Segitiga (cm)\t: ");
                    	while (ts<0){
                            printf("\nHanya berlaku untuk bilangan positif!\n");
                            printf("Silahkan Input Ulang\n");
                            re_valid_float(&ts, "\nMasukkan Tinggi Segitiga (cm)\t: ");
                    	}
                    	re_valid_float(&as, "Masukkan Alas Segitiga (cm)\t\t: ");
                    	while (as<0){
                            printf("\nHanya berlaku untuk bilangan positif!\n");
                            printf("Silahkan Input Ulang\n");
                            re_valid_float(&as, "\nMasukkan Alas Segitiga (cm)\t\t: ");
                    	}
                    	re_valid_float(&t, "Masukkan Tinggi Prisma Segitiga (cm)\t: ");
                    	while (t<0){
                            printf("\nHanya berlaku untuk bilangan positif!\n");
                            printf("Silahkan Input Ulang\n");
                            re_valid_float(&t, "\nMasukkan Tinggi Prisma Segitiga (cm)\t: ");
                    	}

                    	volume_prisma = v_prisma(ts, as, t);
                    	printf("Volume Prisma Segitiga (cm)\t\t: %.2f cm kubik\n\n", volume_prisma);
                	}while (UlangHitung('y','n', "\nUlang Menghitung? [Y/N] : "));

                    system("cls");
					break;

                case 5:
                	do{
                	    system("cls");
                        printf("\nMenghitung Volume Kerucut!\n");
                        re_valid_float(&r, "Masukkan Jari Jari Kerucut (cm)\t : ");
                        while (r<0){
                            printf("\nHanya berlaku untuk bilangan positif!\n");
                            printf("Silahkan Input Ulang\n");
                            re_valid_float(&r, "\nMasukkan Jari Jari Tabung (cm)\t : ");
                    	}
                        re_valid_float(&t, "Masukkan Tinggi Kerucut (cm)\t : ");
                        while (t<0){
                            printf("\nHanya berlaku untuk bilangan positif!\n");
                            printf("Silahkan Input Ulang\n");
                            re_valid_float(&t, "\nMasukkan Tinggi Tabung (cm)\t : ");
                    	}

                        volume_kerucut = v_kerucut(r, t);
                        printf("Volume Kerucut (cm)\t\t : %.2f cm kubik\n\n", volume_kerucut);
                	}while (UlangHitung('y','n', "\nUlang Menghitung? [Y/N] : "));

                    system("cls");
					break;
				case 6:
					goto menuutama1;

			}
			}while(tryAgain('y','n', "\nUlang Program Volume? [Y/N] : "));
			system("cls");
		}
	}while(tryAgain('y','n', "\nUlang Program? [Y/N] : "));

	return 0;
}
