#include <iostream>
#include <fstream>

using namespace std;

int Temp=0;
string x;

int main(){
	ifstream plik;
	plik.open("dane2_4.txt");
	while(plik){
		plik>>x;
		for(int i=0;i<=x.length()-1;i++){
			if(x[i]=='['){
				Temp++;
			}else{
				Temp--;
			}
		}
		if(Temp==0){
			cout<<"tak"<<endl;
		}else{
			cout<<"nie"<<endl;
		}
		Temp=0;
		x.clear();
	}
	return 0;
}
