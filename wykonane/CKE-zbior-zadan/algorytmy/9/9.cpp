#include <iostream>

using namespace std;

int Zad3=0;

void wieze(int n, char x, char y, char z){
	cout<<"9.1: n: "<<n<<" x: "<<x<<" y: "<<y<<" z: "<<z<<endl;
	if(n==1){
		Zad3++;
		cout<<"9.2: "<<x<<" "<<y<<endl;
	}else{
		wieze(n-1,x,z,y);
		Zad3++;
		cout<<"9.2: "<<x<<" "<<y<<endl;
		wieze(n-1,z,y,x);
	}
}
int main(){
	int n;
	char x,y,z;
	cin>>n>>x>>y>>z;
	wieze(n,x,y,z);
	cout<<"9.3: "<<Zad3<<endl;
	return 0;
}
