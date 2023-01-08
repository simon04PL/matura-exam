#include <iostream>

using namespace std;

int B, x;
int potega(int ile, int reszta){
	int resztaTemp=reszta;
	for(int i=1;i<=ile;i++){
		resztaTemp=resztaTemp*reszta;
	}
	return resztaTemp;
}
void narcystyczna(){
	int xP=x;
	int ile=0;
	int wynik=0;
	int BTemp=1;
	while(x!=0){
		cout<<wynik<<endl;
		int m=x;
		int k=1;
		while(m>10){
			m=m/10;
			k++;
		}
		if(ile==0){
			ile=k;
		}
		k--;
		cout<<k<<endl;
		int w=k*10;
		BTemp=B*BTemp;
		int reszta=x%w;
		wynik+=potega(ile, reszta)*BTemp;
		x=x-reszta;
		x=x/w;
	}
	if(xP==wynik){
		cout<<"TAK";
	}else{
		cout<<"NIE";
	}
}
int main(){
	cin>>x>>B;
	narcystyczna();
	return 0;
}
