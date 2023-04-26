#include <iostream>
#include <fstream>

using namespace std;

int Zad1Min=300, Zad1Max=0, Zad2=0, Zad3=0, Zad4=0, Temp=0;
int x[320][200];

int main(){
	ifstream plik;
	plik.open("dane.txt");
	for(int i=0;i<=199;i++){
		for(int j=0;j<=319;j++){
			plik>>x[j][i];
		}
	}
	//6.1
	for(int i=0;i<=199;i++){
		for(int j=0;j<=319;j++){
			if(x[j][i]>Zad1Max){
				Zad1Max=x[j][i];
			}
			if(x[j][i]<Zad1Min){
				Zad1Min=x[j][i];
			}
		}
	}
	//6.2
	for(int i=0;i<=199;i++){
		for(int j=0;j<=319;j++){
			if(x[j][i]!=x[319-j][i]){
				Zad2++;
				break;
			}
		}
	}
	//6.3
	for(int i=0;i<=199;i++){
		for(int j=0;j<=319;j++){
			if(x[j][i]-x[j][i-1]>128&&i-1>=0||x[j][i]-x[j][i-1]<-128&&i-1>=0){
				Zad3++;
			}else if(x[j][i]-x[j][i+1]>128&&i+1<=199||x[j][i]-x[j][i+1]<-128&&i+1<=199){
				Zad3++;
			}else if(x[j][i]-x[j-1][i]>128&&j-1>=0||x[j][i]-x[j-1][i]<-128&&j-1>=0){
				Zad3++;
			}else if(x[j][i]-x[j+1][i]>128&&j+1<=319||x[j][i]-x[j+1][i]<-128&&j+1<=319){
				Zad3++;
			}
		}
	}
	//6.4
	for(int i=0;i<=319;i++){
		for(int j=1;j<=199;j++){
			if(x[i][j]==x[i][j-1]){
				Temp++;
			}else{
				Temp++;
				if(Zad4<Temp){
					Zad4=Temp;
				}
				Temp=0;
			}
		}
		if(Zad4<Temp){
			Zad4=Temp;
		}
		Temp=0;
	}
	cout<<"6.1: najjasniejszy: "<<Zad1Max<<" najciemniejszy: "<<Zad1Min<<endl;
	cout<<"6.2: "<<Zad2<<endl;
	cout<<"6.3: "<<Zad3<<endl;
	cout<<"6.4: "<<Zad4;
	return 0;
}
