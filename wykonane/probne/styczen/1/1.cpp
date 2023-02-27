#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

int l, Temp, Zad1Max=0,Zad1Min=100000000, Zad1MaxI, Zad1MinI, Zad2=0, Zad2P=0, Zad2Z=0, Zad3=0, Zad3P;
int x[1000];
string y;
bool czyPierwsza(int k){
	if(k==1){
		return 0;
	}else if(k==2){
		return 1;
	}
	for(int i=2;i<=k;i++){
		if(k%i==0){
			return 0;
		}
	}
	return 1;
}
int main(){
	ifstream plik;
	plik.open("liczby.txt");
	set<int>Zad1L;
	for(int i=0;i<=999;i++){
		plik>>x[i];
	}
	//1.1
	for(int i =0;i<=999;i++){
		y=to_string(x[i]);
		l=y.length()-1;
		for(int j=0;j<=l;j++){
			char z=y[j];
			Temp=z;
			Zad1L.insert(Temp);
		}
		y.clear();
	}
	for(int i=0;i<=9;i++){
		if(Zad1L.count(i)>Zad1Max){
			Zad1Max=Zad1L.count(i);
			Zad1MaxI=i;
		}
		if(Zad1L.count(i)<Zad1Min){
			Zad1Min=Zad1L.count(i);
			Zad1MinI=i;
		}
	}
	//1.2
	for(int i=0;i<=99;i++){
		Temp=x[i];
		while(Temp!=1){
			for(int j=2;j<=Temp;j++){
				if(Temp%j==0){
					if(czyPierwsza(j)==1){
						Zad2P++;
					}else{
						Zad2Z++;
					}
					Temp=Temp/j;
				}
			}
		}
		if(Zad2Z-Zad2P==1){
			Zad2++;
		}
		Zad2P=0;
		Zad2Z=0;
	}
	//1.3
	Temp=0;
	for(int i=0;i<=999;i++){
		y=to_string(x[i]);
		l=y.length();
		if(l>=5){
			Temp++;
		}else{
			if(Zad3<Temp){
				Zad3=Temp;
				Zad3P=i-Temp;
			}
			Temp=0;
		}
	}
	cout<<"1.2: "<<Zad2<<endl;
	cout<<"1.3 pierwszy wyraz: "<<x[Zad3P]<<" a dlugosc: "<<Zad3;
	return 0;
}
