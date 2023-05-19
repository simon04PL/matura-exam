#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

int Zad1=0, Zad2=0, Zad3=0, Zad3Min=1000, Zad3Max=0;
string w1,w2;
string x[1000];
set<int>pierwsze;

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
void Zad1_1(){
	for(int i=0;i<=199;i++){
		if(x[i].length()%2==0){
			
		}
	}
}
void Zad1_2(){
	for(int i=0;i<=999;i++){
		for(int j=1;j<=x[i].length()-1;j++){
			if(x[i][j-1]=='1'&&x[i][j]=='1'){
				break;
			}
			if(j==x[i].length()-1){
				Zad2++;
			}
		}
	}
}
void Zad1_3(){
	/*pierwsze.insert(2);
	for(int i=3;i<=262143;i+=2){
		if(czyPierwsza(i)==1){
			pierwsze.insert(i);
		}
	}*/
	for(int i=0;i<=999;i++){
		
		int Temp=0, licznik=0;
		Temp=stoi(x[i],nullptr,2);
		if(czyPierwsza(Temp)==0){
			Zad3++;
			if(Zad3Max<Temp){
				Zad3Max=Temp;
			}
			if(Zad3Min>Temp){
				Zad3Min=Temp;
			}
		}
		/*if(Temp%2==0){
			licznik++;
			if(Temp%(2*2)==0){
				licznik++;
			}
			if(licznik==2){
				Zad3++;
				if(Zad3Max<Temp){
					Zad3Max=Temp;
				}
				if(Zad3Min>Temp){
					Zad3Min=Temp;
				}
			}
		}
		for(int j=3;j<=Temp-1;j+=2){
			if(licznik==2){
				break;
			}
			if(pierwsze.count(j)==1&&Temp%j==0){
				licznik++;
				if(Temp%(j*j)==0){
					licznik++;
				}
				if(licznik==2){
					Zad3++;
					if(Zad3Max<Temp){
						Zad3Max=Temp;
					}
					if(Zad3Min>Temp){
						Zad3Min=Temp;
					}
					break;
				}
			}
		}*/
	}
}
int main(){
	ifstream plik;
	plik.open("ciagi.txt");
	for(int i=0;i<=999;i++){
		plik>>x[i];
	}
	Zad1_1();
	Zad1_2();
	Zad1_3();
	cout<<"1.1:"<<endl<<"Ciagow dwucyklicznych w tym pliku jest: "<<Zad1<<endl;
	cout<<"1.2:"<<endl<<"Ciagi w ktorych dwie jedynki nie wystepuja obok siebie jest: "<<Zad2<<endl;
	cout<<"1.3:"<<endl<<"Liczb polpierwszych w tym pliku jest: "<<Zad3<<endl<<"Najwieksza z nich to: "<<Zad3Max<<endl<<"Minimalna z nich to: "<<Zad3Min;
	return 0;
}
