#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

int l, lP, Zadb3=0, Zadb2MaxL=0, Zadb2MinL=100;
string x[1000], y[1000];
string w1, w2, Zadb2Min, Zadb2Max;

void a(){
	for(int i=0;i<=999;i++){
		y[i]=x[i];
		reverse(y[i].begin(),y[i].end());
	}
}
void bWypisz(){
	for(int i=0;i<=999;i++){
		l=x[i].length()-1;
		lP=l;
		if(l%2==0){
			l--;
		}
		while(l>=0){
			w1=x[i].substr(0,l);
			w2=w1;
			reverse(w1.begin(), w1.end());
			if(w1==w2){
				w2.clear();
				w2=x[i].substr(l+1,lP);
				reverse(w2.begin(), w2.end());
				cout<<w2<<x[i]<<endl;
			}
			l-=2;
		}
		w1.clear();
		w2.clear();
	}				
}
void b(){
	for(int i=0;i<=999;i++){
		l=x[i].length()-1;
		lP=l;
		if(l%2==0){
			l--;
		}
		while(l>=0){
			w1=x[i].substr(0,l);
			w2=w1;
			reverse(w1.begin(), w1.end());
			if(w1==w2){
				w2.clear();
				w2=x[i].substr(l+1,lP);
				reverse(w2.begin(), w2.end());
				l=w2.length()+x[i].length();
				Zadb3+=l;
				if(l==12){
					cout<<w2<<x[i]<<endl;
				}
				if(Zadb2MinL>l){
					Zadb2MinL=l;
					Zadb2Min.clear();
					for(int j=0;j<=w2.length()-1;j++){
						Zadb2Min.push_back(w2[j]);
					}
					for(int j=0;j<=x[i].length()-1;j++){
						Zadb2Min.push_back(x[i][j]);
					}
				}
				if(Zadb2MaxL<l){
					Zadb2MaxL=l;
					Zadb2Max.clear();
					for(int j=0;j<=w2.length()-1;j++){
						Zadb2Max.push_back(w2[j]);
					}
					for(int j=0;j<=x[i].length()-1;j++){
						Zadb2Max.push_back(x[i][j]);
					}
				}
				break;
			}
			l-=2;
		}
		w1.clear();
		w2.clear();
	}
}
int main(){
	ifstream plik;
	plik.open("slowa.txt");
	for(int i=0;i<=999;i++){
		plik>>x[i];
	}
	a();
	cout<<"a) "<<endl;
	for(int i=0;i<=999;i++){
		cout<<y[i]<<endl;
	}
	cout<<"b)"<<endl;
	bWypisz();
	cout<<"1. ";
	b();
	cout<<"2. "<<endl<<"najkrutsze: "<<Zadb2Min<<endl<<"Najdulsze slowo to: "<<Zadb2Max<<endl;
	cout<<"3. "<<Zadb3;
	return 0;
}
