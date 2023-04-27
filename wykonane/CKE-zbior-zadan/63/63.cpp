#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int l, Temp, Zad2=0, Zad3L=0, z=0, Zad3Min=1000000, Zad3Max=0;
string x[1000];
bool czyByla=false;

bool czyPierwsza(int k){
	if(k==2){
		return 1;
	}
	for(int i=2;i<k;i++){
		if(k%i==0){
			return 0;
		}
	}
	return 1;
}
int main(){
	ifstream plik;
	plik.open("ciagi.txt");
	vector<string>Zad1;
	vector<int>Zad3;
	for(int i=0;i<=999;i++){
		plik>>x[i];
	}
	//63.1
	for(int i=0;i<=999;i++){
		l=x[i].length();
		if(l%2!=0){
			continue;
		}
		Temp=l/2;
		for(int j=0;j<=(l/2)-1;j++){
			if(x[i][j]!=x[i][Temp]){
				break;
			}
			Temp++;
			if(j==(l/2)-1){
				Zad1.push_back(x[i]);
			}
		}
	}
	//63.2
	for(int i=0;i<=999;i++){
		l=x[i].length();
		for(int j=1;j<=l-1;j++){
			if(x[i][j]=='1'&&x[i][j-1]=='1'){
				break;
			}
			if(j==l-1){
				Zad2++;
			}
		}
	}
	//63.3
	for(int i =0;i<=999;i++){
		Temp=stoi(x[i],nullptr,2);
		for(int j=2;j<=Temp;j++){
			if(Temp%j==0){
				if(czyPierwsza(j)==1){
					Zad3.push_back(j);
					for(int v=0;v<=z;v++){
						if(Zad3[v]*j==Temp){
							Zad3L++;
							if(Zad3Min>Temp){
								Zad3Min=Temp;
							}
							if(Zad3Max<Temp){
								Zad3Max=Temp;
							}
							czyByla=true;
							break;
						}
					}
					z++;
					if(czyByla==true){
						czyByla=false;
						break;
					}
				}
			}
		}
		Zad3.clear();
		z=0;
	}
	cout<<"63.1: "<<endl;
	for(int i=0;i<=Zad1.size()-1;i++){
		cout<<Zad1[i]<<endl;
	}
	cout<<"63.2: "<<Zad2<<endl;
	cout<<"63.3: ilosc takich ciagow: "<<Zad3L<<" minimalny: "<<Zad3Min<<" maksymalny: "<<Zad3Max;
	return 0;
}
