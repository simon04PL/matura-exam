#include <iostream>
#include <fstream>

using namespace std;
char x[20][12], pokolenieP[20][12],pokolenieN[20][12];
int Temp=0, Zad1=0, Zad2=0, Temp3=-1, Zad3, Temp2, Zad3Z;
bool czyUklad=true;

void Pokolenie(int p){
	for(int i=0;i<=11;i++){
		for(int j=0;j<=19;j++){
			pokolenieN[j][i]=x[j][i];
		}
	}
	for(int i=2;i<=p;i++){
		for(int z=0;z<=11;z++){
			for(int j=0;j<=19;j++){
				pokolenieP[j][z]=pokolenieN[j][z];
			}
		}
		for(int z=0;z<=11;z++){
			for(int j=0;j<=19;j++){
				if(pokolenieP[j][(z-1+12)%12]=='.'){
					Temp++;
				}
				if(pokolenieP[(j+1)%20][(z-1+12)%12]=='.'){
					Temp++;
				}
				if(pokolenieP[(j+1)%20][z]=='.'){
					Temp++;
				}
				if(pokolenieP[(j+1)%20][(z+1)%12]=='.'){
					Temp++;
				}
				if(pokolenieP[j][(z+1)%12]=='.'){
					Temp++;
				}
				if(pokolenieP[(j-1+20)%20][(z+1)%12]=='.'){
					Temp++;
				}
				if(pokolenieP[(j-1+20)%20][z]=='.'){
					Temp++;
				}
				if(pokolenieP[(j-1+20)%20][(z-1+12)%12]=='.'){
					Temp++;
				}
				if(pokolenieP[j][z]=='X'){
					if(Temp==6||Temp==5){
						pokolenieN[j][z]='X';
					}else{
						pokolenieN[j][z]='.';
					}
				}else if(pokolenieP[j][z]=='.'&&Temp==5){
					pokolenieN[j][z]='X';
				}else{
					pokolenieN[j][z]='.';
				}
				Temp=0;
			}
		}
	}
}
int main(){
	ifstream plik;
	plik.open("gra.txt");
	for(int i=0;i<=11;i++){
		for(int j=0;j<=19;j++){
			plik>>x[j][i];
		}
	}
	//5.1
	Pokolenie(37);
	if(pokolenieN[18][0]=='X'){
		Zad1++;
	}
	if(pokolenieN[19][0]=='X'){
		Zad1++;
	}
	if(pokolenieN[19][1]=='X'){
		Zad1++;
	}
	if(pokolenieN[19][2]=='X'){
		Zad1++;
	}
	if(pokolenieN[18][2]=='X'){
		Zad1++;
	}
	if(pokolenieN[17][2]=='X'){
		Zad1++;
	}
	if(pokolenieN[17][1]=='X'){
		Zad1++;
	}
	if(pokolenieN[17][0]=='X'){
		Zad1++;
	}
	//5.2
	Pokolenie(2);
	for(int i=0;i<=11;i++){
		for(int j=0;j<=19;j++){
			if(pokolenieN[j][i]=='X'){
				Zad2++;
			}
		}
	}
	//5.3
	for(int i=2;i<=100;i++){
		Pokolenie(i);
		for(int z=0;z<=11;z++){
			for(int j=0;j<=19;j++){
				if(pokolenieN[j][z]!=pokolenieP[j][z]){
					czyUklad=false;
				}
				if(pokolenieP[j][z]=='X'){
					Temp2++;
				}
			}
		}
		if(czyUklad==true){
			Zad3=i;
			Zad3Z=Temp2;
			break;
		}
		czyUklad=true;
		Temp2=0;
	}
	cout<<"5.1: "<<Zad1<<endl;
	cout<<"5.2: "<<Zad2<<endl;
	cout<<"5.3: ktora generacja: "<<Zad3<<" ile zywych: "<<Zad3Z<<endl;
}
