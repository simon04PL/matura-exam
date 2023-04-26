#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int Zad1=0, Zad2=0, TempX=0, TempY=0, k=0, Zad3=0;
string x[1000], y[1000];

bool czyAnagram(string a, string b){
	set<char>anagram;
	anagram.clear();
	if(a.length()==b.length()){
		for(int i=0;i<=a.length()-1;i++){
			if(anagram.count(a[i])==0){
				anagram.insert(a[i]);
				TempX=0;
				TempY=0;
				for(int j=i;j<=a.length()-1;j++){
					if(a[j]==a[i]){
						TempX++;
					}
				}
				for(int j=0;j<=a.length()-1;j++){
					if(b[j]==a[i]){
						TempY++;
					}
				}
				if(TempX!=TempY){
					return 0;
				}
			}
		}
		return 1;
	}else{
		return 0;
	}
}
int main(){
	ifstream plik;
	plik.open("dane_napisy.txt");
	for(int i=0;i<=999;i++){
		plik>>x[i]>>y[i];
	}
	//68.1
	for(int i=0;i<=999;i++){
		if(x[i].length()==y[i].length()){
			for(int j=1;j<=x[i].length()-1;j++){
				if(x[i][j]!=x[i][j-1]||y[i][j]!=y[i][j-1]||y[i][j]!=x[i][j]){
					break;
				}
				if(j==x[i].length()-1){
					Zad1++;
				}
			}
		}
	}
	//68.2
	for(int i=0;i<=999;i++){
		if(czyAnagram(x[i], y[i])==1){
			Zad2++;
		}
	}
	//68.3
	for(int i=0;i<=999;i++){
		k=0;
		for(int j=0;j<=999;j++){
			if(czyAnagram(x[i],y[j])==1){
				k++;
			}
			if(czyAnagram(x[i],x[j])==1){
				k++;
			}
		}
		if(k>Zad3){
			Zad3=k;
		}
		k=0;
		for(int j=0;j<=999;j++){
			if(czyAnagram(y[i],y[j])==1){
				k++;
			}
			if(czyAnagram(y[i],x[j])==1){
				k++;
			}
		}
		if(k>Zad3){
			Zad3=k;
		}
	}
	cout<<"68.1: "<<Zad1<<endl;
	cout<<"68.2: "<<Zad2<<endl;
	cout<<"68.3: "<<Zad3<<endl;
	return 0;
}
