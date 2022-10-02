#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int plikInt[100];
int odwroconeInt[100];
int xInt[100];
int yTab[100];
int y=0;
int z=0;
string xString;

int main() {
	ifstream plikIn;
	ofstream plikOut;
	plikIn.open("liczby.txt");
	plikOut.open("wyniki4.txt");
	for(int i =0; i<=100;i++){
		plikIn>>plikInt[i];
		xString=to_string(plikInt[i]);
		reverse(xString.begin(),xString.end());
		odwroconeInt[i]=stoi(xString);
	}
	//4.1
	for(int i =0; i<=99;i++){
		if(odwroconeInt[i]%17==0){
			xInt[y]=odwroconeInt[i];
			y++;
		}
	}
	plikOut<<"4.1 ";
	for(int i =0; i<=y-1;i++){
		plikOut<<xInt[i]<<endl;
	}
	//4.2
	y=0;
	for(int i =0; i<=100;i++){
		if(plikInt[i]-odwroconeInt[i]>=0){
			if(plikInt[i]-odwroconeInt[i]>y){
				y=plikInt[i]-odwroconeInt[i];
				z=plikInt[i];
			}
		}else{
			if(odwroconeInt[i]-plikInt[i]>y){
				y=odwroconeInt[i]-plikInt[i];
				z=plikInt[i];
			}
		}
	}
	plikOut<<"4.2 liczba: "<<z<<endl;
	plikOut<<"wartosc bezwzgledna tej liczby: "<<y<<endl;
	//4.3
	y=0;
	for(int i =0; i<=100;i++){
		for(int j=2;j<=odwroconeInt[i];j++){
			if(odwroconeInt[i]%j==0){
				break;
			}else if(plikInt[i]%j==0){
				break;
			}
			if(j>=odwroconeInt[i]-1){
				yTab[y]=plikInt[i];
				y++;
			}
		}
	}
	plikOut<<"4.3 ";
	for(int i =0; i<=y-1;i++){
		plikOut<<yTab[i]<<endl;
	}
	//4.4
	y=0;
	z=0;
	set<int> powrorzeniaSet;
	multiset<int> powtorzeniaMultiset;
	for(int i =0; i<=100;i++){
		powrorzeniaSet.insert(plikInt[i]);
		powtorzeniaMultiset.insert(plikInt[i]);
	}
	for(int i =0; i<=100;i++){
		if(powtorzeniaMultiset.count(plikInt[i])==3){
			z++;
		}
		if(powtorzeniaMultiset.count(plikInt[i])==2){
			y++;
		}
	}
	plikOut<<"4.4 roznych cyfr jest: "<<powrorzeniaSet.size()<<endl;
	plikOut<<"dokladnie 2: "<<y/2<<endl;
	plikOut<<"dokladnie 3: "<<z/3<<endl;
	return 0;
}
