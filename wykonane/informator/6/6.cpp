#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int x[2023], Zad1TempInt, Zad1_2=10,Zad1_3=10,Zad1_4=10,Zad1_5=10,Zad1_6=10,Zad1_7=10,Zad1_8=10,Zad1_9=10,Zad1_10=10,Zad1MinTemp=10;

int main(){
	ifstream plik;
	plik.open("dane6przyklad.txt");
	for(int i =0;i<=4;i++){
		plik>>x[i];
	}
	for(int i=0; i<=4;i++){
		string napis=to_string(x[i]);
		for(int j=0;j<=9;j++){
			Zad1TempInt=stoi(napis[j]);
			if(Zad1TempInt>Zad1MinTemp){
				Zad1MinTemp=Zad1TempInt+1;
			}
		}
		if(Zad1MinTemp==2){
			
		}
	}
	return 0;
}
