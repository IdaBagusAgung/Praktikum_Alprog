#include <stdio.h>
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

void re_valid_int(int *var, char *prompt){
	while(1){
		printf(prompt);
		if(validasi_int(var))
			break;
		printf("\nInput Yang Anda Masukkan Salah!\n");
		printf("Silahkan coba lagi.\n");
	}
}

void range_valid_int(int *var, int range1, int range2, char *prompt){
	while(1){
		re_valid_int(var, prompt);
		if(*var >= range1  && *var <= range2)
			break;
		printf("\t\t\t Menu Tidak Tersedia!\nSilahkan Masukkan Input Dengan Benar!\n");
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
		printf("\t\t\t Input Yang Anda Masukkan Salah!\nSilahkan Masukkan Input Dengan Benar!\n");
		}
	}
	if(ext=='n' || ext=='N') return 0;
	return 1;
}

void enkripsi(){

    char plaintext[26], ciphertext[26], inputtext[255];
    char temp, panjangtext, geser;
    int i, j, k, l;
    int status = 0, cnt = 0, valstat = 0, valstat1 = 0;

    do{
        printf("========================================================\n");
        printf("||---------- ENKRIPSI KALIMAT DARI PLAINTEXT ---------||\n");
        printf("========================================================\n");

        re_valid_int(&geser, "\tMasukkan Jumlah Pergeseran: ");

        printf("\n\tPlainText\t: ");
        for (i = 0; i < 26; i++){
            plaintext[i] = 'a' + i;
            ciphertext[i] = 'A' + i;
            printf("%c ", plaintext[i]);
        }

        printf("\n\t\t\t  |");

        if(geser > 0){
            for(j = 0; j < geser; j++){
                temp = ciphertext[0];
                for(l = 0; l < 26; l++){
                    ciphertext[l] = ciphertext[l + 1];
                }
                ciphertext[25] = temp;
            }
        }else if(geser < 0){
            for(j = 0; j > geser; j--){
                temp = ciphertext[25];
                for(l = 25; l >= 0; l--){
                    ciphertext[l] = ciphertext[l - 1];
                }
                ciphertext[0] = temp;
            }
        }
        printf("\n\tCipherText\t: ");
        for (i = 0; i < 26; i++){
            printf("%c ", ciphertext[i]);
        }

        printf("\n\n\tText Yang Ingin Dienkripsi\t: ");
        scanf("%[^\n]", &inputtext);
        fflush(stdin);
        valstat = 0;
        while (valstat == 0){
            if (inputtext[0] == ' '){
                printf("\tInput yang Anda Masukkan Salah!\n\tSilahkan Coba Kembali\t\t: ");
                scanf("%[^\n]", &inputtext);
                fflush(stdin);
            }else{
                valstat = 1;
            }
        }
        panjangtext = strlen(inputtext);

        while (status == 0){
            for(i = 0; i < panjangtext; i++){
                if(inputtext[i] == ' '){
                    cnt = 0;
                }else if(inputtext[i] > 122 || inputtext[i] < 65){
                    cnt = cnt + 1;
                }
            }
            if(cnt > 0){
                printf("\tInput yang Anda Masukkan Salah!\n\tSilahkan Coba Kembali\t\t: ");
                scanf("%[^\n]", &inputtext);
                fflush(stdin);
                valstat1 = 0;
                while (valstat1 == 0){
                    if (inputtext[0] == ' '){
                        printf("\tInput yang Anda Masukkan Salah!\n\tSilahkan Coba Kembali\t\t: ");
                        scanf("%[^\n]", &inputtext);
                        fflush(stdin);
                    }else{
                        valstat1 = 1;
                    }
                }
                panjangtext = strlen(inputtext);
                cnt = 0;
                for(i = 0; i < panjangtext; i++){
                    if(inputtext[i] == ' '){
                        cnt = 0;
                    }else if(inputtext[i] > 122 || inputtext[i] < 65){
                        cnt = cnt + 1;
                    }else{
                        cnt = 0;
                    }
                }
            }else{
                status = 1;
            }
        }
        strupr(inputtext);
        printf("\n\tHasil Enkripsi\t\t\t: ");

        for(i = 0; i < panjangtext; i++){
            if(inputtext[i] == ' '){
                printf(" ");
            }else{
                k = inputtext[i] - 65;
                printf("%c", ciphertext[k]);
            }
        }
        }while(tryAgain('y','n', "\n\n\tApakah Anda Ingin Kembali Melakukan Enkripsi? [Y/N] : "));
    }

