#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;
int Zad1=0, Temp, Zad2=0, suma,k=0,l, moc=0, p=10, Zad1Min=1000000000, Zad1Max=0;
long long iloczyn;
int x[1000];
string xS, xK;
bool czyParzysta;

int main(){
    ifstream plik;
    plik.open("liczby.txt");
    set<int>Zad1P;
    multiset<int>Zad3;
    for(int i=0;i<=999;i++){
        plik>>x[i];
    }
    //59.1    
	for(int i=0;i<=999;i++){
        Temp=x[i];
        while(Temp>1){
        	czyParzysta=false;
            for(int j=2;j<=Temp;j++){
                if(Temp%j==0){
                    Temp=Temp/j;
                    if(j%2==1){
                    	Zad1P.insert(j);
					}else{
						czyParzysta=true;
						break;
					}
					break;
                }
            }
            if(czyParzysta==true){
            	break;
			}
        }
        if(Zad1P.size()==3&&czyParzysta==false){
            Zad1++;
        }
        Zad1P.clear();
    }
    //59.2  
	for(int i=0;i<=999;i++){
        suma=x[i];
        xS=to_string(x[i]);
        reverse(xS.begin(), xS.end());
        Temp=stoi(xS);
        suma+=Temp;
        xS.clear();
        xS=to_string(suma);
        xK=to_string(suma);
        reverse(xK.begin(), xK.end());
        if(xS==xK){
        	Zad2++;
		}
        xS.clear();
        xK.clear();
    }
    //59.3    
	for(int i=0;i<=999;i++){
		moc=0;        
		iloczyn=x[i];        
		while(iloczyn>9){
			xS=to_string(iloczyn);            
			iloczyn=1;            
			l=xS.length()-1;            
			for(int j=0;j<=l;j++){                
				Temp=xS[j]-48;             
				iloczyn=Temp*iloczyn;            
			}           
			moc++;       
		}        
		Zad3.insert(moc);
		if(moc==1){
			if(x[i]>Zad1Max){
				Zad1Max=x[i];
			}
			if(x[i]<Zad1Min){
				Zad1Min=x[i];
			}
		}
	} 
	cout<<"59.1: "<<Zad1<<endl;
    cout<<"59.2: "<<Zad2<<endl;
    cout<<"59.3: minimalna liczba o mocy 1: "<<Zad1Min<<" max liczba o mocy 1: "<<Zad1Max<<endl;
    for(int i=1;i<=8;i++){
        cout<<i<<" "<<Zad3.count(i)<<endl;
    }
    return 0;
}
