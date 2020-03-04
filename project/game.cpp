#include<iostream>
#include<fstream>
#include<string>
#define USER 200
#define ANSWER 300
#define QUESTION 500
using namespace std;
string HoTen[USER];
string NgheNghiep[USER];
string QueQuan[USER];
string CauHoi[QUESTION];
string DapAnA[ANSWER];
string DapAnB[ANSWER];
string DapAnC[ANSWER];
string DapAnD[ANSWER];
string DapAnDung[ANSWER];
string TraLoiCauHoi;
string Reply;
string Enter;
int SoNguoiChoi;
int SoCauHoi;
//Khai bao ham nguyen mau
void NguoiChoi(string HoTen[],string NgheNghiep[],string QueQuan[]);
void DocNguoiChoi(string HoTen[],string NgheNghiep[],string QueQuan[]);
void LuuNguoiChoi(string HoTen[],string NgheNghiep[],string QueQuan[]);
void DocCauHoi(string CauHoi[],string DapAnA[],string DapAnB[],string DapAnC[],string DapAnD[],string DapAnDung[]);
void SanSang(string HoTen[],string QueQuan[]);
void BatDau(string Reply);
//====================================================
int main(){
	DocNguoiChoi(HoTen,NgheNghiep,QueQuan);
	NguoiChoi(HoTen,NgheNghiep,QueQuan);
	LuuNguoiChoi(HoTen,NgheNghiep,QueQuan);
	SanSang(HoTen,QueQuan);
	BatDau(Reply);
	return 0;
}
//====================================================
//Dinh nghia ham - Nguoi choi
void NguoiChoi(string HoTen[],string NgheNghiep[],string QueQuan[]){
	cout<<"\t\tChao mung quy vi da den voi chuong trinh Ai La Trieu Phu"<<endl;
	getline(cin,Enter);
	cout<<"Xin moi ban gioi thieu doi chut ve ban than minh: "<<endl;
	cout<<"- Ho va ten: ";
	getline(cin,HoTen[SoNguoiChoi]);
	cout<<"- Nghe nghiep: ";
	getline(cin,NgheNghiep[SoNguoiChoi]);
	cout<<"- Que Quan: ";
	getline(cin,QueQuan[SoNguoiChoi]);
	SoNguoiChoi++;
}
//------------------------------
void DocNguoiChoi(string Hoten[],string NgheNghiep[],string QueQuan[]){
	//Doc du lieu tu file nguoichoi.txt
	SoNguoiChoi=0;
	fstream fin("nguoichoi.txt");
	fin>>SoNguoiChoi;
	char temp[100];
	fin.getline(temp,100);
	for(int i=0;i<SoNguoiChoi;i++){
		getline(fin,HoTen[i]);
		getline(fin,NgheNghiep[i]);
		getline(fin,QueQuan[i]);
	}
	fin.close();	
}
//------------------------------
void LuuNguoiChoi(string HoTen[],string NgheNghiep[],string QueQuan[]){
	/*Luu du lieu xuong file nguoichoi.txt*/
	ofstream fout("nguoichoi.txt");
	fout<<SoNguoiChoi<<endl;
	for(int i=0;i<SoNguoiChoi;i++){
		fout<<HoTen[i]<<endl<<NgheNghiep[i]<<endl<<QueQuan[i]<<endl;
	}
	fout.close();
}
//====================================================
//Dinh nghia ham - Cau hoi va dap an
void DocCauHoi(string CauHoi[],string DapAnA[],string DapAnB[],string DapAnC[],string DapAnD[],string DapAnDung[]){
	//Doc du lieu tu file cauhoi.txt
	SoCauHoi=15;
	fstream fin("cauhoi.txt");
	fin>>SoCauHoi;
	char temp[100];
	fin.getline(temp,100);
	for(int i=0;i<SoCauHoi;i++){
		getline(fin,CauHoi[i]);
		getline(fin,DapAnA[i]);
		getline(fin,DapAnB[i]);
		getline(fin,DapAnC[i]);
		getline(fin,DapAnD[i]);
		getline(fin,DapAnDung[i]);
	}
	fin.close();
	//Cau 1
	for(int i=0;i<SoCauHoi-(SoCauHoi-1);i++){
		system("clear");
		cout<<CauHoi[i]<<endl;
		cout<<endl;
		cout<<DapAnA[i]<<"\t\t\t\t"<<DapAnB[i]<<endl;
		cout<<DapAnC[i]<<"\t\t\t\t"<<DapAnD[i]<<endl;
		cout<<endl;
		cout<<"=> Cau tra loi cuoi cung cua ban la: ";
		getline(cin,TraLoiCauHoi);
		if(TraLoiCauHoi==DapAnDung[i]){
			cout<<"=> Do la cau cau tra loi dung !"<<endl;
		}
		else{
			cout<<"=> Do la cau tra loi sai, rat tieng ban da phai dung cuoc choi o day !"<<endl;
			break;
		}
	}
	//Cau 2
	for(int i=1;i<SoCauHoi-(SoCauHoi-2);i++){
		system("clear");
		cout<<CauHoi[i]<<endl;
		cout<<endl;
		cout<<DapAnA[i]<<"\t\t\t\t"<<DapAnB[i]<<endl;
		cout<<DapAnC[i]<<"\t\t\t\t"<<DapAnD[i]<<endl;
		cout<<endl;
		cout<<"=> Cau tra loi cuoi cung cua ban la: ";
		getline(cin,TraLoiCauHoi);
		if(TraLoiCauHoi==DapAnDung[i]){
			cout<<"=> Do la cau cau tra loi dung !"<<endl;
		}
		else{
			cout<<"=> Do la cau tra loi sai, rat tieng ban da phai dung cuoc choi o day !"<<endl;
			exit(0);
		}
	}
	//Cau 3
	for(int i=2;i<SoCauHoi-(SoCauHoi-3);i++){
		system("clear");
		cout<<CauHoi[i]<<endl;
		cout<<endl;
		cout<<DapAnA[i]<<"\t\t\t\t"<<DapAnB[i]<<endl;
		cout<<DapAnC[i]<<"\t\t\t\t"<<DapAnD[i]<<endl;
		cout<<endl;
		cout<<"=> Cau tra loi cuoi cung cua ban la: ";
		getline(cin,TraLoiCauHoi);
		if(TraLoiCauHoi==DapAnDung[i]){
			cout<<"=> Do la cau cau tra loi dung !"<<endl;
		}
		else{
			cout<<"=> Do la cau tra loi sai, rat tieng ban da phai dung cuoc choi o day !"<<endl;
			exit(0);
		}
	}
	//Cau 4
	for(int i=3;i<SoCauHoi-(SoCauHoi-4);i++){
		system("clear");
		cout<<CauHoi[i]<<endl;
		cout<<endl;
		cout<<DapAnA[i]<<"\t\t\t\t"<<DapAnB[i]<<endl;
		cout<<DapAnC[i]<<"\t\t\t\t"<<DapAnD[i]<<endl;
		cout<<endl;
		cout<<"=> Cau tra loi cuoi cung cua ban la: ";
		getline(cin,TraLoiCauHoi);
		if(TraLoiCauHoi==DapAnDung[i]){
			cout<<"=> Do la cau cau tra loi dung !"<<endl;
		}
		else{
			cout<<"=> Do la cau tra loi sai, rat tieng ban da phai dung cuoc choi o day !"<<endl;
			exit(0);
		}
	}
	//Cau 5
	for(int i=4;i<SoCauHoi-(SoCauHoi-5);i++){
		system("clear");
		cout<<CauHoi[i]<<endl;
		cout<<endl;
		cout<<DapAnA[i]<<"\t\t\t\t"<<DapAnB[i]<<endl;
		cout<<DapAnC[i]<<"\t\t\t\t"<<DapAnD[i]<<endl;
		cout<<endl;
		cout<<"=> Cau tra loi cuoi cung cua ban la: ";
		getline(cin,TraLoiCauHoi);
		if(TraLoiCauHoi==DapAnDung[i]){
			cout<<"=> Do la cau cau tra loi dung !"<<endl;
		}
		else{
			cout<<"=> Do la cau tra loi sai, rat tieng ban da phai dung cuoc choi o day !"<<endl;
			exit(0);
		}
	}
	//Cau 6
	for(int i=5;i<SoCauHoi-(SoCauHoi-6);i++){
		system("clear");
		cout<<CauHoi[i]<<endl;
		cout<<endl;
		cout<<DapAnA[i]<<"\t\t\t\t"<<DapAnB[i]<<endl;
		cout<<DapAnC[i]<<"\t\t\t\t"<<DapAnD[i]<<endl;
		cout<<endl;
		cout<<"=> Cau tra loi cuoi cung cua ban la: ";
		getline(cin,TraLoiCauHoi);
		if(TraLoiCauHoi==DapAnDung[i]){
			cout<<"=> Do la cau cau tra loi dung !"<<endl;
		}
		else{
			cout<<"=> Do la cau tra loi sai, rat tieng ban da phai dung cuoc choi o day !"<<endl;
			exit(0);
		}
	}
	//Cau 7
	for(int i=6;i<SoCauHoi-(SoCauHoi-7);i++){
		system("clear");
		cout<<CauHoi[i]<<endl;
		cout<<endl;
		cout<<DapAnA[i]<<"\t\t\t\t"<<DapAnB[i]<<endl;
		cout<<DapAnC[i]<<"\t\t\t\t"<<DapAnD[i]<<endl;
		cout<<endl;
		cout<<"=> Cau tra loi cuoi cung cua ban la: ";
		getline(cin,TraLoiCauHoi);
		if(TraLoiCauHoi==DapAnDung[i]){
			cout<<"=> Do la cau cau tra loi dung !"<<endl;
		}
		else{
			cout<<"=> Do la cau tra loi sai, rat tieng ban da phai dung cuoc choi o day !"<<endl;
			exit(0);
		}
	}
	//Cau 8
	for(int i=7;i<SoCauHoi-(SoCauHoi-8);i++){
		system("clear");
		cout<<CauHoi[i]<<endl;
		cout<<endl;
		cout<<DapAnA[i]<<"\t\t\t\t"<<DapAnB[i]<<endl;
		cout<<DapAnC[i]<<"\t\t\t\t"<<DapAnD[i]<<endl;
		cout<<endl;
		cout<<"=> Cau tra loi cuoi cung cua ban la: ";
		getline(cin,TraLoiCauHoi);
		if(TraLoiCauHoi==DapAnDung[i]){
			cout<<"=> Do la cau cau tra loi dung !"<<endl;
		}
		else{
			cout<<"=> Do la cau tra loi sai, rat tieng ban da phai dung cuoc choi o day !"<<endl;
			exit(0);
		}
	}
	//Cau 9
	for(int i=8;i<SoCauHoi-(SoCauHoi-9);i++){
		system("clear");
		cout<<CauHoi[i]<<endl;
		cout<<endl;
		cout<<DapAnA[i]<<"\t\t\t\t"<<DapAnB[i]<<endl;
		cout<<DapAnC[i]<<"\t\t\t\t"<<DapAnD[i]<<endl;
		cout<<endl;
		cout<<"=> Cau tra loi cuoi cung cua ban la: ";
		getline(cin,TraLoiCauHoi);
		if(TraLoiCauHoi==DapAnDung[i]){
			cout<<"=> Do la cau cau tra loi dung !"<<endl;
		}
		else{
			cout<<"=> Do la cau tra loi sai, rat tieng ban da phai dung cuoc choi o day !"<<endl;
			exit(0);
		}
	}
	//Cau 10
	for(int i=9;i<SoCauHoi-(SoCauHoi-10);i++){
		system("clear");
		cout<<CauHoi[i]<<endl;
		cout<<endl;
		cout<<DapAnA[i]<<"\t\t\t\t"<<DapAnB[i]<<endl;
		cout<<DapAnC[i]<<"\t\t\t\t"<<DapAnD[i]<<endl;
		cout<<endl;
		cout<<"=> Cau tra loi cuoi cung cua ban la: ";
		getline(cin,TraLoiCauHoi);
		if(TraLoiCauHoi==DapAnDung[i]){
			cout<<"=> Do la cau cau tra loi dung !"<<endl;
		}
		else{
			cout<<"=> Do la cau tra loi sai, rat tieng ban da phai dung cuoc choi o day !"<<endl;
			exit(0);
		}
	}
	//Cau 11
	for(int i=10;i<SoCauHoi-(SoCauHoi-11);i++){
		system("clear");
		cout<<CauHoi[i]<<endl;
		cout<<endl;
		cout<<DapAnA[i]<<"\t\t\t\t"<<DapAnB[i]<<endl;
		cout<<DapAnC[i]<<"\t\t\t\t"<<DapAnD[i]<<endl;
		cout<<endl;
		cout<<"=> Cau tra loi cuoi cung cua ban la: ";
		getline(cin,TraLoiCauHoi);
		if(TraLoiCauHoi==DapAnDung[i]){
			cout<<"=> Do la cau cau tra loi dung !"<<endl;
		}
		else{
			cout<<"=> Do la cau tra loi sai, rat tieng ban da phai dung cuoc choi o day !"<<endl;
			exit(0);
		}
	}
	//Cau 12
	for(int i=12;i<SoCauHoi-(SoCauHoi-13);i++){
		system("clear");
		cout<<CauHoi[i]<<endl;
		cout<<endl;
		cout<<DapAnA[i]<<"\t\t\t\t"<<DapAnB[i]<<endl;
		cout<<DapAnC[i]<<"\t\t\t\t"<<DapAnD[i]<<endl;
		cout<<endl;
		cout<<"=> Cau tra loi cuoi cung cua ban la: ";
		getline(cin,TraLoiCauHoi);
		if(TraLoiCauHoi==DapAnDung[i]){
			cout<<"=> Do la cau cau tra loi dung !"<<endl;
		}
		else{
			cout<<"=> Do la cau tra loi sai, rat tieng ban da phai dung cuoc choi o day !"<<endl;
			exit(0);
		}
	}
	//Cau 13
	for(int i=13;i<SoCauHoi-(SoCauHoi-14);i++){
		system("clear");
		cout<<CauHoi[i]<<endl;
		cout<<endl;
		cout<<DapAnA[i]<<"\t\t\t\t"<<DapAnB[i]<<endl;
		cout<<DapAnC[i]<<"\t\t\t\t"<<DapAnD[i]<<endl;
		cout<<endl;
		cout<<"=> Cau tra loi cuoi cung cua ban la: ";
		getline(cin,TraLoiCauHoi);
		if(TraLoiCauHoi==DapAnDung[i]){
			cout<<"=> Do la cau cau tra loi dung !"<<endl;
		}
		else{
			cout<<"=> Do la cau tra loi sai, rat tieng ban da phai dung cuoc choi o day !"<<endl;
			exit(0);
		}
	}
	//Cau 14
	for(int i=14;i<SoCauHoi-(SoCauHoi-15);i++){
		system("clear");
		cout<<CauHoi[i]<<endl;
		cout<<endl;
		cout<<DapAnA[i]<<"\t\t\t\t"<<DapAnB[i]<<endl;
		cout<<DapAnC[i]<<"\t\t\t\t"<<DapAnD[i]<<endl;
		cout<<endl;
		cout<<"=> Cau tra loi cuoi cung cua ban la: ";
		getline(cin,TraLoiCauHoi);
		if(TraLoiCauHoi==DapAnDung[i]){
			cout<<"=> Do la cau cau tra loi dung !"<<endl;
		}
		else{
			cout<<"=> Do la cau tra loi sai, rat tieng ban da phai dung cuoc choi o day !"<<endl;
			exit(0);
		}
	}
	//Cau 15
	for(int i=15;i<SoCauHoi+1;i++){
		system("clear");
		cout<<CauHoi[i]<<endl;
		cout<<endl;
		cout<<DapAnA[i]<<"\t\t\t\t"<<DapAnB[i]<<endl;
		cout<<DapAnC[i]<<"\t\t\t\t"<<DapAnD[i]<<endl;
		cout<<endl;
		cout<<"=> Cau tra loi cuoi cung cua ban la: ";
		getline(cin,TraLoiCauHoi);
		if(TraLoiCauHoi==DapAnDung[i]){
			cout<<"=> Do la cau cau tra loi dung !"<<endl;
		}
		else{
			cout<<"=> Do la cau tra loi sai, rat tieng ban da phai dung cuoc choi o day !"<<endl;
			exit(0);
		}
	}
}
//====================================================
//Dinh nghia ham - san sang va bat dau choi
void SanSang(string HoTen[],string QueQuan[]){
	system("clear");
	cout<<"=> Nguoi choi cua chung ta, ban "<<HoTen[SoNguoiChoi-1]<<" den tu "<<QueQuan[SoNguoiChoi-1]<<" !";
	getline(cin,Enter);
	cout<<"=> Co tat ca 15 cau hoi dang doi ban !";
	getline(cin,Enter);
	cout<<"=> Co 3 moc cau hoi quan trong ban can vuot qua do la: ";
	getline(cin,Enter);
	cout<<"\t\t=> 5 <=";
	getline(cin,Enter);
	cout<<"\t\t=> 10 <=";
	getline(cin,Enter);
	cout<<"\t\t=> 15 <=";
	getline(cin,Enter);
}
//------------------------------
void BatDau(string Reply){
	system("clear");
	char y,n;
	cout<<"=> Ban da san sang choi chua ? (y/n) - ";
	getline(cin,Reply);
	if(Reply=="y"){
		cout<<"=> Nguoi choi da san sang va chung ta bat dau di tim ai la trieu phu !"<<endl;
		DocCauHoi(CauHoi,DapAnA,DapAnB,DapAnC,DapAnD,DapAnDung);
	}
	else if(Reply=="n"){
		cout<<"=> HaizZz !!!"<<endl;
	}
	else{
		cout<<"=> Nhap sai roi ban oi !"<<endl;
	}
}
//====================================================
