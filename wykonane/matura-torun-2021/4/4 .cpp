#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n,k, Temp;
string Zad3Temp;

set<int>Zad1;
vector<vector<int>>x;
vector<int>y;
set<string>Zad3;

void Zad4_2(){
	for(int i=0;i<=n-1;i++){
		for(int j=0;j<=x[i].size()-1;j++){
			Zad1.insert(x[i][j]);
		}
	}
}
void Zad4_3(){
	for(int i=0;i<=n-1;i++){
		for(int j=0;j<=x[i].size()-1;j++){
			for(int z=0;z<=x[x[i][j]].size()-1;z++){
				if(i==x[x[i][j]][z]){
					Zad3Temp.clear();
					Zad3Temp.push_back(min(x[i][j]+48, i+48));
					Zad3Temp.push_back('-');
					Zad3Temp.push_back(max(x[i][j]+48, i+48));
					Zad3.insert(Zad3Temp);
					break;
				}
			}
		}
	}
}
int main(){
	cin>>n;
	for(int i=0;i<=n-1;i++){
		cin>>k;
		for(int j=0;j<=k-1;j++){
			cin>>Temp;
			y.push_back(Temp);
			
		}
		x.push_back(y);
		y.clear();
	}
	Zad4_2();
	Zad4_3();
	cout<<"4.2: "<<endl;
	for(int i=0;i<=n-1;i++){
		if(Zad1.count(i)==0){
			cout<<i<<endl;
		}
	}
	cout<<"4.3: "<<endl;
	for(auto e:Zad3){
		cout<<e<<endl;
	}
	
}
