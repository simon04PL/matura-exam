#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int h, k;
string x,y;

int main(){
	ifstream plik3;
	ifstream plik4;
	plik3.open("dane3_3.txt");
	plik4.open("dane3_4.txt");
	//3.3
	cout<<"3.3: ";
	for(int i=0;i<=49;i++){
		plik3>>x;
		k=0;
		h=0;
		for(int j=0;j<=x.length()-1;j++){
			if(x[j]=='['){
				k++;
				if(k>h){
					h=k;
				}
			}else{
				k--;
			}
		}
		cout<<h<<endl;
	}
	cout<<"3.4: ";
	for(int i=0;i<=49;i++){
		plik4>>y;
		k=0;
		//3.4
		for(int j=0;j<=y.length()-1;j++){
			if(x[j]=='['){
				k++;
			}else{
				k--;
			}
		}
		if(k!=0){
			cout<<"nie"<<endl;
		}else{
			cout<<"tak"<<endl;
		}
	}
	return 0;
}
