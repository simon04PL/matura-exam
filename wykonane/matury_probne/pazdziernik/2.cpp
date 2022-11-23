#include <iostream>
#include<set>
#include<fstream>

using namespace std;

string slowo, tempString;
int a=0,b=0,c=0,tempLiczba=0;
int main(){
	fstream plik;
	fstream plik1;
	plik.open("teksty.txt");
	plik1.open("wzorce.txt");
	for(int i =0;i<500;i++){
		plik>>slowo;
		set<char> Litery(slowo.begin(), slowo.end());
		multiset<char>LiteryDuplikat(slowo.begin(), slowo.end());
		//1.a
		if(Litery.size()==26){
			a++;
		}
		//1.b
		if(Litery.size()==slowo.length()){
			b++;
		}
		//1.3
		for(auto e: Litery){
			if(LiteryDuplikat.count(e)>tempLiczba){
				tempLiczba==LiteryDuplikat.count(e);
				tempString=slowo;
			}
		}
	}
	cout<<a<<'\n';
	cout<<b<<'\n';
	cout<<tempLiczba<<" "<<tempString<<'\n';
	return 0;
}
