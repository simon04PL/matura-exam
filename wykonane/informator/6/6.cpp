#include <iostream>
#include <fstream>
#include <set>

using namespace std;

char x[2023][100];
int Zad1Temp=0, Temp, sumaTemp=0;
int Zad2Suma[11]={0,0,0,0,0,0,0,0,0,0,0};
int Zad2[11]={3000,3000,3000,3000,3000,3000,3000,3000,3000,3000,3000};
int Zad3L=0;

void charNaInt(char k){
	Temp=k-48;
}
bool czyAntypalindrom(int k){
	for(int i=0;i<=49;i++){
		if(x[k][i]==x[k][99-i]){
			return 0;
		}
	}
	return 1;
}
int main(){
	ifstream plik;
	ofstream oPlik;
	plik.open("dane6.txt");
	oPlik.open("zadanie6_3.txt");
	multiset<int>Zad1;
	set<int>Zad3S;
	for(int i =0;i<=2022;i++){
		for(int j=0;j<=99;j++){
			plik>>x[i][j];
		}
	}
	//6.1
	for(int i=0;i<=2022;i++){
		for(int j=0;j<=99;j++){
			charNaInt(x[i][j]);
			if(Zad1Temp<Temp+1){
				Zad1Temp=Temp+1;
			}
		}
		Zad1.insert(Zad1Temp);
		Zad1Temp=0;
	}
	//6.2
	for(int i=0;i<=2022;i++){
		for(int j=0;j<=99;j++){
			charNaInt(x[i][j]);
			if(Zad1Temp<Temp+1){
				Zad1Temp=Temp+1;
			}
			sumaTemp+=Temp;
		}
		if(Zad2Suma[Zad1Temp]<sumaTemp){
			Zad2[Zad1Temp]=i;
			Zad2Suma[Zad1Temp]=sumaTemp;
		}
		sumaTemp=0;
		Zad1Temp=0;
	}
	//6.3
	for(int i =0;i<=2022;i++){
		if(czyAntypalindrom(i)==1){
			Zad3L++;
			Zad3S.insert(i);
		}
	}
	cout<<"6.1: "<<endl;
	for(int i=2;i<=10;i++){
		cout<<"p: "<<i<<" liczba p: "<<Zad1.count(i)<<endl;
	}
	cout<<"6.2: "<<endl;
	for(int i=2;i<=10;i++){
		if(Zad2[i]<=2023){
			cout<<"p: "<<i<<" minimalna suma: ";
			for(int j=0;j<=99;j++){
				cout<<x[Zad2[i]][j];
			}
			cout<<endl;
		}
	}
	cout<<"6.3: ciag:"<<endl;
	for(auto e: Zad3S){
		for(int i=0;i<=99;i++){
			cout<<x[e][i];
			oPlik<<x[e][i];
		}
		cout<<endl;
		oPlik<<endl;
	}
	cout<<"liczba: "<<Zad3L;
	oPlik<<Zad3L;
	return 0;
}
