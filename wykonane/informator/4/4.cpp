#include <iostream>
#include <fstream>

using namespace std;

int maxI, Temp=0, l;
int A[2023];


int main(){
	ifstream plik;
	plik.open("dane4.txt");
	for(int i=0;i<=2022;i++){
		plik>>A[i];
	}
	for(int i=1;i<=2022;i++){
		for(int j=i-1;j>=0;j--){
			if(A[i]>A[j]){
				l++;
			}
		}
		if(l>Temp){
			Temp=l;
			maxI=i;
		}
		l=0;
	}
	cout<<maxI+1;
	return 0;
}
