#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <sstream>
using namespace std;

string keyword;
int mainmenu,jumlahinput,jumlahdata,searchmethod;
int a,i=0;
int jumlahbuku;
bool found;
char jwb;
char filename[50];
void lihatbuku();
void inputbuku();
void searching();
void sorting();
void transaksi();
void pilihan();
void binarysearch();
void seqsearch();
void bubblesort2();
void tampil();

//-------------


typedef struct{
	
	string judul,author,idbuku;
	int harga;
	
}data_buku;

data_buku buku[999];

int jumlahbukufile;

//-------------
void pilihan(){
	system ("cls");
	cout<<"---------------------------"<<endl;
	cout<<"          TOKO BUKU        "<<endl;
	cout<<"---------------------------"<<endl;
	cout<<"\n";
	cout<<"1. Input data \n2. Tampilkan Data \n3. Searching data"<<endl;
	cout<<"4. Sorting data \n5. Transaksi \n6. Keluar"<<endl;
	cout<<"\n";
	cout<<"Masukan Pilihan: "; cin>>mainmenu;
	cout<<"---------------------------"<<endl;
	switch(mainmenu)
	{
	case 1:
		inputbuku();
	break;
	
	case 2:  
		lihatbuku(); 
	break;
	
	case 3:
		searching();
	break;
	
	case 4:
		sorting();
	break;
	
	case 5:
		transaksi();
	break;
	case 6:
		exit(0);
	break;
	default:
		cout<<"Menu tidak tersedia!"<<endl;
		system("pause");
		pilihan();
	break;
	}
}


void inputbuku(){
system ("cls");
ofstream Archive;
    cout<<"Masukan nama file :";cin>>filename;
    Archive.open(filename,ios::out);
    cout<< "=====[Input data Buku]=====" <<endl;
    
    if (Archive.is_open()) {
    do{
        cout<<"Jumlah input data = ";cin>>jumlahinput;
        jumlahbukufile = jumlahbukufile + jumlahinput;
		Archive<<jumlahbukufile<<endl;
        for(a=0;a<jumlahinput;a++)
        {
        cout<<"Data ke "<<a+1<<endl;
        cout<<"Id Buku                     :";cin>>buku[a].idbuku;cin.ignore();
        cout<<"Judul Buku               :";getline(cin, buku[a].judul);
        cout<<"Harga buku               :";cin>>buku[a].harga;cin.ignore();
        cout<<"Author / Penulis Buku     :";getline(cin, buku[a].author);
        Archive<<buku[a].idbuku<<endl<<buku[a].judul<<endl<<buku[a].harga<<endl<<buku[a].author<<endl;
        }
        cout <<"input lagi? (Y/N)"; cin>>jwb;
    }while (jwb=='Y'||jwb=='y');
    }else 
    cout<<"\nFile tidak dapat diciptakan!";
	cout<<"Jumlahbuku : "<<jumlahbukufile<<endl;
	//jumlahbuku = jumlahbuku+jumlahinput;
    Archive.close();
    system("pause");
    pilihan();
}


void lihatbuku(){
	system ("cls");
	cout<<"Masukan nama file :";cin>>filename;	
	
	
	ifstream Archive;
	Archive.open(filename, ios::out);
	Archive>>jumlahbukufile;
	if(Archive.is_open()){
		cout<< "=====[Lihat data Buku]=====" << endl;
		cout<<"Jumlah data yang ingin dilihat (Maks "<<jumlahbukufile<<")= ";cin>>jumlahdata;
		for(a=0;a<jumlahdata;a++){
			Archive.ignore();
            getline(Archive, buku[a].idbuku);
            getline(Archive, buku[a].judul);
            Archive >> buku[a].harga;
            Archive.ignore();
            getline(Archive, buku[a].author);

            cout<<"\nData ke "<<a+1<<endl;
            cout<<endl;
            cout<<"Id Buku               :"<<buku[a].idbuku;
            cout<<endl;
            cout<<"Judul Buku            :"<<buku[a].judul;
            cout<<endl;
            cout<<"Harga buku            :"<<buku[a].harga;
            cout<<endl;
            cout<<"Author / Penulis buku :"<<buku[a].author;
            cout<<endl;
        }
	}else{
		cout<<"\nFile tidak dapat dibuka!";
	}
	cout<<"Jumlahbuku : "<<jumlahbukufile<<endl;
	Archive.close();
	system("pause");
	pilihan();
}

