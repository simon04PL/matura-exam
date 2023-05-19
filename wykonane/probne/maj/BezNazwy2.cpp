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
int main(){
	for(int i=2;i<=8;i++){
		cout<<wynik(i)<<endl;
	}
	return 0;
}
