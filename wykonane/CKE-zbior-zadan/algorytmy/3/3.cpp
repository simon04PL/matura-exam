#include <iostream>

using namespace std;

int k;

int F(int x, int n){
	if(n==1){
		return x;
	}else{
		if(n%3==0){
			k=F(x, n%3);
			return k*k*k;
		}else{
			return x*F(x, n-1);
		}
	}
}
int main(){
	int x,n;
	cin>>x>>n;
	cout<<F(x, n);
	return 0;
}
