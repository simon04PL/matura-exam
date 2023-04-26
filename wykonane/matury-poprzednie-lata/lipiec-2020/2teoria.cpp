#include <iostream>

using namespace std;

int p, q;


void egipskie(){
	int odwrotnosc;
	do{
		if(q%p==0){
			odwrotnosc=q/p;
		}else{
			odwrotnosc=q/p+1;
		}
		cout<<"1\\"<<odwrotnosc<<endl;
		p=p*odwrotnosc-q;
		q=q*odwrotnosc;
	}while(p>0);
}
int main(){
	cin>>p>>q;
	egipskie();
	return 0;
}
