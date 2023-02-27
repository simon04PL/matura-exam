#include <iostream>

using namespace std;

int n,k,b,a;
char X[100];
int T[100];

int main(){
	cin>>n;
	k=1;
	for(int i=1;i<=n;i++){
		cin>>X[i];
	}
	for(int i=1;i<=n;i++){
		if(X[i]!='*'&&X[i]!='+'&&X[i]!='-'){
			T[k]=X[i]-48;
		}else{
			b=T[k-1];
			a=T[k-2];
			k-=2;
			if(X[i]=='+'){
				T[k]=a+b;
			}else if(X[i]=='-'){
				T[k]=a-b;
			}else if(X[i]=='*'){
				T[k]=a*b;
			}
		}
		k++;
		cout<<"11.2: "<<i<<" "<<k<<" ";
		for(int j=1;j<=k-1;j++){
			cout<<T[j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
