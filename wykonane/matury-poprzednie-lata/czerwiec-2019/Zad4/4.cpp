#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int Temp, Zad3=0;
int l[300], p[200];
string x;

bool czyPierwsza(int k){
	if(k==1){
		return 0;
	}else if(k==2){
		return 1;
	}else{
		for(int i=2;i<=k-1;i++){
			if(k%i==0){
				return 0;
			}
		}
	}
	return 1;
}
int main(){
	ifstream liczby;
	ifstream pierwsze;
	liczby.open("liczby.txt");
	pierwsze.open("pierwsze.txt");
	vector<int>Zad1;
	vector<int>Zad2;
	for(int i=0;i<=299;i++){
		liczby>>l[i];
	}
	for(int i=0;i<=199;i++){
		pierwsze>>p[i];
	}
	//4.1
	for(int i=0;i<=299;i++){
		if(l[i]>=100&&l[i]<=5000&&czyPierwsza(l[i])==1){
			Zad1.push_back(l[i]);
		}
	}
	//4.2
	for(int i=0;i<=199;i++){
		x=to_string(p[i]);
		reverse(x.begin(), x.end());
		Temp=stoi(x);
		if(czyPierwsza(Temp)==1){
			Zad2.push_back(p[i]);
		}
		x.clear();
	}
	//4.3
	for(int i=0;i<=199;i++){
		Temp=p[i];
		while(Temp>9){
			x=to_string(Temp);
			Temp=0;
			for(int j=0;j<=x.length()-1;j++){
				Temp+=x[j]-48;
			}
			x.clear();
		}
		if(Temp==1){
			Zad3++;
		}	
	}
	cout<<"4.1: ";
	for(int i=0;i<=Zad1.size()-1;i++){
		cout<<Zad1[i]<<", ";
	}
	cout<<endl;
	cout<<"4.2: ";
	for(int i=0;i<=Zad2.size()-1;i++){
		cout<<Zad2[i]<<", ";
	}
	cout<<endl;
	cout<<"4.3: "<<Zad3;
	return 0;
}
