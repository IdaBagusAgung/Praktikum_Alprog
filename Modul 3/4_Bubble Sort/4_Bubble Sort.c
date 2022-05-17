#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void sort(int pilihan);

double bubblesort(int n);
double bubble_pointer(int *ptr, int n);
int angka[64000];

int validasiInput(int *var){
	char buff[1024];
	char cek;
	fflush(stdin);
	if (fgets(buff, sizeof(buff), stdin) !=NULL) {
		if (sscanf(buff, "%d %c", var, &cek) ==1){
			return 1;
		}
	}
	return 0;
}

void validasi(int *var){
	while(1){
		if(validasiInput(var))
        break;
        printf("\n\t Pilihan yang anda masukan salah!");
		printf("\n\n\t Masukan Ulang Pilihan : ");
	}
}


void header(){
	printf("\t====================================\n");
	printf("\t        B U B B L E  S O R T        \n");
	printf("\t====================================\n");
	printf("\n\t Pilih Metode : \n");
	printf("\t 1. Biasa\n");
	printf("\t 2. Pointer\n");
	printf("\t ====================================\n");
	
}

void metode(int metode);

double bubblesort(int n){
	int i,k,temp;
	int a[n];
	double waktu1;
	clock_t t1;
	
	printf("\t Data Acak Bubblesort(%d) biasa ", n);
	printf("\n\n\t Data Sebelum Sorting : \n");
	printf("\t Press any key...");
	getch();
	srand(time(0));
	for(i=0;i<n;i++){
		a[i]=rand();
		printf("\t %d ", a[i]);
	}
	t1= clock();
	
	for(i=0;i<n-1;i++){
		for(k=n-1;k>i;k--){
			if(a[k]<a[k-1]){
				temp=a[k];
				a[k]=a[k-1];
				a[k-1]=temp;
			}
		}
	}
	
	printf("\n\n\n\t Data Sesudah Sorting : \n");
	printf("\t Press any key...");
	getch();
	for(i=0;i<n;i++){
		printf("\t %d ",a[i]);
	}
	t1=clock()-t1;
	waktu1 = ((double)t1)/CLOCKS_PER_SEC;
 	return waktu1;
}

