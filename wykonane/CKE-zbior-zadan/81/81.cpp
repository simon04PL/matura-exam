#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <vector>

using namespace std;

int Zad1=0, Zad2=0, Zad3L, Zad794=0;
float Zad3Max=0, TempAB, TempBC, TempAC, Temp, xS, yS, xD, yD;
float xA1[100],xB1[100],xC1[100],yA1[100],yB1[100],yC1[100],xA2[100],xB2[100],xC2[100],yA2[100],yB2[100],yC2[100];

int main(){
	ifstream plik1;
	ifstream plik2;
	plik1.open("wspolrzedne.txt");
	plik2.open("wspolrzedneTR.txt");
	vector<int>Zad5I;
	vector<float>Zad5X;
	vector<float>Zad5Y;
	for(int i=0;i<=99;i++){
		plik1>>xA1[i]>>yA1[i]>>xB1[i]>>yB1[i]>>xC1[i]>>yC1[i];
		plik2>>xA2[i]>>yA2[i]>>xB2[i]>>yB2[i]>>xC2[i]>>yC2[i];
	}
	//81.1
	for(int i=0;i<=99;i++){
		if(xA1[i]>0&&yA1[i]>0&&xB1[i]>0&&yB1[i]>0&&xC1[i]>0&&yC1[i]>0){
			Zad1++;
		}
	}
	//81.2
	for(int i=0;i<=99;i++){
		if((yA1[i]-yB1[i])/(xA1[i]-xB1[i])==(yC1[i]-yB1[i])/(xC1[i]-xB1[i])){
			Zad2++;
		}
	}
	//81.3
	for(int i=0;i<=99;i++){
		Temp=((xB2[i]-xA2[i])*(xB2[i]-xA2[i]))+((yB2[i]-yA2[i])*(yB2[i]-yA2[i]));
		TempAB=sqrt(Temp);
		Temp=((xC2[i]-xB2[i])*(xC2[i]-xB2[i]))+((yC2[i]-yB2[i])*(yC2[i]-yB2[i]));
		TempBC=sqrt(Temp);
		Temp=((xC2[i]-xA2[i])*(xC2[i]-xA2[i]))+((yC2[i]-yA2[i])*(yC2[i]-yA2[i]));
		TempAC=sqrt(Temp);
		if(TempAB+TempBC+TempAC>Zad3Max){
			Zad3Max=TempAB+TempBC+TempAC;
			Zad3L=i;
		}
	}
	//79.4
	for(int i=0;i<=99;i++){
		TempAB=((xB2[i]-xA2[i])*(xB2[i]-xA2[i]))+((yB2[i]-yA2[i])*(yB2[i]-yA2[i]));
		TempBC=((xC2[i]-xB2[i])*(xC2[i]-xB2[i]))+((yC2[i]-yB2[i])*(yC2[i]-yB2[i]));
		TempAC=((xC2[i]-xA2[i])*(xC2[i]-xA2[i]))+((yC2[i]-yA2[i])*(yC2[i]-yA2[i]));
		if(TempAB+TempBC==TempAC||TempAC+TempBC==TempAB||TempAB+TempAC==TempBC){
			Zad794++;
		}
	}
	//81.5
	for(int i=0;i<=99;i++){
		xD=xA2[i]-xB2[i]+xC2[i];
		yD=yA2[i]-yB2[i]+yC2[i];
		if(xD==yD){
			Zad5I.push_back(i);
			Zad5X.push_back(xD);
			Zad5Y.push_back(yD);
		}
	}
	cout<<"81.1: "<<Zad1<<endl;
	cout<<"81.2: "<<Zad2<<endl;
	cout<<"81.3: A("<<xA2[Zad3L]<<", "<<yA2[Zad3L]<<"); B("<<xB2[Zad3L]<<", "<<yB2[Zad3L]<<"); C("<<xC2[Zad3L]<<", "<<yC2[Zad3L]<<") Obw="<<Zad3Max<<endl;
	cout<<"79.4: "<<Zad794<<endl;
	cout<<"81.5: "<<endl;
	for(int i=0;i<=Zad5I.size()-1;i++){
		cout<<"A("<<xA2[Zad5I[i]]<<", "<<yA2[Zad5I[i]]<<"); B("<<xB2[Zad5I[i]]<<", "<<yB2[Zad5I[i]]<<"); C("<<xC2[Zad5I[i]]<<", "<<yC2[Zad5I[i]]<<") D("<<Zad5X[i]<<", "<<Zad5Y[i]<<")"<<endl;
	}
	return 0;
}
