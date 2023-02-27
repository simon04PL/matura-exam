#include <iostream>
#include <fstream>

using namespace std;

int p[100],k[100],a[100],b[100],c[100], Zad2=0, Zad3=0, Zad4, Zad4Temp=0, Zad4Max=0;

int main(){
	ifstream plikP;
	ifstream plikT;
	plikP.open("przedzialy.txt");
	plikT.open("trojmiany.txt");
	for(int i=0;i<=99;i++){
		plikP>>p[i]>>k[i];
		plikT>>a[i]>>b[i]>>c[i];
	}
	//3.2
	for(int i=0;i<=99;i++){
		for(int j=p[i+1];j<=k[i];j++){
			if(a[i]*(j-1)*(j-1)+b[i]*(j-1)+c[i]==0||a[i]*j*j+b[i]*j+c[i]==0){
				Zad2++;
				break;
			}else if(a[i]*(j-1)*(j-1)+b[i]*(j-1)+c[i]>0&&a[i]*j*j+b[i]*j+c[i]<0){
				Zad2++;
				break;
			}else if(a[i]*(j-1)*(j-1)+b[i]*(j-1)+c[i]<0&&a[i]*j*j+b[i]*j+c[i]>0){
				Zad2++;
				break;
			}
		}
	}
	//3.3
	for(int i=0;i<=99;i++){
		for(int j=p[i+1];j<=k[i];j++){
			if(a[i]*(j-1)*(j-1)+b[i]*(j-1)+c[i]>=a[i]*j*j+b[i]*j+c[i]){
				break;
			}
			if(j==k[i]){
				Zad3++;
			}
		}
	}
	//3.4
	for(int i=0;i<=99;i++){
		for(int j=p[i+1];j<=k[i];j++){
			if(a[i]*(j-1)*(j-1)+b[i]*(j-1)+c[i]<a[i]*j*j+b[i]*j+c[i]){
				Zad4Temp++;
			}
			if(k[i]==j&&Zad4Max<Zad4Temp){
				Zad4Max=Zad4Temp;
				Zad4=i+1;
			}
		}
		Zad4Temp=0;
	}
	cout<<"3.2: "<<Zad2<<endl;
	cout<<"3.3: "<<Zad3<<endl;
	cout<<"3.4: "<<Zad4<<endl;
	return 0;
}
