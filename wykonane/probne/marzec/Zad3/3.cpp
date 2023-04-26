#include <iostream>
#include <fstream>

using namespace std;

int n;
float x,w;
float a[6];

int main(){
	ifstream plik;
	plik.open("wielomiany.txt");
	for(int i=0;i<=999;i++){
		for(int j=5;j>=0;j--){
			plik>>a[j];
		}
		plik>>x;
		w=a[5];
		for(int k=n-1;k>=0;k--){
			w=x*w+a[k];
		}
		if(w>-10&&w<10){
			for(int z=5;z>=0;z--){
				cout<<a[z]<<" ";
			}
			cout<<endl;
		}
	}
	
	return 0;
}
