#include <iostream>

using namespace std;

float W[6];

void blinarny(float x, int k){
	cout<<"0,";
	float y=x;
	for(int i=1;i<=k;i++){
		W[i]=y;
		if(y>=0.5){
			cout<<"1";
		}else{
			cout<<"0";
		}
		y=y*2;
		if(y>=1){
			y=y-1;
		}
	}
}
int main(){
	int k;
	float x;
	cin>>x>>k;
	cout<<"1.1:"<<endl;
	blinarny(x,k);
	cout<<endl;
	for(int i=1;i<=5;i++){
		cout<<i<<": "<<W[i]<<endl;
	}
	
}
