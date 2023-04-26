#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int Zad1Max=0, Zad2=0, TempL,TempS, Zad3LMax=0,Zad3SMax=0, Zad4O=0, Zad4SO=0, TempSOI, TempSumaSO;
int l[1000];
string x[1000];
string y,TempSO, TempOstateczne;
bool czyGen=false, czyFragment=false, czyBylo=false;

multiset<int>Zad1M;
set<int>Zad1S;

void Zad69_1(){
	for(int i=0;i<=999;i++){
		l[i]=x[i].length();
		Zad1M.insert(l[i]);
		Zad1S.insert(l[i]);
		for(int j=1;j<=500;j++){
			if(Zad1M.count(j)>Zad1Max){
				Zad1Max=Zad1M.count(j);
			}
		}
	}
}
void Zad69_2And3(){
	for(int i=0;i<=999;i++){
		TempS=0;
		for(int j=1;j<=l[i]-1;j++){
			if(x[i][j-1]=='A'&&x[i][j]=='A'&&czyGen==false){
				czyGen=true;
				TempL=j-1;
			}else if(x[i][j-1]=='B'&&x[i][j]=='B'&&czyGen==true){
				TempS++;
				czyGen=false;
				if(Zad3LMax<j+1-TempL){
					Zad3LMax=j+1-TempL;
				}
				if(czyFragment==true&&czyBylo==false){
					czyBylo=true;
					Zad2++;
				}
			}
			if(x[i][j]=='B'&&x[i][j+1]=='C'&&x[i][j+2]=='D'&&x[i][j+3]=='D'&&x[i][j+4]=='C'&&czyGen==true){
				czyFragment=true;
			}
		}
		if(TempS>Zad3SMax){
			Zad3SMax=TempS;
		}
		czyFragment=false;
		czyBylo=false;
		czyGen=false;
	}
}
void Zad69_4(){
	for(int i=0;i<=999;i++){
		y=x[i];
		reverse(y.begin(), y.end());
		if(y==x[i]){
			Zad4SO++;
		}
		y.clear();
		TempSO.clear();
		TempOstateczne.clear();
		TempSumaSO=0;
		TempSOI=0;
		czyGen=false;
		for(int j=1;j<=l[i]-1;j++){
			if(x[i][j-1]=='A'&&x[i][j]=='A'&&czyGen==false){
				czyGen=true;
				TempSOI=0;
			}else if(x[i][j+1]=='B'&&x[i][j]=='B'&&czyGen==true){
				czyGen=false;
				TempSumaSO+=TempSOI;
			}else if(czyGen==true){
				TempSO.push_back(x[i][j]);
				TempSOI++;
			}
		}
		for(int j=0;j<=TempSumaSO-1;j++){
			TempOstateczne.push_back(TempSO[j]);
		}
		y=TempOstateczne;
		reverse(y.begin(), y.end());
		if(y==TempOstateczne){
			Zad4O++;
		}
		y.clear();
	}
}
int main(){
	ifstream plik;
	plik.open("dane_geny.txt");
	for(int i =0;i<=999;i++){
		plik>>x[i];
	}
	Zad69_1();
	Zad69_2And3();
	Zad69_4();
	cout<<"69.1: ile osobnikow: "<<Zad1S.size()<<" najwieksza liczba osobnikow to: "<<Zad1Max<<endl;
	cout<<"69.2: "<<Zad2<<endl;
	cout<<"69.3: najwieksza liczba genow: "<<Zad3SMax<<" najdluzszy gen w pliku: "<<Zad3LMax<<endl;
	cout<<"69.4: silnie odporny: "<<Zad4SO<<" odporny: "<<Zad4O<<endl;
	return 0;
}
