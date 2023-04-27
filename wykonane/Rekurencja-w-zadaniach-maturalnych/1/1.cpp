#include <iostream>

using namespace std;

int sklej(int n){
	if(n==1){
		return 0;
	}else if(n%2==0){
		return n-1+2*sklej((n/2));
	}else{
		return n-1+sklej((n-1)/2)+sklej((n+1)/2);
	}
}
int main(){
	int x;
	cin>>x;
	cout<<sklej(x);
	return 0;
}
