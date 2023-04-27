#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int Zad1L=0, Zad1P, Zad3Max=0;
string x[200], y[200];

int main(){
	ifstream plik;
	plik.open("napisy.txt");
	vector<int>Zad2;
	vector<int>Zad3;
	for(int i=0;i<=199;i++){
		plik>>x[i]>>y[i];
	}
	//72.1
	for(int i=0;i<=199;i++){
		if(x[i].length()*3<=y[i].length()||x[i].length()>=3*y[i].length()){
			Zad1L++;
			if(Zad1L==1){
				Zad1P=i;
			}
		}
	}
	//72.2
	for(int i=0;i<=199;i++){
		if(x[i].length()<y[i].length()){
			for(int j=0;j<=x[i].length()-1;j++){
				if(x[i][j]!=y[i][j]){
					break;
				}
				if(j==x[i].length()-1){
					Zad2.push_back(i);
				}
			}
		}
	}
	//72.3
	for(int i=0;i<=199;i++){
		for(int j=0;j<=x[i].length()-1;j++){
			if(x[i][x[i].length()-j]!=y[i][y[i].length()-j]){
				if(Zad3Max==j-1){
					Zad3.push_back(i);
				}else if(Zad3Max<j-1){
					Zad3.clear();
					Zad3.push_back(i);
					Zad3Max=j-1;
				}
				break;
			}
		}
	}
	cout<<"72.1: liczba takich wyrazow: "<<Zad1L<<" pierwszy taki wyraz: "<<x[Zad1P]<<", "<<y[Zad1P]<<endl;
	cout<<"72.2: "<<endl;
	for(int i=0;i<=Zad2.size()-1;i++){
		cout<<" cale wyrazy: "<<x[Zad2[i]]<<", "<<y[Zad2[i]]<<" fragment powtarzajacy sie: "<<x[Zad2[i]]<<" fragment dodany: ";
		for(int j=x[Zad2[i]].length();j<=y[Zad2[i]].length()-1;j++){
			cout<<y[Zad2[i]][j];
		}
		cout<<endl;
	}
	cout<<"72.3: najdluzsze takie zakonczenie: "<<Zad3Max<<endl;
	for(int i=0;i<=Zad3.size()-1;i++){
		cout<<" pary ktore osiagnely taka dlugosc: "<<x[Zad3[i]]<<", "<<y[Zad3[i]]<<endl;
	}
	return 0;
}
