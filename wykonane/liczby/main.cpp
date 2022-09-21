#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <stdio.h>

using namespace std;

int xInt[5000];
int l;
int a=0;
int b =0;
int c =0;
int d =0;
int index;
int yInt=0;
string xString;
string yString;

int inty_na_stringi(int x){
	xString = to_string(x);
	return 0;
}

int main() {
	ifstream plik;
	plik.open("dane.txt");
	for(int i =0; i<=5000;i++){
		plik>>xInt[i];
	}
	//a
	for(int i =0; i<=5000-1;i++){
		inty_na_stringi(xInt[i]);
		l=xString.length();
		if(xString[0]==xString[l-1]){
			a++;
		}
	}	
	cout<<a<<endl;
	a=0;
	//b
	for(int i =0; i<=5000-1;i++){
		yInt=0;
		index=1;
		inty_na_stringi(xInt[i]);
		l=xString.length();
		for(int j=0; j<=l;j++){
			if(xString[l-j-1]=='1'){
				yInt+=index*1;
			}else if(xString[l-j-1]=='2'){
				yInt+=index*2;
			}else if(xString[l-j-1]=='3'){
				yInt+=index*3;
			}else if(xString[l-j-1]=='4'){
				yInt+=index*4;
			}else if(xString[l-j-1]=='5'){
				yInt+=index*5;
			}else if(xString[l-j-1]=='6'){
				yInt+=index*6;
			}else if(xString[l-j-1]=='7'){
				yInt+=index*7;
			}
			index=index*8;
		}
		yString = to_string(yInt);
		l=yString.length();
		if(yString[0]==yString[l-1]){
			b++;
		}
	}
	cout<<b<<endl;
	//c
	for(int i =0; i<=5000-1;i++){
		inty_na_stringi(xInt[i]);
		l=xString.length();
		d=0;
		for(int j=0;j<=l-1;j++){
			if(xString[j]>=xString[j-1]){
				d+=0;
			}else{
				d++;
			}
		}
		if(d==0){
			c++;
		}

	}
	cout<<c<<endl;
	return 0;
}
