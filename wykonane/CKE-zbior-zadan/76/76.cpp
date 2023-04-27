#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int zSzyfr[]={6,2,4,1,5,3};
int xSzyfr[50], ySzyfr[15];
string Temp, y, Zad2, z, Zad3, TempMain;
string x[6];

vector<string>Zad1;

void Zad76_1(){
	for(int i=0;i<=5;i++){
		TempMain=x[i];
		for(int j=0;j<=49;j++){
			Temp=TempMain;
			TempMain[xSzyfr[j]-1]=Temp[j];
			TempMain[j]=Temp[xSzyfr[j]-1];
		}
		Zad1.push_back(TempMain);
	}
}
void Zad76_2(){
	TempMain=y;
	for(int i=0;i<=49;i++){
		Temp=TempMain;
		TempMain[ySzyfr[i%15]-1]=Temp[i];
		TempMain[i]=Temp[ySzyfr[i%15]-1];
	}
	Zad2=TempMain;
}
void Zad76_3(){
	TempMain=z;
	for(int i=49;i>=0;i--){
		Temp=TempMain;
		TempMain[zSzyfr[i%6]-1]=Temp[i];
		TempMain[i]=Temp[zSzyfr[i%6]-1];
	}
	Zad3=TempMain;
}
int main(){
	ifstream plik1;
	ifstream plik2;
	ifstream plik3;
	plik1.open("szyfr1.txt");
	plik2.open("szyfr2.txt");
	plik3.open("szyfr3.txt");
	for(int i=0;i<=5;i++){
		plik1>>x[i];
	}
	for(int i=0;i<=49;i++){
		plik1>>xSzyfr[i];
	}
	plik2>>y;
	for(int i=0;i<=14;i++){
		plik2>>ySzyfr[i];
	}
	plik3>>z;
	for(int i=0;i<=5;i++){
		plik3>>zSzyfr[i];
	}
	Zad76_1();
	Zad76_2();
	Zad76_3();
	cout<<"76.1: "<<endl;
	for(int i=0;i<=5;i++){
		cout<<Zad1[i]<<endl;
	}
	cout<<"76.2: "<<Zad2<<endl;
	cout<<"76.3: "<<Zad3<<endl;
	return 0;
}
