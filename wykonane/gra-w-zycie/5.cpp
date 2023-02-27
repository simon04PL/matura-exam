#include <iostream>
#include <fstream>

using namespace std;

char x[12][20];

void Pokolenie(int p){
	for(int i=1;i<=p;i++){
		
	}
}
int main(){
	ifstream plik;
	plik.open("gra.txt");
	for(int i=0;i<=11;i++){
		for(int j=0;j<=19;j++){
			plik>>x[i][j];
		}
	}
	
}
