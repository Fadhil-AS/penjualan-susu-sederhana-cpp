#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <cstring>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <fstream>


using namespace std;

typedef struct{
	char jenis[15],
		 ukuran[15];
	int	harga;
}susu;

susu data_susu[100];


typedef struct{
	char no_penjualan,
		 jenis[15],
		 ukuran[15];
	int harga,
		qty,
		total;
	float diskon;
}penjualan;

penjualan data_penjualan[100];
int jml_data = 0;

void menu(){
	system( "COLOR 70" );
	system( "CLS" );
	cout<< "============================\n";
	cout<< "|      Menu Penjualan      |\n";
	cout<< "============================\n";
	cout<< "|1. Entry data penjualan   |\n";
	cout<< "|2. Tampil penjualan       |\n";
	cout<< "|3. Cari penjualan         |\n";
	cout<< "|4. Urutan penjualan       |\n";
	cout<< "|5. Export data penjualan  |\n";
	cout<< "|6. Import data penjualan  |\n";
	cout<< "|7. Keluar                 |\n";
	cout<< "============================\n";
	cout<<endl;
}

void input_susu(){
	//dancow kecil
	strcpy(data_susu[0].jenis, "Dancow");
	strcpy(data_susu[0].ukuran, "Kecil");
	data_susu[0].harga = 15000;
	
	//dancow sedang
	strcpy(data_susu[1].jenis, "Dancow");
	strcpy(data_susu[1].ukuran, "Sedang");
	data_susu[1].harga = 20000;
	
	//dancow besar
	strcpy(data_susu[2].jenis, "Dancow");
	strcpy(data_susu[2].ukuran, "Besar");
	data_susu[2].harga = 25000;
	
	//bendera kecil
	strcpy(data_susu[3].jenis, "Bendera");
	strcpy(data_susu[3].ukuran, "Kecil");
	data_susu[3].harga = 13500;
	
	//bendera sedang
	strcpy(data_susu[4].jenis, "Bendera");
	strcpy(data_susu[4].ukuran, "Sedang");
	data_susu[4].harga = 175000;
	
	//bendera besar
	strcpy(data_susu[5].jenis,"Bendera");
	strcpy(data_susu[5].ukuran, "Besar");
	data_susu[5].harga = 20000;
	
	//sgm kecil
	strcpy(data_susu[6].jenis, "SGM");
	strcpy(data_susu[6].ukuran, "Kecil");
	data_susu[6].harga = 15000;
	
	//sgm sedang
	strcpy(data_susu[7].jenis, "SGM");
	strcpy(data_susu[7].ukuran, "Sedang");
	data_susu[7].harga = 18500;
	
	//sgm besar
	strcpy(data_susu[8].jenis, "SGM");
	strcpy(data_susu[8].ukuran, "Besar");
	data_susu[8].harga = 22000;
}

void tampil_susu(){
	//system("CLS");
	cout<< "=====================================\n";
	cout<< "|             Data susu	            |\n";
	cout<< "=====================================\n";
	cout<< "No | Jenis   |   Ukuran    |  Harga |\n";
	cout<< "=====================================\n";
	for(int i = 0; i < 9; i++){
		cout<< i + 1 <<" ";
		cout<< setw(9) << data_susu[i].jenis;
		cout<< setw(11) << data_susu[i].ukuran;
		cout<< setw(13) << data_susu[i].harga << endl;
	}
}

float diskon(penjualan data_penjualan){
	if(data_penjualan.qty > 10 && (!strcmp(data_penjualan.ukuran, "Besar") || !strcmp(data_penjualan.ukuran, "Sedang"))){
		return 0.01;
	}else if(data_penjualan.qty > 5 && !strcmp(data_penjualan.ukuran, "Besar")){
		return 0.05;
	}else if(data_penjualan.qty > 10 && !strcmp(data_penjualan.ukuran, "Kecil")){
		return 0.02;
	}else{
		return 0;	
	}
}

int cari_susu(susu s[], int jml, char jenis[], char ukuran[]){
	for(int i = jml - 1; i > -2; i--){
		if(i == -1 || !strcmp(s[i].jenis, jenis) && !strcmp(s[i].ukuran, ukuran)) return i;
	}
}

void input_penjualan(){
	system("CLS");
	tampil_susu();
	char tambah = 'y';
	int a = 0;
	int jml_susu = 9;
	
	do{
		cout<<endl;
		cout<< "No Penjualan : "; 
		cin>> data_penjualan[a].no_penjualan;
		
		cout<< "Jenis Susu : "; 
		cin>>data_penjualan[a].jenis;
		
		cout<< "Ukuran Susu : "; 
		cin>>data_penjualan[a].ukuran;
		
		cout<< "Harga : ";
		int i = cari_susu(data_susu, jml_susu, data_penjualan[a].jenis, data_penjualan[a].ukuran);
		data_penjualan[a].harga = data_susu[i].harga;
		cout<< data_penjualan[a].harga<< endl;
		
		cout<< "Qty : "; 
		cin>>data_penjualan[a].qty;
		
		cout<< "Diskon : "; 
		data_penjualan[a].diskon = diskon(data_penjualan[a]); 
		cout<< data_penjualan[a].diskon<<endl;
		
		cout<< "Total : "; 
		data_penjualan[a].total = (data_penjualan[a].harga - (data_penjualan[a].harga * data_penjualan[a].diskon)) * data_penjualan[a].qty; 
		cout<< data_penjualan[a].total<<endl;
		
		a++;
		cout<< "\nTambah data(y/n)\n"; cin>> tambah;
	}while(tambah == 'y' || tambah == 'Y');
	
	jml_data += a;
}

