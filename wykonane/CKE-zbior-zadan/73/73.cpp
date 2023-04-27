#include <iostream>
#include <fstream>
#include <set>
#include <math.h>
#include <cmath>
#include <stdio.h>

using namespace std;

int Zad1=0, Zad2Ile=0, Zad3Ile=0, Zad3Max=0,Temp3=0;
float Temp;
string x[1876],y;
char Zad2='A';
bool czyBylo=false;

int main(){
	ifstream plik;
	plik.open("tekst.txt");
	multiset<char>Zad2Litery;
	for(int i=0;i<=1875;i++){
		plik>>x[i];
	}
	//73.1
	for(int i=0;i<=1875;i++){
		for(int j=1;j<=x[i].length()-1;j++){
			if(x[i][j]==x[i][j-1]){
				Zad1++;
				break;
			}
		}
	}
	//73.2
	for(int i=0;i<=1875;i++){
		for(int j=0;j<=x[i].length()-1;j++){
			Zad2Litery.insert(x[i][j]);
			Zad2Ile++;
		}
	}
	//73.3
	for(int i=0;i<=1875;i++){
		Temp3=0;
		for(int j=0;j<=x[i].length()-1;j++){
			if(x[i][j]!='A'&&x[i][j]!='E'&&x[i][j]!='I'&x[i][j]!='O'&&x[i][j]!='U'&&x[i][j]!='Y'){
				Temp3++;
			}else{
				Temp3=0;
			}
			if(Zad3Max==Temp3&&czyBylo==false){
				Zad3Ile++;
				czyBylo=true;
			}else if(Zad3Max<Temp3){
				Zad3Ile=1;
				Zad3Max=Temp3;
				y=x[i];
				czyBylo=true;
			}
		}
		czyBylo=false;
	}
	cout<<"73.1: "<<Zad1<<endl;
	cout<<"73.2: "<<endl;
	while(Zad2!='Z'+1){
		cout<<Zad2<<": "<<Zad2Litery.count(Zad2)<<" (";
		printf("%.2f", 100 * Zad2Litery.count(Zad2)/float(Zad2Ile));
		cout<<"%)"<<endl;
		Zad2++;
	}
	cout<<"73.3: ile najdluzszy ciag: "<<Zad3Max<<" ile takich ciagow: "<<Zad3Ile<<" pierwszy z nich to: "<<y;
	return 0;
}
