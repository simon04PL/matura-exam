#include <iostream>
#include <string>

using namespace std;

int xInt;
int l;
int wynik=0;
int yInt;
char yChar;

int main() {
	cin>>xInt;
	string xString = to_string(xInt);
	l=xString.length();
	for(int i=l-1;i>=0;i--){
		yChar=xString[i];
		yInt=yChar - '0';
		wynik+=yInt*yInt;	
	}
	cout<<wynik;
	
	return 0;
}
