#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int Zad1=0, Zad2A=0, Zad2B=0, Temp3=1, Zad3=0, Zad3l=0;
string Zad2[1], Zad3D[1];
char mecz[10000];

int main(){
	ifstream plik;
	plik.open("mecz.txt");
	for(int i=0;i<=9999;i++){
		plik>>mecz[i];
	}
	//1.1
	for(int i=1;i<=9999;i++){
		if(mecz[i]!=mecz[i-1]){
			Zad1++;
		}
	}
	//1.2
	for(int i=0;i<=9999;i++){
		if(mecz[i]=='A'){
			Zad2A++;
		}
		if(mecz[i]=='B'){
			Zad2B++;
		}
		if(Zad2A>=1000&&Zad2A-Zad2B>=3){
			Zad2[0]="A";
			break;
		}
		if(Zad2B>=1000&&Zad2B-Zad2A>=3){
			Zad2[0]="B";
			break;
		}
	}
	//1.3
	for(int i=1;i<=9999;i++){
		if(mecz[i]==mecz[i-1]){
			Temp3++;
		}else{
			if(Temp3>=10&&Zad3<Temp3){
				Zad3=Temp3;
			}
			if(mecz[i-1]=='A'){
				Zad3D[0]="A";
			}else{
				Zad3D[0]="B";
			}
			Temp3=1;
		}
		if(Temp3==10){
			Zad3l++;
		}
	}
	cout<<"1.1: "<<Zad1<<endl;
	cout<<"1.2: wygrala druzyna: "<<Zad2[0]<<" wynikiem: A: "<<Zad2A<<" B: "<<Zad2B<<endl;
	cout<<"1.3: najdluzsza: "<<Zad3<<" Druzyna: "<<Zad3D[0]<<" bylo ich: "<<Zad3l;
	return 0;
}
