#include <iostream>

using namespace std;

int n,x,k,m,w;
int Z[100], A[50], B[50];

int F(int T[]){
	if(n==1){
		return T[0];
	}
	k=n/2;
	for(int i=0;i<=k-1;i++){
		A[i]=T[i];
		B[i]=T[n-i];
		return F(A)+F(B)*Z[m-1];
	}
}
int main(){
	int T[1000];
	cin>>n>>x;
	Z[0]=x;
	m=1;
	w=2;
	while(w<n){
		Z[m]=Z[m-1]*Z[m-1];
		m++;
		w=w*2;
	}
	for(int i=0;i<=n-1;i++){
		cin>>T[i];
	}
	cout<<F(T);
	return 0;
}
