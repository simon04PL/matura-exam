#include <iostream>

using namespace std;

int n;
int s[100];

int main(){
	cin>>n;
	s[1]=0;
	for(int i=2;i<=n;i++){
		if(i%2==0){
			s[i]=i-1+2*s[i/2];
		}else{
			s[i]=i-1+s[(i-1)/2]+s[(i+1)/2];
		}
	}
	cout<<s[n];
	return 0;
}
