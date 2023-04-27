#include <iostream>

using namespace std;

int Zad2=0;

int sym(int a, int b){
	if(a!=0){
		sym(a-1,b+1);
		Zad2++;
		cout<<a*b<<" ";
		sym(a-1,b+1);
	}
}
int main(){
	int a,b;
	cin>>a>>b;
	sym(a, b);
	cout<<endl;
	cout<<Zad2;
	return 0;
}
