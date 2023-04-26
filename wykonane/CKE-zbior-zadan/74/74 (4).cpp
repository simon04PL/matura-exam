#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>

using namespace std;

int Zad1=0, Zad3TempMax=0, Zad3TempMin=2000, Zad3=0, Zad4=0;
string x[200];
bool czyNumer=false, czyDuza=false, czyMala=false;
set<string>Zad2;

void Zad74_1(){
	for(int i=0;i<=199;i++){
		for(int j=0;j<=x[i].length()-1;j++){
			if(x[i][j]<48||x[i][j]>57){
				break;
			}
			if(j==x[i].length()-1){
				Zad1++;
			}
		}
	}
}
void Zad74_2(){
	for(int i=0;i<=198;i++){
		for(int j=i+1;j<=199;j++){
			if(x[i]==x[j]){
				Zad2.insert(x[i]);
				break;
			}
		}
	}
}
void Zad74_3(){
	for(int i=0;i<=199;i++){
		if(x[i].length()>=4){
			for(int j=3;j<=x[i].length()-1;j++){
				/*string fr = x[i].substr(j-3, 4);
				sort(fr.begin(), fr.end());
				if(fr[1] == fr[0] + 1 and fr[2] == fr[1] + 1 and fr[3] == fr[2] + 1)
				{
					Zad3++;
					break;
				}
				*/if(x[i][j]!=x[i][j-1]&&x[i][j-2]!=x[i][j]&&x[i][j]!=x[i][j-3]&&x[i][j-1]!=x[i][j-2]&&x[i][j-1]!=x[i][j-3]&&x[i][j-2]!=x[i][j-3]){
					for(int z=0;z<=3;z++){
						if(Zad3TempMin>x[i][j-z]){
							Zad3TempMin=x[i][j-z];
						}
						if(Zad3TempMax<x[i][j-z]){
							Zad3TempMax=x[i][j-z];
						}
					}
					if(Zad3TempMax-Zad3TempMin==3){
						Zad3++;
						cout<<x[i][j]<<", "<<x[i][j-1]<<", "<<x[i][j-2]<<", "<<x[i][j-3]<<endl;
						Zad3TempMax=0;
						Zad3TempMin=2000;
						break;
					}
					Zad3TempMax=0;
					Zad3TempMin=2000;
				}
			}
		}
	}
}
void Zad74_4(){
	for(int i=0;i<=199;i++){
		for(int j=0;j<=x[i].length()-1;j++){
			if(x[i][j]>=48&&x[i][j]<=57){
				czyNumer=true;
			}else if(x[i][j]>=97&&x[i][j]<=122){
				czyMala=true;
			}else if(x[i][j]>=65&&x[i][j]<=90){
				czyDuza=true;
			}
		}
		if(czyNumer==true&&czyDuza==true&&czyMala==true){
			Zad4++;
		}
		czyNumer=false;
		czyDuza=false;
		czyMala=false;
		
	}
}
int main(){
	ifstream plik;
	plik.open("hasla.txt");
	for(int i=0;i<=199;i++){
		plik>>x[i];
	}
	Zad74_1();
	cout<<"74.1: "<<Zad1<<endl;
	Zad74_2();
	cout<<"74.2: "<<endl;
	for(auto e:Zad2){
		cout<<e<<endl;
	}
	Zad74_3();
	cout<<"74.3: "<<Zad3<<endl;
	Zad74_4();
	cout<<"74.4: "<<Zad4;
	return 0;
}
