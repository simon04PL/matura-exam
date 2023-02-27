#include <iostream>

using namespace std;

int k, Temp,n, s=1, z=1, j;
int A[100];

int main(){
	cin>>k;
	for(int i=1;i<=k;i++){
		z*=2;
	}
	for(int i =1;i<=z;i++){
		cin>>A[i];
	}
	n=1;
	for(int i=1;i<=k;i++){
		n*=2;
	}
	s=1;
	while(s<n){
		j=1;
		while(j<n){
			if(A[j]>A[j+s]){
				Temp=A[j];
				A[j]=A[j+s];
				A[j+s]=Temp;
			}
			j=j+2*s;
		}
		s*=2;
	}
	cout<<A[1]<<endl;
	for(int i=1;i<=z;i++){
		cout<<A[i]<<", ";
	}
	return 0;
}
