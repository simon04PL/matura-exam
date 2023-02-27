#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

string S1CzasString, S2CzasString, S3CzasString, S1TempString, S2TempString, S3TempString;
int S1CzasInt, S2CzasInt, S3CzasInt, S1TempInt, S2TempInt, S3TempInt, Zad1S1=400, Zad1S2=400, Zad1S3=400, y, l, k,p, Temp, Zad2=0, Temp1=12, Zad3=0, TempRekord1=-400, TempRekord2=-400, TempRekord3=-400, r, iJ, Zad4=0, tR;
int liczbaBlinarna[32], temperaturaS1[1095];
bool czyUjemna =false;


void DziesientneNaBlinarne(int y){
    if(y<0){
        y*=-1;
        czyUjemna=true;
    }else{
        czyUjemna=false;
    }
    int i=0;
    while(y){
        liczbaBlinarna[i]=y%2;
        y/=2;
        i++;
    }
    if(czyUjemna==true){
        cout<<'-';
    }
    for(int j=i-1;j>=0;j--){
        cout<<liczbaBlinarna[j];
    }
}
int main(){
    ifstream plik1;
    ifstream plik2;
    ifstream plik3;
    plik1.open("dane_systemy1.txt");
    plik2.open("dane_systemy2.txt");
    plik3.open("dane_systemy3.txt");
    for(int i=0;i<=1094;i++){
        plik1>>S1CzasString>>S1TempString;
        plik2>>S2CzasString>>S2TempString;
        plik3>>S3CzasString>>S3TempString;
        //58.1        
		S1TempInt=stoi(S1TempString,nullptr,2);
        S2TempInt=stoi(S2TempString,nullptr,4);
        S3TempInt=stoi(S3TempString,nullptr,8);
        if(Zad1S1>S1TempInt){
            Zad1S1=S1TempInt;
        }
        if(Zad1S2>S2TempInt){
            Zad1S2=S2TempInt;
        }
        if(Zad1S3>S3TempInt){
            Zad1S3=S3TempInt;
        }
        //58.2        
		S1CzasInt=stoi(S1CzasString,nullptr,2);
        S2CzasInt=stoi(S2CzasString,nullptr,4);
        S3CzasInt=stoi(S3CzasString,nullptr,8);
        if(Temp1!=S1CzasInt&&Temp1!=S2CzasInt&&Temp1!=S3CzasInt){
            Zad2++;
        }
        Temp1+=24;
        //58.3       
		if(TempRekord1<S1TempInt||TempRekord2<S2TempInt||TempRekord3<S3TempInt){
            Zad3++;
            if(TempRekord1<S1TempInt){
                TempRekord1=S1TempInt;
            }
            if(TempRekord2<S2TempInt){
                TempRekord2=S2TempInt;
            }
            if(TempRekord3<S3TempInt){
                TempRekord3=S3TempInt;
            }
        }
        //58.4        
		temperaturaS1[i]=S1TempInt;
        S1CzasString.clear();
        S2CzasString.clear();
        S3CzasString.clear();
        S1TempString.clear();
        S2TempString.clear();
        S3TempString.clear();   
    }
    for(int i=0;i<=1093;i++){
        for(int j=i+1;j<=1094;j++){
            if(temperaturaS1[i]>temperaturaS1[j]){
                tR=temperaturaS1[i]-temperaturaS1[j];
                r=tR*tR;
                iJ=j-i;
                if(Zad4<r/iJ){
                    Zad4=r/iJ;
                    if(r%iJ!=0){
                        Zad4++;
                    }
                }
            }else{
                tR=temperaturaS1[i]-temperaturaS1[j];
                r=tR*tR;
                iJ=j-i;
                if(Zad4<r/iJ){
                    Zad4=r/iJ;
                    if(r%iJ!=0){
                        Zad4++;
                    }
                }
            }
        }
    }
    cout<<"58.1: dla stacji S1: ";
    DziesientneNaBlinarne(Zad1S1);
    cout<<" dla stacji S2: ";
    DziesientneNaBlinarne(Zad1S2);
    cout<<" dla stacji S3: ";
    DziesientneNaBlinarne(Zad1S3);
    cout<<endl;
    cout<<"58.2: "<<Zad2<<endl;
    cout<<"58.3: "<<Zad3<<endl;
    cout<<"58.4: "<<Zad4;
    return 0;
}
