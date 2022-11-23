#include <iostream>
#include <fstream>

using namespace std;

int x[1000], y[1000];
int Zad1=0;

 czyPierwsza(int p){
	if(p==1){
		return true;
	}else if(p==2){
		return false;
	}
	for(int i=2;i<=p;i++){
		if(p%i==0){
			return true;
		}
	}
	return false;
}
int main(){
	ifstream plik;
	plik.open("punkty.txt");
	for(int i=0;i<=999;i++){
		plik>>x[i];
		plik>>y[i];
	}
	//4.1
	for(int i=0;i<=999;i++){
		if(czyPierwsza(x[i])==true&&czyPierwsza(y[i])==true){
			Zad1++;
		}
	}
	//4.2
	
	cout<<"4.1: "<<Zad1<<endl;
	return 0;
}
