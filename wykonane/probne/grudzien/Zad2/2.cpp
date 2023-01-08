#include <iostream>
#include <fstream>

using namespace std;

int N=100000, strzalkaX[100000], strzalkaY[100000],i=0, n=0, PTemp,DTemp;

int rysuj(int x){
	if(2*x<=N){
		strzalkaX[i]=x;
		strzalkaY[i]=x*2;
		i++;
		rysuj(2*x);
	}
	if(2*x+1<=N){
		strzalkaX[i]=x;
		strzalkaY[i]=x*2+1;
		i++;
		rysuj(2*x+1);
	}
	return 1;
}
int main(){
	ifstream plik;
	plik.open("pary.txt");
	rysuj(1);
	for(int j=0;j<=1000;j++){
		plik>>PTemp;
		plik>>DTemp;
		for(int z=0;z<=100000;z++){
			if(strzalkaX[z]==PTemp&&strzalkaY[z]==DTemp){
				cout<<PTemp<<" "<<DTemp<<endl;
			}
			if(strzalkaY[z]==PTemp&&strzalkaX[z]==DTemp){
				cout<<PTemp<<" "<<DTemp<<endl;
			}
		}
	}
	
	return 0;
}
