#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string Temp;
string x[805], y[5], z[5];

vector<string>Zad1;
vector<string>Zad2;
pair<int, int>Zad3Szyfr[5];
pair<int, int>Zad3DeSzyfr[5];

bool szyfrowanie(string s, string d, int k, int f){
	for(int i=0;i<=s.length()-1;i++){
		if((((s[i]-97)*k+f)%26)+97!=d[i]){
			return 0;
		}
		if(i==s.length()-1){
			return 1;
		}
	}
}
void Zad75_1(){
	for(int i=0;i<=804;i++){
		if(x[i][0]=='d'&&x[i][x[i].length()-1]=='d'){
			Zad1.push_back(x[i]);
		}
	}
}
void Zad75_2(){
	for(int i=0;i<=804;i++){
		if(x[i].length()>=10){
			Temp.clear();
			for(int j=0;j<=x[i].length()-1;j++){
				Temp.push_back((((x[i][j]-97)*5+2)%26)+97);
			}
			Zad2.push_back(Temp);
		}
	}
}
void Zad75_3(){
	for(int i=0;i<=4;i++){
		for(int A=0;A<=25;A++){
			for(int B=0;B<=25;B++){
				if(szyfrowanie(y[i], z[i], A, B)==1){
					Zad3Szyfr[i]={A, B};
				}
				if(szyfrowanie(z[i], y[i], A, B)==1){
					Zad3DeSzyfr[i]={A, B};
				}
			}
		}
	}
}
int main(){
	ifstream plik1;
	ifstream plik2;
	plik1.open("probka.txt");
	plik2.open("tekst.txt");
	for(int i=0;i<=804;i++){
		plik2>>x[i];
	}
	for(int i=0;i<=4;i++){
		plik1>>y[i]>>z[i];
	}
	Zad75_1();
	Zad75_2();
	Zad75_3();
	cout<<"75.1: "<<endl;
	for(int i=0;i<=Zad1.size()-1;i++){
		cout<<Zad1[i]<<endl;
	}
	cout<<"75.2: "<<endl;
	for(int i=0;i<=Zad2.size()-1;i++){
		cout<<Zad2[i]<<endl;
	}
	cout<<"75.3: "<<endl;
	for(int i=0;i<=4;i++){
		cout<<"szyfrujemy liczbami "<<i+1<<": ("<<Zad3Szyfr[i].first<<", "<<Zad3Szyfr[i].second<<")"<<endl;
		cout<<"deszyfrujemy liczbami "<<i+1<<": ("<<Zad3DeSzyfr[i].first<<", "<<Zad3DeSzyfr[i].second<<")"<<endl;
	}
	return 0;
}
