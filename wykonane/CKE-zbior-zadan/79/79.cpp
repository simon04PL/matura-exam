#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

int Zad1I=0, Zad1II=0, Zad1III=0, Zad1IV=0, Zad1Inne=0, Zad2=0, Zad3=0, Zad4Max=0, Temp;
float x[2000], y[2000], r[2000];
bool czyBylo90=false, czyBylo180=false;

vector<int>Zad4;

void Zad79_1(){
	for(int i=0;i<=1999;i++){
		if(x[i]>0&&y[i]>0&&y[i]-r[i]>0&&x[i]-r[i]>0){
			Zad1I++;
		}else if(x[i]<0&&y[i]>0&&y[i]-r[i]>0&&x[i]-r[i]<0){
			Zad1II++;
		}else if(x[i]<0&&y[i]<0&&y[i]-r[i]<0&&x[i]-r[i]<0){
			Zad1III++;
		}else if(x[i]>0&&y[i]<0&&y[i]-r[i]<0&&x[i]-r[i]>0){
			Zad1IV++;
		}else{
			Zad1Inne++;
		}
	}
}
void Zad79_2(){
	for(int i=0;i<=1998;i++){
		for(int j=i+1;j<=1999;j++){
			if(x[i]*(-1)==x[j]&&y[i]==y[j]&&r[i]==r[j]){
				Zad2++;
			}else if(x[i]==x[j]&&y[i]*(-1)==y[j]&&r[i]==r[j]){
				Zad2++;
			}
		}
	}
}
void Zad79_3(){
	for(int i=0;i<=1998;i++){
		for(int j=i+1;j<=1999;j++){
			if(x[i]==y[j]*(-1)&&x[j]==y[i]&&r[i]==r[j]){
				Zad3++;
			}else if(x[i]==y[j]&&x[j]*(-1)==y[i]&&r[i]==r[j]){
				Zad3++;
			}
		}
		czyBylo90=false;
		czyBylo180=false;
	}
}
void Zad79_4(){
	Temp=1;
	for(int i=1;i<=999;i++){
		if(sqrt((x[i]-x[i-1])*(x[i]-x[i-1])+(y[i]-y[i-1])*(y[i]-y[i-1]))<=r[i]+r[i-1]){
			Temp++;
			if(i==999){
				Zad4.push_back(Temp);
			}
		}else{
			Zad4.push_back(Temp);
			Temp=1;
		}
	}
	for(int i=0;i<=Zad4.size()-1;i++){
		if(Zad4Max<Zad4[i]){
			Zad4Max=Zad4[i];
		}
	}

}
int main(){
	ifstream plik;
	plik.open("okregi.txt");
	for(int i=0;i<=1999;i++){
		plik>>x[i]>>y[i]>>r[i];
	}
	Zad79_1();
	Zad79_2();
	Zad79_3();
	Zad79_4();
	cout<<"79.1: I cwiartka: "<<Zad1I<<", II cwiartka: "<<Zad1II<<", III cwiartka: "<<Zad1III<<", IV ciwartka: "<<Zad1IV<<", inne cwiartki: "<<Zad1Inne<<endl;
	cout<<"79.2: "<<Zad2<<endl;
	cout<<"79.3: "<<Zad3<<endl;
	cout<<"79.4:Max: "<<Zad4Max<<" wszystkie ciagi: "<<endl;
	for(int i=0;i<=Zad4.size()-1;i++){
		cout<<Zad4[i]<<", ";
	}
	return 0;
}
