#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int Zad1=0, k, Zad2=0, Zad3=0;
string x[1000], y[1000];
bool czyBylo=false;
char a='A';

multiset<char>Zad3X;
multiset<char>Zad3Y;

void Zad6_1(){
	for(int i=0;i<=999;i++){
		if(x[i][x[i].length()-1]=='A'){
			Zad1++;
		}
		if(y[i][y[i].length()-1]=='A'){
			Zad1++;
		}
	}

}
void Zad6_2(){
	for(int i=0;i<=999;i++){
		if(y[i].length()>=x[i].length()){
			for(int j=0;j<=y[i].length()-1;j++){
				k=0;
				while(y[i][j+k]==x[i][k]){
					k++;
					if(k==x[i].length()){
						Zad2++;
						czyBylo=true;
						break;
					}
				}
				if(czyBylo==true){
					czyBylo=false;
					break;
				}
			}
		}
	}
}
void Zad6_3(){
	for(int i=0;i<=999;i++){
		if(x[i].length()==y[i].length()){
			for(int j=0;j<=x[i].length()-1;j++){
				Zad3X.insert(x[i][j]);
				Zad3Y.insert(y[i][j]);
			}
			a='A';
			while(a<='Z'){
				if(Zad3X.count(a)!=Zad3Y.count(a)){
					break;
				}
				if(a=='Z'){
					Zad3++;
				}
				a++;
			}
			Zad3X.clear();
			Zad3Y.clear();
		}
	}
}
int main(){
	ifstream plik;
	plik.open("slowa.txt");
	for(int i=0;i<=999;i++){
		plik>>x[i]>>y[i];
	}
	Zad6_1();
	Zad6_2();
	Zad6_3();
	cout<<"6.1: "<<Zad1<<endl;
	cout<<"6.2: "<<Zad2<<endl;
	cout<<"6.3: "<<Zad3<<endl;
	return 0;
}
