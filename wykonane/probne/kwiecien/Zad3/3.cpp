#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int Zad3=0;
string x[400], y[400];

multiset<char>Zad1_1;
multiset<char>Zad1_2;
multiset<char>Zad2;
vector<string>Odp;

void Zad3_3(){
	for(int i=0;i<=399;i++){
		if(x[i].length()==y[i].length()){
			for(int j=0;j<=x[i].length()-1;j++){
				Zad1_1.insert(x[i][j]);
				Zad1_2.insert(y[i][j]);
			}
			char a='A';
			while(a<='Z'){
				if(Zad1_1.count(a)!=Zad1_2.count(a)){
					break;
				}
				if(a=='Z'){
					Zad3++;
				}
				a++;
			}
		}
		Zad1_1.clear();
		Zad1_2.clear();
	}
}
void Zad3_4(){
	for(int i=0;i<=399;i++){
		Zad2.clear();
		if(x[i].length()==8){
			for(int j=0;j<=x[i].length()-1;j++){
				Zad2.insert(x[i][j]);
			}
			if(Zad2.count('A')==3&&Zad2.count('B')==2&&Zad2.count('R')==1&&Zad2.count('K')==1&&Zad2.count('N')==1){
				Odp.push_back(x[i]);
			}
		}
		Zad2.clear();
		if(y[i].length()==8){
			for(int j=0;j<=y[i].length()-1;j++){
				Zad2.insert(y[i][j]);
			}
			if(Zad2.count('A')==3&&Zad2.count('B')==2&&Zad2.count('R')==1&&Zad2.count('K')==1&&Zad2.count('N')==1){
				Odp.push_back(y[i]);
			}
		}
	}
}
int main(){
	ifstream plik;
	plik.open("pary_slow.txt");
	for(int i=0;i<=399;i++){
		plik>>x[i]>>y[i];
	}
	Zad3_3();
	Zad3_4();
	cout<<"3.3: "<<Zad3<<endl;
	cout<<"3.4: "<<endl;
	for(int i=0;i<=Odp.size()-1;i++){
		cout<<Odp[i]<<endl;
	}
}
