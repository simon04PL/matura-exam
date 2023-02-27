#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Zad1Max=0, Zad1Min=100000000, Temp=1, Zad2P, Zad2Max=0, Zad3A=0, Zad3B=0, l, Zad4Przed=0, Zad4Po=0;
int x[1000];
string y[1000];
string Zad1MaxS, Zad1MinS, wyraz;
vector<int>zamianaV;

void zamiana(int k){
	zamianaV.clear();
	while(k>1){
		Temp=k%8;
		zamianaV.push_back(Temp);
		k/=8;
	}
}
int main(){
	ifstream plik1;
	ifstream plik2;
	plik1.open("liczby1.txt");
	plik2.open("liczby2.txt");
	for(int i=0;i<=999;i++){
		plik1>>y[i];
		plik2>>x[i];
	}
	//62.1
	for(int i=0;i<=999;i++){
		if(stoi(y[i],nullptr,8)>Zad1Max){
			Zad1MaxS.clear();
			Zad1MaxS=y[i];
			Zad1Max=stoi(y[i],nullptr,8);
		}
		if(stoi(y[i],nullptr,8)<Zad1Min){
			Zad1MinS.clear();
			Zad1MinS=y[i];
			Zad1Min=stoi(y[i],nullptr,8);
		}
	}
	//62.2
	for(int i=1;i<=999;i++){
		if(x[i]>=x[i-1]){
			Temp++;
		}else{
			if(Zad2Max<Temp){
				Zad2Max=Temp;
				Zad2P=x[i-Temp];
			}
			Temp=1;
		}
	}
	//62.3
	for(int i=0;i<=999;i++){
		//a
		if(x[i]==stoi(y[i],nullptr,8)){
			Zad3A++;
		}
		//b
		if(x[i]<stoi(y[i],nullptr,8)){
			Zad3B++;
		}
	}
	//62.4
	for(int i=0;i<=999;i++){
		wyraz=to_string(x[i]);
		l=wyraz.length()-1;
		for(int j=0;j<=l;j++){
			if(wyraz[j]=='6'){
				Zad4Przed++;
			}
		}
		zamiana(x[i]);
		l=zamianaV.size()-1;
		for(int j=0;j<=l;j++){
			if(zamianaV[j]==6){
				Zad4Po++;
			}
		}
		
	}
	cout<<"62.1: najwiekszy: "<<Zad1MaxS<<" najmniejszy: "<<Zad1MinS<<endl;
	cout<<"62.2: dlugosc: "<<Zad2Max<<" pierwszy: "<<Zad2P<<endl;
	cout<<"62.3:"<<endl;
	cout<<Zad3A<<endl;
	cout<<Zad3B<<endl;
	cout<<"63.4: przed zamiana: "<<Zad4Przed<<" po zamianie: "<<Zad4Po;
	return 0;
}
