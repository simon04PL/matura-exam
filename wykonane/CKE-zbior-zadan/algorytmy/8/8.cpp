#include <iostream>

using namespace std;

int n, i=1, j, x, Zad1=0;
int A[100], B[100];

int main(){
	cin>>n>>x;
	for(int z=1;z<=n;z++){
		cin>>A[z];
	}
	for(int z=1;z<=n;z++){
		cin>>B[z];
	}
	j=n;
	while(i<=n&&j>0){
		Zad1++;
		if(A[i]+B[j]==x){
			cout<<"True "<<Zad1;
			return 0;
		}else{
			if(A[i]+B[j]<x){
				i++;
			}else{
				j--;
			}
		}
	}
	cout<<"Fals "<<Zad1;
	return 0;
}