void tampil_penjualan(){
	system("CLS");
	cout<< "======================================================\n";
	cout<< "|                Data Penjualan Susu                 |\n";
	cout<< "======================================================\n";
	cout<< "| No | Jenis | Ukuran | Harga | Qty | Diskon | Total |\n";
	cout<< "======================================================\n";
	for(int i = 0; i < jml_data; i++){
		cout<<"|"<< i + 1 << " ";
		cout<< setw(3)<< "|"<<data_penjualan[i].jenis<< setw(2)<< "|" ;
		cout<< data_penjualan[i].ukuran<< setw(4)<< "|";
		cout<< data_penjualan[i].harga<< setw(3)<<"|";
		cout<< data_penjualan[i].qty<< setw(4)<<"|";
		cout<< data_penjualan[i].diskon<< setw(5)<<"|";
		cout<< data_penjualan[i].total << setw(2)<<"|"<<endl;
	}
	
	
}

int cari_data_penjualan(penjualan p[], int jml,char no){
	for(int x = jml - 1; x > - 2; x--){
		if(x == -1 || p[x].no_penjualan == no)return x;
	}
}

void cari_penjualan(){
	system("CLS");
	int index;
	char no;
	
	cout<< "No Penjualan: ";
	cin>>no;
	
	index = cari_data_penjualan(data_penjualan, jml_data, no);
	cout<< data_penjualan[index].no_penjualan << "\n";
	cout<< data_penjualan[index].jenis<< "\n";
	cout<< data_penjualan[index].ukuran<< "\n";
	cout<< data_penjualan[index].harga<< "\n";
	cout<< data_penjualan[index].qty<< "\n";
	cout<< data_penjualan[index].total<< "\n";
}

int sorting(){
	for(int i = 1; i < jml_data; i++){
		for(int j = jml_data - 1; j >= i; j--){
			if(data_penjualan[j].total > data_penjualan[j - 1].total){
				data_penjualan[70] = data_penjualan[j];
				data_penjualan[j] = data_penjualan[j - 1];
				data_penjualan[j] = data_penjualan[70];
			}
		}
	}
}

void urutan_penjualan(){
	sorting();
	system("CLS");
	cout<< "======================================================\n";
	cout<< "|                Data Penjualan Susu                 |\n";
	cout<< "======================================================\n";
	cout<< "| No | Jenis | Ukuran | Harga | Qty | Diskon | Total |\n";
	cout<< "======================================================\n";
	for(int i = 0; i < jml_data; i++){
		cout<<"|"<< i + 1 << " ";
		cout<< setw(3)<< "|"<<data_penjualan[i].jenis<< setw(2)<< "|" ;
		cout<< data_penjualan[i].ukuran<< setw(4)<< "|";
		cout<< data_penjualan[i].harga<< setw(3)<<"|";
		cout<< data_penjualan[i].qty<< setw(4)<<"|";
		cout<< data_penjualan[i].diskon<< setw(5)<<"|";
		cout<< data_penjualan[i].total << setw(2)<<"|"<<endl;
	}
	
}

void saveToFile(){
	ofstream file("Data Penjualan.txt");
	if(jml_data != 0 && file.is_open()){
		for(int a = 0; a < jml_data; a++){
			file<< "No Penjualan : "<< data_penjualan[a].no_penjualan << "\n";
			file<< "Jenis : "<< data_penjualan[a].jenis << "\n";
			file<< "Ukuran : "<< data_penjualan[a].ukuran << "\n";
			file<< "Harga : "<< data_penjualan[a].harga<< "\n";
			file<< "Qty : "<< data_penjualan[a].qty<< "\n";
			file<< "Diskon : "<< data_penjualan[a].diskon<< "\n";
			file<< "Total : "<< data_penjualan[a].total;
			file<< "\n";
		}
		cout<< "\nData sudah terkirim\n";
	}else{
		cout<< "\nData tidak terkirim, karena ada kesalahan";
	}
	system("PAUSE");
}

void readFile(){
	system("CLS");
	ifstream file("Data Penjualan.txt");
	string line;
	if(file.is_open()){
		while(getline(file, line)){
			cout<< line << "\n";
		}
	}else{
		cout<< "Tidak bisa membuka file";
	}
	system("PAUSE");
}

int main(){
	int pilihMenu;
	char backToMenu = 'y';
	
	do{
		menu();
		cout<< "Pilih Menu (1 - 6) :";
		cin>> pilihMenu;
		
		switch(pilihMenu){
			case 1 : input_susu();tampil_susu();input_penjualan();break;
			case 2 : tampil_penjualan();break;
			case 3 : cari_penjualan();break;
			case 4 : urutan_penjualan();break;
			case 5 : saveToFile();break;
			case 6 : readFile();break;
			case 7 : return 0;break;
			default : cout<< "\nPilihan menu tidak ada\n";
		}
		
		cout<< "Kembali ke menu (y/n) : ";
		cin>> backToMenu;
	}while(backToMenu == 'y' || backToMenu == 'Y');
	
	system("PAUSE");
	return EXIT_SUCCESS;
}
