#include<iostream>
#include<stdlib.h>
#include<string>
#include<fstream>//Tao ghi file va doc thong tin tu file
using namespace std;
#define MAX 200
char ten[MAX][50];//Mang hai chieu luu tru ten nguoi toi da MAX nguoi, moi ten nguoi dai khong qua 50 ki tu
char sdt[MAX][11];//Mang hai chieu luu tru so dien thoai, toi da MAX sdt, moi sdt dai khong qua 11 ki tu
char email[MAX][60];//Mang hai chieu luu tru email, toi da MAX email, moi email dai khong qua 50 ki tu
int N;//Luu tru so nguoi danh ba dang qua ly
int main(){	
	N = 0; //Mac dinh khi khoi dong khong co nguoi nao trong danh ba
	/*Doc du lieu tu file danhba2.txt*/
	fstream fin("danhba2.txt");
	fin>>N;
	char temp[100];
	fin.getline(temp,100);
	for(int i=0;i<N;i++){
		fin.getline(ten[i],50);
		fin.getline(sdt[i],11);
		fin.getline(email[i],60);
	}
	fin.close();//Ket thuc
	//-------------------------------
	/*Xu ly menu*/
	int chon;
	do{
		cout<<"\tPhan Mem Quan Ly Danh Ba - Version 3\n";
		cout<<endl;
		cout<<"1. Them lien he"<<endl;
		cout<<"2. Hien thi toan bo danh ba"<<endl;
		cout<<"3. Sua lien he"<<endl;
		cout<<"4. Xoa lien he"<<endl;
		cout<<"5. Tim lien he"<<endl;
		cout<<"0. Thoat"<<endl;
		cout<<"=> Moi chon chuc nang: ";		
		cin>>chon;
		cout<<"------------------------"<<endl;//Phan cach
		/*Xu ly sau khi chon*/
		if(chon==1){//Them lien he
			cout<<"\t\tThem lien he\n";
			cout<<endl;
			cout<<"Xim moi nhap ho va ten: ";
			cin.ignore();//Doc va loai bo ky tu trong bo nho dem
			cin.getline(ten[N],50);//Nhan day ky tu nhap vao cho den khi du 49 ki tu hoac khi ket thuc bang dau Enter va xoa ky tu Enter khoi bo dem		
            	cout<<"Xin moi nhap so dien thoai: ";
			cin.getline(sdt[N],11);//Nhan day ky tu nhap vao cho den khi du 11 ki tu hoac khi ket thuc bang dau Enter va xoa ky tu Enter khoi bo dem
			cout<<"Xin moi nhap dia chi email: ";
			cin.getline(email[N],60);//Nhan day ky tu nhap vao cho den khi du 49 ki tu hoac khi ket thuc bang dau Enter va xoa ky tu Enter khoi bo dem		
			N++;//Dem so danh ba
		}
		else if(chon==2){//Hien thi toan bo danh ba
			cout<<"\t\tToan bo danh ba\n";
			cout<<endl;
			cout<<"Stt\tHo va ten\t\tSo dien thoai\t\tEmail\n";
			cout<<endl;
			for(int i=0;i<N;i++){
				cout<<i+1<<"\t"<<ten[i]<<"\t\t"<<sdt[i]<<"\t\t"<<email[i]<<endl;
			}
		}
		else if(chon==3){//Sua lien he
		}
		else if(chon==4){//Xoa lien he
		}
		else if(chon==5){//Tim lien he
			cout<<"\t\tTim lien he\n";
			cout<<endl;
			cin.ignore();//Doc va loai bo ky tu trong bo nho dem
			string name;//Khoi tao chuoi ten
			cout<<"Xin moi nhap ten: ";
			getline(cin,name);//Chuoi ki tu nhap vao gan cho bien name
			bool kiemtra=0;//kiem tra sai
			for(int i=0;i<N;i++){
				if(ten[i]==name){//Neu ten trong mang trung chuoi nhap vao thi in ra sdt tuong ung
					cout<<"So dien thoai can tim la: "<<sdt[i]<<endl;
					kiemtra=1;//Kiem tra dung
				}
			}
			if(kiemtra==0){//Neu kiem tra sai
				cout<<"Lien he khong ton tai. Vui long thu lai !"<<endl;
			}
		}
		else if(chon==0){//Thoat va luu thay doi
			/*Luu du lieu xuong file danhba2.txt*/
			ofstream fout("danhba2.txt");//Tao file va luu thong tin toi file danhba2.txt
			fout<<N<<endl;//Ghi va dem so danh ba
			for(int i=0;i<N;i++){
				fout<<ten[i]<<endl<<sdt[i]<<endl<<email[i]<<endl;//Ghi ten va sdt va file danhba2.txt
			}
			fout.close();//Ket thuc
		}
		if(chon!=0){//Neu chon #0 va sau khi thuc hien xong thì quay ve menu chon
			cout<<endl;
			cout<<"=> Nhan Enter de tro ve !";
			cin.ignore();//Doc va loai bo ki tu con trong bo nho dem
			cin.get();//Giu ky tu Enter trong bo nho dem
			system("clear");//Xoa
		}	
	}
	while(chon!=0);//Neu chon #0 thì lap lai
	return 0;
}
