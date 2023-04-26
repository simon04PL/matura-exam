#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int Zad1=0, Zad1Max=0, Zad1Min=10000000, Zad2=0, Zad3=0; 
int x[5000];
char y[17]; 
string z,w;

set<int>zS;
set<int>wS;

bool czyPierwsza(int k){
	if(k==1){
		return 0;
	}else if(k==2){
		return 1;
	}else{
		for(int i=2;i<=k-1;i++){
			if(k%i==0){
				return 0;
			}
		}
	}
	return 1;
}
void Zad4_1(){
	for(int i=0;i<=4999;i++){
		if(czyPierwsza(x[i])==1){
			Zad1++;
			if(Zad1Max<x[i]){
				Zad1Max=x[i];
			}
			if(Zad1Min>x[i]){
				Zad1Min=x[i];
			}
		}
	}
}
void Zad4_2(){
	for(int i=0;i<=4999;i++){
		itoa(x[i],y,2);
		int k=0;
		while(y[k]=='1'||y[k]=='0'){
			z.push_back(y[k]);
			k++;
		}
		w=z;
		reverse(z.begin(),z.end());
		if(w==z){
			Zad2++;
		}else{
			k=w.length()-1;
			while(w[k]=='0'){
				k--;
			}
			w=w.substr(0,k+1);
			z.clear();
			z=w;
			reverse(z.begin(), z.end());
			if(w==z){
				Zad2++;
			}
		}
		w.clear();
		z.clear();
	}
}
void Zad4_3(){
	for(int i=1;i<=4999;i++){
		for(int j=i-1;j>=0;j--){
			w=to_string(x[i]);
			z=to_string(x[j]);
			for(int k=0;k<=w.length()-1;k++){
				wS.insert(w[k]);
			}
			for(int k=0;k<=z.length()-1;k++){
				zS.insert(z[k]);
			}
			for(int k=48;k<=57;k++){
				if(zS.count(k)!=wS.count(k)){
					break;
				}
				if(k==57){
					Zad3++;
				}
			}
			w.clear();
			z.clear();
			wS.clear();
			zS.clear();
		}
	}
}
int main(){
	ifstream plik;
	plik.open("dane.txt");
	for(int i=0;i<=4999;i++){
		plik>>x[i];
	}
	
	Zad4_1();
	Zad4_2();
	Zad4_3();
	cout<<"4.1: ile liczb pierwszych "<<Zad1<<" max liczba: "<<Zad1Max<<" min liczba: "<<Zad1Min<<endl;
	cout<<"4.2: "<<Zad2<<endl;
	cout<<"4.3: "<<Zad3<<endl;
	return 0;
}
