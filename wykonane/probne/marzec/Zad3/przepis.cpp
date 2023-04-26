#include <iostream>

using namespace std;

int n;
float x,w;
float a[100];

int main(){
	cin>>n>>x;
	for(int i=0;i<=n-1;i++){
		cin>>a[i];
	}
	w=a[n];
	for(int k=n-1;k>=0;k--){
		w=x*w+a[k];
		cout<<k<<" "<<w<<endl;
	}
	return 0;
}
