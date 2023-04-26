#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>

using namespace std;

int maxL=0, a, b, w=0, Zad2=0, Zad3=0;
int x[2023], y[2023], z[2023];
set<int> l;
multiset<int> lMulti;
pair <int, int>P[2023];

bool Porownanie(pair<int, int> p1, pair<int, int>p2){
	return p1.second-p1.first+1<p2.second-p2.first+1;
}
void Zad3_2(){
	for(auto e:l){
		if(maxL<lMulti.count(e)){
			Zad2=lMulti.count(e);
			maxL=e;
		}
	}
}
void Zad3_3(){
	sort(P, P+2023, Porownanie);
	fill(z, z+2023, 1);
	for(int i=1;i<=2022;i++){
		for(int j=i-1;j>=0;j--){
			if(P[i].first<=P[j].first&&P[i].second>=P[j].second&&z[i]<z[j]+1){
				z[i]=z[j]+1;
			}
		}
	}
	for(int i=0;i<=2022;i++){
		if(z[i]>Zad3){
			Zad3=z[i];
		}
	}
}
int main(){
	fstream plik;
	plik.open("dane3.txt");
	//3.1
	for(int i =0;i<=2022;i++){
		plik>>a>>b;
		x[i]=a;
		y[i]=b;
		P[i].first=a;
		P[i].second=b;
		l.insert(b-a+1);
		lMulti.insert(b-a+1);
	}
	cout<<"3.1: ";
	for(auto e:l){
		cout<<e<<" ";
		w++;
		if(w==2){
			break;
		}
	}
	cout<<endl;
	Zad3_2();
	cout<<"3.2: "<<maxL<<" ile razy wystapila: "<<Zad2<<endl;
	Zad3_3();
	cout<<"3.3: "<<Zad3;
	return 0;
}
