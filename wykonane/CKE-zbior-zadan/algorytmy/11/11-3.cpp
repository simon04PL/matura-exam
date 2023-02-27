#include <iostream>

using namespace std;

int n, licznik;
char X[100];

bool CzyPoprawne(){
	licznik=0;
	for(int i=1;i<=n;i++){
		if(X[i]!='*'&&X[i]!='+'&&X[i]!='-'){
			licznik++;
		}else{
			if(licznik<2){
				cout<<licznik<<endl;
				return 0;
			}else{
				licznik--;
			}
		}
	}
	cout<<licznik<<endl;
	if(licznik!=1){
		return 0;
	}else{
		return 1;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>X[i];
	}
	cout<<CzyPoprawne();
	return 0;
}
