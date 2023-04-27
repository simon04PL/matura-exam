#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <vector>

using namespace std;

int x;
float Zad1, Temp, wynik,Zad2I=-1, Zad2F=-99999, Zad2Temp;
float a0[5], a1[5], a2[5],a3[5];

float wartosc(int k, float z){
	wynik=a0[k];
	Temp=z;
	wynik+=a1[k]*Temp;
	Temp*=z;
	wynik+=a2[k]*Temp;
	Temp*=z;
	wynik+=a3[k]*Temp;
	return wynik;
}
int main(){
	ifstream plik;
	plik.open("funkcja.txt");
	vector<float>Zad3;
	for(int i=0;i<=4;i++){
		plik>>a0[i]>>a1[i]>>a2[i]>>a3[i];
	}
	//71.1
	Zad1=wartosc(1, 1.5);
	//71.2
	for(int i=0;i<=5;i++){
		for(float j=0;j<5;j+=0.001){
			x=j/1;
			Zad2Temp=wartosc(x, j);
			if(Zad2Temp>Zad2F){
				Zad2F=Zad2Temp;
				Zad2I=j;
			}
		}
	}
	//71.2
	for(int i=0;i<=4;i++){
		for(float j;j<5;j+=0.00001){
			if(wartosc((j-0.00001)/1, j-0.00001)>0&&0>wartosc(j/1, j)){
				Zad3.push_back(j);
			}else if(wartosc((j-0.00001)/1, j-0.00001)<0&&0<wartosc(j/1, j)){
				Zad3.push_back(j);
			}else if(wartosc(j/1, j)==0){
				Zad3.push_back(j);
			}
		}
	}
	cout<<"71.1: "<<Zad1<<endl;
	cout<<"71.2:  x wynosi: "<<round(Zad2I*1000)/1000<<" wynik tej F(x)= "<<Zad2F<<endl;
	cout<<"72.3: "<<endl;
	for(int i=0;i<=Zad3.size()-1;i++){
		cout<<Zad3[i]<<endl;
	}
	return 0;
}
