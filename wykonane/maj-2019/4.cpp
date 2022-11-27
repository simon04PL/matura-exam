#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

int kopiaN,suma,c;
int x[499];
vector<int>Zad2;

int silnia(int n){
	if(n==1){
		return 1;
	}else{
		return n*silnia(n-1);
	}
}
bool czySumaSilni(int n){
	kopiaN=n;
	suma=0;
	while(n>0){
		c=n%10;
		suma+=silnia(c);
		n=n/10;
		if(kopiaN==suma){
			return true;
		}else{
			return false;
		}
	}
}
int main(){
	ifstream plik;
	plik.open("przyklad.txt");
	for(int i =0;i<=499;i++){
		plik>>x[i];
	}
	//4.1
	
	//4.2
	for(int i=0;i<=499;i++){
		if(czySumaSilni(x[i])==true){
			Zad2.push_back(x[i]);
		}
	}
	
	cout<<"4.2: ";
	for(int i=0;i<=Zad2.size();i++){
		cout<<Zad2[i]<<" ";
	}
	return 0;
}
