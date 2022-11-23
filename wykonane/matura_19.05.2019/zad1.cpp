#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int ileTrawa=0, Zad1=0, Zad3=0,k=0;
char plan[51][31][31];

int main(){
	ifstream plik;
	plik.open("dzialki.txt");
	set<int>Zad3Dzialki;
	for(int i =1;i<=50;i++){
		for(int j=1;j<=30;j++){
			for(int z =1;z<=30;z++){
				plik>>plan[i][j][z];
			}
		}
	}
	//4.1
	for(int i=1;i<=50;i++){
		for(int j=1;j<=30;j++){
			for(int z =1;z<=30;z++){
				if(plan[i][j][z]=='*'){
					ileTrawa++;
				}
			}
		}
		if(ileTrawa>=630){
			Zad1++;
		}
		ileTrawa=0;
	}
	//4.2
	
	//4.3
	for(int i=1;i<=50;i++){
		for(int j=1;j<=30;j++){
			for(int z=1;z<=j;z++){
				if(plan[i][z][j]=='X'){
					if(Zad3<j-1){
						Zad3=j-1;
					}
					k++;
					break;
				}
				if(plan[i][j][z]=='X'){
					if(Zad3<j-1){
						Zad3=j-1;
					}
					k++;
					break;
				}
			}
			if(k>0){
				k=0;
				break;
			}
		}
	}
	cout<<"4.1: "<<Zad1++<<endl;
	cout<<"4.3: "<<Zad3;
	
	cout<<endl;
}
