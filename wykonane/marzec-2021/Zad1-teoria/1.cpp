#include <iostream>

using namespace std;

int k,x,y,runda;

void turniej(){
	for(int i=1;i<=k;i++){
		if(x%2!=y%2){
			runda =i;
		}
		x/=2;
		y/=2;
	}
	cout<<runda;
}
int main(){
	cin>>k>>x>>y;
	turniej();
	return 0;
}