void dekripsi(){

    char plaintext[26], ciphertext[26], inputtext[255];
    char temp, panjangtext, geser;
    int i, j, l;
    int status = 0, cnt = 0,valstat = 0, valstat1 = 0;

    do{
        printf("========================================================\n");
        printf("||--------- DEKRIPSI KALIMAT DARI CIPHERTEXT ---------||\n");
        printf("========================================================\n");

        re_valid_int(&geser, "\tMasukkan Jumlah Pergeseran: ");

        printf("\n\tPlainText\t: ");
        for (i = 0; i < 26; i++){
            plaintext[i] = 'a' + i;
            ciphertext[i] = 'A' + i;
            printf("%c ", plaintext[i]);
        }

        printf("\n\t\t\t  |");

        if(geser > 0){
            for(j = 0; j < geser; j++){
                temp = ciphertext[0];
                for(l = 0; l < 26; l++){
                    ciphertext[l] = ciphertext[l + 1];
                }
                ciphertext[25] = temp;
            }
        }else if(geser < 0){
            for(j = 0; j > geser; j--){
                temp = ciphertext[25];
                for(l = 25; l >= 0; l--){
                    ciphertext[l] = ciphertext[l - 1];
                }
                ciphertext[0] = temp;
            }
        }
        printf("\n\tCipherText\t: ");
        for (i = 0; i < 26; i++){
            printf("%c ", ciphertext[i]);
        }

        printf("\n\n\tText Yang Ingin Didekripsi\t: ");
        scanf("%[^\n]", &inputtext);
        fflush(stdin);
        valstat = 0;
        while (valstat == 0){
            if (inputtext[0] == ' '){
                printf("\tInput yang Anda Masukkan Salah!\n\tSilahkan Coba Kembali\t\t: ");
                scanf("%[^\n]", &inputtext);
                fflush(stdin);
            }else{
                valstat = 1;
            }
        }
        strupr(inputtext);
        panjangtext = strlen(inputtext);

        while (status == 0){
            for(i = 0; i < panjangtext; i++){
                if(inputtext[i] == ' '){
                    cnt = 0;
                }else if(inputtext[i] > 122 || inputtext[i] < 65){
                    cnt = cnt + 1;
                }else{
                    cnt = 0;
                }
            }
            if(cnt > 0){
                printf("\tInput Yang Anda Masukkan Salah!\n\tSilahkan Masukkan Ulang\t\t: ");
                scanf("%[^\n]", &inputtext);
                fflush(stdin);
                valstat1 = 0;
                while (valstat1 == 0){
                    if (inputtext[0] == ' '){
                        printf("\tInput yang Anda Masukkan Salah!\n\tSilahkan Coba Kembali\t\t: ");
                        scanf("%[^\n]", &inputtext);
                        fflush(stdin);
                    }else{
                        valstat1 = 1;
                    }
                }
                panjangtext = strlen(inputtext);
                cnt = 0;
            for(i = 0; i < panjangtext; i++){
                if(inputtext[i] == ' '){
                    cnt = 0;
                }else if(inputtext[i] > 122 || inputtext[i] < 65){
                        cnt = cnt + 1;
                }
            }
            }else{
                status = 1;
            }
        }

        printf("\n\tHasil Dekripsi\t\t\t: ");

        for(i = 0; i < panjangtext; i++){
            if(inputtext[i] == ' '){
                printf(" ");
            }else{
                j = 0;
                while(inputtext[i] != ciphertext[j]){
                    j++;
                }
                printf("%c", plaintext[j]);
            }
        }
        }while(tryAgain('y','n', "\n\n\tApakah Anda Ingin Kembali Melakukan Dekripsi? [Y/N] : "));
    }

int main(){

    int menu_utama;

    do{
    system("cls");
    printf("========================================================\n");
    printf("||------ Modul III No.V - Enkripsi dan Dekripsi ------||\n");
    printf("||------------------ By Kelompok 22 ------------------||\n");
    printf("========================================================\n");
    printf("||  Pilihan:                                          ||\n");
    printf("||  1.  Enkripsi Kalimat (dari Plaintext)             ||\n");
    printf("||  2.  Dekripsi Kalimat (dari Chiphertext)           ||\n");
    printf("||  3.  Keluar                                        ||\n");
    printf("========================================================\n");

    range_valid_int(&menu_utama, 1, 3, "Masukkan Menu Pilihan: ");

    if (menu_utama == 1){
        system("cls");
        enkripsi();
    }else if (menu_utama == 2){
        system("cls");
        dekripsi();
    }else if (menu_utama == 3){
        sleep(1);
        system("cls");
        system("exit");
    }
    }while(tryAgain('y','n', "\nApakah Anda Ingin Kembali Ke Menu Utama? [Y/N] : "));
}
