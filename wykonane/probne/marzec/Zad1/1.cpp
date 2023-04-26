#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

string Temp;
string A[200], B[200];

int main(){
	ifstream plik;
	plik.open("slowa.txt");
	for(int i=0;i<=199;i++){
		plik>>A[i]>>B[i];
	}
	//1.1
	
	//1.2
	cout<<B[0];
	for(int i=0;i<=1;i++){
		Temp=reverse(B[i]);
		cout<<Temp;
	}
	return 0;
}
