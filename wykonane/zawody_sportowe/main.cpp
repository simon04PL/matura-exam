#include <iostream>
#include <fstream>

using namespace std;

int seria [310];
int x=0;
int y=0;
int minSkok=100000000;
int maxSkok=0;
int minDzien;
int maxDzien;
int maxSeria=0;
int maxSeriProgres;


int main() {
	ifstream plik;
	plik.open("dziennik.txt");
	for(int i =0;i<=309;i++){
		plik>>seria[i];
	}
	//a
	for(int i=1;i<=309;i++){
		if(seria[i]>seria[i-1]){
			x++;
		}else{
			if(x>=3){
				y++;
			}
			x=0;
		}
	}
	cout<<y<<endl;
	//b
	for(int i=0;i<=309;i++){
		if(seria[i]<minSkok){
			minSkok=seria[i];
			minDzien=i+1;
		}else if(seria[i]>maxSkok){
			maxSkok=seria[i];
			maxDzien=i+1;
		}
	}
	cout<<minSkok<<" "<<minDzien<<endl;
	cout<<maxSkok<<" "<<maxDzien<<endl;
	//c
	x=0;
	for(int i=1;i<=309;i++){
		if(seria[i]>seria[i-1]){
			x++;
		}else {
			if(x>maxSeria){
				maxSeria=x+1;
				maxSeriProgres=seria[i-1]-seria[i-x-1];
			}
			x=0;
		}	
	}
	cout<<maxSeria<<endl;
	cout<<maxSeriProgres<<endl;
	return 0;
}
