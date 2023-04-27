#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <cmath>

using namespace std;

int k=0, k2=0, wynik=0, ile=0;
float Zad3, n;
string szyfr1={"LUBIMYCZYTAC"};
char a;
string szyfr2;
string Temp;

vector<string>x;
vector<string>Zad1;
vector<string>y;
vector<string>Zad2;
multiset<char>Zad3Liczby;

void Zad77_1(){
	k=0;
	for(int i=0;i<=42;i++){
		Temp.clear();
		for(int j=0;j<=x[i].length()-1;j++){
			if(x[i][j]!=','&&x[i][j]!='.'){
				Temp.push_back(((x[i][j]+szyfr1[k%12]-65*2)%26)+65);
				k++;
			}else{
				Temp.push_back(x[i][j]);
			}
		}
		Zad1.push_back(Temp);
	}
}
void Zad77_2(){
	k2=0;
	for(int i=0;i<=50;i++){
		Temp.clear();
		for(int j=0;j<=y[i].length()-1;j++){
			if(y[i][j]!=','&&y[i][j]!='.'){
				if(y[i][j]-szyfr2[k2%(szyfr2.length())]+65<65){
					Temp.push_back(y[i][j]+26-szyfr2[k2%(szyfr2.length())]+65);
				}else{
					Temp.push_back(y[i][j]-szyfr2[k2%(szyfr2.length())]+65);
				}
				k2++;
			}else{
				Temp.push_back(y[i][j]);
			}
		}
		Zad2.push_back(Temp);
	}
}
void Zad77_3(){
	for(int i=0;i<=50;i++){
		for(int j=0;j<=y[i].length()-1;j++){
			Zad3Liczby.insert(y[i][j]);
		}
	}
	a='A';
	while('Z'+1>a){
		wynik+=Zad3Liczby.count(a)*(Zad3Liczby.count(a)-1);
		ile+=Zad3Liczby.count(a);
		a++;
	}
	n=wynik/(ile*(ile-1)*1.0);
	Zad3=0.0285/(n-0.0385);
}
int main(){
	ifstream plik1;
	ifstream plik2;
	plik1.open("dokad.txt");
	plik2.open("szyfr.txt");
	for(int i=0;i<=42;i++){
		plik1>>Temp;
		x.push_back(Temp);
		Temp.clear();
	}
	Temp.clear();
	for(int i=0;i<=50;i++){
		plik2>>Temp;
		y.push_back(Temp);
		Temp.clear();
	}
	plik2>>szyfr2;
	Zad77_1();
	Zad77_2();
	Zad77_3();
	cout<<"77.1: a) "<<(k/12)+1<<endl;
	cout<<"77.1: b)";
	for(int i=0;i<=42;i++){
		cout<<Zad1[i];
		cout<<" ";
	}
	cout<<endl;
	cout<<"77.2: ";
	for(int i=0;i<=50;i++){
		cout<<Zad2[i];
		cout<<" ";
	}
	cout<<endl;
	cout<<"77.3: a) "<<endl;
	a='A';
	while('Z'+1>a){
		cout<<a<<": "<<Zad3Liczby.count(a)<<endl;
		a++;
	}
	cout<<endl;
	cout<<"77.3: b) szacowana dlugosc klucza: "<<round(Zad3)<<endl;
	cout<<"dokladna dlugosc klucza: "<<round(100*Zad3)/100;
}
