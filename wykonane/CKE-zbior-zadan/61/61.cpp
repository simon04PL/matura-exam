#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int Zad1A=0, Zad1Max=0, Temp=0, p=1;
int x[100][1000],l[100], y[20][1000], lB[20], Zad3[20];

bool czyPotega(int k){
	p=1;
	if(k==1){
		return 1;
	}
	while(k>=p*p*p){
		if(p*p*p==k){
			return 1;
		}
		p++;
	}
	return 0;
}
int main(){
	ifstream plik1;
	ifstream plik2;
	plik1.open("ciagi.txt");
	plik2.open("bledne.txt");
	vector<int>Zad2;
	for(int i=0;i<=99;i++){
		plik1>>l[i];
		for(int j=0;j<=l[i]-1;j++){
			plik1>>x[i][j];
		}
	}
	for(int i=0;i<=19;i++){
		plik2>>lB[i];
		for(int j=0;j<=lB[i]-1;j++){
			plik2>>y[i][j];
		}
	}
	cout<<y[0][2]<<endl;
	//61.1
	for(int i=0;i<=99;i++){
		for(int j=2;j<=l[i]-1;j++){
			if(x[i][j-1]!=(x[i][j-2]+x[i][j])/2.0){
				break;
			}
			if(j==l[i]-1){
				Zad1A++;
				if(x[i][j]-x[i][j-1]>Zad1Max){
					Zad1Max=x[i][j]-x[i][j-1];
				}
			}
		}
	}
	//61.2
	for(int i=0;i<=99;i++){
		Temp=0;
		for(int j=0;j<=l[i]-1;j++){
			if(czyPotega(x[i][j])==1&&x[i][j]>Temp){
				Temp=x[i][j];
			}
		}
		if(Temp!=0){
			Zad2.push_back(Temp);
		}
	}
	//61.3
	for(int i =0;i<=19;i++){
		for(int j=2;j<=lB[i]-1;j++){
			if(y[i][j]-y[i][j-1]!=y[i][j-1]-y[i][j-2]&&j==2){
				if(y[i][j+1]-y[i][j]==y[i][j]-y[i][j-1]){
					Zad3[i]=y[i][0];
					break;
				}else if(y[i][j+2]-y[i][j+1]==y[i][j+1]-y[i][j]){
					Zad3[i]=y[i][1];
					break;
				}else{
					Zad3[i]=y[i][2];
					break;
				}
			}
			if(y[i][j]-y[i][j-1]!=y[i][j-1]-y[i][j-2]){
				Zad3[i]=y[i][j];
				break;
			}
		}
	}
	cout<<"61.1: ile jest ciagow arytmetycznych: "<<Zad1A<<" a najwieksza roznica wynosi: "<<Zad1Max<<endl;
	cout<<"61.2: "<<endl;
	for(int i=0;i<=Zad2.size()-1;i++){
		cout<<Zad2[i]<<endl;
	}
	cout<<"61.3: "<<endl;
	for(int i=0;i<=19;i++){
		cout<<Zad3[i]<<endl;
	}
	return 0;
}
