#include <iostream>
#include <math.h>
#include<string>
#include <fstream>

using namespace std;

unsigned long long x;
unsigned long long index=1;
unsigned long long wynik=0;

int main() {
	cin>>x;
	while(x/index>=1){
		index=index*10;
	}
	for(int i=index; i>=0;i--){
		wynik+=pow(x%index,2);
		x=x-index-x%index;
		cout<<wynik;
	}
	return 0;
}
