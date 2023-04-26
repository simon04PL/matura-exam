#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int k=0;
string b, z;

int F(int n){
	if(n==1||n==2){
		return 1;
	}else{
		return F(n-1)+F(n-2);
	}
}
bool czyPierwsza(int n){
	if(n==1){
		return 0;
	}else if(n==2){
		return 1;
	}else{
		for(int i=2;i<=n-1;i++){
			if(n%i==0){
				return 0;
			}
		}
		return 1;
	}
}
void naBlinarny(int n){
	int Temp =n;
	b.clear();
	while(Temp){
		z=to_string(Temp%2);
		b.push_back(z[0]);
		Temp=Temp/2;
		z.clear();
	}
	reverse(b.begin(), b.end());
}
int main(){
	vector<int>Zad2;
	vector<int>Zad4;
	//67.2
	for(int i=1;i<=40;i++){
		if(czyPierwsza(F(i))){
			Zad2.push_back(F(i));
		}
	}
	//67.4
	for(int i=1;i<=40;i++){
		naBlinarny(F(i));
		for(int j=0;j<=b.length()-1;j++){
			if(b[j]=='1'){
				k++;
			}
		}
		if(k==6){
			Zad4.push_back(i);
		}
		k=0;
	}
	cout<<"67.1: "<<endl;
	cout<<"10: "<<F(10)<<endl<<"20: "<<F(20)<<endl<<"30: "<<F(30)<<endl<<"40: "<<F(40)<<endl;
	cout<<"67.2: "<<endl;
	for(int i=0;i<=Zad2.size()-1;i++){
		cout<<Zad2[i]<<endl;
	}
	cout<<"67.4: "<<endl;
	for(int i=0;i<=Zad4.size()-1;i++){
		naBlinarny(F(Zad4[i]));
		cout<<b<<endl;
	}
	return 0;
}
