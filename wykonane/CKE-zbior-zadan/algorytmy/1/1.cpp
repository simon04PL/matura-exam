#include <iostream>

using namespace std;


int wynik(int i){
	if(i<3){
		return 1;
	}else{
		if(i%2==0){
			return wynik(i-3)+wynik(i-1)+1;
		}else{
			return wynik(i-1)%7;
		}
	}
}
int E(int i){
	if(i<3){
		return 1;
	}else{
		if(i%2==0){
			return E(i-3)+E(i-1);
		}else{
			return E(i-1);
		}
	}
}
int main(){
	int i;
	cin>>i;
	cout<<"1.1: "<<wynik(i)<<endl;
	cout<<"1.2: "<<E(i)<<endl;
	return 0;
}
