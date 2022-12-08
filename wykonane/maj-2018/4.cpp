#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

string x, Zad1, Zad2;
char slowo1, slowo2;
set<char>litery;
bool czyKoniec=false;
int l=0;

int main(){
	ifstream plik;
	plik.open("sygnaly.txt");
	cout<<"4.3: ";
	for(int i =0;i<=999;i++){
		plik>>x;
		//4.1
		if((i+1)%40==0){
			Zad1.push_back(x[9]);
		}
		//4.2
		for(int j=1;j<=x.size()-1;j++){
			litery.insert(x[j]);
		}
		if(litery.size()>l){
			Zad2=x;
			l=litery.size();
		}
		litery.clear();
		//4.3
		for(int j=0;j<=x.size()-2;j++){
			for(int k=j+1;k<=x.size()-1;k++){
				if(x[k]-x[j]>=0&&x[k]-x[j]>10){
					czyKoniec=true;
					break;
				}else if(x[j]-x[k]>10){
					czyKoniec=true;
					break;
				}	
			}
			
		}
		if(czyKoniec==false){
			cout<<x<<endl;
		}
		czyKoniec=false;
		x.clear();
	}
	cout<<"4.1: "<<Zad1<<endl;
	cout<<"4.2 slowo: "<<Zad2<<" liczba: "<<l<<endl;
	return 0;
}
