#include <iostream>
#include <vector>

using namespace std;

int n, x,k=0;
vector<int>A;

void permutacja(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n-1;j++){
			if(A[j]==i){
				break;
			}
			if(j==n-1){
				k++;
			}
		}
	}
	cout<<k;
}
int main(){
	cin>>n;
	for(int i =0;i<=n-1;i++){
		cin>>x;
		A.push_back(x);
	}
	permutacja();
	return 0;
}
