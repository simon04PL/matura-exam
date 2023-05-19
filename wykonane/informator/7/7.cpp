#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

string TempData, TempWyraz;
int szyfr[26], poprawne[26];
char a='A';

vector<string>x;
vector<string>Zad3;
multiset<char>lSzyfru;

void liczbaSzyfr(){
	for(int i=65;i<=90;i++){
		szyfr[i-65]=lSzyfru.count(i);
	}
}
void Zad7_1(){
	for(int i=0;i<=x.size()-2;i++){
		for(int j=0;j<=x[i].length()-1;j++){
			lSzyfru.insert(x[i][j]);
		}
	}
}
void Zad7_3(){
	for(int i=0;i<=x.size()-2;i++){
		for(int j=0;j<=x[i].length()-1;j++){
			for(int k=0;k<=25;k++){
				if(poprawne[k]==szyfr[x[i][j]-65]){
					TempWyraz.push_back(k+65);
					break;
				}
			}
		}
		Zad3.push_back(TempWyraz);
		TempWyraz.clear();
	}
}
int main(){
	ifstream plik;
	ifstream plik1;
	plik.open("szyfrogram.txt");
	plik1.open("czestosc.txt");
	while(plik){
		plik>>TempData;
		x.push_back(TempData);
		TempData.clear();
	}
	for(int i=0;i<=25;i++){
		plik1>>a>>poprawne[i];
	}
	Zad7_1();
	liczbaSzyfr();
	Zad7_3();
	cout<<"7.1: "<<endl;
	a='A';
	for(int i=0;i<=25;i++){
		cout<<a<<": "<<szyfr[i]<<endl;
		a++;
	}
	cout<<"7.3: "<<endl;
	for(int i=0;i<=Zad3.size()-1;i++){
		cout<<Zad3[i]<<endl;
	}
	return 0;
}