void searching(){
	system ("cls");
	cout<<"---------------------------"<<endl;
	cout<<"          TOKO BUKU        "<<endl;
	cout<<"---------------------------"<<endl;
	cout<<"\n";
	cout<<"1. Sequential Search \n2. Binary Search \n3. Kembali ke menu"<<endl;
	cout<<"\n";
	cout<<"Masukan Pilihan: "; cin>>mainmenu;
	cout<<"---------------------------"<<endl;
	switch(mainmenu)
	{
	case 1:
		seqsearch();
	break;
	
	case 2:  
		binarysearch(); 
	break;
	case 3:
		pilihan();
	break;
	default:
		cout<<"Menu tidak tersedia!"<<endl;
		system("pause");
		pilihan();
	break;
	}
}

void binarysearch(){
	
}
void seqsearch(){
	system ("cls");
	cout<<"Masukan nama file :";cin>>filename;	
	
	
	ifstream Archive;
	Archive.open(filename, ios::out);
			Archive >> jumlahbukufile;
			
        cout<<jumlahbukufile<<endl;
	if(Archive.is_open()){
		
		cout<<"=====[Cari Buku]====="<<endl;
    	cin.ignore();
    	cout<<"Judul Buku   : "; getline(cin, keyword);
    	found=false;
    	while((i<jumlahbukufile) & (!found)){
    			Archive.ignore();
				getline(Archive, buku[i].idbuku);
	            getline(Archive, buku[i].judul);
	            Archive >> buku[i].harga;
	            Archive.ignore();
	            getline(Archive, buku[i].author);
	        if(keyword==buku[i].judul)
	            found=true;
	        else
	            i=i+1;
    	}
    	if(found){
        	cout<<"Judul                	: " << buku[i].judul << endl;
        	cout<<"Harga buku             	: " << buku[i].harga << endl;
        	cout<<"Author/Penulis buku      : " << buku[i].author << endl;
        	cout<<endl;
    	}else{
        	cout << keyword << " tidak ditemukan dalam data" << endl;
    	}	
	}else{
		cout<<"\nFile tidak dapat dibuka!";
	}
	cout<<i<<jumlahbukufile;
    Archive.close();
    system("pause");
    pilihan();
}

void tampil(){
	
}

void sorting(){
	
}

void bubblesort2(){
	
}

void transaksi(){
	
}




main(){	

system ("cls");
cout<<"\t-------------------------------------------------\n";
cout<<"\t\t     TUGAS PROJECT ALGORITMA 2021  \n";
cout<<"\t\t              TOKO BUKU            \n";
cout<<"\t-------------------------------------------------\n";
cout<<"\t|                                                |\n";
cout<<"\t| Kelompok 43:                                   |\n";
cout<<"\t| 1. Al Ahmad Syah Huud Sharifudin               |\n";
cout<<"\t| 2. Agatha Prima Vista                          |\n";
cout<<"\t| 3. Augys Dellea Rischa Aisyah                  |\n";
cout<<"\t|                                                |\n";
cout<<"\t-------------------------------------------------\n";
cout<<"\t|                                                |\n";
cout<<"\t|  UPN Veteran YK | Sistem Informasi |  Kelas B  |\n";
cout<<"\t|                                                |\n";
cout<<"\t=================================================\n";
cout<<"\t\t   Press Any Key To Continue...  \n";
cout<<"\t=================================================\n"; 
//getch();
	system("pause");
pilihan();
}
