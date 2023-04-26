#include <iostream>
#include <fstream>

using namespace std;

int n,k=-1, a,b, wynik;
int S[50];
string W[50];

int main(){
	ifstream plik;
	plik.open("wyrazenia.txt");
	for(int i=0;i<=49;i++){
		plik>>W[i];
	}
	for(int i=0;i<=50;i++){
		for(int j=0;j<=W[i].length();j++){
			if(W[i]!='+'&&W[i]!='-'&&W[i]!='*'&&W[i]!='/'){
				k++;
				S[k]=W[i];
			}else{
				a=S[k];
				k--;
				b=S[k];
				k--;
				if(W[i]=='+'){
					wynik=a+b;
				}else if(W[i]=='-'){
					wynik=b-a;
				}else if(W[i]=='*'){
					wynik=b*a;
				}else if(W[i]=='/'){
					wynik=b/a;
				}
				k++;
				S[k]=wynik;
			}
		}
	}
	return 0;
}
