#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int Zad1L=0, Zad2L=0, Temp=0, Zad3=0;
int x[200], Zad1[2], Zad2[200][19];
bool czyWzgledniePierwsza=true;

int main(){
	ifstream plik;
	plik.open("liczby.txt");
	for(int i=0;i<=199;i++){
		plik>>x[i];
	}
	//60.1
	for(int i=199;i>=0;i--){
		if(x[i]<1000){
			if(Zad1L<=1){
				Zad1[Zad1L]=x[i];
			}
			Zad1L++;
		}
	}
	//60.2
	for(int i=0;i<=199;i++){
		for(int j=1;j<=x[i];j++){
			if(x[i]%j==0){
				Temp++;
				if(Temp<=18){
					Zad2[Zad2L][Temp]=j;
				}
			}
		}
		if(Temp==18){
			Zad2[Zad2L][0]=x[i];
			Zad2L++;
		}
		Temp=0;
	}
	//60.3
	for(int i=0;i<=199;i++){
		if(x[i]>Zad3){
			for(int j=0;j<=199;j++){
				if(j!=i){
					if(__gcd(x[i],x[j])!=1){
						break;
					}
					if(j==199){
						Zad3=x[i];
					}
				}
			}
		}
	}
	cout<<"60.1: liczb takich jest: "<<Zad1L<<" a jest ich: "<<Zad1[0]<<", "<<Zad1[1]<<endl;
	cout<<"60.2: "<<endl; 
	for(int i=0;i<=Zad2L-1;i++){
		cout<<"Liczba ta to: "<<Zad2[i][0]<<" a dzielniki to: ";
		for(int j=1;j<=18;j++){
			cout<<Zad2[i][j]<<", ";
		}
		cout<<endl;
	}
	cout<<"60.3: "<<Zad3;
	return 0;
}
