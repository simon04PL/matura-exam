#include <iostream>

using namespace std;

int N, strzalkaX[2047], strzalkaY[2047],i=0, n=0;

int rysuj(int x){
	if(2*x<=N){
		strzalkaX[i]=x;
		strzalkaY[i]=x*2;
		n++;
		if(strzalkaY[i]==2047){
			cout<<n<<endl;
		}
		i++;
		rysuj(2*x);
	}
	if(2*x+1<=N){
		strzalkaX[i]=x;
		strzalkaY[i]=x*2+1;
		n++;
		if(strzalkaY[i]==2047){
			cout<<n<<endl;
		}
		i++;
		rysuj(2*x+1);
	}
	return 1;
}
int main(){
	cin>>N;
	rysuj(1);
	for(int j=0;j<=2047;j++){
		cout<<"x= "<<strzalkaX[j]<<"y= "<<strzalkaY[j]<<endl;
	}
	return 0;
}