double bubble_pointer(int *ptr, int n){
	int i,j,temp;
	double waktu2;
	clock_t t2;
	
	printf("\t Data Acak Bubblesort(%d) dengan pointer ", n);
	printf("\n\n\t Data Sebelum Sorting : \n");
	printf("\t Press any key...");
	getch();
	srand(time(0));
	for(i=0;i<n;i++){
		angka[i]=rand();
		printf("\t %d ", angka[i]);
	}
	printf("\n\n\n\t Data Sesudah Sorting : \n");
	printf("\t Press any key...");		
	getch();
	t2= clock();
	for(i=1;i<n;i++){
		for(j=0;j<n-1;j++){
			if(*(ptr+j)>*(ptr+j+1)){
				temp=*(ptr+j);
				*(ptr+j)=*(ptr+j+1);
				*(ptr+j+1)=temp;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("\t %d ",angka[i]);
	}
	t2=clock()-t2;	
	waktu2 = ((double)t2)/CLOCKS_PER_SEC;			
	return waktu2;
}

void menu(){
	int metode;
	int pilihan;
	char menu2;
	double t1,t2;
	int n;
	
	while(1){
	system("cls");
	printf("\t         B U B B L E  S O R T          \n");
	printf("\t+=====================================+\n");
    printf("\n\t Jumlah angka yang mau di urut: \n");
    printf("\t 1. 1.000 \n");
    printf("\t 2. 16.000 \n");
    printf("\t 3. 64.000 \n");
    printf("\t+=====================================+\n");
    printf("\t Masukkan Pilihan : ");
		if(validasiInput(&pilihan)){
			
			if(pilihan==1){
				n=1000;
				
				satu:				
				system("cls");
				header();
			    printf("\t Masukkan Pilihan : ");	
				validasi(&metode);
			    if(metode==1){
			    	t1=bubblesort(n);
			    	printf("\n\n\n\t Hasil Waktu Sorting : \n");
			    	printf("\t BubleSort(%d) cara biasa memerlukan waktu %.2f seconds\n", n, t1);
					printf("\t Masukkan y untuk kembali dan n untuk keluar\n");
					printf("\t Masukkan :");
					scanf("%c", &menu2);
					if(menu2 == 'y'){
						menu();
					}
					else if(menu2 == 'n'){
						system("cls");
						printf("+============================================================+\n");
						printf("\t Terimakasih Sudah Menggunakan Program Kami");
						printf("\n+============================================================+\n");
						exit(0);
					}
					getch();
				}else if(metode==2){
					t2=bubble_pointer(angka, n);
					printf("\n\n\n\t Hasil Waktu Sorting : \n");
					printf("\t BubleSort(%d) dengan pointer memerlukan waktu %.2f seconds\n", n, t2);
					printf("\t Masukkan y untuk kembali dan n untuk keluar\n");
					printf("\t Masukkan :");
					scanf("%c",&menu2);
					if(menu2 == 'y'){
						menu();
					}
					else if(menu2 == 'n'){
						system("cls");
						printf("+============================================================+\n");
						printf("\t Terimakasih Sudah Menggunakan Program Kami");
						printf("\n+============================================================+\n");
						exit(0);
					}
					getch();
				}else {
					printf("\n\t Inputan yang anda masukkan salah.");
					getch();
					goto satu;
				}
			}
			else if(pilihan==2){
				n=16000;
				
				dua:
				system("cls");
				header();
			    printf("\t Masukkan Pilihan : ");	
				validasi(&metode);
			    if(metode==1){
			    	t1=bubblesort(n);
			    	printf("\n\n\n\t Hasil Waktu Sorting : \n");
			    	printf("\t BubleSort(%d) cara biasa memerlukan waktu %.2f seconds\n", n, t1);
			    	printf("\t Masukkan y untuk kembali dan n untuk keluar\n");
					printf("\t Masukkan :");
					scanf("%c",&menu2);
					if(menu2 == 'y'){
						menu();
					}
					else if(menu2 == 'n'){
						system("cls");
						printf("+============================================================+\n");
						printf("\t Terimakasih Sudah Menggunakan Program Kami");
						printf("\n+============================================================+\n");
						exit(0);
					}
					getch();
				
				}else if(metode==2){
					t2=bubble_pointer(angka, n);
					printf("\n\n\n\t Hasil Waktu Sorting : \n");
					printf("\t BubleSort(%d) dengan pointer memerlukan waktu %.2f seconds\n", n, t2);
					printf("\t Masukkan y untuk kembali dan n untuk keluar\n");
					printf("\t Masukkan :");
					scanf("%c",&menu2);
					if(menu2 == 'y'){
						menu();
					}
					else if(menu2 == 'n'){
						system("cls");
						printf("+============================================================+\n");
						printf("\t Terimakasih Sudah Menggunakan Program Kami");
						printf("\n+============================================================+\n");
						exit(0);
					}
					getch();
				}else {
					printf("\n\t Inputan yang anda masukkan salah.");
					getch();
					goto dua;
					
				}
			}
			else if(pilihan==3){
				n=64000;
				
				tiga:
				system("cls");
				header();
			    printf("\t Masukkan Pilihan : ");	
				validasi(&metode);
			    if(metode==1){
			    	t1=bubblesort(n);
			    	printf("\n\n\n\t Hasil Waktu Sorting : \n");
			    	printf("\t BubleSort(%d) cara biasa memerlukan waktu %.2f seconds\n", n, t1);
			    	printf("\t Masukkan y untuk kembali dan n untuk keluar\n");
					printf("\t Masukkan :");
					scanf("%c",&menu2);
					if(menu2 == 'y'){
						menu();
					}
					else if(menu2 == 'n'){
						system("cls");
						printf("+============================================================+\n");
						printf("\t Terimakasih Sudah Menggunakan Program Kami");
						printf("\n+============================================================+\n");
						exit(0);
					}
					getch();
					
				}else if(metode==2){
					t2=bubble_pointer(angka, n);
					printf("\n\n\n\t Hasil Waktu Sorting : \n");
					printf("\t BubleSort(%d) dengan pointer memerlukan waktu %.2f seconds\n", n, t2);
					printf("\t Masukkan y untuk kembali dan n untuk keluar\n");
					printf("\t Masukkan :");
					scanf("%c",&menu2);
					if(menu2 == 'y'){
						menu();
					}
					else if(menu2 == 'n'){
						system("cls");
						printf("+============================================================+\n");
						printf("\t Terimakasih Sudah Menggunakan Program Kami");
						printf("\n+============================================================+\n");
						exit(0);
					}
					getch();
					
				}else {
					break;
					printf("\n\t Inputan yang anda masukkan salah.");
					getch();
					goto tiga;
				}
			}else{
				printf("\n\t Inputan yang anda masukkan salah!");
				getch();
			}	
		}else{
			printf("\n\t Error, Masukan Salah!\n");
			printf("\n\t Pilihan hanya 1-3!");
	        getch();

		}
	}
}

int main(){
	menu();
	
	return 0;
}
