#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int liczby[1000];
int pierwsze[1000];
int s;
int a=0;
int b=0;
int l1=0;
int l2=0;
int l3=0;
int maxP =0;
int maxK=0;
int maxL=0;
int p=0;
int k=0;
int l=0;

bool czyPierwsza(int n){
	if(n==1){
		return false;
	}
	for(int d=2; d<n;d++){
		if(n%d==0){
			return false;
		}
	}
	return true;
}

int main() {
	ifstream plik;
	plik.open("liczby.txt");
	for(int i=0;i<=1000;i++){
		plik>>liczby[i];
	}
	//1.1
	for(int i=1;i<=1000;i++){
		if(liczby[i-1]>liczby[i]){
			s=liczby[i];
		}else{
			s=liczby[i-1];
		}
		for(int j=2;j<=s;j++){
			if(liczby[i]%j==0&&liczby[i-1]%j==0){
				break;
			}
			if(j==s){
				a++;
			}
		}
	}
	cout<<"1.1 "<<a<<endl;
	
	//1.2a
	cout<<"1.2b ";
	for(int i =2;i<=1000;i++){
		if(liczby[i-2]+liczby[i-1]==liczby[i]){
			b++;
			string x=to_string(liczby[i-2]);
			string y=to_string(liczby[i-1]);
			string z=to_string(liczby[i]);
			l1=x.length();
			l2=y.length();
			l3=z.length();
			if(l1<l2&&l2<l3){
				cout<<liczby[i-2]<<" "<<liczby[i-1]<<" "<<liczby[i]<<endl;
			}
		}
	}
	cout<<"1.2a "<<b<<endl;
	//1.3
	for(int i=0;i<=1000;i++){
		pierwsze[i]=liczby[i];
	}
	for(int i =0;i<1000;i++){
		if(!czyPierwsza(pierwsze[i])){
			pierwsze[i]=0;
		}
	}
	for(int i =1;i<1000;i++){
		if(pierwsze[i]>pierwsze[i-1]){
			if(pierwsze[i-1]){
				p=i;
			}
			l++;
		}
		else{
			if(l>maxL){
				maxP=p;
				maxK=i-1;
				maxL=l;
			}
			l=0;
		}
	}
	cout<<maxL<<" "<<pierwsze[maxP]<<" "<<pierwsze[maxK]<<endl;
	return 0;
}
