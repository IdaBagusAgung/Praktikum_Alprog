#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct kubus_struct{
    float sisi;
    float luaspermukaan;
    float volume;
};

union kubus_union{
    float sisi;
};

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
		printf("Input salah! Silahkan coba lagi.\n");
		}
	}
	if(ext=='n' || ext=='N') return 0;
	return 1;
}

int main() {
	float sisi, luaspermukaan, volume;
	struct kubus_struct k_struck;
	union kubus_union k_union;

	system("cls");

	do{
		printf("Program Kubus dengan Struct dan Union\n");
		re_valid_float(&sisi, "\nMasukkan sisi : ");
		k_struck.sisi = sisi;
		k_union.sisi = sisi;

	    printf("\nKubus dengan Struct");
	    printf("\nSisi \t\t: %.1f", k_struck.sisi);
	    k_struck.luaspermukaan = 6 * k_struck.sisi * k_struck.sisi;
	    k_struck.volume = k_struck.sisi * k_struck.sisi * k_struck.sisi;
	    printf("\nLuas Permukaan \t: %.1f", k_struck.luaspermukaan);
	    printf("\nVolume \t\t: %.1f\n", k_struck.volume);


	    printf("\nKubus dengan Union");
	    printf("\nSisi \t\t: %.1f", k_union.sisi);
	    k_union.sisi = 6 * k_struck.sisi * k_struck.sisi;
	    printf("\nLuas Permukaan \t: %.1f", k_union.sisi);

	    k_union.sisi = k_struck.sisi * k_struck.sisi * k_struck.sisi;
	    printf("\nVolume \t\t: %.1f\n", k_union.sisi);

	    printf("\nUkuran memory pada kubus struct: %d", sizeof(k_struck));
	    printf("\nUkuran memory pada kubus union : %d", sizeof(k_union));
	    printf("\n");
	}while(tryAgain('y', 'n', "\nUlang Program? [Y/N] : "));

	return 0;
}
