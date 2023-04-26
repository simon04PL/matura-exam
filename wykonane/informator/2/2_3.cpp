#include <iostream>
#include <fstream>

using namespace std;

int Temp=0, Zad3;
string x;

int main(){
	ifstream plik;
	plik.open("dane2_3.txt");
	while(plik){
		plik>>x;
		for(int i=0;i<=x.length()-1;i++){
			if(x[i]=='['){
				Temp++;
			}else{
				Temp--;
			}
			if(Zad3<Temp){
				Zad3=Temp;
			}
		}
		cout<<Zad3<<endl;
		Zad3=0;
		Temp=0;
		x.clear();
	}
	return 0;
}
