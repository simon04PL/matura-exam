#include <iostream>
#include <string>
#include <set>

using namespace std;

bool z=true;
int xInt;
int l;
int wynik=0;
int yInt;
char yChar;

int main() {
	set<int>wynikSet;

	cin>>xInt;
	while(z==true){
		string xString = to_string(xInt);
		l=xString.length();
		for(int i=l-1;i>=0;i--){
			yChar=xString[i];
			yInt=yChar - '0';
			wynik+=yInt*yInt;	
		}
		if(wynik==1){
			cout<<xInt<<" jest liczba nudna";
			z=false;
		}else if(wynikSet.count(wynik)==1){
			cout<<xInt<<" jest liczba ciekawa";
			z=false;
		}else{
		wynikSet.insert(wynik);
		xInt=wynik;
		wynik=0;
		}
	}
	
	return 0;
}
