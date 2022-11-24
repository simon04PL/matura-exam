#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <math.h>

using namespace std;

int x[1000], y[1000];
int Zad1=0, Zad2=0,Zad3XA, Zad3XB,Zad3YA, Zad3YB, Zad4A=0,Zad4B=0,Zad4C=0;
float Zad3Temp,Zad3;
string xString,yString;

 czyPierwsza(int p){
    if(p==1){
        return false;
    }else if(p==2){
        return true;
    }
    for(int i=2;i<p;i++){
        if(p%i==0){
            return false;
        }
    }
    return true;
}
int main(){
	set<char>znaki;
	set<char>znakiTemp;
	ifstream plik;
	plik.open("punkty.txt");
	for(int i=0;i<=999;i++){
		plik>>x[i];
		plik>>y[i];
	}
	//4.1
	for(int i=0;i<=999;i++){
		if(czyPierwsza(x[i])==true&&czyPierwsza(y[i])==true){
			Zad1++;
		}
	}
	//4.2
	for(int i =0;i<=999;i++){
		xString=to_string(x[i]);
		yString=to_string(y[i]);
		for(int j =0;j<=xString.size();j++){
			znaki.insert(xString[j]);
		}
		for(int j=0;j<=yString.size();j++){
			if(znaki.count(yString[j])==1){
				znakiTemp.insert(yString[j]);
				if(znakiTemp.size()==znaki.size()&&j>=yString.size()){
					Zad2++;
				}
			}else{
				break;
			}
		}
		xString.clear();
		yString.clear();
		znaki.clear();
		znakiTemp.clear();
	}
	//4.3
	for(int i=0;i<=998;i++){
		for(int j=i+1;j<=999;j++){
			Zad3Temp=pow((x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]),2);
			if(Zad3Temp>Zad3){
				Zad3=Zad3Temp;
				Zad3XA=x[i];
				Zad3XB=x[j];
				Zad3YA=y[i];
				Zad3YB=y[j];
			}
		}
	}
	//4.4
	 for(int i =0;i<=999;i++){
        if(x[i]<=5000){
            if(x[i]==5000&&y[i]>=5000){
                Zad4B++;
            }else if(x[i]<5000&&y[i]==5000){
                Zad4B++;
            }
        }
        if(x[i]>5000||y[i]>5000){
            Zad4C++;
        }
        if(x[i]<5000&&y[i]<5000){
            Zad4A++;
        }
    }
	cout<<"4.1: "<<Zad1<<endl;
	cout<<"4.2: "<<Zad2<<endl;
	cout<<"4.3: ("<<Zad3XA<<","<<Zad3YA<<"),("<<Zad3XB<<","<<Zad3YB<<")"<<endl;
	cout<<"4.4: wewnatrz: "<<Zad4A<<"na bokach: "<<Zad4B<<"na zewnatrz: "<<Zad4C;
	return 0;
}
