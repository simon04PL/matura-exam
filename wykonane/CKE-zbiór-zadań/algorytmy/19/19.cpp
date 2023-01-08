#include <iostream>

using namespace std;

int p, n, *A,*B,*R, *c;

void dodawanie(){
	for(int i=n;i>=0;i--){
		int x=A[i-1]+B[i-1]+R[i-1];
		R[i-2]=x/p;
		c[i]=x%p;
	}
	for(int i =0;i<=n;i++){
		cout<<c[i];
	}
}
int main(){
	cin>>p>>n;
	A= new int [n];
	B= new int [n];
	R= new int [n];
	c= new int [n+1];
	for(int i =0;i<=n-1;i++){
		cin>>A[i];
	}
	for(int i =0;i<=n-1;i++){
		cin>>B[i];
	}
	dodawanie();
	return 0;
}
