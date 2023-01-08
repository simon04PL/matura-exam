#include <iostream>

using namespace std;

int a, x, M,b;

void mod(){
	int p=1;
	for(int i=1;i<=x;i++){
		p=p*a;
	}
	b=p%M;
	cout<<b;
}

int main(){
	cin>>a>>x>>M;
	mod();
	return 0;
}
