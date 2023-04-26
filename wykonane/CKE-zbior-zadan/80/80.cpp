#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int Zad2, Zad3=0;
int x[500], y[500];

vector<int>Zad1;

bool porownanie(int p1, int p2){
	return p1>p2;
}
void Zad80_1(){
	for(int i=0;i<=497;i++){
		if(x[i]*x[i]+x[i+1]*x[i+1]==x[i+2]*x[i+2]||x[i+2]*x[i+2]+x[i+1]*x[i+1]==x[i]*x[i]||x[i]*x[i]+x[i+2]*x[i+2]==x[i+1]*x[i+1]){
			Zad1.push_back(i);
		}
	}
}
void Zad80_2(){
	for(int i=0;i<=499;i++){
		y[i]=x[i];
	}
	sort(y, y+500, porownanie);
	for(int i=0;i<=497;i++){
		if(y[i]+y[i+1]>y[i+2]&&y[i+2]+y[i+1]>y[i]&&y[i+2]+y[i+1]>y[i+1]){
			Zad2=y[i]+y[i+1]+y[i+2];
			break;
		}
	}
}
void Zad80_3(){
	for(int i=0;i<=497;i++){
		for(int j=i+1;j<=498;j++){
			for(int z=j+1;z<=499;z++){
				if(x[i]+x[j]>x[z]&&x[z]+x[j]>x[i]&&x[i]+x[z]>x[j]){
					Zad3++;
				}
			}
		}
	}
}
int main(){
	ifstream plik;
	plik.open("dane_trojkaty.txt");
	for(int i=0;i<=499;i++){
		plik>>x[i];
	}
	Zad80_1();
	Zad80_2();
	Zad80_3();
	cout<<"80.1: "<<endl;
	for(int i=0;i<=Zad1.size()-1;i++){
		cout<<x[Zad1[i]]<<", "<<x[Zad1[i]+1]<<", "<<x[Zad1[i]+2]<<endl;
	}
	cout<<"80.2: "<<Zad2<<endl;
	cout<<"80.3: "<<Zad3;
}
