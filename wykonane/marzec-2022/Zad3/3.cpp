#include <iostream>
#include <fstream>

using namespace std;

int Zad3=0, Zad4=0, Zad5=0;
int M[1000], a[1000], b[1000];
long long int Temp;

bool czyPierwsza(int p){
	if(p==2){
		return 1;
	}
	for(int i=2;i<=p-1;i++){
		if(p%i==0){
			return 0;
		}
	}
	return 1;
}
bool czyWzgledniePierwsze(int p, int d){
	if(p>=d){
		for(int i=2;i<=d;i++){
			if(p%i==0&&d%i==0){
				return 1;
			}
		}
	}else{
		for(int i=2;i<=p;i++){
			if(p%i==0&&d%i==0){
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	ifstream plik;
	plik.open("liczby.txt");
	for(int i=0;i<=999;i++){
		plik>>M[i]>>a[i]>>b[i];
	}
	//3.3
	for(int i=0;i<=999;i++){
		if(czyPierwsza(M[i])==1){
			Zad3++;
		}
	}
	//3.4
	for(int i=0;i<=999;i++){
		if(czyWzgledniePierwsze(M[i], a[i])==0){
			Zad4++;
		}
	}
	//3.5
	for(int i=0;i<=999;i++){
		Temp=1;
		if(b[i]==Temp%M[i]){
			Zad5++;
		}else{
			for(int j=1;j<=M[i]-1;j++){
				Temp=(Temp*a[i])%M[i];
				if(b[i]==Temp){
					Zad5++;
					break;
				}
			}
		}
	}
	cout<<"3.3: "<<Zad3<<endl;
	cout<<"3.4: "<<Zad4<<endl;
	cout<<"3.5: "<<Zad5<<endl;
	return 0;
}
