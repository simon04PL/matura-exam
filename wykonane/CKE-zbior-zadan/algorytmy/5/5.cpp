#include <iostream>

using namespace std;

int n, x, p, k, i, Zad1K[]={0,0,0,0,0,0}, Zad1P[]={0,0,0,0,0,0};
int A[100];

int main(){
	cin>>n;
	for(int j=1;j<=n;j++){
		cin>>A[j];
	}
	for(int j=n-1;j>=1;j--){
		x=A[j];
		p=j;
		k=n+1;
		while(k-p>1){
			i=(p+k)/2;
			if(x<=A[i]){
				k=i;
				Zad1K[j]++;
			}else{
				p=i;
				Zad1P[j]++;
			}
			for(i=j;i<=p-1;i++){
				A[i]=A[i+1];
			}
			A[p]=x;
		}
	}
	cout<<"5.1: "<<endl;
	for(int j=5;j>=1;j--){
		cout<<"i do k: "<<Zad1K[j]<<" i na p: "<<Zad1P[j]<<endl;
	}
	return 0;
}
