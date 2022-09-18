#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <set>

using namespace std;

string b;
int y =0;
int l;
int maxI;
string maxS;
int x=0;
int d=0;
int tmp;
int bO [20];
int h=0;

int main() {
	
	ifstream plik;
	plik.open("liczby.txt",ios::in);
	
	for(int i=0;i<1000; i++){
		plik>>b;
		l=b.length();
		//6.a
		if(b[l-1]=='0'){
			y++;
		}
		//6.b
		d=0;
		for(int j = 0;j<=l;j++){
			if(b[l-1-j]=='1'){
				d+=pow(2,j);
			}
		}
		if(d>maxI){
			maxI=d;
			maxS=b;
		}
		//6.c
		if(l==9){
			x++;
		}
	}
	tmp=x;
	while(tmp){
		bO[h++]=tmp%2;
		tmp=tmp/2;
	}
	
	cout<<y<<endl;
	cout<<maxI<<" "<<maxS<<endl;
	cout<<x<<" ";
	for(int i=h;i>=0;i--){
		cout<<bO[i];
	}
	return 0;
}
