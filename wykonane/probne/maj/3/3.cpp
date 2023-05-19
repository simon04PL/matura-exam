#include <bits/stdc++.h>

using namespace std;

int Zad2P=0, Zad2NP=0, Zad3=0, Zad4=0;
int x[2023], d[2023];

void Zad3_2(){
	for(int i=1;i<=2022;i++){
		if(x[i]>x[i-1]){
			if((x[i]-x[i-1])%2==0){
				Zad2P++;
			}else{
				Zad2NP++;
			}
		}else{
			if((x[i-1]-x[i])%2==0){
				Zad2P++;
			}else{
				Zad2NP++;
			}
		}
	}
}
void Zad3_3(){
	for(int i=1;i<=2022;i++){
		for(int j=0;j<=i-1;j++){
			if(x[j]>x[i]){
				Zad3++;
			}
		}
	}
}
void Zad3_4(){
	fill(d,d+2023,1);
	for(int i=1;i<=2022;i++){
		for(int j=i-1;j>=0;j--){
			if(x[j]<x[i]&&d[i]<=d[j]){
				d[i]=d[j]+1;
			}
		}
	}
	for(int i=0;i<=2022;i++){
		if(Zad4<d[i]){
			Zad4=d[i];
		}
	}
}
int main(){
	ifstream plik;
	plik.open("liczby.txt");
	for(int i=0;i<=2022;i++){
		plik>>x[i];
	}
	Zad3_2();
	Zad3_3();
	Zad3_4();
	cout<<"3.2:"<<endl<<"Luk parzystych jest: "<<Zad2P<<endl<<"Luk nieparzystych jest: "<<Zad2NP<<endl;
	cout<<"3.3:"<<endl<<"Liczba nieuporzadkowanych par wynosi: "<<Zad3<<endl;
	cout<<"3.4:"<<endl<<"Dlugosc najdluzszego podciagu malejacego w tym zbiorze liczb wynosi: "<<Zad4;
	return 0;
}
