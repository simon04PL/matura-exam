#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int Zad1=0,y,z;
int x[3000];
string A,B;

int main(){
	ifstream plik;
	plik.open("liczby.txt");
	for(int i =0;i<=2999;i++){
		plik>>x[i];
	}
	//4.1
	for(int i=0;i<=2998;i++){
		for(int j=i+1;j<=2999;j++){
			A=to_string(x[i]);
			B=to_string(x[j]);
			y=A.length();
			z=B.length();
			if(z==y){
				for(int k=0;k<=z;k++){
					if(A[k]!=B[y-k-1]){
						break;
					}
					if(k>=z){
						Zad1++;
					}
				}
			}
			A.clear();
			B.clear();
		}
	}
	//4.2
	
	cout<<"4.1: "<<Zad1<<endl;
	return 0;
}
