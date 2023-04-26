#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int l, Zad4=0, k=10000, Temp4=0, Zad4Max=0, Temp3;
long long Temp=0;
long long x[1000], y[1000], z[1000];
string xS;

bool czyPitagoras(int a, int b, int c){
	Temp3=max(max(a, b),c);
	if(2*Temp3*Temp3==a*a+b*b+c*c){
		return 1;
	}
	return 0;
}
bool czyPierwsza(int p){
	if(p==1){
		return 0;
	}else if(p==2){
		return 1;
	}else{
		for(int i=2;i<=p-1;i++){
			if(p%i==0){
				return 0;
			}
		}
	}
	return 1;
}
int main(){
	ifstream plik;
	plik.open("trojki.txt");
	vector<int>Zad1;
	vector<int>Zad2;
	vector<int>Zad3;
	for(int i=0;i<=999;i++){
		plik>>x[i]>>y[i]>>z[i];
	}
	
	//66.1
	for(int i=0;i<=999;i++){
		xS=to_string(x[i]);
		l=xS.length()-1;
		for(int j=0;j<=l;j++){
			Temp+=xS[j]-48;
		}
		xS.clear();
		xS=to_string(y[i]);
		l=xS.length()-1;
		for(int j=0;j<=l;j++){
			Temp+=xS[j]-48;
		}
		xS.clear();
		if(Temp==z[i]){
			Zad1.push_back(i);
		}
		Temp=0;
	}
	//66.2
	for(int i=0;i<=999;i++){
		if(x[i]*y[i]==z[i]&&czyPierwsza(x[i])==1&&czyPierwsza(y[i])==1){
			Zad2.push_back(i);
		}
	}
	//66.3
	
	for(int i=1;i<=999;i++){
		if(czyPitagoras(x[i], y[i], z[i])==1&&czyPitagoras(x[i-1], y[i-1], z[i-1])==1){
			if(k+1==i){
				Zad3.push_back(i);
			}else{
				Zad3.push_back(i-1);
				Zad3.push_back(i);
			}
			k=i;
		}
	}
	//66.4
	for(int i=0;i<=999;i++){
		if(x[i]+y[i]>=z[i]&&x[i]+z[i]>=y[i]&&y[i]+z[i]>=x[i]){
			Zad4++;
			Temp4++;
		}else{
			if(Temp4>Zad4Max){
				Zad4Max=Temp4;
			}
			Temp4=0;
		}
	}
	cout<<"66.1: "<<endl;
	for(int i=0;i<=Zad1.size()-1;i++){
		cout<<x[Zad1[i]]<<" "<<y[Zad1[i]]<<" "<<z[Zad1[i]]<<endl;
	}
	cout<<"66.2: "<<endl;
	for(int i=0;i<=Zad2.size()-1;i++){
		cout<<x[Zad2[i]]<<" "<<y[Zad2[i]]<<" "<<z[Zad2[i]]<<endl;
	}
	cout<<"66.3: "<<endl;
	for(int i=0;i<=Zad3.size()-1;i++){
		cout<<x[Zad3[i]]<<" "<<y[Zad3[i]]<<" "<<z[Zad3[i]]<<endl;
	}
	cout<<"66.4: ile jest trojkontow: "<<Zad4<<" jaki najdluzszy ciag: "<<Zad4Max;
	return 0;
}
