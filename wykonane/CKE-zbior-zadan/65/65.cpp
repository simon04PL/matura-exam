#include <iostream>
#include <fstream>

using namespace std;

float Zad1Temp=13000, Temp;
int Zad1Max=0, Zad2=0, Zad3=0;
long long Zad4=0,b=0;
int x[1000], y[1000];

bool czySkracalny(int k){
	for(int i=2;i<=x[k];i++){
		if(x[k]%i==0&&y[k]%i==0){
			return 1;
		}
	}
	return 0;
}
int SkracanieUlamku(int k){
	int l=x[k];
	int m=y[k];
	for(int i=l;i>=2;i--){
		if(l%i==0&&m%i==0){
			l=l/i;
			m=m/i;
		}
	}
	return l;
}
int main(){
	ifstream plik;
	plik.open("dane_ulamki.txt");
	for(int i=0;i<=999;i++){
		plik>>x[i]>>y[i];
	}
	//65.1
	for(int i=0;i<=999;i++){
		Temp=1.0*x[i]/y[i];
		if(Zad1Temp>Temp){
			Zad1Temp=Temp;
			Zad1Max=i;
		}else if(Zad1Temp==Temp&&y[i]<y[Zad1Max]){
			Zad1Temp=Temp;
			Zad1Max=i;
		}
	}
	//65.2 i 65.3
	for(int i=0;i<=999;i++){
		if(czySkracalny(i)==0){
			Zad2++;
			Zad3+=x[i];
		}else{
			Zad3+=SkracanieUlamku(i);
		}
	}
	//65.4
	b=2*2*3*3*5*5*7*7*13;
	for(int i=0;i<=999;i++){
		Zad4+=x[i]*b/y[i];
	}
	cout<<"65.1: "<<x[Zad1Max]<<"/"<<y[Zad1Max]<<endl;
	cout<<"65.2: "<<Zad2<<endl;
	cout<<"65.3: "<<Zad3<<endl;
	cout<<"65.4: "<<Zad4;
	return 0;
}
