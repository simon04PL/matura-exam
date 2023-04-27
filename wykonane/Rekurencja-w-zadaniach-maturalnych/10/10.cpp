#include <iostream>
#include <string>

using namespace std;

int Zad2=0;

void pisz(string s,int n,int k){
	Zad2++;
	if(s.length()==n){
		cout<<s<<" ";
	}else{
		string napis[100];
		for(int i=0;i<=k-1;i++){
			string Temp=to_string(i);
			pisz(s+Temp,n,k);
		}
	}
}
int main(){
	string s;
	int n,k;
	cin>>n>>k;
	pisz("", n, k);
	cout<<endl;
	cout<<Zad2;
	return 0;
}
