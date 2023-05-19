#include <iostream>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

int Zad2MaxP=0, Zad2MinP=100000, Zad3MinL=100, Zad3MaxL=0;
int d[50][70], w[50][70];
string kod[50], miasto[50];
string Zad2Max, Zad2Min, Zad3Min, Zad3Max;

set<string>Zad1;
multiset<string>Zad1Licz;
set<int>Zad3P;


void Zad4_1(){
	for(int i=0;i<=49;i++){
		Zad1.insert(kod[i]);
		Zad1Licz.insert(kod[i]);
	}
}
void Zad4_2(){
	for(int i=0;i<=49;i++){
		int Temp=0, lL;
		cout<<"Miasto: "<<miasto[i];
		for(int j=0;j<=69;j++){
			Temp+=d[i][j]*w[i][j];
			if(d[i][j]==0&&w[i][j]==0){
				lL=j;
				break;
			}
		}
		if(Zad2MaxP<Temp){
				Zad2MaxP=Temp;
				Zad2Max.clear();
				Zad2Max=miasto[i];
			}
			if(Zad2MinP>Temp){
				Zad2MinP=Temp;
				Zad2Min.clear();
				Zad2Min=miasto[i];
		}
		cout<<" powierzchnia galeri wynosi: "<<Temp<<" liczba lokali wynosi: "<<lL<<endl;
	}
}

void Zad4_3(){
	for(int i=0;i<=49;i++){
		for(int j=0;j<=69;j++){
			if(d[i][j]==0&&w[i][j]==0){
				break;
			}else{
				Zad3P.insert(d[i][j]*w[i][j]);
			}
		}
		if(Zad3P.size()>Zad3MaxL){
			Zad3MaxL=Zad3P.size();
			Zad3Max.clear();
			Zad3Max=miasto[i];
		}
		if(Zad3P.size()<Zad3MinL){
			Zad3MinL=Zad3P.size();
			Zad3Min.clear();
			Zad3Min=miasto[i];
		}
		Zad3P.clear();
	}
}
int main(){
	ifstream plik;
	plik.open("galerie.txt");
	for(int i=0;i<=49;i++){
		plik>>kod[i]>>miasto[i];
		for(int j=0;j<=69;j++){
			plik>>d[i][j]>>w[i][j];
		}
	}
	Zad4_1();
	Zad4_3();
	cout<<"1.1:"<<endl;
	for(auto e :Zad1){
		cout<<"kod kraju: "<<e<<" Jest tych krajow: "<<Zad1Licz.count(e)<<endl;
	}
	cout<<"1.2: a)"<<endl;
	Zad4_2();
	cout<<"1.2: b)"<<endl<<"Miasto z najwieksza powiezchnia galeri to: "<<Zad2Max<<", a powierzchnia taw ynosi: "<<Zad2MaxP<<endl<<"Miasto z najmniejsza powierzchnia galeri to: "<<Zad2Min<<", a powierzchnia ta wynosi: "<<Zad2MinP<<endl;
	cout<<"1.3:"<<endl<<"Najwieksza liczba roznych lokali jest w miescie: "<<Zad3Max<<", jest ich: "<<Zad3MaxL<<endl<<"Najmniejsza liczba roznych lokalijest w: "<<Zad3Min<<", a jest ich: "<<Zad3MinL;
	return 0;
}
